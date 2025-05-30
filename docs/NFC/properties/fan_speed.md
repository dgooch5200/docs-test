# Fan Speed Property Details (v002)

### **Alias:**
- **fan**
- **fan_control**

### **RDM:**
- N/A

### **Explanation:**
The `Fan Speed` property allows the user to control the cooling fan's operating mode to match the performance or acoustic requirements of the fixture.

### **Data Structure:**
- **1 byte (number)**

### **Default Value:**
- **0x00** The default factory fan speed setting is used (typically `Auto`).
---
### **Range:**
The following table shows the possible values that can be set for Fan Speed:

#### **Fan Speed v1**
| Fan Speed Value  | Fan Speed Mode | 
|------------------|----------------|
| **0x00**         | Auto           | 
| **0x01**         | Full           | 
| **0x02**         | Eco Mode       | 
| **0x03**         | TV-25 Mode     | 
| **0x04**         | TV-35 Mode     | 
| **0x05 - 0xFF ** | Reserved       | 


---
#### **Fan Speed v2**
| Fan Speed Value  | Fan Speed Mode                 | 
|------------------|--------------------------------|
| **0x00**         | Auto                           | 
| **0x01**         | Full                           | 
| **0x02**         | Eco Mode                       | 
| **0x03 - 0xFF ** | Reserved                       | 

---
#### **Fan Speed v3**
| Fan Speed Value  | Fan Speed Mode                 | 
|------------------|--------------------------------|
| **0x00**         | Auto                           | 
| **0x01**         | Full                           | 
| **0x02 - 0xFF ** | Reserved                       | 

---
#### **Fan Speed v4**
| Fan Speed Value  | Fan Speed Mode                 | 
|------------------|--------------------------------|
| **0x00**         | Auto                           | 
| **0x01**         | Full                           | 
| **0x02**         | Silent                         | 
| **0x03**         | Off                            | 
| **0x04 - 0xFF ** | Reserved                       | 
---

### **Notes:**
- The **Auto** mode adjusts the fan speed dynamically based on the fixture's temperature.
- **Full Speed** mode forces the fan to operate at maximum speed for maximum cooling.
- **Eco Mode** optimizes fan speed for energy efficiency while maintaining adequate cooling.
- **TV-25 Mode** and **TV-35 Mode** provide quieter cooling modes optimized for television studio applications, balancing low noise levels with sufficient cooling.

### **Version History:**
- **v001**: Initial version.

- **v002**:
    - i) Removed 'Default' mode from each version.
