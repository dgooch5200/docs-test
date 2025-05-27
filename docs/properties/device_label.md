# Device Label Property Details (v001)

### **Explanation:**
The `device_label` property allows the user to assign a custom name to the lighting fixture. This name can be used for identification purposes in various control systems.

### **Data Structure:**
- **32 bytes (string, null-terminated if less than 32 bytes)**

### **Default Value:**
- **Empty**: By default, the device label is empty, meaning all 32 bytes are set to `'\0'` (null characters).

### **Usage:**
- The string stored in the `device_label` field is null-terminated, meaning a `'\0'` character is used to indicate the end of the string.
- If the string is shorter than 32 bytes, the remaining bytes should be filled with `'\0'` to ensure the entire buffer is clean and free of residual data.

### **Example:**
- If the user sets the device label to `"Fixture01"`, the bytes would be stored as follows:
    - **Bytes 0 to 8**: `"Fixture01"` (9 characters)
    - **Byte 9**: `'\0'` (null terminator)
    - **Bytes 10 to 31**: `'\0'` (remaining null bytes to fill the 32-byte buffer)

### **Important Notes:**
- Always ensure that the `device_label` string is properly null-terminated if less than 32 bytes.
- The remaining bytes in the buffer should be filled with null characters to avoid any potential issues with residual data. 


### **Version History:**
- **v001**: Initial version.
