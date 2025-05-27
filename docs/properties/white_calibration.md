# White Calibration Property Details (v001)

### **Explanation:**
The `white_calibration` property determines the calibration mode of the fixture. 


### **Data Structure:**
- **1 byte (number)**

### **Default Value:**
- **0**: By default, the fixture operates with no calibration.
---
### **Range:**

#### **White Calibratopm v1**
| Calibration Value | Description               | Notes                                                  |
|-------------------|---------------------------|--------------------------------------------------------|
| **0x00**          | No Calibration            | The fixture operates using default calibration setting |
| **0x01**          | Factory Calibration       | The fixture uses factory-set calibration values.       |
| **0x02**          | User Calibration          | The fixture uses user-defined calibration values.      |
| **0x03-0xFF**     | Reserved                  | Reserved for future use.                               |

---
#### **White Calibratopm v2 (Custom)**
- The fixture uses custom calibration values defined by the manufactorer.  Therefore, this data should be available via
the Fixture Data table.

---



### **Version History:**
- **v001**: Initial version.
