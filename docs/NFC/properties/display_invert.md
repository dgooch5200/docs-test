# Display Invert Property Details (v001)

### **Alias:**
- **display_orientation**
- **screen_invert**

### **RDM:**
- N/A

### **Explanation:**
The `display_invert` property allows users to configure orientation settings on the fixture.

### **Data Structure:**
- **1 byte (number, unsigned)**

### **Default Value:**
- **0x00** (0): By default, all display options are disabled.
---
### **Range:**

#### **Display Invert v1**
| Value     | Option              | Description                                         |
|-----------|---------------------|-----------------------------------------------------|
| **0**     | None                | No display options enabled.                         |
| **1**     | Display Invert      | Inverts the display orientation (flips vertically). |
| **2**     | Display Auto-Invert | Automatically inverts display based on orientation. |
| **3-255** | Reserved            | Reserved for future use.                            |

---
#### **Display Invert v2**
| Value     | Option              | Description                                         |
|-----------|---------------------|-----------------------------------------------------|
| **0**     | None                | No display options enabled.                         |
| **1**     | Display Invert      | Inverts the display orientation (flips vertically). |
| **2-255** | Reserved            | Reserved for future use.                            |

---
### **Version History:**
- **v001**: Initial version.


