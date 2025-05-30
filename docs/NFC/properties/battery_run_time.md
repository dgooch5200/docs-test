# Battery Run Time Property Details (v001)

### **Alias:**

### **RDM:**
- N/A

### **Explanation:**
The `battery_run_time' property allows users to set their battery fixtures to be able to run for a minimum amount of time.

### **Data Structure:**
- **1 byte (number)**

---
### **Range:**
#### **Battery Run Time v1**

| Battery Run Time Value | Time            | 
|------------------------|-----------------|
| **0x00**               | Maximum Power   | 
| **0x01**               | 3 hours         | 
| **0x02**               | 5 hours         | 
| **0x03**               | 8 hours         |
| **0x04**               | 12 hours        |
| **0x05 - 0xFF**        | Reserved        |

---

#### **Battery Run Time v2 (custom)**
- The fixture uses custom battery run time values defined by the manufactorer.  Therefore, this data should be available via
  the Fixture Data table.

---

### **Version History:**
- **v001**: Initial version.
