# Logging Data Structure (urn:nfc:ext:chauvet.com:logg001)

| Block Address             | Byte Address              | Writer | Property                                  | Data Type   | Description                                                                        |
|---------------------------|---------------------------|--------|-------------------------------------------|-------------|------------------------------------------------------------------------------------|
| 0x0000   (0)              | 0x0000 - 0x0001 (0 - 1)   | Fixt   | [log_format](../properties/log_format.md) | number      | Log Format (2 bytes, big-endian)                                                   |
| 0x0000   (0)              | 0x0002 - 0x0003 (2 - 3)   | Fixt   | max_log_records                           | number      | Max Log Records (2 bytes, big-endian)                                              |
| 0x0001 - 0x00C0 (1 - 192) | 0x0004 - 0x0303 (4 - 771) | Fixt   | logs                                      | string      | Logs (each record is 2 or 6 bytes, `0xFFFF` or `0xFFFFFFFFFFFF` filled by default) |


