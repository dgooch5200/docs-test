# Fixture Data Structure (urn:nfc:ext:chauvet.com:fixt001)

| Block Address              | Byte Address                  | Writer        | Attribute                                                             | Data Type | Description                                                                                        |
|----------------------------|-------------------------------|---------------|-----------------------------------------------------------------------|-----------|----------------------------------------------------------------------------------------------------|
| 0x0000           (0)       | 0x0000            (0)         | ComApp / Fixt | [fixt_status](../properties/fixt_status.md)                           | bitfield  | Fixture Status (1 byte)                                                                            |
| 0x0000           (0)       | 0x0001 - 0x0003   (1 - 3)     | ComApp        | Reserved                                                              | number    | Reserved (3 bytes)                                                                                 |
| 0x0001           (1)       | 0x0004 - 0x0005   (4 - 5)     | ComApp        | [ndef_structure_type](../properties/ndef_structure_type.md)           | number    | NDEF Structure Type (2 bytes, big-endian)                                                          |
| 0x0001           (1)       | 0x0006 - 0x0007   (6 - 7)     | ComApp        | [ndef_structure_version](../properties/ndef_structure_version.md)     | number    | NDEF Structure Version (2 bytes, big-endian)                                                       |
| 0x0002 - 0x0005  (2 - 5)   | 0x0008 - 0x0017   (8 - 23)    | Fixt          | [device_uid](../properties/device_uid.md)                             | string    | Device UID (string, 16 bytes)                                                                      |
| 0x0006 - 0x0007  (6 - 7)   | 0x0018 - 0x001D   (24 - 29)   | Fixt          | [rdm_uid](../properties/rdm_uid.md)                                   | hex       | RDM UID (string, 6 bytes)                                                                          |
| 0x0007           (7)       | 0x001E - 0x001F   (30 - 31)   | ComApp        | Reserved                                                              | number    | Reserved (2 bytes)                                                                                 |
| 0x0008 - 0x000F  (8 - 15)  | 0x0020 - 0x003F   (32 - 63)   | ComApp        | [device_serial_number](../properties/device_serial_number.md)         | string    | Device Serial Number (string, null-terminated if less than 32 bytes, 32 bytes)                     |
| 0x0010           (16)      | 0x0040 - 0x0041   (64 - 65)   | Fixt          | [device_model_id](../properties/device_model_id.md)                   | number    | Device Model ID, identical to RDM reported value (2 bytes, big-endian)                             |
| 0x0010           (16)      | 0x0042 - 0x0043   (66 - 67)   | Fixt          | [product_category](../properties/product_category.md)                 | number    | Product Category (2 bytes, big-endian)                                                             |
| 0x0011 - 0x0018  (17 - 24) | 0x0044 - 0x0063   (68 - 99)   | ComApp        | [manufacturer_label](../properties/manufacturer_label.md)             | string    | Manufacturer Label (string, null-terminated if less than 32 bytes, 32 bytes)                       |
| 0x0019 - 0x001A  (25 - 26) | 0x0064 - 0x0069   (100 - 105) | Fixt          | [mac_address](../properties/mac_address.md)                           | string    | MAC Address (hexadecimal, 6 bytes)                                                                 |
| 0x001A           (26)      | 0x006A - 0x006B   (106 - 107) | ComApp        | Reserved                                                              | number    | Spare (2 bytes)                                                                                    |
| 0x001B - 0x0022  (27 - 34) | 0x006C - 0x008B   (108 - 139) | Fixt          | [device_model_description](../properties/device_model_description.md) | string    | Device Model Description (string, null-terminated if less than 32 bytes, 32 bytes)                 |
| 0x0023           (35)      | 0x008C - 0x008F   (140 - 143) | Fixt          | [software_version](../properties/software_version.md)                 | number    | Software Version (number, big-endian, 4 bytes)                                                     |
| 0x0024 - 0x002b  (36 - 43) | 0x0090 - 0x00AF   (144 - 175) | Fixt          | [software_version_label](../properties/software_version_label.md)     | string    | Software Version Label (string, null-terminated if less than 32 bytes, 32 bytes)                   |
| 0x002c           (44)      | 0x00B0 - 0x00B3   (176 - 179) | Fixt          | [boot_software_version](../properties/boot_software_version.md)       | number    | Boot Software Version (number, big-endian, 4 bytes)                                                |
| 0x002d - 0x0034  (45 - 52) | 0x00B4 - 0x00D3   (180 - 211) | Fixt          | [personality_description](../properties/personality_description.md)   | string    | Personality Description for current mode (string, null-terminated if less than 32 bytes, 32 bytes) |
| 0x0035           (53)      | 0x00D4 - 0x00D7   (212 - 215) | Fixt          | [lamp_strikes](../properties/lamp_strikes.md)                         | number    | Lamp Strikes (number, big-endian, 4 bytes)                                                         |
| 0x0036           (54)      | 0x00D8 - 0x00DB   (216 - 219) | Fixt          | [device_hours](../properties/device_hours.md)                         | number    | Device Hours (number, big-endian, 4 bytes)                                                         |
| 0x0037           (55)      | 0x00DC - 0x00DF   (220 - 223) | Fixt          | [lamp_hours](../properties/lamp_hours.md)                             | number    | Lamp Output On Hours (number, big-endian, 4 bytes)                                                 |
| 0x0038           (56)      | 0x00E0 - 0x00E3   (224 - 227) | Fixt          | [device_power_cycles](../properties/device_power_cycles.md)           | number    | Device Power Cycle Count (number, big-endian, 4 bytes)                                             |
| 0x0039           (57)      | 0x00E4 - 0x00E7   (228 - 231) | Fixt          | [device_error_count](../properties/device_error_count.md)             | number    | Device Error Count (number, big-endian, 4 bytes)                                                   |
| 0x003A           (58)      | 0x00E8 - 0x00EB   (232 - 235) | Fixt          | [device_status](../properties/device_status.md)                       | number    | Device Status (number, big-endian, 4 bytes)                                                        |
| 0x003B           (59)      | 0x00EC - 0x00EF   (236 - 239) | Fixt          | [time_last_powered_on](../properties/time_last_powered_on.md)         | number    | Time Last Powered On, refer to Capabilities T0 (number, big-endian, 4 bytes)                       |
| 0x003C           (60)      | 0x00F0 - 0x00F3   (240 - 243) | Fixt          | [time_last_powered_off](../properties/time_last_powered_off.md)       | number    | Time Last Powered Off, refer to Capabilities T0 (number, big-endian, 4 bytes)                      |
| 0x003D           (61)      | 0x00F4 - 0x00F7   (244 - 247) | Fixt          | [time_last_lamped_on](../properties/time_last_lamped_on.md)           | number    | Time Last Lamped On, refer to Capabilities T0 (number, big-endian, 4 bytes)                        |
| 0x003E           (62)      | 0x00F8 - 0x00FB   (248 - 251) | Fixt          | [time_last_lamped_off](../properties/time_last_lamped_off.md)         | number    | Time Last Lamped Off, refer to Capabilities T0 (number, big-endian, 4 bytes)                       |
| 0x003F           (63)      | 0x00FC            (252)       | Fixt          | [battery_level](../properties/product_category.md)                    | number    | Battery Level (number, 1 byte)                                                                     |
| 0x003F           (63)      | 0x00FD - 0x00FF   (253 - 255) | ComApp        | Reserved                                                              | number    | Spare (3 bytes)                                                                                    |
| 0x0040           (64)      | 0x0100 - 0x0103   (256 - 259) | Fixt          | [trip_lamp_strikes](../properties/trip_lamp_strikes.md)               | number    | Trip Lamp Strikes (number, big-endian, 4 bytes)                                                    |
| 0x0041           (65)      | 0x0104 - 0x0107   (260 - 263) | Fixt          | [trip_device_hours](../properties/trip_device_hours.md)               | number    | Trip Device Hours (number, big-endian, 4 bytes)                                                    |
| 0x0042           (66)      | 0x0108 - 0x010B   (264 - 267) | Fixt          | [trip_lamp_hours](../properties/trip_lamp_hours.md)                   | number    | Trip Lamp Output On Hours (number, big-endian, 4 bytes)                                            |
| 0x0043           (67)      | 0x010C - 0x010F   (268 - 271) | Fixt          | [trip_power_cycles](../properties/trip_power_cycles.md)               | number    | Trip Power Cycle Count (number, big-endian, 4 bytes)                                               |
| 0x0044           (68)      | 0x0110 - 0x0113   (272 - 275) | Fixt          | [trip_error_count](../properties/trip_error_count.md)                 | number    | Trip Error Count (number, big-endian, 4 bytes)                                                     |
| 0x0045           (69)      | 0x0114 - 0x0117   (276 - 279) | ComApp        | Reserved                                                              | number    | Spare (4 bytes)                                                                                    |
| 0x0046           (70)      | 0x0118 - 0x011B   (280 - 283) | ComApp        | Reserved                                                              | number    | Spare (4 bytes)                                                                                    |
| 0x0047           (71)      | 0x011C - 0x011F   (284 - 287) | ComApp        | Reserved                                                              | number    | Spare (4 bytes)                                                                                    |
| 0x0048           (72)      | 0x0120            (288)       | Fixt          | [capabilities_A](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x0048           (72)      | 0x0121            (289)       | Fixt          | [capabilities_B](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x0048           (72)      | 0x0122            (290)       | Fixt          | [capabilities_C](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x0048           (72)      | 0x0123            (291)       | Fixt          | [capabilities_D](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x0049           (73)      | 0x0124            (292)       | Fixt          | [capabilities_E](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x0049           (73)      | 0x0125            (293)       | Fixt          | [capabilities_F](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x0049           (73)      | 0x0126            (294)       | Fixt          | [capabilities_G](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x0049           (73)      | 0x0127            (295)       | Fixt          | [capabilities_H](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004A           (74)      | 0x0128            (296)       | Fixt          | [capabilities_I](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004A           (74)      | 0x0129            (297)       | Fixt          | [capabilities_J](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004A           (74)      | 0x012A            (298)       | Fixt          | [capabilities_K](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004A           (74)      | 0x012B            (299)       | Fixt          | [capabilities_L](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004B           (75)      | 0x012C            (300)       | Fixt          | [capabilities_M](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004B           (75)      | 0x012D            (301)       | Fixt          | [capabilities_N](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004B           (75)      | 0x012E            (302)       | Fixt          | [capabilities_O](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004B           (75)      | 0x012F            (303)       | Fixt          | [capabilities_P](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004C           (76)      | 0x0130            (304)       | Fixt          | [capabilities_Q](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004C           (76)      | 0x0131            (305)       | Fixt          | [capabilities_R](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004C           (76)      | 0x0132            (306)       | Fixt          | [capabilities_S](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004C           (76)      | 0x0133            (307)       | Fixt          | [capabilities_T](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004D           (77)      | 0x0134            (308)       | Fixt          | [capabilities_U](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004D           (77)      | 0x0135            (309)       | Fixt          | [capabilities_V](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004D           (77)      | 0x0136            (310)       | Fixt          | [capabilities_W](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004D           (77)      | 0x0137            (311)       | Fixt          | [capabilities_X](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004E           (78)      | 0x0138            (312)       | Fixt          | [capabilities_Y](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004E           (78)      | 0x0139            (313)       | Fixt          | [capabilities_Z](../properties/capabilities.md)                       | bitfield  | Capabilities Flags (1 byte)                                                                        |
| 0x004E           (78)      | 0x013A - 0x013B   (314 - 315) | ComApp        | Reserved                                                              | number    | Spare (2 bytes)                                                                                    |
| 0x004F           (79)      | 0x013C - 0x013F   (316 - 319) | ComApp        | Reserved                                                              | number    | Spare (4 bytes)                                                                                    |



























































