# Line Voltage Power Loss Property Details (v001)

### **Alias:**

### **RDM:**
- N/A

### **Explanation:**
The `line_voltage_power_loss' property allows users to set how their battery fixture responds when it is connected
to line voltage in the event of power loss.

### **Data Structure:**
- **1 byte (number)**

---
### **Range:**

| Battery Run Time Value | Time          | 
|------------------------|---------------|
| **0x00**               | Default       | 
| **0x01**               | Stay In State | 
| **0x02**               | All At Full   | 
| **0x03**               | Dim Out       |
| **0x04 - 0xFF**        | Reserved      |


---

### **Version History:**
- **v001**: Initial version.
