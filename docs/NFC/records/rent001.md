# Rental Data Structure (urn:nfc:ext:chauvet.com:rent001)

| Block Address             | Byte Address               | Writer   | Attribute                                     | Data Type | Description                                                         |
|---------------------------|----------------------------|----------|-----------------------------------------------|-----------|---------------------------------------------------------------------|
| 0x0000          (0)       | 0x0000          (0)        | App/Fixt | [trip_actions](../properties/trip_actions.md) | bitfield  | Trip Actions (1 byte)                                               |
| 0x0000          (0)       | 0x0001 - 0x0003 (1 - 3)    | App      | Reserved                                      | number    | Reserved (3 bytes)                                                  |
| 0x0001          (1)       | 0x0004 - 0x0007 (4 - 7)    | App      | Reserved                                      | number    | Reserved (4 bytes)                                                  |
| 0x0002          (2)       | 0x0008 - 0x000B (8 - 11)   | App      | Reserved                                      | number    | Reserved (4 bytes)                                                  |
| 0x0003          (3)       | 0x000C - 0x000F (12 - 15)  | App      | Reserved                                      | number    | Reserved (4 bytes)                                                  |
| 0x0004          (4)       | 0x0010 - 0x0013 (16 - 19)  | App      | Reserved                                      | number    | Reserved (4 bytes)                                                  |
| 0x0005 - 0x000C (5 - 12)  | 0x0014 - 0x0033 (20 - 51)  | App      | trip_company_name                             | string    | Trip Company Name (32 bytes, null-terminated if less than 32 bytes) |
| 0x000D - 0x0014 (13 - 20) | 0x0034 - 0x0053 (52 - 83)  | App      | trip_job_name                                 | string    | Trip Job Name (32 bytes, null-terminated if less than 32 bytes)     |
| 0x0015          (21)      | 0x0054 - 0x0057 (84 - 87)  | App      | trip_time_start                               | number    | Trip Start Time (number, big-endian, 4 bytes)                       |
| 0x0016 - 0x0035 (22 - 53) | 0x0058 - 0x00D7 (88 - 215) | App      | rental_custom_data                            | number    | Rental Custom Data (open format, 128 bytes)                         |



