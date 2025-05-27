# RF Channel Property Details (v001)

### **Alias:**
- **rf_channel**
- **radio_channel**

### **RDM:**
- N/A

### **Explanation:**
The `RF Channel` property allows the user to select a specific radio frequency channel for communication with devices. 

### **Data Structure:**
- **1 byte (number)**

### **Default Value:**
- **0x01** (Channel 1)

### **Range:**
The following table shows the possible values that can be set for the RF Channel:

| RF Channel Value | Channel        | 
|------------------|----------------|
| **0x00**         | Off            | 
| **0x01**         | Channel 1      | 
| **0x02**         | Channel 2      | 
| **0x03**         | Channel 3      | 
| **0x04**         | Channel 4      |
| **0x05**         | Public Channel |

### **Notes:**
- Channel values above **0x05** are reserved for future use or special applications.

### **Version History:**
- **v001**: Initial version.
