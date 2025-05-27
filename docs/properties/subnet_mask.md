# Subnet Mask Property Details (v001)

### **Alias:**
- **sub_mask**
- **subnet**

### **RDM:**
- N/A

### **Explanation:**
The `Subnet Mask` property defines the range of IP addresses within a network that the fixture can communicate with 
directly. It helps to determine the network portion and the host portion of an IP address. The subnet mask is 
crucial for routing and communication within a local network.

### **Data Structure:**
- **4 bytes (string, IPv4 format)**

### **Default Value:**
- **XXX.XXX.XXX.XXX**: Different fixtures may set a different default value.

### **Range:**
The subnet mask is a 32-bit value, typically represented in the format `xxx.xxx.xxx.xxx`, where each `xxx` can 
range from 0 to 255. Common subnet masks include:

### **Example Values:**

| Subnet Mask (Hex) | Subnet Mask (Decimal) | Description                                                |
|-------------------|-----------------------|------------------------------------------------------------|
| **0xFFFFFF00**    | 255.255.255.0         | Default subnet mask for many local networks (/24).         |
| **0xFFFF0000**    | 255.255.0.0           | Subnet mask for larger networks (/16).                     |
| **0xFF000000**    | 255.0.0.0             | Subnet mask for very large networks (/8).                  |
| **0xFFFFFFFF**    | 255.255.255.255       | Used for point-to-point links or loopback configurations.  |
| **0x00000000**    | 0.0.0.0               | This represents an invalid subnet mask and should not be used.|


### **Special Considerations:**
- The subnet mask must match the network configuration of all devices within the same network to ensure proper communication.
- Incorrect subnet masks can lead to communication issues, such as the inability to reach other devices on the network.

### **Version History:**
- **v001**: Initial version.
