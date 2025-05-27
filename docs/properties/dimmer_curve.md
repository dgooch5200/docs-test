# Dimmer Curve Property Details (v002)

### **Explanation:**
The `dimmer_curve` property defines the response curve of the dimmer function in the fixture. This allows users to choose how the dimmer reacts to changes in DMX values, enabling smoother or more abrupt transitions based on the selected curve.

### **Data Structure:**
- **1 byte (number)**

### **Default Value:**
- **0x00**: By default, the fixture operates with a linear dimmer curve.

### **Range:**

#### **Dimmer Curve v1**
| Dimmer Curve Value | Description             | Notes                                                                                           |
|--------------------|-------------------------|-------------------------------------------------------------------------------------------------|
| **0x00**           | Linear                  | A direct, linear relationship between DMX value and light intensity.                            |
| **0x01**           | Square                  | A curve where changes are more gradual at the low end and faster at the high end.               |
| **0x02**           | I Square                | The inverse of the square curve, with faster changes at the low end and slower at the high end. |
| **0x03**           | S Curve                 | A smooth, gradual curve, with slow changes at both ends and faster changes in the middle.       |
| **0x04-0xFF**      | Reserved                | Reserved for future dimmer curve options.                                                       |

#### **Dimmer Curve v2**
| Dimmer Curve Value | Description | Notes                                                                                           |
|--------------------|-------------|-------------------------------------------------------------------------------------------------|
| **0x00**           | Linear      | A direct, linear relationship between DMX value and light intensity.                            |
| **0x01**           | Square      | A curve where changes are more gradual at the low end and faster at the high end.               |
| **0x02**           | I Square    | The inverse of the square curve, with faster changes at the low end and slower at the high end. |
| **0x03**           | S Curve     | A smooth, gradual curve, with slow changes at both ends and faster changes in the middle.       |
| **0x04**           | Lamp Curve  | Dimmer curve to represent physical shutter blades                                               |
| **0x05-0xFF**      | Reserved    | Reserved for future dimmer curve options.                                                       |



### **Reserved Values:**
All other values (from `0x04` to `0xFF`) are reserved for future dimmer curve options or features.

### **Version History:**
- **v001**: Initial version.
- **v002**: Added `Dimmer Curve v2` option to the dimmer curve list.
