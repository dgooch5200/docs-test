# IP Mode Property Details (v002)


| IP Mode Value | IP Mode   | Description                                                   |
|---------------|-----------|---------------------------------------------------------------|
| **0**         | Manual    | The network configuration is manually set by the user.        |
| **1**         | DHCP      | The network configuration is automatically assigned via DHCP. |
| **2**         | Static    | The network configuration uses a static IP address.           |


---
### **0 (Manual)**
When `ip_mode` is set to `0`, the user must manually configure the network settings, including IP address, subnet mask, and gateway.

---
### **1 (DHCP)**
When `ip_mode` is set to `1`, the device will automatically obtain its network configuration from a DHCP server.

---
### **2 (Static)**
When `ip_mode` is set to `2`, the device will use a pre-configured static IP address and network settings, which must be manually set by the user.

---



### **Version History:**
- **v001**: Initial version.

- **v002**: 
  - i) Removed `Undefined` mode.
