# Display Language Property Details (v001)

### **Explanation:**
The `display_language` property specifies the language used in the fixture's display. This setting allows users to choose the language in which on-screen text and menus are presented. The language code follows the [ISO 639-1 standard](https://www.loc.gov/standards/iso639-2/php/code_list.php).

### **Data Structure:**
- **2 bytes (string)**

### **Default Value:**
- **"en"**: By default, the display language is set to English.

### **Range:**

| Language Code | Description                 | Notes                                                                                                                             |
|---------------|-----------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
| **"en"**      | English                     | The default language for the display.                                                                                             |
| **"es"**      | Spanish                     | Sets the display language to Spanish.                                                                                             |
| **"fr"**      | French                      | Sets the display language to French.                                                                                              |
| **"de"**      | German                      | Sets the display language to German.                                                                                              |
| **"zh"**      | Chinese                     | Sets the display language to Chinese.                                                                                             |
| **"jp"**      | Japanese                    | Sets the display language to Japanese.                                                                                            |
| **Others**    | Various                     | Any valid [ISO 639-1 code](https://www.loc.gov/standards/iso639-2/php/code_list.php) can be used to set a corresponding language. |


### **Notes:**
- The language code must be a valid [ISO 639-1 code](https://www.loc.gov/standards/iso639-2/php/code_list.php).
- If an invalid code is entered, the display may default to the last known good setting or to English ("en").

### **Version History:**
- **v001**: Initial version.
