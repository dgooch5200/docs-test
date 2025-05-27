# Wireless Channel Property Details (v001)

### **Alias:**
- **defi_channel**

### **RDM:**
- N/A

### **Explanation:**
The `wireless_channel` property specifies the currently selected defi channel used for receiving/transmitting wireless data.

### **Data Structure:**
- **1 byte (number)**

### **Default Value:**
- **0**: By default, the defi Channel is set to '0' indicating that it is using the manufacturer's default channel.

### **Range:**

| Wireless Channel Value | Channel Number | 
|------------------------|----------------|
| **0x00**               | Reserved       | 
| **0x01**               | 1              | 
| **0x02**               | 2              | 
| **0x03**               | 3              | 
| **0x04**               | 4              | 
| **0x05 - 0xFF**        | Reserved       |




### **Notes:**
- Displayed values in the App should be accessed via FixtureInfo data.



### **Version History:**
- **v001**: Initial version.
