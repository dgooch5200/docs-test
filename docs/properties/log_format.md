# Log Format Property Details (v001)

### **Explanation:**
The log_format property determines how logs are stored and presented by the device. This property is set by the 
fixture and defines the logging format.

### **Data Structure:**
2 bytes (number, big-endian)


### **Range:**
| Log Format | Data Structure                           | Writer | Description                                                                                         |
|------------|------------------------------------------|--------|-----------------------------------------------------------------------------------------------------|
| **0**      | No data                                  | Fixt   | **No Logging**: Logging is disabled, and no log entries will be stored.                             |
| **1**      | 2 bytes (number, big-endian)             | Fixt   | [log_code](../properties/log_code.md): Uses a 2-byte log code to represent each log entry.          |
| **2**      | 4 bytes (timestamp) + 2 bytes (log code) | Fixt   | **4-Byte Timestamp + 2-Byte Log Code**: Includes a 4-byte unsigned timestamp and a 2-byte log code. |

---
### **0 (No Logging)**
Setting `log_format` to `0` will disable logging, meaning that no logs will be recorded.

---
### **1 (2-Byte Log Code)**
Example: `0x0001` represents a log code of `1`.

---
### **2 (Timestamp & 2-Byte Log Code)**
Example: `0x60D0A23C0001`, where `0x60D0A23C` is the timestamp (in UNIX format), and `0x0001` is the log code `1`.


### **Version History:**
- **v001**: Initial version.
