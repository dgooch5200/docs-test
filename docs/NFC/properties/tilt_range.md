# Tilt Range Property Details (v001)

### **Alias:**
- **max_tilt_angle**

### **RDM:**
- N/A

### **Explanation:**
The `tilt_angle` property specifies the maximum pan angle of the lighting fixture.

### **Data Structure:**
- **1 byte (number)**

### **Default Value:**
- **0**: By default, indicating no pan restriction.

### **Range:**

#### **Pan Range v1**

| Pan Range Value | Angle (deg)  | 
|-----------------|--------------|
| **0x00**        | Unrestricted | 
| **0x01**        | 90           | 
| **0x02**        | 180          | 
| **0x03**        | Unrestricted | 
| **0x04 - 0xFF** | Reserved     |




### **Notes:**
- Ensure that the pan angle value is within the supported range of the fixture.
- Displayed values in the App should be accessed via FixtureInfo data.



### **Version History:**
- **v001**: Initial version.
