# Universe Property Details (v001)

### **Explanation:**
- **universe_main**: The `universe_main` property specifies the primary universe for the fixture. When in `Dual Control` 
mode this is used to specify the universe of the `Movement` controls.
- 
- **universe_aux**: This is used *ONLY* in `Dual Control` mode to specify the universe of the `Pixel` fixture controls.

### **Data Structure:**
- **2 bytes (number, big-endian)**

### **Default Value:**
- **0**: By default, the fixture operates on Universe `0` for both `universe_main` and `universe_aux`. Note that in some 
situations, Universe `0` may not be a valid universe (such as when using sACN).

### **Range:**
| Universe Value | Description                                                                      |
|----------------|----------------------------------------------------------------------------------|
| **0x0000**     | Default universe for primary or auxiliary control functions.                     |
| **0x0001**     | Universe 1 for primary or auxiliary control functions.                           |
| **...**        | Additional values correspond to other universes as defined by the network setup. |



### **Version History:**
- **v001**: Initial version.
