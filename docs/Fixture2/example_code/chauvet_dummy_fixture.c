// Chauvet Dummy Fixture
//
// Dummy fixture for testing of the NFC
// This is an example file only.
// This file will be replaced by the code of the fixture manufacturer


#include <memory.h>
#include <string.h>
#include "stdlib.h"

#include "ndef_demo.h"
#include "chauvet_dummy_fixture.h"
#include "chauvet_nfc_demo.h"

/* Display management */
#if defined(ST25DX_DISCOVERY_MB1283)
#include "st25dx_discovery_lcd.h"
#elif defined(ST25_DISCOVERY_MB1396)
#include "st25_discovery_lcd.h"
#endif /* ST25DX_DISCOVERY_MB1283 */
#include "Menu_config.h"
#include "Menu_core.h"

#include "st25_discovery.h"

extern volatile uint32_t ms_counter;

DummyFixture_t dummy_fixture;

uint32_t power_on_utc = 0;				// UTC value when device powered on (used if no RTC)

uint32_t last_check_nfc_utc = 0;        // Timer for checking changes made by the App in the NFC
uint32_t last_dev_hour_utc = 0;	        // Timer for updating dev hours (every hour after power on)
uint32_t last_lamp_hour_utc = 0;        // Timer for updating lamp hours (every hour after lamp strike)
uint32_t last_backup_time_utc = 0;		// Timer for updating times to NFC (every 15 minutes)


void start_utc()
{
	// If fixture does not have a RTC then need to start UTC from last power off time + 1

	power_on_utc = nfc_get_last_powered_off_utc()+1;

}

uint32_t get_utc()
{
	// Get the current UTC from the Real Time Clock
	// If fixture does not have a Real Time Clock then this is incrementing number of seconds, stored over power cycles

   return (power_on_utc+(ms_counter/1000));
}


void check_timers(void)
{
	// Check if App has written to NFC
	// Note this could be interrupt driven instead of polling

	if (get_utc()>last_check_nfc_utc+CHECK_NFC_INTERVAL)
	{
		if (nfc_check_changed())
			update_menu();
		last_check_nfc_utc += CHECK_NFC_INTERVAL;
	}


	// Check update device hours

	if (get_utc()>last_dev_hour_utc+DEV_HOURS_INTERVAL)
	{
		dummy_fixture.device_hours++;
		dummy_fixture.trip_device_hours++;
		last_dev_hour_utc += DEV_HOURS_INTERVAL;
	}

    // Check update lamp hours

	if (dummy_fixture.status & FIXTURE_STATUS_LAMP_ON)
	{
		if (get_utc()>last_lamp_hour_utc+DEV_HOURS_INTERVAL)
		{
			dummy_fixture.lamp_hours++;
			dummy_fixture.trip_lamp_hours++;
			last_lamp_hour_utc += DEV_HOURS_INTERVAL;
		}
	}

	// Check backup of times to NFC

	if (get_utc()>last_backup_time_utc+BACKUP_TO_NFC_INTERVAL)
	{
		nfc_backup_times();
		last_backup_time_utc += BACKUP_TO_NFC_INTERVAL;
	}
}



void create_fixture()
{
	// Creates data for the dummy fixture

    // The following data would be loaded from the non volatile storage of the fixture itself
    // Here we just initialise to some dummy values

    // Fixture data

    memset((uint8_t *)&dummy_fixture,0,sizeof(DummyFixture_t));   // Clear all data

    strcpy((char *)&(dummy_fixture.device_uid),"Spot 1234-56789");

    dummy_fixture.rdm_uid[0] = 0x21;
    dummy_fixture.rdm_uid[1] = 0xA4;
    dummy_fixture.rdm_uid[2] = 0x01;
    dummy_fixture.rdm_uid[3] = 0x02;
    dummy_fixture.rdm_uid[4] = 0x03;
    dummy_fixture.rdm_uid[5] = 0x04;

    strcpy((char *)&(dummy_fixture.device_serial_number),"12345678");

    dummy_fixture.mac_address[0] = 200;
    dummy_fixture.mac_address[1] = 201;
    dummy_fixture.mac_address[2] = 202;
    dummy_fixture.mac_address[3] = 203;
    dummy_fixture.mac_address[4] = 204;
    dummy_fixture.mac_address[5] = 205;

    dummy_fixture.software_version = (2<<8) | 0;
    strcpy((char *)&(dummy_fixture.software_version_label),"Version 2.0");
    dummy_fixture.boot_software_version = (1<<8) | 0;

    dummy_fixture.lamp_strikes = 10;
    dummy_fixture.device_hours = 100;
    dummy_fixture.lamp_hours = 30;
    dummy_fixture.device_power_cycles = 5;

    dummy_fixture.battery_level = 0;

    dummy_fixture.device_status = 0;

    dummy_fixture.time_last_powered_off = 0;
    dummy_fixture.time_last_powered_on = 0;
    dummy_fixture.time_last_lamped_on = 0;
    dummy_fixture.time_last_lamped_off = 0;


    // Fixture manufacturer may choose to store trip data in the fixture NV storage as well as the NFC tag, or just in the NFC tag
    // If only stored in the NFC tag then the trip data must be read from the Tag on power up

    dummy_fixture.trip_lamp_strikes = 0;
    dummy_fixture.trip_device_hours = 0;
    dummy_fixture.trip_lamp_hours = 0;
    dummy_fixture.trip_power_cycles = 0;
    dummy_fixture.trip_error_count = 0;

    // Config options

    dummy_fixture.start_address_main = 51;
    dummy_fixture.personality_main = 2;
    strcpy((char *)&(dummy_fixture.device_label),"Fixture 101");

    dummy_fixture.option_A = 0;
    dummy_fixture.option_B = 0;
    dummy_fixture.option_C = 0;
    dummy_fixture.option_D = 0;
    dummy_fixture.option_E = 0;
    dummy_fixture.option_F = 0;
    dummy_fixture.option_G = 0;
    dummy_fixture.option_H = 0;
    dummy_fixture.option_I = 0;
    dummy_fixture.option_J = 0;

    dummy_fixture.pan_range = 1;
    dummy_fixture.tilt_range = 1;

    dummy_fixture.display_level = 200;
    dummy_fixture.language = ('e'<<8) | 'n';
    dummy_fixture.dimmer_curve = 1;

    dummy_fixture.ip_address[0] = 2;
    dummy_fixture.ip_address[1] = 0;
    dummy_fixture.ip_address[2] = 0;
    dummy_fixture.ip_address[3] = 220;

    dummy_fixture.subnet_mask[0] = 255;
    dummy_fixture.subnet_mask[1] = 0;
    dummy_fixture.subnet_mask[2] = 0;
    dummy_fixture.subnet_mask[3] = 0;

    dummy_fixture.gateway_address[0] = 2;
    dummy_fixture.gateway_address[1] = 0;
    dummy_fixture.gateway_address[2] = 0;
    dummy_fixture.gateway_address[3] = 1;

    dummy_fixture.universe_main = 10;
    dummy_fixture.universe_aux = 20;

    dummy_fixture.ils_channel = 4;
    dummy_fixture.rf_channel = 5;
}


void fixture_power_on()
{
	// Called when the fixture powers on

	start_utc();

	dummy_fixture.device_power_cycles++;              // Every time we power on increment the power cycles
	dummy_fixture.trip_power_cycles++;
	dummy_fixture.time_last_powered_on = get_utc();

	nfc_startup();

	nfc_add_log_record(FIXTURE_POWER_ON);

	// Initalise timer intervals

	last_backup_time_utc = get_utc();
	last_dev_hour_utc = get_utc();
	last_lamp_hour_utc = 0;   // This gets set when fixture is lamped on

	update_menu();
}



void fixture_reset_trip()
{
	// Reset the fixture trip data

    dummy_fixture.trip_lamp_strikes = 0;
    dummy_fixture.trip_device_hours = 0;
    dummy_fixture.trip_lamp_hours = 0;
    dummy_fixture.trip_power_cycles = 0;
    dummy_fixture.trip_error_count = 0;
	nfc_update_fixture_record();
}


void fixture_lamp_on(void)
{
	// Called to lamp on the fixture

	dummy_fixture.status |= FIXTURE_STATUS_LAMP_ON;
	dummy_fixture.lamp_strikes++;
	dummy_fixture.trip_lamp_strikes++;
	dummy_fixture.time_last_lamped_on = get_utc();
	nfc_update_fixture_record();

	last_lamp_hour_utc = dummy_fixture.time_last_lamped_on;
}

void fixture_lamp_off(void)
{
    // Called to lamp off the fixture

	dummy_fixture.status &= ~FIXTURE_STATUS_LAMP_ON;
	dummy_fixture.time_last_lamped_off = get_utc();
	nfc_update_fixture_record();
}

void fixture_factory_reset()
{
	// Called to reset the config to factory default

    dummy_fixture.start_address_main = 0x01;
    dummy_fixture.personality_main = 1;
    strcpy((char *)&(dummy_fixture.device_label),"");

    dummy_fixture.option_A = 0;
    dummy_fixture.option_B = 0;
    dummy_fixture.option_C = 0;
    dummy_fixture.option_D = 0;
    dummy_fixture.option_E = 0;
    dummy_fixture.option_F = 0;
    dummy_fixture.option_G = 0;
    dummy_fixture.option_H = 0;
    dummy_fixture.option_I = 0;
    dummy_fixture.option_J = 0;

    dummy_fixture.pan_range = 1;
    dummy_fixture.tilt_range = 1;

    dummy_fixture.display_level = 200;
    dummy_fixture.language = ('e'<<8) | 'n';
    dummy_fixture.dimmer_curve = 1;

    dummy_fixture.ip_address[0] = 2;
    dummy_fixture.ip_address[1] = 0;
    dummy_fixture.ip_address[2] = 0;
    dummy_fixture.ip_address[3] = 101;

    dummy_fixture.subnet_mask[0] = 255;
    dummy_fixture.subnet_mask[1] = 0;
    dummy_fixture.subnet_mask[2] = 0;
    dummy_fixture.subnet_mask[3] = 0;

    dummy_fixture.gateway_address[0] = 2;
    dummy_fixture.gateway_address[1] = 0;
    dummy_fixture.gateway_address[2] = 0;
    dummy_fixture.gateway_address[3] = 1;

    dummy_fixture.universe_main = 1;
    dummy_fixture.universe_aux = 1;

    dummy_fixture.ils_channel = 0;
    dummy_fixture.rf_channel = 0;

	nfc_update_config_record();  // Write the config to the NFC tag

	update_menu();
}




void set_dmx_start(uint16_t DMXStart)
{
    dummy_fixture.start_address_main = DMXStart;

    nfc_update_dmx_start();
}

void set_dmx_personality(uint16_t Personality)
{
    dummy_fixture.personality_main = Personality;

    nfc_update_dmx_personality();
}



// Simple fixture menu structure
// Uses joystick left, right, up, down buttons


char *get_mode_str(uint16_t mode)
{
	switch (mode)    // Personality description as returned in E1-20 RDM DMX_PERSONALITY_DESCRIPTION
	{
		case 1:return("Mode 1 basic");
		case 2:return("Mode 2 advanced");
		case 3:return("Mode 3 silly");
		default:return("Unknown");
	}
}


#define TOP_LEVEL_MENU_ITEMS 9

int menu_level = 0;
int menu_item = 0;
uint32_t menu_val = 0;

void update_menu(void)
{
    char msg[200];
    switch (menu_item)
    {
        case 0:
            if (menu_level==1)
                sprintf(msg, "Set DMX Address\n %d", menu_level ? menu_val : dummy_fixture.start_address_main);
            else
            	sprintf(msg, "DMX Address: %d", menu_level ? menu_val : dummy_fixture.start_address_main);
            break;
        case 1:
            if (menu_level==1)
        	    sprintf(msg, "Set Mode\n %i %s", menu_val,get_mode_str(menu_val));
            else
        	    sprintf(msg, "Mode: %i %s", dummy_fixture.personality_main,get_mode_str(dummy_fixture.personality_main));
            break;
        case 2:
            if (menu_level==1)
                sprintf(msg, "Lamp On\nAre you sure?");
            else
                sprintf(msg, "Lamp On");

            break;
        case 3:
            if (menu_level==1)
                sprintf(msg, "Lamp Off\nAre you sure?");
            else
                sprintf(msg, "Lamp off");

            break;
        case 4:
            if (menu_level==1)
                sprintf(msg, "Factory Reset\nAre you sure?");
            else
                sprintf(msg, "Factory Reset");

            break;
        case 5:
            if (menu_level==1)
            	sprintf(msg, "Reset Trip\nAre you sure?");
            else
            	sprintf(msg, "Reset Trip");
            break;
        case 6:
            sprintf(msg, "Create Error");
            break;
        case 7:
            if (menu_level==1)
            {
            	sprintf(msg, "UTC %i\nDev Hours %i\nLamp Hours %i\nTrip Hours %i\nTrip Lamp Hours%i\nWrite Count %i",
            			get_utc(),dummy_fixture.device_hours,dummy_fixture.lamp_hours,dummy_fixture.trip_device_hours,dummy_fixture.trip_lamp_hours,ndef_get_write_counter());
            }
            else
            	sprintf(msg, "Info");
            break;
        case 8:
            if (menu_level==1)
            	sprintf(msg, "Clear NFC\nAre you sure?");
            else
            	sprintf(msg, "Clear NFC");
            break;

    }
    Menu_MsgStatus("Dummy Fixture", msg, MSG_INFO);
}

void check_buttons(void)
{
	static uint32_t write_counter = 0;

	switch (menu_level)
	{
		case 0: // Top level
			if (BSP_PB_GetState(JOYSTICK_UP))
			{
				if (menu_item) menu_item--;
				update_menu();
		    }
			else if (BSP_PB_GetState(JOYSTICK_DOWN))
			{
				if (menu_item+1<TOP_LEVEL_MENU_ITEMS) menu_item++;
				update_menu();
			}
			else if (BSP_PB_GetState(JOYSTICK_RIGHT))
			{
				menu_level = 1;
				switch (menu_item)
				{
					case 0:menu_val = dummy_fixture.start_address_main;break;
					case 1:menu_val = dummy_fixture.personality_main;break;
				}
				update_menu();
			}
			break;

		case 1: // 1st level
			switch (menu_item)
			{
				case 0: // DMX start address
					if (BSP_PB_GetState(JOYSTICK_UP))
					{
						if (menu_val>1) menu_val--;
						update_menu();
					}
					else if (BSP_PB_GetState(JOYSTICK_DOWN))
					{
						if (menu_val<512) menu_val++;
						update_menu();
					}
					else if (BSP_PB_GetState(JOYSTICK_RIGHT))  // Store
					{
						set_dmx_start(menu_val);
						menu_level = 0;
						update_menu();
					}
					else if (BSP_PB_GetState(JOYSTICK_LEFT))  // Cancel
					{
						menu_level = 0;
						update_menu();
					}
					break;

				case 1: // DMX Personality
					if (BSP_PB_GetState(JOYSTICK_UP))
					{
						if (menu_val>1) menu_val--;
						update_menu();
					}
					else if (BSP_PB_GetState(JOYSTICK_DOWN))
					{
						if (menu_val<3) menu_val++;
						update_menu();
					}
					else if (BSP_PB_GetState(JOYSTICK_RIGHT))   // Store
					{
						set_dmx_personality(menu_val);
						menu_level = 0;
						update_menu();
					}
					else if (BSP_PB_GetState(JOYSTICK_LEFT))   // Cancel
					{
						menu_level = 0;
						update_menu();
					}
					break;

				case 2: // Lamp on
					if (BSP_PB_GetState(JOYSTICK_RIGHT))
					{
						fixture_lamp_on();
						menu_level = 0;
						update_menu();
					}
					else if (BSP_PB_GetState(JOYSTICK_LEFT))   // Cancel
					{
						menu_level = 0;
						update_menu();
					}
					break;

				case 3: // Lamp off
					if (BSP_PB_GetState(JOYSTICK_RIGHT))
					{
						fixture_lamp_off();
						menu_level = 0;
						update_menu();
					}
					else if (BSP_PB_GetState(JOYSTICK_LEFT))   // Cancel
					{
						menu_level = 0;
						update_menu();
					}
					break;

				case 4: // Factory Reset
					if (BSP_PB_GetState(JOYSTICK_RIGHT))  // Confirm
					{
						fixture_factory_reset();
						menu_level = 0;
						update_menu();
					}
					else if (BSP_PB_GetState(JOYSTICK_LEFT))  // Cancel
					{
						menu_level = 0;
						update_menu();
					}
					break;

				case 5: // Trip Reset (NFC Testing only - this should not be available from fixture display on real fixture)
					if (BSP_PB_GetState(JOYSTICK_RIGHT))  // Confirm
					{
						fixture_reset_trip();
						menu_level = 0;
						update_menu();
					}
					else if (BSP_PB_GetState(JOYSTICK_LEFT))  // Cancel
					{
						menu_level = 0;
						update_menu();
					}
					break;

				case 6: // Create error in the log
					nfc_add_log_record(PAN_ENCODER_ERROR);
					menu_level = 0;
					update_menu();
					break;

				case 7: // Info
					if (BSP_PB_GetState(JOYSTICK_RIGHT) || BSP_PB_GetState(JOYSTICK_LEFT))  // Confirm
					{
						menu_level = 0;
						update_menu();
					}
					else if (ndef_get_write_counter()!=write_counter)
					{
						update_menu();
						write_counter = ndef_get_write_counter();
					}

					break;

				case 8: // Clear entire NFC - test only, not for Users
					if (BSP_PB_GetState(JOYSTICK_RIGHT))  // Confirm
					{
						ndef_clear_all();
						menu_level = 0;
						update_menu();
					}
					break;
			}
			break;
	}
}


void fixture_base_loop(void)
{
	while (1)
	{
		check_buttons();

		dummy_fixture.time_last_powered_off = get_utc();       // Power off time is kept updated in the NFC as fixture will not have time to write it to NFC on power off

		check_timers();
	}
}


void fixture_main(void)
{
	// Main function of the dummy fixture

	ndef_init();   // Initialise access to the NFC IC

	create_fixture();         // Creates the dummy fixture data structures

	fixture_power_on();        // Perform the power on

	fixture_base_loop();       // Base loop
}

