# User Data Property Details (v001)

### **Explanation:**
The `user_data` property is a 128-byte string that allows users to store custom information within the fixture. This 
could include notes, identifiers, or any other user-defined data relevant to the operation or management of the fixture. 
The string is null-terminated if less than 128 bytes, meaning that the data is followed by a null character (`\0`) to indicate the end of the string.

### **Data Structure:**
- **128 bytes (string, null-terminated if less than 128 bytes)**

### **Default Value:**
- **Empty string (`\0`)**: By default, the `user_data` is an empty string, represented by a single null character.

### **Usage:**
- **Custom Identifiers:** Users can store a custom identifier for the fixture, such as a location or owner name.
- **Notes:** The `user_data` field can be used to keep notes related to the fixture's usage, maintenance, or configuration.


### **Notes:**
- **Storing Data:** To store data, write a string to the `user_data` property. If the string is shorter than 128 characters, it should still be null-terminated.
- **Clearing Data:** To clear the `user_data`, write a single null character (`\0`) to this property, which will remove any previously stored information.
- **Overflow Protection:** If more than 127 characters are written, only the first 127 characters will be stored, followed by a null terminator.
- **Encoding:** The string is typically stored in ASCII or UTF-8 encoding, depending on the system's configuration.
- 

### **Version History:**
- **v001**: Initial version.
