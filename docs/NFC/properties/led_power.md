# LED Power Property Details (v001)

### **Alias:**
- **led_brightness**

### **RDM:**
- N/A

### **Explanation:**
The `LED Power` property allows the user to control the power level supplied to the fixture's LED, effectively adjusting the brightness.

### **Data Structure:**
- **1 byte (number)**

### **Default Value:**
- **0xFF** The default factory LED power is set to 100% brightness.
---
### **Range:**
The following table shows the possible values that can be set for LED Power:

| LED Power Value     | Power Level (%)              | 
|---------------------|------------------------------|
| **0x00**            | 0% (Off)                     | 
| **0x01**            | 1%                           | 
| **0x02**            | 2%                           | 
| **...**             | ...                          |
| **0x63**            | 99%                          |
| **0x64**            | 100% (Full Power)            |

---

### **Version History:**
- **v001**: Initial version.
