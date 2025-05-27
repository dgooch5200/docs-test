# Control Mode Property Details (v001)

### **Alias:**
- **protocol**
- **out**

### **RDM:**
- N/A

### **Explanation:**
- **`control_mode_main`**: The `control_mode` determines the main operating mode of the fixture. In `Dual Control` mode
    this is used to specify the control mode of the `Movement` fixture controls.
- **`control_mode_aux`**: This is used *ONLY* in `Dual Control` mode to specify the control mode of the `Pixel` fixture controls.

### **Data Structure:**
- **1 byte (number)**

### **Default Value:**
- **0x0000 (DMX)**: By default, the fixture operates in DMX control mode.

### **Range:**

| Control Mode Value | Description                                                         | Applicable To | Notes                                      |
|--------------------|---------------------------------------------------------------------|---------------|--------------------------------------------|
| **0x00**           | DMX: The fixture is controlled via DMX protocol.                    | Main          | Standard DMX control mode.                 |
| **0x01**           | WDMX: The fixture is controlled via WDMX protocol.                  | Main          | Wireless DMX control mode.                 |
| **0x02**           | Art-Net: The fixture is controlled via the Art-Net protocol.        | Main & Aux    | Art-Net control mode.                      |
| **0x03**           | sACN: The fixture is controlled via the sACN protocol.              | Main & Aux    | sACN control mode.                         |
| **0x04**           | Kling-Net: The fixture operates as a slave in a Master-Slave setup. | Main & Aux    | Slave mode for Master-Slave configuration. |
| **0x05-0xFF**      | Reserved                                                            | N/A           | Reserved for future use.                   |

### **Notes:**
- **`control_mode_main`** supports all values listed, including advanced modes (Auto, Sound, and Auto Test programs).
- **`control_mode_aux`** supports only the basic modes (DMX, Art-Net, sACN, Slave) and does not support Auto Test programs.
- The displayed Control Modes should refer to the specific capabilities which have been included in the fixture. 
  - For example, if the fixture does not support Art-Net, then the Art-Net control mode should not be displayed.



### **Version History:**
- **v001**: Initial version.
