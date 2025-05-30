# Personality Property Details (v001)

### **Explanation:**
- **personality_main**: The `personality` property determines the DMX operating mode of the fixture. When in `Dual Control` mode this
is used to specify the personality of the `Movement` fixture controls.

- **personality_aux**: This is used *ONLY* in `Dual Control` mode to specify the personality of the `Pixel` fixture controls.

### **Data Structure:**
- **2 bytes (number, big-endian)**

### **Default Value:**
- **0**: By default, the fixture operates in the first personality (Personality `0`), unless otherwise specified.


### **Range:**
| Personality Value | Description                                                                 |
|-------------------|-----------------------------------------------------------------------------|
| **0**             | Corresponds to a specific DMX personality for the fixture. Refer to the fixture's personality documentation for details. |
| **1**             | Corresponds to a specific DMX personality for the fixture. Refer to the fixture's personality documentation for details. |
| **2**             | Corresponds to a specific DMX personality for the fixture. Refer to the fixture's personality documentation for details. |
| **...**           | Additional values correspond to other personalities as defined by the fixture. |




### **Version History:**
- **v001**: Initial version.
