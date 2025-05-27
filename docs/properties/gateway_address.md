# Gateway Address Property Details (v001)

### **Explanation:**
The `Gateway Address` property specifies the IP address of the network gateway, which acts as an access point or 
router that the fixture uses to communicate with other networks or devices outside its local network. 

### **Data Structure:**
- **4 bytes (string, IPv4 format)**

### **Default Value:**
- **XXX.XXX.XXX.XXX**: Different fixtures may set a different default value.

### **Range:**
The gateway address is a 32-bit value, typically represented in the format `xxx.xxx.xxx.xxx`, where each `xxx` can range from 0 to 255.

### **Example Values:**

| Gateway Address (Hex) | Gateway Address (Decimal) | Description                                           |
|-----------------------|---------------------------|-------------------------------------------------------|
| **0xC0A80001**        | 192.168.0.1               | Default gateway for many home or small office routers.|
| **0xC0A80101**        | 192.168.1.1               | Common gateway address for routers in a different subnet. |
| **0x0A000001**        | 10.0.0.1                  | Often used for enterprise networks.                   |
| **0x7F000001**        | 127.0.0.1                 | Loopback address for the local machine (localhost).   |
| **0x00000000**        | 0.0.0.0                   | Represents an invalid or unspecified gateway address. |

### **Version History:**
- **v001**: Initial version.
