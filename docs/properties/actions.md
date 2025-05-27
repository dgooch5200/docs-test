# Actions Property Details (v001)

### **Explanation:**
Actions represent commands or requests for specific operations to be performed by the device. Unlike regular options, actions typically revert to an idle state (`0`) once the action is completed. Setting an action bit to `1` triggers the corresponding action.

---
## Actions_A Byte (Bitfield Representation)

| Bit Position | Action                           | Description                       | Default Value | Data Type | Notes                                                                                             |
|--------------|----------------------------------|-----------------------------------|---------------|-----------|---------------------------------------------------------------------------------------------------|
| **0**  (LSB) | actions_A_factory_reset          | Request a Factory Reset.          | Idle (`0`)    | Boolean   | Set to `1` to initiate a factory reset. Fixture clears the bit when it has performed the action.  |
| **1**        | actions_A_wireless_receive_reset | Request a Wireless Receive Reset. | Idle (`0`)    | Boolean   | Set to `1` to reset wireless settings. Fixture clears the bit when it has performed the action.   |
| **2**        | actions_A_pan_tilt_reset         | Request a Pan/Tilt Reset.         | Idle (`0`)    | Boolean   | Set to `1` to reset pan/tilt. Fixture clears the bit when it has performed the action.            |
| **3**        | actions_A_iris_prism_reset       | Request an Iris/Prism Reset.      | Idle (`0`)    | Boolean   | Set to `1` to reset iris/prism. Fixture clears the bit when it has performed the action.          |
| **4**        | actions_A_color_cmy_blade_reset  | Request a Color/CMY/Blade Reset.  | Idle (`0`)    | Boolean   | Set to `1` to reset color/cmy/blade. Fixture clears the bit when it has performed the action.     |
| **5**        | actions_A_shutter_reset          | Request a Shutter Reset.          | Idle (`0`)    | Boolean   | Set to `1` to reset shutter. Fixture clears the bit when it has performed the action.             |
| **6**        | actions_A_gobo_reset             | Request a Gobo Reset.             | Idle (`0`)    | Boolean   | Set to `1` to reset gobo. Fixture clears the bit when it has performed the action.                |
| **7**  (MSB) | actions_A_frost_reset            | Request a Frost Reset.            | Idle (`0`)    | Boolean   | Set to `1` to reset frost. Fixture clears the bit when it has performed the action.               |

### **Example:**
- `ActionsA = 0b00000001` (1 in decimal, `0x01` in hexadecimal) would represent:
  - Bit 0: **1** (Factory Reset requested)
  - Bit 1-7: **0** (No other actions requested)

### **Default State for Action Bytes:**
If an `Action` byte is not set or is invalid, it defaults to `0x00`, meaning no actions are requested (idle state).

---
## Actions_B Byte (Bitfield Representation)

| Bit Position | Action                     | Description                          | Default Value | Data Type | Notes                                                                                                      |
|--------------|----------------------------|--------------------------------------|---------------|-----------|------------------------------------------------------------------------------------------------------------|
| **0**  (LSB) | actions_B_animation_reset  | Request a Animation Reset.           | Idle (`0`)    | Boolean   | Set to `1` to reset animation. Fixture clears the bit when it has performed the action.                    |
| **1**        | actions_B_zoom_reset       | Request a Zoom Reset.                | Idle (`0`)    | Boolean   | Set to `1` to reset zoom. Fixture clears the bit when it has performed the action.                         |
| **2**        | actions_B_all_motors_reset | Request an All Motors Reset.         | Idle (`0`)    | Boolean   | Set to `1` to reset frost. Fixture clears the bit when it has performed the action.                        |
| **3**        | actions_B_rf_bind          | Request an RF Bind Pairing.          | Idle (`0`)    | Boolean   | Set to `1` to initiate an RF Bind Pairing. Fixture clears the bit when it has performed the action.        |
| **4**        | actions_B_foot_pedal_bind  | Reserved a Foot-Pedal Bind Pairing . | Idle (`0`)    | Boolean   | Set to `1` to initiate a Foot-Pedal Bind Pairing. Fixture clears the bit when it has performed the action. |
| **5**        | Reserved                   | Reserved for future use.             | Idle (`0`)    | Boolean   | Not currently in use.                                                                                      |
| **6**        | Reserved                   | Reserved for future use.             | Idle (`0`)    | Boolean   | Not currently in use.                                                                                      |
| **7**  (MSB) | Reserved                   | Reserved for future use.             | Idle (`0`)    | Boolean   | Not currently in use.                                                                                      |


---
## Actions_C Byte (Bitfield Representation)

| Bit Position  | Action    | Description                       | Default Value | Data Type | Notes                    |
|---------------|-----------|-----------------------------------|---------------|-----------|--------------------------|
| **0**  (LSB)  | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |
| **1**         | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |
| **2**         | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |
| **3**         | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |
| **4**         | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |
| **5**         | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |
| **6**         | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |
| **7**  (MSB)  | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |

---
## Actions_D Byte (Bitfield Representation)

| Bit Position  | Action    | Description                       | Default Value | Data Type | Notes                    |
|---------------|-----------|-----------------------------------|---------------|-----------|--------------------------|
| **0**  (LSB)  | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |
| **1**         | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |
| **2**         | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |
| **3**         | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |
| **4**         | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |
| **5**         | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |
| **6**         | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |
| **7**  (MSB)  | Reserved  | Reserved for future use.          | Idle (`0`)    | Boolean   | Not currently in use.    |


### **Version History:**
- **v001**: Initial version.
