// Chauvet NFC handler
//
// Manages changes to the the NFC data

#include <memory.h>
#include <string.h>
#include "stdlib.h"

#include "chauvet_nfc_demo.h"
#include "ndef_demo.h"

/* Display management */
#if defined(ST25DX_DISCOVERY_MB1283)
#include "st25dx_discovery_lcd.h"
#elif defined(ST25_DISCOVERY_MB1396)
#include "st25_discovery_lcd.h"
#endif /* ST25DX_DISCOVERY_MB1283 */
#include "Menu_config.h"
#include "Menu_core.h"

/* Tag & board management */
#include "commonfunc.h"
#include "mailboxfunc.h"
#include "stm32l4xx_it.h"
#if defined(ST25DX_DISCOVERY_MB1283)
#include "st25dx_discovery.h"
#elif defined(ST25_DISCOVERY_MB1396)
#include "st25_discovery.h"
#endif /* ST25DX_DISCOVERY_MB1283 */

#include "ndef_config.h"
#include "ndef_message.h"
#include "ndef_nfcv_wrapper.h"
#include "ndef_types.h"
#include "ndef_demo.h"
#include "chauvet_nfc_demo.h"
#include "chauvet_dummy_fixture.h"

int nfc_startup(void)
{
    // On start up check the NFC to see whether there are any requests from the App
	// Action any requests then update the NFC with latest fixture and config data
	// Returns 1 if the NFC was commissioned by this function


	if (nfc_check_commissioning()) return (1);

	// NFC was already commissioned so just read and update it

	nfc_read_trip_data();  	        // If Trip data stored only in the NFC tag (not in fixture) then read it from the Tag now

	nfc_update_fixture_record();    // Update fixture record of the NFC

	nfc_check_changed();   		    // Check for Config changes from the NFC requested when fixture was powered off

	nfc_update_config_record();     // Update Config record of the NFC

	return (0);
}



int nfc_check_commissioning(void)
{
	// Check to see whether NFC needs commissioning
	// Returns true if commissioning was required

	if (!ndef_is_fixture_record_valid())
	{
		ndef_find_record_offsets();     // Check for valid Chauvet NDEF records
	}


    if (ndef_is_fixture_record_valid())
	{
		uint8_t fixt_status = 0;
		if (ndef_read_fixture_record((uint8_t *)&fixt_status,offsetof(NFCFixtureRecord_t,fixt_status),sizeof(fixt_status)))
			return 0;  // Failed to read

		if (!(fixt_status & FIXT_STATUS_COMMISSIONING_INTIALIZED))
		{
			// NFC records need commissioning

			ndef_find_record_offsets();     // The NFC record offsets and lengths may have changed, so set them up again

			nfc_update_fixture_record();    // Write Fixture data to the NFC

			nfc_reset_logs();               // Initialise the Log records in the NFC

			nfc_init_rental();              // Initialise the Rental record in the NFC

			nfc_update_config_record();     // Write current Config data to the NFC

		    fixt_status = FIXT_STATUS_COMMISSIONING_INTIALIZED;         // Mark the NFC as commissioned.  The App will then finish the Commissioning
			ndef_write_fixture_record((uint8_t *)&fixt_status,offsetof(NFCFixtureRecord_t,fixt_status),sizeof(fixt_status));

			return 1;
		}
	}


	return 0;
}


uint32_t nfc_get_last_powered_off_utc(void)
{
	uint32_t time_last_powered_off = 0;

	if (ndef_is_fixture_record_valid())
	{
		ndef_read_fixture_record((uint8_t *)&(time_last_powered_off),offsetof(NFCFixtureRecord_t,time_last_powered_off),sizeof(time_last_powered_off));
	}

	return (time_last_powered_off);
}


void nfc_read_trip_data(void)
{
	// Read the current trip data from the NFC

   if (!ndef_is_fixture_record_valid()) return;

   ndef_read_fixture_record((uint8_t *)&(dummy_fixture.trip_lamp_strikes),offsetof(NFCFixtureRecord_t,trip_lamp_strikes),sizeof(dummy_fixture.trip_lamp_strikes));
   ndef_read_fixture_record((uint8_t *)&(dummy_fixture.trip_device_hours),offsetof(NFCFixtureRecord_t,trip_device_hours),sizeof(dummy_fixture.trip_lamp_hours));
   ndef_read_fixture_record((uint8_t *)&(dummy_fixture.trip_lamp_hours),offsetof(NFCFixtureRecord_t,trip_lamp_hours),sizeof(dummy_fixture.trip_device_hours));
   ndef_read_fixture_record((uint8_t *)&(dummy_fixture.trip_power_cycles),offsetof(NFCFixtureRecord_t,trip_power_cycles),sizeof(dummy_fixture.trip_power_cycles));
   ndef_read_fixture_record((uint8_t *)&(dummy_fixture.trip_error_count),offsetof(NFCFixtureRecord_t,trip_error_count),sizeof(dummy_fixture.trip_error_count));
}


void nfc_update_fixture_record(void)
{
   // Updates the Fixture record in the NFC memory

   if (!ndef_is_fixture_record_valid()) return;

   NFCFixtureRecord_t data;

   memset((uint8_t *)&data,0,sizeof(NFCFixtureRecord_t));

   // Read fields that the App writes, so we don't overwrite them

   uint8_t fixt_status = 0;
   ndef_read_fixture_record((uint8_t *)&(data.fixt_status),offsetof(NFCFixtureRecord_t,fixt_status),sizeof(data.fixt_status));
   fixt_status |= FIXT_STATUS_COMMISSIONING_INTIALIZED;

   ndef_read_fixture_record((uint8_t *)&(data.device_serial_number),offsetof(NFCFixtureRecord_t,device_serial_number),sizeof(data.device_serial_number));

   // Set fields from our dummy fixture data

   data.ndef_structure_type = __builtin_bswap16(0);

   data.ndef_structure_version = __builtin_bswap16(0);

   data.product_category[0] = 0x00;   // Product Category as returned in E1-20 RDM DEVICE_INFO
   data.product_category[1] = 0x04;

   data.device_model_id[0] = 0;       // Model ID as returned in E1-20 RDM DEVICE_INFO
   data.device_model_id[1] = 10;

   strcpy(data.manufacturer_label,"Chauvet");  // As returned in E1-20 MANUFACTURER_LABEL

   strcpy(data.device_model_description,"Fancy Spot");  // Same as Device Model Description as returned in E1-20 RDM DEVICE_MODEL_DESCRIPTION

   strcpy(data.personality_description,get_mode_str(dummy_fixture.personality_main));

   // Write the Fixture data

   memcpy(data.device_uid,dummy_fixture.device_uid,sizeof(data.device_uid));
   memcpy(data.rdm_uid,dummy_fixture.rdm_uid,sizeof(data.rdm_uid));
   memcpy(data.device_serial_number,dummy_fixture.device_serial_number,sizeof(data.device_serial_number));
   memcpy(data.mac_address,dummy_fixture.mac_address,sizeof(data.mac_address));
   data.software_version = __builtin_bswap32(dummy_fixture.software_version);
   memcpy(data.software_version_label,dummy_fixture.software_version_label,sizeof(data.software_version_label));
   data.boot_software_version = __builtin_bswap32(dummy_fixture.boot_software_version);

   data.lamp_strikes = __builtin_bswap32(dummy_fixture.lamp_strikes);
   data.device_hours = __builtin_bswap32(dummy_fixture.device_hours);
   data.lamp_hours = __builtin_bswap32(dummy_fixture.lamp_hours);
   data.device_power_cycles = __builtin_bswap32(dummy_fixture.device_power_cycles);
   data.device_status = __builtin_bswap32(dummy_fixture.device_status);

   data.battery_level = dummy_fixture.battery_level;

   data.device_error_count = __builtin_bswap32(dummy_fixture.device_error_count);

   data.time_last_powered_on = __builtin_bswap32(dummy_fixture.time_last_powered_on);
   data.time_last_powered_off = __builtin_bswap32(dummy_fixture.time_last_powered_off);
   data.time_last_lamped_on = __builtin_bswap32(dummy_fixture.time_last_lamped_on);
   data.time_last_lamped_off = __builtin_bswap32(dummy_fixture.time_last_lamped_off);

   data.trip_lamp_strikes = __builtin_bswap32(dummy_fixture.trip_lamp_strikes);
   data.trip_device_hours = __builtin_bswap32(dummy_fixture.trip_device_hours);
   data.trip_lamp_hours = __builtin_bswap32(dummy_fixture.trip_lamp_hours);
   data.trip_power_cycles = __builtin_bswap32(dummy_fixture.trip_power_cycles);
   data.trip_error_count = __builtin_bswap32(dummy_fixture.trip_error_count);

   // Report capabilities of our dummy fixture
   // These capabilities should reflect the capabilities of the real fixture

   data.capabilities_A = CAPABILITIES_A_PAN_TILT_REVERSE | CAPABILITIES_A_SWAP_PAN_TILT;
   data.capabilities_B = CAPABILITIES_B_FAN_SPEED_V1;
   data.capabilities_C = CAPABILITIES_C_DISPLAY_LEVEL | CAPABILITIES_C_DISPLAY_INVERT_V1 | CAPABILITIES_C_DISPLAY_SHUTOFF;
   data.capabilities_D = CAPABILITIES_D_DIMMER_CURVE_V1 | CAPABILITIES_D_DIMMER_RESPONSE_V1;
   data.capabilities_E = CAPABILITIES_E_LANGUAGE;
   data.capabilities_F = CAPABILITIES_F_NETWORK | CAPABILITIES_F_ETHERNET_MAIN;
   data.capabilities_G = 0;
   data.capabilities_H = CAPABILITIES_H_PAN_TILT_BLACKOUT ;
   data.capabilities_I = 0;
   data.capabilities_J = CAPABILITIES_J_FACTORY_RESET | CAPABILITIES_J_PAN_TILT_RESET;
   data.capabilities_K = 0;
   data.capabilities_L = 0;
   data.capabilities_M = 0;
   data.capabilities_N = 0;
   data.capabilities_O = CAPABILTIIES_O_ART_NET_MAIN | CAPABILTIIES_O_SACN_MAIN;
   data.capabilities_P = 0;
   data.capabilities_Q = 0;
   data.capabilities_R = 0;
   data.capabilities_S = CAPABILITIES_S_PWM_FREQUENCY_V1;
   data.capabilities_T = CAPABILITIES_T_RTC_TIMING;
   data.capabilities_U = 0;
   data.capabilities_V = 0;
   data.capabilities_W = 0;
   data.capabilities_X = 0;
   data.capabilities_Y = 0;
   data.capabilities_Z = 0;

   ndef_write_fixture_record((uint8_t *)&data,0,sizeof(NFCFixtureRecord_t));
}


void nfc_backup_times(void)
{
	// Updates the device hours and power off timers info to the NFC memory
	// Only updates the fields that change on timers
	// Other fields get updated when user makes the change

    if (!ndef_is_fixture_record_valid()) return;

    uint32_t data = __builtin_bswap32(dummy_fixture.device_hours);

    ndef_write_fixture_record((uint8_t *)&data,offsetof(NFCFixtureRecord_t,device_hours),sizeof(uint32_t));

    data = __builtin_bswap32(dummy_fixture.lamp_hours);

    ndef_write_fixture_record((uint8_t *)&data,offsetof(NFCFixtureRecord_t,lamp_hours),sizeof(uint32_t));

    data = __builtin_bswap32(dummy_fixture.trip_device_hours);

    ndef_write_fixture_record((uint8_t *)&data,offsetof(NFCFixtureRecord_t,trip_device_hours),sizeof(uint32_t));

    data = __builtin_bswap32(dummy_fixture.trip_lamp_hours);

    ndef_write_fixture_record((uint8_t *)&data,offsetof(NFCFixtureRecord_t,trip_lamp_hours),sizeof(uint32_t));

    data = __builtin_bswap32(dummy_fixture.time_last_powered_off);

    ndef_write_fixture_record((uint8_t *)&data,offsetof(NFCFixtureRecord_t,time_last_powered_off),sizeof(uint32_t));

    data = __builtin_bswap32(dummy_fixture.device_error_count);

    ndef_write_fixture_record((uint8_t *)&data,offsetof(NFCFixtureRecord_t,device_error_count),sizeof(uint32_t));

    data = __builtin_bswap32(dummy_fixture.trip_error_count);

    ndef_write_fixture_record((uint8_t *)&data,offsetof(NFCFixtureRecord_t,trip_error_count),sizeof(uint32_t));
}



uint16_t current_log_record = 0;                  // Internal index to the current log record, so we don't have to calculate it each time we write a record

void nfc_reset_logs(void)
{
	// Clears all the logs

	if (ndef_is_logging_record_valid())
	{
		int size = ndef_get_logging_record_size();

		if (size>sizeof(NFCLoggingRecord_t))
		{
			uint8_t *data = malloc(size);
			NFCLoggingRecord_t *hdr = (NFCLoggingRecord_t *) data;

			hdr->log_format = LOG_FORMAT_TIME_AND_CODE;
		    hdr->max_log_records = (size - sizeof(NFCLoggingRecord_t)) / sizeof(NFCLogTimeAndCode_t);

			for (int i=sizeof(NFCLoggingRecord_t);i<size;i++)
				data[i] = 0xFF;

            ndef_write_logging_record(data,0,size);

            current_log_record = 0;

			free (data);
		}
	}
}

void find_current_log_record(void)
{
	// Searches through log record to see where log pointer is for next free log record

	if (ndef_is_logging_record_valid())
	{
		int size = ndef_get_logging_record_size();

		if (size>sizeof(NFCLoggingRecord_t))
		{
			uint8_t *data = malloc(size);

			if (ndef_read_logging_record(data,0,size)==NFCTAG_OK)
			{
			    uint16_t max_records = (size - sizeof(NFCLoggingRecord_t)) / sizeof (NFCLogTimeAndCode_t);

				for (int i=0;i<max_records;i++)
				{
					NFCLogTimeAndCode_t *log_record = (NFCLogTimeAndCode_t *) &(data[sizeof(NFCLoggingRecord_t)+(i*sizeof(NFCLogTimeAndCode_t))]);
					if (log_record->log_code==0xFFF)
					{
						current_log_record = i;
						break;
					}
				}

			}
			free (data);
		}
	}
}


void nfc_write_log_record(uint16_t log_code)
{
	// Write a single log record the the NFC Log record

	if (ndef_is_logging_record_valid())
	{
	    uint16_t max_records = (ndef_get_logging_record_size() - sizeof(NFCLoggingRecord_t)) / sizeof (NFCLogTimeAndCode_t);

	    NFCLogTimeAndCode_t record;
		record.log_code = log_code;
		record.time = get_utc();
		ndef_write_logging_record(&record,sizeof(NFCLoggingRecord_t)+(current_log_record*sizeof(NFCLogTimeAndCode_t)),sizeof(NFCLogTimeAndCode_t));

		current_log_record++;
		if (current_log_record>=max_records) current_log_record = 0;

		// Ensure next record is clear so we can keep track of the start and end of the log

		record.log_code = 0xFFFF;
		record.time = 0xFFFFFFFF;
		ndef_write_logging_record(&record,sizeof(NFCLoggingRecord_t)+(current_log_record*sizeof(NFCLogTimeAndCode_t)),sizeof(NFCLogTimeAndCode_t));
	}
}

// Log Record Throttling
//
// To avoid the log filling up with all records of the same type, we throttle log records when we reach a threshold count for each log type
// Throttling is reset every time a fixture is power on / resets

#define MAX_THROTTLE_LOG_CODES 30                // This should be set to the maximum likely different log codes to occur in a session

#define MAX_LOG_RECORD_COUNT 20                  // This should be set with reference to the total number of log records in the log, to avoid one particular log code filling the whole log

uint32_t num_throttle_log_records = 0;
uint32_t throttle_count[MAX_THROTTLE_LOG_CODES];
uint32_t throttle_code[MAX_THROTTLE_LOG_CODES];


void nfc_add_log_record(uint16_t log_code)
{
	// Creates a log record
	// Throttle log writes to prevent log getting full of the same record

	if (log_code>=ERROR_CODES_START)
	{
	    dummy_fixture.device_error_count++;
	    dummy_fixture.trip_error_count++;
	}

	int i;

	for (i=0;i<num_throttle_log_records;i++)
	{
		if (throttle_code[i]==log_code)
		{
			throttle_count[i]++;
			if (throttle_count[i]>MAX_LOG_RECORD_COUNT)
				return; // Ignore this record as we have already logged it
			else if (throttle_count[i]==MAX_LOG_RECORD_COUNT)
				nfc_write_log_record(LOG_THROTTLED);   // Add an extra LOG_THROTTLED before the log_code to indicate no more log codes of this type will be logged in this session

			break;
		}
	}

	if (i>=num_throttle_log_records)   // First time this log code has been logged in this session
	{
		if (num_throttle_log_records<MAX_THROTTLE_LOG_CODES)
		{
			throttle_code[num_throttle_log_records] = log_code;
			throttle_count[num_throttle_log_records] = 1;
			num_throttle_log_records++;
		}
	}


	nfc_write_log_record(log_code);    // Write the log record
}

void nfc_init_rental(void)
{
	// Initialises the rental record to 0

	if (ndef_is_rental_record_valid())
	{
		NFCRentalRecord_t data;

		memset((uint8_t *)&data,0,sizeof(NFCRentalRecord_t));
		ndef_write_rental_record((uint8_t *)&data,0,sizeof(NFCRentalRecord_t));
	}
}



void nfc_update_config_record(void)
{
	// Updates entire NFC Config record from the internal fixture config data
	// Reads from the NFC memory first so any user fields/unknown fields are maintained with the same values

	if (!ndef_is_config_record_valid()) return;

	NFCConfigRecord_t data;

	if (ndef_read_config_record((uint8_t *)&data,0,sizeof(NFCConfigRecord_t))==NFCTAG_OK)
	{
	     data.start_address_main = __builtin_bswap16(dummy_fixture.start_address_main);
	     data.personality_main = __builtin_bswap16(dummy_fixture.personality_main);
	     memset(&(data.device_label),0,sizeof(data.device_label));
	     strcpy((char *)data.device_label,dummy_fixture.device_label);
		 data.option_A = dummy_fixture.option_A;
		 data.option_B = dummy_fixture.option_B;
		 data.option_C = dummy_fixture.option_C;
		 data.option_D = dummy_fixture.option_D;
		 data.option_E = dummy_fixture.option_E;
		 data.option_F = dummy_fixture.option_F;
		 data.option_G = dummy_fixture.option_G;
		 data.option_H = dummy_fixture.option_H;
		 data.option_I = dummy_fixture.option_I;
		 data.option_J = dummy_fixture.option_J;

		 data.pan_range = dummy_fixture.pan_range;
		 data.tilt_range = dummy_fixture.tilt_range;
         data.display_level = dummy_fixture.display_level;
         data.display_invert = dummy_fixture.display_invert;
         data.display_shutoff = dummy_fixture.display_shutoff;
         data.white_calibration = dummy_fixture.white_calibration;

		 data.dimmer_curve = dummy_fixture.dimmer_curve;
		 data.dimmer_response = dummy_fixture.dimmer_response;

		 data.language = __builtin_bswap16(dummy_fixture.language);

		 data.pwm_frequency = dummy_fixture.pwm_frequency;

		 data.ip_mode = dummy_fixture.ip_mode;

         memcpy(data.ip_address,dummy_fixture.ip_address,sizeof(dummy_fixture.ip_address));
		 memcpy(data.subnet_mask,dummy_fixture.subnet_mask,sizeof(dummy_fixture.subnet_mask));
		 memcpy(data.gateway_address,dummy_fixture.gateway_address,sizeof(dummy_fixture.gateway_address));

         data.universe_main = __builtin_bswap16(dummy_fixture.universe_main);
         data.universe_aux = __builtin_bswap16(dummy_fixture.universe_aux);

         data.user_observation_error_code = __builtin_bswap16(dummy_fixture.user_observation_error_code);

         data.ils_channel = dummy_fixture.ils_channel;
         data.rf_channel = dummy_fixture.rf_channel;

         ndef_write_config_record((uint8_t *)&data,0,sizeof(NFCConfigRecord_t));
	}
}


int nfc_check_changed(void)
{
	// Checks whether App has written to the NFC

	if (nfc_check_commissioning()) return 1;            // NFC has been recommissioned

	// Check log and trip reset flags in the Rental record

	if (ndef_is_rental_record_valid())
	{
		uint8_t trip_reset_flags = 0;
	    ndef_read_rental_record(&trip_reset_flags,offsetof(NFCRentalRecord_t,trip_reset_flags),1);

	    if (trip_reset_flags)
	    {
	    	if (trip_reset_flags & TRIP_RESET_LOGS_RESET)
	    		nfc_reset_logs();

	    	if (trip_reset_flags & TRIP_RESET_TRIP_RESET)
	    		fixture_reset_trip();

	    	trip_reset_flags &= ~ (TRIP_RESET_LOGS_RESET|TRIP_RESET_TRIP_RESET);        // Clear the reset flags that we have processed
   		    ndef_write_rental_record(&trip_reset_flags,offsetof(NFCRentalRecord_t,trip_reset_flags),1);
	    }
	}

	// Check for changes in the Config record

	if (ndef_is_config_record_valid())
	{
		uint8_t status = 0;
	    ndef_read_config_record(&status,offsetof(NFCConfigRecord_t,conf_status),1);

	    if (status & CONF_STATUS_CHANGED)
	    {
	    	// Read entire Config record

	    	NFCConfigRecord_t data;

	    	if (ndef_read_config_record((uint8_t *)&data,0,sizeof(NFCConfigRecord_t))==NFCTAG_OK)
	    	{
	    		// Check for actions first

	    		if (data.action_A) // Some resets
	    		{
					if (data.action_A & ACTION_A_FACTORY_RESET)
					{
						fixture_factory_reset();
					}

					uint8_t action = 0;   // Clear the action bits
				    ndef_write_config_record(&action,offsetof(NFCConfigRecord_t,action_A),1);
	    		}

                // Check for Config parameter changes

	    	    if (status & CONF_STATUS_PROPERTY_CHANGED)
	    	    {
					if (data.property_change_A & PROPERTY_CHANGE_A_START_ADDRESS_MAIN)
					{
						data.start_address_main = __builtin_bswap16(data.start_address_main); // byte swap 32 bit field
						dummy_fixture.start_address_main = data.start_address_main;
					}

					if (data.property_change_A & PROPERTY_CHANGE_A_PERSONALITY_MAIN)
					{
			    		data.personality_main = __builtin_bswap16(data.personality_main);
						dummy_fixture.personality_main = data.personality_main;
					}

					// Handle other Property change here


			    	memset(&(data.property_change_A),0,NUM_PROPERTY_CHANGE_BYTES);     // Clear all the property change bytes
				    ndef_write_config_record(&status,offsetof(NFCConfigRecord_t,property_change_A),NUM_PROPERTY_CHANGE_BYTES);
	    	    }

	    	    // Check for Option changes

	    	    if (status & CONF_STATUS_OPTION_CHANGED)
	    	    {
					if (data.option_change_B & OPTION_CHANGE_B_PAN_REVERSE)
					{
						dummy_fixture.option_B &= ~OPTION_B_PAN_REVERSE;
						dummy_fixture.option_B |= (data.option_B & OPTION_B_PAN_REVERSE);
					}

					if (data.option_change_B & OPTION_CHANGE_B_TILT_REVERSE)
					{
						dummy_fixture.option_B &= ~OPTION_B_TILT_REVERSE;
						dummy_fixture.option_B |= (data.option_B & OPTION_B_TILT_REVERSE);
					}

					// Handle other Option changes here


			    	memset(&(data.option_change_A),0,NUM_OPTION_CHANGE_BYTES);     // Clear all the option change bytes
				    ndef_write_config_record(&status,offsetof(NFCConfigRecord_t,option_change_A),NUM_OPTION_CHANGE_BYTES);
	    	    }


	    	}

	    	// Clear the Config changed flags

	    	status &= ~CONF_STATUS_CHANGED;  // Clear the bit
		    ndef_write_config_record(&status,offsetof(NFCConfigRecord_t,conf_status),1);

		    return (1);
	    }
	}

    return 0;
}

void nfc_update_dmx_start(void)
{
    uint16_t data = __builtin_bswap16(dummy_fixture.start_address_main);

    ndef_write_config_record((uint8_t *)&data,offsetof(NFCConfigRecord_t,start_address_main),sizeof(data));
}

void nfc_update_dmx_personality(void)
{
    uint16_t data = __builtin_bswap16(dummy_fixture.personality_main);

    ndef_write_config_record((uint8_t *)&data,offsetof(NFCConfigRecord_t,personality_main),sizeof(data));

    nfc_update_fixture_record();   // Ensure personality description in the NFC Fixture record is updated
}

