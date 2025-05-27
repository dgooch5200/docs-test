# Display Level Property Details (v001)

### **Explanation:**
The `display_level` property controls the brightness level of the fixture's display. This setting allows users to adjust the visibility of the display based on the environment or preference.

### **Data Structure:**
- **1 byte (number)**

### **Default Value:**
- **100**: By default, the display level is set to `100`, which corresponds to 100% brightness.

### **Range:**
- The display level ranges from `0` to `100`, where:
    - `0` corresponds to the display being turned off (0% brightness).
    - Values from `1` to `99` represent a percentage of the brightness, where `1` is 1% and `99` is 99%.
    - Values `100` and above represent 100% brightness.



### **Notes:**
- Values of `100` and above do not increase brightness beyond 100% but will ensure maximum brightness.
- Many fixtures have values that are incremented by different amounts.


### **Version History:**
- **v001**: Initial version.
