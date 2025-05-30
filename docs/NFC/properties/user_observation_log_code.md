# User Observed Log Codes Property Details (v001)

### **Explanation:**
The `user_observed_log_codes` property logs codes that the user has observed during the operation of the fixture. 
These log codes provide a simple way to identify common issues that may arise during the fixture's operation. 
Each log code is represented by a unique 2-byte number.

### **Data Structure:**
- **2 bytes (number, big-endian)**

### **Default Value:**
- **0x0000**: No log recorded (default state).

### **Range:**
| Log Code Value | Description                                                        |
|----------------|--------------------------------------------------------------------|
| **0x0001**     | Other: A general log that does not fall under specific categories. |
| **0x0002**     | No Power: Indicates that the fixture is not receiving power.       |
| **...**        | Additional values may be added as new log types are identified.    |


### **Version History:**
- **v001**: Initial version.
