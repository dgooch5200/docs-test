# CONF_STATUS Property Details (v001)

### **Explanation:**
The `CONF_STATUS` property is a bitfield used to track the status of configuration data. 

### **Data Structure:**
- **1 byte (bitfield)**

### **Default Value:**
- **0x00** (No changes have been made to the configuration.)

### **Bitfield Representation:**
The following table shows the possible values for each bit in the `CONF_STATUS` byte:

---
## conf_status Byte (Bitfield Representation)

| Bit Position | Attribute              | Description                                     | Default Value | Data Type | Notes                  |
|--------------|------------------------|-------------------------------------------------|---------------|-----------|------------------------|
| **0**        | actions_change_master  | Indicates app has modified any `ACTIONS` data.  | `0` (False)   | Boolean   | ACTION A - D Requested |
| **1**        | property_change_master | Indicates app has modified any `PROPERTY` data. | `0`           | Boolean   | PROPERTY Change A - H  |
| **2**        | options_change_master  | Indicates app has modified any `OPTIONS` data.  | `0`           | Boolean   | OPTION Change A - J    |
| **3**        | Reserved               | Reserved for future use.                        | `0`           | Boolean   |                        |
| **4**        | Reserved               | Reserved for future use.                        | `0`           | Boolean   |                        |
| **5**        | Reserved               | Reserved for future use.                        | `0`           | Boolean   |                        |
| **6**        | Reserved               | Reserved for future use.                        | `0`           | Boolean   |                        |
| **7**        | Reserved               | Reserved for future use.                        | `0`           | Boolean   |                        |

---
## property_change_A Byte (Bitfield Representation)

| Bit Position | Modified Attribute                   | Description                                      | Default Value | Data Type | Notes |
|--------------|--------------------------------------|--------------------------------------------------|---------------|-----------|-------|
| **0**        | property_change_A_start_address_main | Indicates app has modified `start_address_main`. | `0` (False)   | Boolean   |       |
| **1**        | property_change_A_personality_main   | Indicates app has modified `personality_main`.   | `0`           | Boolean   |       |
| **2**        | property_change_A_control_mode_main  | Indicates app has modified `control_mode_main`.  | `0`           | Boolean   |       |
| **3**        | Reserved                             | Reserved for future use.                         | `0`           | Boolean   |       |
| **4**        | property_change_A_start_address_aux  | Indicates app has modified `start_address_aux`.  | `0`           | Boolean   |       |
| **5**        | property_change_A_personality_aux    | Indicates app has modified `personality_aux`.    | `0`           | Boolean   |       |
| **6**        | property_change_A_control_mode_aux   | Indicates app has modified `control_mode_aux`.   | `0`           | Boolean   |       |
| **7**        | Reserved                             | Reserved for future use.                         | `0`           | Boolean   |       |

---

## property_change_B Byte (Bitfield Representation)

| Bit Position | Modified Attribute                   | Description                                     | Default Value | Data Type | Notes |
|--------------|--------------------------------------|-------------------------------------------------|---------------|-----------|-------|
| **0**        | property_change_B_pan_range          | Indicates app has modified `pan_range`.         | `0` (False)   | Boolean   |       |
| **1**        | property_change_B_tilt_range         | Indicates app has modified `tilt_range`.        | `0`           | Boolean   |       |
| **2**        | property_change_B_fan_speed          | Indicates app has modified `fan_speed`.         | `0`           | Boolean   |       |
| **3**        | property_change_B_display_level      | Indicates app has modified `display_level`.     | `0`           | Boolean   |       |
| **4**        | property_change_B_display_invert     | Indicates app has modified `display_invert`.    | `0`           | Boolean   |       |
| **5**        | property_change_B_display_shutoff    | Indicates app has modified `display_shutoff`.   | `0`           | Boolean   |       |
| **6**        | property_change_B_white_calibration  | Indicates app has modified `white_calibration`. | `0`           | Boolean   |       |
| **7**        | property_change_B_dimmer_curve       | Indicates app has modified `dimmer_curve`.      | `0`           | Boolean   |       |

---

## property_change_C Byte (Bitfield Representation)

| Bit Position | Modified Attribute                | Description                                   | Default Value | Data Type | Notes |
|--------------|-----------------------------------|-----------------------------------------------|---------------|-----------|-------|
| **0**        | property_change_C_dimmer_response | Indicates app has modified `dimmer_response`. | `0` (False)   | Boolean   |       |
| **1**        | property_change_C_language        | Indicates app has modified `Language`.        | `0`           | Boolean   |       |
| **2**        | property_change_C_PWM Frequency   | Indicates app has modified `pwm_frequency`.   | `0`           | Boolean   |       |
| **3**        | property_change_C_ip_mode         | Indicates app has modified `ip_mode`.         | `0`           | Boolean   |       |
| **4**        | property_change_C_ip_address      | Indicates app has modified `ip_address`.      | `0`           | Boolean   |       |
| **5**        | property_change_C_subnet_mask     | Indicates app has modified `subnet_mask`.     | `0`           | Boolean   |       |
| **6**        | property_change_C_gateway_address | Indicates app has modified `gateway_address`. | `0`           | Boolean   |       |
| **7**        | property_change_C_universe_main   | Indicates app has modified `universe_main`.   | `0`           | Boolean   |       |

---

## property_change_D Byte (Bitfield Representation)

| Bit Position | Modified Attribute              | Description                                   | Default Value | Data Type | Notes                              |
|--------------|---------------------------------|-----------------------------------------------|---------------|-----------|------------------------------------|
| **0**        | property_change_D_universe_aux  | Indicates app has modified `universe_aux`.    | `0` (False)   | Boolean   |                                    |
| **1**        | property_change_D_ils_channel   | Indicates app has modified `ils_channel`.     | `0`           | Boolean   |                                    |
| **2**        | property_change_D_rf_channel    | Indicates app has modified `rf_channel`.      | `0`           | Boolean   |                                    |
| **3**        | property_change_D_shared1_a     | Indicates app has modified `shared1_a`.       | `0`           | Boolean   | Single Axis Movement/Fog Fan Speed |
| **4**        | property_change_D_shared1_b     | Indicates app has modified `shared1_b`.       | `0`           | Boolean   | LED Power/Fog Volume               |
| **5**        | property_change_D_shared1_c     | Indicates app has modified `shared1_c`.       | `0`           | Boolean   | Cell Order                         |
| **6**        | property_change_D_shared1_d     | Indicates app has modified `shared1_d `.      | `0`           | Boolean   | Gobo Rotation Position             |
| **7**        | property_change_D_shared1_e     | Indicates app has modified `shared1_e`.       | `0`           | Boolean   | Battery Run Time                   |

---

## property_change_E Byte (Bitfield Representation)

| Bit Position | Modified Attribute           | Description                             | Default Value | Data Type | Notes                     |
|--------------|------------------------------|-----------------------------------------|---------------|-----------|---------------------------|
| **0**        | property_change_E_shared1_f  | Indicates app has modified `shared1_f`. | `0` (False)   | Boolean   | Line Voltage Power Loss   |
| **1**        | property_change_E_shared1_g  | Indicates app has modified `shared1_g`. | `0`           | Boolean   | Zoom Range                |
| **2**        | property_change_E_shared1_h  | Indicates app has modified `shared1_h`. | `0`           | Boolean   | Zoom Offset               |
| **3**        | property_change_E_shared2_a  | Indicates app has modified `shared2_a`. | `0`           | Boolean   | Fog Duration / Zoom Level |
| **4**        | property_change_E_shared2_b  | Indicates app has modified `shared2_b`. | `0`           | Boolean   | Fog Interval              |
| **5**        | Reserved                     | Reserved for future use.                | `0`           | Boolean   |                           |
| **6**        | Reserved                     | Reserved for future use.                | `0`           | Boolean   |                           |
| **7**        | Reserved                     | Reserved for future use.                | `0`           | Boolean   |                           |

---


## property_change_F Byte (Bitfield Representation)

| Bit Position | Modified Attribute | Description                             | Default Value | Data Type | Notes |
|--------------|--------------------|-----------------------------------------|---------------|-----------|-------|
| **0**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **1**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **2**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **3**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **4**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **5**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **6**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **7**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |

---


## property_change_G Byte (Bitfield Representation)

| Bit Position | Modified Attribute | Description                             | Default Value | Data Type | Notes |
|--------------|--------------------|-----------------------------------------|---------------|-----------|-------|
| **0**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **1**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **2**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **3**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **4**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **5**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **6**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **7**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |

---


## property_change_H Byte (Bitfield Representation)

| Bit Position | Modified Attribute | Description                             | Default Value | Data Type | Notes |
|--------------|--------------------|-----------------------------------------|---------------|-----------|-------|
| **0**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **1**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **2**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **3**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **4**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **5**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **6**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |
| **7**        | Reserved           | Reserved for future use.                | `0`           | Boolean   |       |

---

## options_change_A Byte (Bitfield Representation)

| Bit Position | Modified Option                                | Description                                                | Default Value | Notes |
|--------------|------------------------------------------------|------------------------------------------------------------|---------------|-------|
| **0**  (LSB) | options_change_A_prevent_lamp_strike_on_power  | Indicates app has modified `prevent_lamp_strike_on_power`. | `0`           |       |
| **1**        | options_change_A_prevent_lamp_off_via_dmx      | Indicates app has modified `prevent_lamp_off_via_dmx`.     | `0`           |       |
| **2**        | options_change_A_prevent_lamp_on_via_dmx       | Indicates app has modified `prevent_lamp_on_via_dmx`.      | `0`           |       |
| **3**        | options_change_A_lamp_off_when_no_dmx          | Indicates app has modified `lamp_off_when_no_dmx`.         | `0`           |       |
| **4**        | options_change_A_lamp_strike_delay             | Indicates app has modified `lamp_strike_delay`.            | `0`           |       |
| **5**        | options_change_A_lamp_low_power_delay          | Indicates app has modified `lamp_low_power_delay`.         | `0`           |       |
| **6**        | Reserved                                       | Reserved for future use.                                   | `0`           |       |
| **7**  (MSB) | Reserved                                       | Reserved for future use.                                   | `0`           |       |


---

## options_change_B Byte (Bitfield Representation)

| Bit Position | Modified Option                               | Description                                                | Default Value | Notes |
|--------------|-----------------------------------------------|------------------------------------------------------------|---------------|-------|
| **0**  (LSB) | options_change_B_pan_reverse                  | Indicates app has modified `pan_reverse`.                  | `0`           |       |
| **1**        | options_change_B_tilt_reverse                 | Indicates app has modified `tilt_reverse`.                 | `0`           |       |
| **2**        | options_change_B_swap_pan_tilt                | Indicates app has modified `swap_pan_tilt`.                | `0`           |       |
| **3**        | options_change_B_pan_2_reverse                | Indicates app has modified `pan_2_reverse`.                | `0`           |       |
| **4**        | options_change_B_tilt_2_reverse               | Indicates app has modified `tilt_2_reverse`.               | `0`           |       |
| **5**        | options_change_B_prevent_single_axis_movement | Indicates app has modified `prevent_single_axis_movement`. | `0`           |       |
| **6**        | options_change_B_absolute_silence             | Indicates app has modified `absolute_silence`.             | `0`           |       |
| **7**  (MSB) | Reserved                                      | Reserved for future use.                                   | `0`           |       |

---
## options_change_C Byte (Bitfield Representation)

| Bit Position | Modified Option                 | Description                                  | Default Value | Notes |
|--------------|---------------------------------|----------------------------------------------|---------------|-------|
| **0**  (LSB) | options_change_C_pan_blackout   | Indicates app has modified `pan_blackout`.   | `0`           |       |
| **1**        | options_change_C_tilt_blackout  | Indicates app has modified `tilt_blackout`.  | `0`           |       |
| **2**        | options_change_C_color_blackout | Indicates app has modified `color_blackout`. | `0`           |       |
| **3**        | options_change_C_gobo_blackout  | Indicates app has modified `gobo_blackout`.  | `0`           |       |
| **4**        | Reserved                        | Reserved for future use.                     | `0`           |       |
| **5**        | Reserved                        | Reserved for future use.                     | `0`           |       |
| **6**        | Reserved                        | Reserved for future use.                     | `0`           |       |
| **7**  (MSB) | Reserved                        | Reserved for future use.                     | `0`           |       |

---
## options_change_D Byte (Bitfield Representation)

| Bit Position | Modified Option                              | Description                                               | Default Value | Notes |
|--------------|----------------------------------------------|-----------------------------------------------------------|---------------|-------|
| **0**  (LSB) | options_change_D_min_zoom_focus              | Indicates app has modified `min_zoom_focus`.              | `0`           |       |
| **1**        | options_change_D_zoom_reverse                | Indicates app has modified `zoom_reverse`.                | `0`           |       |
| **2**        | options_change_D_smart_zoom                  | Indicates app has modified `smart_zoom`.                  | `0`           |       |
| **3**        | options_change_D_merge_zoom                  | Indicates app has modified `merge_zoom`.                  | `0`           |       |
| **4**        | options_change_D_prevent_zoom_via_dmx        | Indicates app has modified `prevent_zoom_via_dmx`.        | `0`           |       |
| **5**        | options_change_D_prevent_zoom_reset_on_power | Indicates app has modified `prevent_zoom_reset_on_power`. | `0`           |       |
| **6**        | Reserved                                     | Reserved for future use.                                  | `0`           |       |
| **7**  (MSB) | Reserved                                     | Reserved for future use.                                  | `0`           |       |


---
## options_change_E Byte (Bitfield Representation)

| Bit Position | Modified Option                          | Description                                           | Default Value | Notes |
|--------------|------------------------------------------|-------------------------------------------------------|---------------|-------|
| **0**  (LSB) | options_change_E_totem_orientation_down  | Indicates app has modified `totem_orientation_down`.  | `0`           |       |
| **1**        | options_change_E_gobo_rotator_power      | Indicates app has modified `gobo_rotator_power`.      | `0`           |       |
| **2**        | options_change_E_fog_fluid_sensor        | Indicates app has modified `fog_fluid_sensor`.        | `0`           |       |
| **3**        | options_change_E_follow_spot_mode        | Indicates app has modified `follow_spot_mode`.        | `0`           |       |
| **4**        | options_change_E_follow_spot_mode_head_2 | Indicates app has modified `follow_spot_mode_head_2`. | `0`           |       |
| **5**        | options_change_E_defrost_fan             | Indicates app has modified `defrost_fan`.             | `0`           |       |
| **6**        | options_change_E_color_mixing_mode_cmy   | Indicates app has modified `color_mixing_mode_cmy`.   | `0`           |       |
| **7**  (MSB) | options_change_E_red_shift               | Indicates app has modified `red_shift`.               | `0`           |       |


---
## options_change_F Byte (Bitfield Representation)

| Bit Position | Modified Option                | Description                                 | Default Value | Notes   |
|--------------|--------------------------------|---------------------------------------------|---------------|---------|
| **0**  (LSB) | options_change_F_wdmx_activate | Indicates app has modified `wdmx_activate`. | `0`           |         |
| **1**        | options_change_F_wdmx_transmit | Indicates app has modified `wdmx_transmit`. | `0`           |         |
| **2**        | options_change_F_wdmx2dmx      | Indicates app has modified `wdmx2dmx`.      | `0`           |         |
| **3**        | options_change_F_ethernet2dmx  | Indicates app has modified `ethernet2dmx`.  | `0`           |         |
| **4**        | options_change_F_ir_activation | Indicates app has modified `ir_activation`. | `0`           |         |
| **5**        | Reserved                       | Reserved for future use.                    | `0`           |         |
| **6**        | Reserved                       | Reserved for future use.                    | `0`           |         |
| **7**  (MSB) | options_change_F_master_slave  | Indicates app has modified `master_slave`.  | `0`           |         |


---
## options_change_G Byte (Bitfield Representation)

| Bit Position | Modified Option                     | Description                                      | Default Value | Notes |
|--------------|-------------------------------------|--------------------------------------------------|---------------|-------|
| **0**  (LSB) | options_change_G_screen_lock        | Indicates app has modified `screen_lock`.        | `0`           |       |
| **1**        | options_change_G_touchscreen_lock   | Indicates app has modified `touchscreen_lock`.   | `0`           |       |
| **2**        | options_change_G_data_loss_blackout | Indicates app has modified `data_loss_blackout`. | `0`           |       |
| **3**        | options_change_G_flash_on_dmx       | Indicates app has modified `flash_on_dmx`.       | `0`           |       |
| **4**        | options_change_G_tv_reset_mode      | Indicates app has modified `tv_reset_mode`.      | `0`           |       |
| **5**        | Reserved                            | Reserved for future use.                         | `0`           |       |
| **6**        | Reserved                            | Reserved for future use.                         | `0`           |       |
| **7**  (MSB) | Reserved                            | Reserved for future use.                         | `0`           |       |

---
## options_change_H Byte (Bitfield Representation)

| Bit Position | Modified Option                         | Description                                          | Default Value | Notes |
|--------------|-----------------------------------------|------------------------------------------------------|---------------|-------|
| **0**  (LSB) | options_change_H_output_setting         | Indicates app has modified `output_setting`.         | `0`           |       |
| **1**        | options_change_H_standby                | Indicates app has modified `standby`.                | `0`           |       |
| **2**        | options_change_H_foot_pedal_control     | Indicates app has modified `foot_pedal_control`.     | `0`           |       |
| **3**        | options_change_H_foot_pedal_mode_common | Indicates app has modified `foot_pedal_mode_common`. | `0`           |       |
| **4**        | Reserved                                | Reserved for future use.                             | `0`           |       |
| **5**        | Reserved                                | Reserved for future use.                             | `0`           |       |
| **6**        | Reserved                                | Reserved for future use.                             | `0`           |       |
| **7**  (MSB) | Reserved                                | Reserved for future use.                             | `0`           |       |


---
## options_change_I Byte (Bitfield Representation)

| Bit Position | Modified Option                         | Description                                          | Default Value | Notes |
|--------------|-----------------------------------------|------------------------------------------------------|---------------|-------|
| **0**  (LSB) | Reserved                                | Reserved for future use.                             | `0`           |       |
| **1**        | Reserved                                | Reserved for future use.                             | `0`           |       |
| **2**        | Reserved                                | Reserved for future use.                             | `0`           |       |
| **3**        | Reserved                                | Reserved for future use.                             | `0`           |       |
| **4**        | Reserved                                | Reserved for future use.                             | `0`           |       |
| **5**        | Reserved                                | Reserved for future use.                             | `0`           |       |
| **6**        | Reserved                                | Reserved for future use.                             | `0`           |       |
| **7**  (MSB) | Reserved                                | Reserved for future use.                             | `0`           |       |

---
## options_change_J Byte (Bitfield Representation)

| Bit Position | Modified Option                         | Description                                          | Default Value | Notes |
|--------------|-----------------------------------------|------------------------------------------------------|---------------|-------|
| **0**  (LSB) | Reserved                                | Reserved for future use.                             | `0`           |       |
| **1**        | Reserved                                | Reserved for future use.                             | `0`           |       |
| **2**        | Reserved                                | Reserved for future use.                             | `0`           |       |
| **3**        | Reserved                                | Reserved for future use.                             | `0`           |       |
| **4**        | Reserved                                | Reserved for future use.                             | `0`           |       |
| **5**        | Reserved                                | Reserved for future use.                             | `0`           |       |
| **6**        | Reserved                                | Reserved for future use.                             | `0`           |       |
| **7**  (MSB) | Reserved                                | Reserved for future use.                             | `0`           |       |

### **Version History:**
- **v001**: Initial version.
