# Start Address Main Property Details (v001)

### **Alias:**
- **dmx_address**
- **address**

### **RDM:**
- **DMX_START_ADDRESS**

### **Explanation:**
- **dmx_address_main**: The `dmx_address` property specifies the starting DMX address of the fixture. When in `Dual Control` mode this
is used to specify the DMX Address of the `Movement` fixture controls.

- **dmx_address_aux**: This is used *ONLY* in `Dual Control` mode to specify the DMX Address of the `Pixel` fixture controls.

### **Data Structure:**
2 bytes (number, big-endian)

### **Default Value:**
- **1**: By default, the fixture operates at DMX Address `1`.


### **Version History:**
- **v001**: Initial version.
