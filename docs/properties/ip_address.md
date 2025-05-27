# IP Address Property Details (v001)

### **Explanation:**
The `IP Address` property specifies the network address of the fixture within an IP-based network, such as those using 
Art-Net or sACN protocols.

### **Data Structure:**
- **4 bytes (string, IPv4 format)**

### **Default Value:**
- **XXX.XXX.XXX.XXX**: Different fixtures may set a different default value.

### **Range:**
The IP address is a 32-bit value, divided into four 8-bit octets, usually represented in the format `xxx.xxx.xxx.xxx`, where each `xxx` can range from 0 to 255.

### **Example Values:**

| IP Address (Hex)  | IP Address (Decimal) | Description                                          |
|-------------------|----------------------|------------------------------------------------------|
| **0xC0A80064**    | 192.168.0.100        | Default IP address commonly used for fixtures.       |
| **0xC0A80001**    | 192.168.0.1          | Commonly used as a gateway or router address.        |
| **0xC0A800FF**    | 192.168.0.255        | Broadcast address for the 192.168.0.x subnet.        |
| **0x0A000001**    | 10.0.0.1             | Example IP address in a private network range.       |
| **0x7F000001**    | 127.0.0.1            | Loopback address, used for internal testing.         |



### **Notes:**
- The IP address can be configured manually or automatically via DHCP, depending on the network setup.
- Ensure correct subnet mask and gateway address settings to enable proper network communication.

### **Version History:**
- **v001**: Initial version.
