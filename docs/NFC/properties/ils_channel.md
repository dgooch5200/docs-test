# ILS Channel Property Details (v001)

### **Alias:**
- **ils_channel**
- **light_show_channel**
- **synchronization_channel**

### **RDM:**
- N/A

### **Explanation:**
The `ILS Channel` property allows the user to select a specific channel for ILS (Intelligent Lighting Synchronization).

### **Data Structure:**
- **1 byte (number)**

### **Default Value:**
- **0x01** (ILS Channel 1)

### **Range:**
The following table shows the possible values that can be set for the ILS Channel:

| ILS Channel Value   | Channel       | 
|---------------------|---------------|
| **0x00**            | Off           | 
| **0x01**            | ILS Channel 1 | 
| **0x02**            | ILS Channel 2 | 
| **0x03**            | ILS Channel 3 | 
| **0x04**            | ILS Channel 4 |

### **Notes:**
- Values above **0x04** are reserved for future use or special synchronization setups.

### **Version History:**
- **v001**: Initial version.
