// NDEF Driver
//
// Manages writing to the NDEF records in the STM ST25DV NFC

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

ndefContext NdefCtx;

uint16_t fixture_record_offset = 0;
uint16_t logging_record_offset = 0;
uint16_t rental_record_offset = 0;
uint16_t config_record_offset = 0;

uint16_t fixture_record_size = 0;
uint16_t logging_record_size = 0;
uint16_t rental_record_size = 0;
uint16_t config_record_size = 0;

uint32_t write_counter = 0;                // This is a counter to help monitor frequency of writes to the NFC when developing the code

uint32_t ndef_get_write_counter(void)
{
	return write_counter;
}

void ndef_init(void)
{
	// Initialise the STM Development board

    if ((ST25DVChipID == I_AM_ST25DV04) || (ST25DVChipID == I_AM_ST25DV64)) {
        /* Tag configuration for NDEF */
        BSP_LPD_WritePin(GPIO_PIN_RESET);
    }
    PresentPasswd(true);

    /* Disable Mailbox mode */
    DeInitMailBoxMode();
    /* Activate RF */
    ST25_RETRY(BSP_NFCTAG_WriteRFMngt(BSP_NFCTAG_INSTANCE, 0));

    /* Disable Energy Harvesting */
    ST25_RETRY(BSP_NFCTAG_ResetEHENMode_Dyn(BSP_NFCTAG_INSTANCE));

    /* De-activate any protection */
    if ((ST25DVChipID == I_AM_ST25DV04) || (ST25DVChipID == I_AM_ST25DV64))
    {
        ST25DV_PROTECTION_ZONE ZoneRF;
        ST25DV_RF_PROT_ZONE no_rf_prot = { .PasswdCtrl = ST25DV_NOT_PROTECTED, .RWprotection = ST25DV_NO_PROT };
        for (ZoneRF = ST25DV_PROT_ZONE1; ZoneRF <= ST25DV_PROT_ZONE4; ZoneRF++)
        {
            ST25_RETRY(BSP_NFCTAG_WriteRFZxSS(BSP_NFCTAG_INSTANCE, ZoneRF, &no_rf_prot));
            ST25_RETRY(BSP_NFCTAG_WriteI2CProtectZonex(BSP_NFCTAG_INSTANCE, ZoneRF, ST25DV_NO_PROT));
        }
        ST25_RETRY(BSP_NFCTAG_InitEndZone(BSP_NFCTAG_INSTANCE));

        ST25_RETRY(BSP_NFCTAG_WriteLockCCFile(BSP_NFCTAG_INSTANCE, ST25DV_CCFILE_2BLCK, ST25DV_UNLOCKED));
    }
    else
    {
        ST25DVxxKC_PROTECTION_ZONE_E ZoneRF;
        ST25DVxxKC_RF_PROT_ZONE_t no_rf_prot = { .PasswdCtrl = ST25DVXXKC_NOT_PROTECTED, .RWprotection = ST25DVXXKC_NO_PROT };
        for (ZoneRF = ST25DVXXKC_PROT_ZONE1; ZoneRF <= ST25DVXXKC_PROT_ZONE4; ZoneRF++)
        {
            ST25_RETRY(BSP_NFCTAG_WriteRFZxSS(BSP_NFCTAG_INSTANCE, ZoneRF, &no_rf_prot));
            ST25_RETRY(BSP_NFCTAG_WriteI2CProtectZonex(BSP_NFCTAG_INSTANCE, ZoneRF, ST25DVXXKC_NO_PROT));
        }
        ST25_RETRY(BSP_NFCTAG_InitEndZone(BSP_NFCTAG_INSTANCE));

        ST25_RETRY(BSP_NFCTAG_WriteLockCCFile(BSP_NFCTAG_INSTANCE, ST25DVXXKC_CCFILE_2BLCK, ST25DVXXKC_UNLOCKED));
    }

    ndefT5TagContextInitialization(&NdefCtx);

    if (ndefT5TagNdefDetect(&NdefCtx) != ERR_NONE)
    {
        if (ndefT5TagFormat(&NdefCtx, NULL, 1) != ERR_NONE)
        {
            Menu_MsgStatus("No CCFILE", "CCFILE init failed!", MSG_STATUS_ERROR);
        }
    }

    // Set up interupts for read and such

    int32_t ST25DV_GetGPO_ENABLE(const ST25DV_Ctx_t* const ctx, uint8_t* const value);
    int32_t ST25DV_SetGPO_RFWRITE(const ST25DV_Ctx_t* const ctx, const uint8_t* const value);

    ndef_find_record_offsets();   // Search the NFC Tag for known Chauvet records
}



uint16_t ndef_find_record_offsets(void)
{
	// Finds the record offsets within the NDEF for each of the Chauvet records
	// This avoids having to read the NDEF headers all the time

    ndefMessage ndefmessage;
    uint16_t ndef_size = 8192;
    uint8_t* p_ndef_buffer;
    uint16_t offset = 0;
    uint16_t status = 1;

    fixture_record_offset = 0;
    logging_record_offset = 0;
    rental_record_offset = 0;
    config_record_offset = 0;

    fixture_record_size = 0;
    logging_record_size = 0;
    rental_record_size = 0;
    config_record_size = 0;

    p_ndef_buffer = malloc(ndef_size);
    if (p_ndef_buffer == NULL)
    {
        return (status);
    }

    memset(p_ndef_buffer,0,ndef_size);

    status = ndefT5TagReadRawMessage(&NdefCtx, p_ndef_buffer, ndef_size);
    if (status != ERR_NONE)
    {
    	free (p_ndef_buffer);
        return (status);
    }

    // Now find the Chauvet records
    // Chauvet records have a TNF of 0x04 external

    while (offset<ndef_size)
    {
    	uint8_t type = p_ndef_buffer[offset];
    	uint8_t type_length = p_ndef_buffer[offset+1];
    	uint8_t id_length = 0;
    	uint32_t payload_length = 0;

    	if (type & 0x10)             // SR (short record) bit
    	{
    		payload_length = p_ndef_buffer[offset+2];
    		offset+=3;
        }
    	else  // Payload length field is 32 bit
    	{
    		payload_length = __builtin_bswap32(* ((uint32_t *) &(p_ndef_buffer[offset+2])));
    		offset+=6;
    	}

    	if (type & 0x08)            // IL  - ID length present
    	{
    		id_length = p_ndef_buffer[offset];
    		offset++;
    	}

    	if ((type & 0x07) == 0x04)        // External record
    	{
        	char *external_type = &(p_ndef_buffer[offset]);
    		if (type_length>=31)
    		{
    			if (!memcmp(external_type,"urn:nfc:ext:chauvet.com:",24))
    			{
    				char *record_type = &(external_type[24]);
    				if (!memcmp(record_type,"fixt",4))
    				{
    					fixture_record_offset = ndefTagGetMessageOffset(&NdefCtx) + offset + type_length + id_length;
    					fixture_record_size = payload_length;
    				}
    				else if (!memcmp(record_type,"conf",4))
    				{
    					config_record_offset = ndefTagGetMessageOffset(&NdefCtx) + offset + type_length + id_length;
    					config_record_size = payload_length;
    				}
    				else if (!memcmp(record_type,"logg",4))
    				{
    					logging_record_offset = ndefTagGetMessageOffset(&NdefCtx) + offset + type_length + id_length;
    					logging_record_size = payload_length;
    				}
    				else if (!memcmp(record_type,"rent",4))
    				{
    					rental_record_offset = ndefTagGetMessageOffset(&NdefCtx) + offset + type_length + id_length;
    					rental_record_size = payload_length;
    				}
    			}
    		}
    	}

    	if (type & 0x40) // ME (message end) bit - last record in the message
    		break;

    	offset += type_length + id_length + payload_length;
    }

	free (p_ndef_buffer);

	return ERR_NONE;
}


// Functions for the Fixture record
// The contents of the Fixture record are written by the fixture.  The NFC App does not write this record

uint8_t ndef_is_fixture_record_valid(void)
{
	return (fixture_record_size && (fixture_record_size>=sizeof(NFCFixtureRecord_t)));
}


uint16_t ndef_read_fixture_record(uint8_t *data, uint16_t start, uint16_t len)
{
	// Read part of the fixture record

	if (!fixture_record_size || (fixture_record_size<sizeof(NFCFixtureRecord_t))) return(1);

	if (start+len>fixture_record_size) return(1);

    return (BSP_NFCTAG_ReadData(BSP_NFCTAG_INSTANCE, data, fixture_record_offset+start, len));
}


uint16_t ndef_write_fixture_record(uint8_t *data, uint16_t start, uint16_t len)
{
	// Write part of the fixture record with our fixture info

	if (!fixture_record_size || (fixture_record_size<sizeof(NFCFixtureRecord_t))) return(1);

	if (start+len>fixture_record_size) return(1);

	write_counter++;

    return (BSP_NFCTAG_WriteData(BSP_NFCTAG_INSTANCE, data, fixture_record_offset+start, len));
}



// Functions for the Logging record
// The contents of the Logging record is written by the fixture
// Once the NFC is commissioned the App does not write to the logging record

uint8_t ndef_is_logging_record_valid(void)
{
	return (logging_record_size && (logging_record_size>=sizeof(NFCLoggingRecord_t)));
}


uint16_t ndef_read_logging_record(uint8_t *data, uint16_t start, uint16_t len)
{
	// Read part of the Logging record

	if (!logging_record_size || (logging_record_size<sizeof(NFCLoggingRecord_t))) return(1);

	if (start+len>logging_record_size) return(1);

    return (BSP_NFCTAG_ReadData(BSP_NFCTAG_INSTANCE, data, logging_record_offset+start, len));
}

uint16_t ndef_write_logging_record(uint8_t *data, uint16_t start, uint16_t len)
{
	// Write part of the Loggins record

	if (!logging_record_size || (logging_record_size<sizeof(NFCLoggingRecord_t))) return(1);

	if (start+len>logging_record_size) return(1);

	write_counter++;

	return (BSP_NFCTAG_WriteData(BSP_NFCTAG_INSTANCE, data, logging_record_offset+start, len));
}

uint16_t ndef_get_logging_record_size(void)
{
	return logging_record_size;
}


// Functions for the Rental record
// The contents of the Rental record is written by the NFC App
// The fixture does not write this record, except to clear the trip reset flags after clearing the trip data


uint8_t ndef_is_rental_record_valid(void)
{
	return (rental_record_size && (rental_record_size>=sizeof(NFCRentalRecord_t)));
}


uint16_t ndef_read_rental_record(uint8_t *data, uint16_t start, uint16_t len)
{
	// Read part of the rental record

	if (!rental_record_size || (rental_record_size<sizeof(NFCRentalRecord_t))) return(1);

	if (start+len>rental_record_size) return(1);

    return (BSP_NFCTAG_ReadData(BSP_NFCTAG_INSTANCE, data, rental_record_offset+start, len));
}


uint16_t ndef_write_rental_record(uint8_t *data, uint16_t start, uint16_t len)
{
	// Write part of the Rental record

	if (!rental_record_size || (rental_record_size<sizeof(NFCRentalRecord_t))) return(1);

	if (start+len>rental_record_size) return(1);

	write_counter++;

	return (BSP_NFCTAG_WriteData(BSP_NFCTAG_INSTANCE, data, rental_record_offset+start, len));
}


// Functions for the Config record
// The contents of the Config record are read and written by both the NFC App and the Fixture

uint8_t ndef_is_config_record_valid(void)
{
	return (config_record_size && (config_record_size>=sizeof(NFCConfigRecord_t)));
}

uint16_t ndef_read_config_record(uint8_t *data, uint16_t start, uint16_t len)
{
	// Read part of the Config record

	if (!config_record_size || (config_record_size<sizeof(NFCConfigRecord_t))) return(1);

	if (start+len>config_record_size) return(1);

    return (BSP_NFCTAG_ReadData(BSP_NFCTAG_INSTANCE, data, config_record_offset+start, len));
}


uint16_t ndef_write_config_record(uint8_t *data, uint16_t start, uint16_t len)
{
	// Write part of the Config record with our config info

	if (!config_record_size || (config_record_size<sizeof(NFCConfigRecord_t))) return(1);

	if (start+len>config_record_size) return(1);

	write_counter++;

	return (BSP_NFCTAG_WriteData(BSP_NFCTAG_INSTANCE, data, config_record_offset+start, len));
}


uint16_t ndef_clear_all(void)
{
	// Clears the whole NFC
	// This is for test purposes only.  Should not be accessible to users

    uint16_t ndef_size = 8192;
    uint8_t* p_ndef_buffer;

    p_ndef_buffer = malloc(ndef_size);
    if (p_ndef_buffer == NULL)
    {
        return (1);
    }

    memset(p_ndef_buffer,0,ndef_size);

    BSP_NFCTAG_WriteData(BSP_NFCTAG_INSTANCE, p_ndef_buffer, 0, ndef_size);

	free (p_ndef_buffer);

	return ERR_NONE;
}
