# Product Category Property Details (v001)


| Coarse Category   | Fine Category   | Category Description                       |
|-------------------|-----------------|--------------------------------------------|
| 0x00              | 0x00            | PRODUCT_CATEGORY_NOT_DECLARED              |
| 0x01              | 0x00            | PRODUCT_CATEGORY_FIXTURE                   |
| 0x01              | 0x01            | PRODUCT_CATEGORY_FIXTURE_FIXED             |
| 0x01              | 0x02            | PRODUCT_CATEGORY_FIXTURE_MOVING_YOKE       |
| 0x01              | 0x03            | PRODUCT_CATEGORY_FIXTURE_MOVING_MIRROR     |
| 0x01              | 0xFF            | PRODUCT_CATEGORY_FIXTURE_OTHER             |
| 0x02              | 0x00            | PRODUCT_CATEGORY_FIXTURE_ACCESSORY         |
| 0x02              | 0x01            | PRODUCT_CATEGORY_FIXTURE_ACCESSORY_COLOR   |
| 0x02              | 0x02            | PRODUCT_CATEGORY_FIXTURE_ACCESSORY_YOKE    |
| 0x02              | 0x03            | PRODUCT_CATEGORY_FIXTURE_ACCESSORY_MIRROR  |
| 0x02              | 0x04            | PRODUCT_CATEGORY_FIXTURE_ACCESSORY_EFFECT  |
| 0x02              | 0x05            | PRODUCT_CATEGORY_FIXTURE_ACCESSORY_BEAM    |
| 0x02              | 0xFF            | PRODUCT_CATEGORY_FIXTURE_ACCESSORY_OTHER   |
| 0x03              | 0x00            | PRODUCT_CATEGORY_PROJECTOR                 |
| 0x03              | 0x01            | PRODUCT_CATEGORY_PROJECTOR_FIXED           |
| 0x03              | 0x02            | PRODUCT_CATEGORY_PROJECTOR_MOVING_YOKE     |
| 0x03              | 0x03            | PRODUCT_CATEGORY_PROJECTOR_MOVING_MIRROR   |
| 0x03              | 0xFF            | PRODUCT_CATEGORY_PROJECTOR_OTHER           |
| 0x04              | 0x00            | PRODUCT_CATEGORY_ATMOSPHERIC               |
| 0x04              | 0x01            | PRODUCT_CATEGORY_ATMOSPHERIC_EFFECT        |
| 0x04              | 0x02            | PRODUCT_CATEGORY_ATMOSPHERIC_PYRO          |
| 0x04              | 0xFF            | PRODUCT_CATEGORY_ATMOSPHERIC_OTHER         |
| 0x05              | 0x00            | PRODUCT_CATEGORY_DIMMER                    |
| 0x05              | 0x01            | PRODUCT_CATEGORY_DIMMER_AC_INCANDESCENT    |
| 0x05              | 0x02            | PRODUCT_CATEGORY_DIMMER_AC_FLUORESCENT     |
| 0x05              | 0x03            | PRODUCT_CATEGORY_DIMMER_AC_COLDCATHODE     |
| 0x05              | 0x04            | PRODUCT_CATEGORY_DIMMER_AC_NONDIM          |
| 0x05              | 0x05            | PRODUCT_CATEGORY_DIMMER_AC_ELV             |
| 0x05              | 0x06            | PRODUCT_CATEGORY_DIMMER_AC_OTHER           |
| 0x05              | 0x07            | PRODUCT_CATEGORY_DIMMER_DC_LEVEL           |
| 0x05              | 0x08            | PRODUCT_CATEGORY_DIMMER_DC_PWM             |
| 0x05              | 0x09            | PRODUCT_CATEGORY_DIMMER_CS_LED             |
| 0x05              | 0xFF            | PRODUCT_CATEGORY_DIMMER_OTHER              |
| 0x06              | 0x00            | PRODUCT_CATEGORY_POWER                     |
| 0x06              | 0x01            | PRODUCT_CATEGORY_POWER_CONTROL             |
| 0x06              | 0x02            | PRODUCT_CATEGORY_POWER_SOURCE              |
| 0x06              | 0xFF            | PRODUCT_CATEGORY_POWER_OTHER               |
| 0x07              | 0x00            | PRODUCT_CATEGORY_SCENIC                    |
| 0x07              | 0x01            | PRODUCT_CATEGORY_SCENIC_DRIVE              |
| 0x07              | 0xFF            | PRODUCT_CATEGORY_SCENIC_OTHER              |
| 0x08              | 0x00            | PRODUCT_CATEGORY_DATA                      |
| 0x08              | 0x01            | PRODUCT_CATEGORY_DATA_DISTRIBUTION         |
| 0x08              | 0x02            | PRODUCT_CATEGORY_DATA_CONVERSION           |
| 0x08              | 0xFF            | PRODUCT_CATEGORY_DATA_OTHER                |
| 0x09              | 0x00            | PRODUCT_CATEGORY_AV                        |
| 0x09              | 0x01            | PRODUCT_CATEGORY_AV_AUDIO                  |
| 0x09              | 0x02            | PRODUCT_CATEGORY_AV_VIDEO                  |
| 0x09              | 0xFF            | PRODUCT_CATEGORY_AV_OTHER                  |
| 0x0A              | 0x00            | PRODUCT_CATEGORY_MONITOR                   |
| 0x0A              | 0x01            | PRODUCT_CATEGORY_MONITOR_ACLINEPOWER       |
| 0x0A              | 0x02            | PRODUCT_CATEGORY_MONITOR_DCPOWER           |
| 0x0A              | 0x03            | PRODUCT_CATEGORY_MONITOR_ENVIRONMENTAL     |
| 0x0A              | 0xFF            | PRODUCT_CATEGORY_MONITOR_OTHER             |
| 0x70              | 0x00            | PRODUCT_CATEGORY_CONTROL                   |
| 0x70              | 0x01            | PRODUCT_CATEGORY_CONTROL_CONTROLLER        |
| 0x70              | 0x02            | PRODUCT_CATEGORY_CONTROL_BACKUPDEVICE      |
| 0x70              | 0xFF            | PRODUCT_CATEGORY_CONTROL_OTHER             |
| 0x71              | 0x00            | PRODUCT_CATEGORY_TEST                      |
| 0x71              | 0x01            | PRODUCT_CATEGORY_TEST_EQUIPMENT            |
| 0x71              | 0xFF            | PRODUCT_CATEGORY_TEST_EQUIPMENT_OTHER      |
| 0x7F              | 0xFF            | PRODUCT_CATEGORY_OTHER                     |
| 0x80-0xDF         | 0x00-0xFF       | Manufacturer Specific Categories           |


### **Notes:**
- The `Product Categories` should match `ANSI E1.20 - 2010, Entertainment Technology – RDM – Remote Device Management over DMX512 Networks` official specification.


### **Version History:**
- **v001**: Initial version.
