# Display Shutoff Property Details (v002)

### **Alias:**
- **backlight_timeout**
- **screen_timeout**

### **RDM:**
- N/A

### **Explanation:**
The `display_shutoff` property allows users to configure the duration for which the display remains powered on before 
automatically turning off. to conserve energy. 

### **Data Structure:**
- **1 byte (number, unsigned)**

### **Default Value:**
- **0x00** (0): By default, the display will turn off as defined by factory default.

### **Display Shuttoff v1**

| Value     | Option          | Description                                                    |
|-----------|-----------------|----------------------------------------------------------------|
| **0**     | Always On       | The display remains on indefinitely until manually turned off. |
| **1**     | 10s             | The display powers off after 10 seconds of inactivity.         |
| **2**     | 30s             | The display powers off after 30 seconds of inactivity.         |
| **3**     | 120s            | The display powers off after 120 seconds of inactivity.        |
| **4-255** | Reserved        | Reserved for future use.                                       |

### **Display Shutoff v2**

| Value     | Option          | Description                                                      |
|-----------|-----------------|------------------------------------------------------------------|
| **0**     | Always On       | The display remains on indefinitely until manually turned off.   |
| **1**     | 30s             | The display powers off after 30 seconds of inactivity.           |
| **2**     | 60s             | The display powers off after 60 seconds of inactivity.           |
| **3**     | 300s            | The display powers off after 300 seconds of inactivity.          |
| **4-255** | Reserved        | Reserved for future use.                                         |


### **Version History:**
- **v001**: Initial version.

- **v002**: 
  - i) Added `v2`
  - ii）Removed `default` value for `v1`.
