# Dimmer Response Property Details (v001)

### **Alias:**
- **dimmer_speed**
- **dim**

### **RDM:**
- N/A

### **Explanation:**
The `dimmer_mode` property controls how quickly the fixture responds to changes in the dimmer level. This allows 
users to choose between a smooth, gradual transition or a fast, immediate response when adjusting the light output.

### **Data Structure:**
- **1 byte (number)**

### **Default Value:**
- **0x00**: By default, the fixture operates with no dimmer timing adjustments.

### **Range:**

#### **Dimmer Response v1**
| Dimmer Speed Value | Description | Notes                                     |
|--------------------|-------------|-------------------------------------------|
| **0x00**           | Off         | No dimming response                       |
| **0x01**           | Dimmer 1    | Dimmer 1 response                         |
| **0x02**           | Dimmer 2    | Dimmer 2 response                         |
| **0x03**           | Dimmer 3    | Dimmer 3 response                         |
| **0x04-0xFF**      | Reserved    | Reserved for future dimmer speed options. |

#### **Dimmer Response v2**
| Dimmer Speed Value | Description | Notes                                     |
|--------------------|-------------|-------------------------------------------|
| **0x00**           | Off         | No dimming response                       |
| **0x01**           | DIM 1       | Dimmer 1 response                         |
| **0x02**           | DIM 2       | Dimmer 2 response                         |
| **0x03**           | DIM 3       | Dimmer 3 response                         |
| **0x04-0xFF**      | DIM 4       | Reserved for future dimmer speed options. |

#### **Dimmer Response v3**
| Dimmer Speed Value | Description | Notes                                     |
|--------------------|-------------|-------------------------------------------|
| **0x00**           | Fast        | Fast                                      |
| **0x01**           | Smooth      | Smooth dimmer response                    |
| **0x02-0xFF**      | Reserved    | Reserved for future dimmer speed options. |



### **Version History:**
- **v001**: Initial version.
