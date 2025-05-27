# Cell Order Property Details (v001)

### **Alias:**
- **pod_order**

### **RDM:**
- N/A

### **Explanation:**
The `cell_order' property allows users to configure the order in which the cells are addressed.

### **Data Structure:**
- **1 byte (number)**

---
### **Range:**
#### **Cell Order v1**
 - The fixture uses a fixed cell order.  The cells are addressed in a fixed order, starting from the first cell and ending with the last cell.
   - **0x00**: Normal
   - **0x01**: Reverse

#### **Cell Order v2 (custom)** 
- The fixture uses custom cell arrangment values defined by the manufactorer.  Therefore, this data should be available via
  the Fixture Data table.

---

### **Version History:**
- **v001**: Initial version.
