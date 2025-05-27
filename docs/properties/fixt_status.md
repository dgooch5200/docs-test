# FIXT_STATUS Property Details (v001)

### **Explanation:**
The `FIXT_STATUS` property is a bitfield used to track the status of fixture data. 

### **Data Structure:**
- **1 byte (bitfield)**

### **Default Value:**
- **0x00** (No fixture status has been set)

### **Bitfield Representation:**
The following table shows the possible values for each bit in the `CONF_STATUS` byte:

| Bit Position | Status                    | Description                                                              | Default Value | Data Type | Notes                                                                       |
|--------------|---------------------------|--------------------------------------------------------------------------|---------------|-----------|-----------------------------------------------------------------------------|
| **0**  (LSB) | Commissioning Initialized | Indicates if the commissioning has been performed by the fixture.        | `0` (False)   | Boolean   | Set to `1` when the i2c populates the NDEF records.                         |
| **1**        | Commissioning Finalized   | Indicates if the RF has written the serial number and verified the data. | `0`           | Boolean   | Set to `1` when the RF populates the serial number and verifies the data.   |
| **2**        | Reserved                  | Reserved for future use.                                                 | `0`           | Boolean   | Not currently in use.                                                       |
| **3**        | Reserved                  | Reserved for future use.                                                 | `0`           | Boolean   | Not currently in use.                                                       |
| **4**        | Reserved                  | Reserved for future use.                                                 | `0`           | Boolean   | Not currently in use.                                                       |
| **5**        | Reserved                  | Reserved for future use.                                                 | `0`           | Boolean   | Not currently in use.                                                       |
| **6**        | Reserved                  | Reserved for future use.                                                 | `0`           | Boolean   | Not currently in use.                                                       |
| **7**  (MSB) | Reserved                  | Reserved for future use.                                                 | `0`           | Boolean   | Not currently in use.                                                       |

### **Example:**
- If the Commissioning is complete and verified, `FIXT_STATUS` would be `0b00000011` (3 in decimal, `0x03` in hexadecimal).

### **Commissioning Process:**
- During the commissioning process, the `FIXT_STATUS` byte will be updated to reflect the status of the fixture data.
- The Fixture should be powered on during the commissioning process.
- **STEP 1**: The RF will structure and write the NDEF message, with associated record headers and empty data. This will 
also mean that the `Commissioning Initialized` bit will be set to `0`. 
- **STEP 2**: The Fixture will populate the NDEF records with the appropriate data. Once this is complete, the 
`Commissioning Initialized` bit will be set to `1`. 
- **STEP 3**: The RF App should scan the fixture bar code and write the serial number to the NDEF message. The RF App 
should also perform some simple data verification checks on both the structure and contents of the NDEF message. Once 
this is complete, the `Commissioning Finalized` bit will be set to `1`.

### **Version History:**
- **v001**: Initial version.
