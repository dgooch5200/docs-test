// NDEF Driver
//
// Manages writing to the NDEF records in the STM ST25DV NFC
  

#ifndef NDEF_DEMO_H
#define NDEF_DEMO_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>


void NDEF_DEMO_Init_Tag(void);
void NDEF_DEMO_Write_URI_URL(void);
void NDEF_DEMO_Write_URI_Tel(void);
void NDEF_DEMO_Read_URI(void);
void NDEF_DEMO_Read_SMS(void);
void NDEF_DEMO_Write_SMS(void);
void NDEF_DEMO_Read_Email(void);
void NDEF_DEMO_Write_Email(void);
void NDEF_DEMO_Read_Vcard(void);
void NDEF_DEMO_Write_Vcard(void);
void NDEF_DEMO_Read_Geo(void);
void NDEF_DEMO_Write_Geo(void);
void NDEF_DEMO_Write_MyApp(void);
void NDEF_DEMO_Read_MyAPP(void);
void NDEF_DEMO_Write_AAR(void);
void NDEF_DEMO_MultiRecord_With_AAR(void);
void NDEF_DEMO_BLE_ChangeDeviceAddr(void);
void NDEF_DEMO_Write_BLE_OOB(void);
void NDEF_DEMO_Read_Bluetooth_OOB(void);
void NDEF_DEMO_Write_Wifi_OOB(void);
void NDEF_DEMO_Read_Wifi_OOB(void);
void NDEF_DEMO_Write_empty_NDEF( void );
void NDEF_DEMO_Erase_CCFile( void );
void NDEF_DEMO_Clear_Eeprom( void );



 void ndef_init(void);             // Initialise the NDEF record reader

 uint16_t ndef_find_record_offsets(void); // Find the Chauvet NDEF records for quick access

 uint8_t ndef_is_fixture_record_valid(void);
 uint16_t ndef_read_fixture_record(uint8_t *data, uint16_t start, uint16_t len);
 uint16_t ndef_write_fixture_record(uint8_t *data, uint16_t start, uint16_t len);

 uint16_t ndef_get_logging_record_size(void);
 uint8_t ndef_is_logging_record_valid(void);
 uint16_t ndef_read_logging_record(uint8_t *data, uint16_t start, uint16_t len);
 uint16_t ndef_write_logging_record(uint8_t *data, uint16_t start, uint16_t len);

 uint8_t ndef_is_rental_record_valid(void);
 uint16_t ndef_read_rental_record(uint8_t *data, uint16_t start, uint16_t len);
 uint16_t ndef_write_rental_record(uint8_t *data, uint16_t start, uint16_t len);

 uint8_t ndef_is_config_record_valid(void);
 uint16_t ndef_read_config_record(uint8_t *data, uint16_t start, uint16_t len);
 uint16_t ndef_write_config_record(uint8_t *data, uint16_t start, uint16_t len);

 uint16_t ndef_clear_all(void);    // For test only - not for users
 uint32_t ndef_get_write_counter(void);  // For test only to check frequency of writing to EEPROM, so we avoid EEPROM wear


#endif /* NDEF_DEMO_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

