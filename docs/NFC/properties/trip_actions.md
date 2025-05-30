# TRIP_ACTIONS Attribute Details (v001)

### **Explanation:**
The `TRIP_ACTIONS` attribute is a bitfield used to request the fixture to carry out certain actions. 

### **Data Structure:**
- **1 byte (bitfield)**

### **Default Value:**
- **0x00** (No changes have been made to the configuration.)

### **Bitfield Representation:**
The following table shows the possible values for each bit in the `TRIP_RESET_FLAGS` byte:

| Bit Position | Status                   | Description                                      | Default Value  | Data Type | Notes                                                                                         |
|--------------|--------------------------|--------------------------------------------------|----------------|-----------|-----------------------------------------------------------------------------------------------|
| **0**  (LSB) | trip_actions_reset_logs  | Request a Logs Reset.                            | `0` (False)    | Boolean   | Set to `1` to initiate a logs reset. Fixture clears the bit when it has performed the action. |
| **1**        | trip_actions_reset_time  | trip_time_start will be set to the current time. | `0`            | Boolean   | Set to `1` to initiate a trip reset. Fixture clears the bit when it has performed the action. |
| **2**        | Reserved                 | Reserved for future use.                         | `0`            | Boolean   | Not currently in use.                                                                         |
| **3**        | Reserved                 | Reserved for future use.                         | `0`            | Boolean   | Not currently in use.                                                                         |
| **4**        | Reserved                 | Reserved for future use.                         | `0`            | Boolean   | Not currently in use.                                                                         |
| **5**        | Reserved                 | Reserved for future use.                         | `0`            | Boolean   | Not currently in use.                                                                         |
| **6**        | Reserved                 | Reserved for future use.                         | `0`            | Boolean   | Not currently in use.                                                                         |
| **7**  (MSB) | Reserved                 | Reserved for future use.                         | `0`            | Boolean   | Not currently in use.                                                                         |

## **Notes:**
- Trip Reset should clear `trip_lamp_strikes`, `trip_device_hours`, `trip_power_cycles`, `trip_error_count`, 
`trip_time_start` and `trip_lamp_hours` properties.  The `trip_name`, `rental_company_name` and `trip_custom_data` 
properties should not be cleared.

### **Version History:**
- **v001**: Initial version.
