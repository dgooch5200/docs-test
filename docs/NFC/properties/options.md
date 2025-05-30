# Options Bytes Property Details (v001)

## Options_A Byte (Bitfield Representation)

The `Options_A` byte represents up to 8 individual options, with each bit in the byte corresponding to a specific feature. 


| Bit Position | Option                                 | Description                                  | Default Value  | Notes                   |
|--------------|----------------------------------------|----------------------------------------------|----------------|-------------------------|
| **0**  (LSB) | options_A_prevent_lamp_strike_on_power | Enable/Disable prevent_lamp_strike_on_power. | Disabled (`0`) |                         |
| **1**        | options_A_prevent_lamp_off_via_dmx     | Enable/Disable prevent_lamp_off_via_dmx.     | Disabled (`0`) |                         |
| **2**        | options_A_prevent_lamp_on_via_dmx      | Enable/Disable prevent_lamp_on_via_dmx.      | Disabled (`0`) |                         |
| **3**        | options_A_lamp_off_when_no_dmx         | Enable/Disbable lamp_off_when_no_dmx .       | Disabled (`0`) |                         |
| **4**        | options_A_lamp_strike_delay            | Enable/Disable lamp_strike_delay.            | Disabled (`0`) | use fixture delay value |
| **5**        | options_A_lamp_low_power_delay         | Enable/Disable Lamp Low Power Delay.         | Disabled (`0`) | use fixture delay value |
| **6**        | Reserved                               | Reserved for future use.                     | Disabled (`0`) |                         |
| **7**  (MSB) | Reserved                               | Reserved for future use.                     | Disabled (`0`) |                         |


### **Example:**
- `Options_A = 0b00001100` (12 in decimal, `0x0C` in hexadecimal) would represent:
  - Bit 0: **0** (prevent_lamp_strike_on_power disabled)
  - Bit 1: **0** (prevent_lamp_off_via_dmx disabled)
  - Bit 2: **1** (prevent_lamp_on_via_dmx enabled)
  - Bit 3: **1** (lamp_off_when_no_dmx enabled)
  - Bit 4: **0** (lamp_strike_delay disabled)
  - Bit 5: **0** (lamp_low_power_delay disabled)
  - Bit 6: **0** (reserved)
  - Bit 7: **0** (reserved)


---

## Options_B Byte (Bitfield Representation)


| Bit Position | Option                                 | Description                                 | Default Value  | Notes |
|--------------|----------------------------------------|---------------------------------------------|----------------|-------|
| **0**  (LSB) | options_B_pan_reverse                  | Enable/Disable pan_reverse.                 | Disabled (`0`) |       |
| **1**        | options_B_Tilt Reverse                 | Enable/Disable Tilt Reverse.                | Disabled (`0`) |       |
| **2**        | options_B_swap_pan_tilt                | Enable/Disable swap_pan_tilt                | Disabled (`0`) |       |
| **3**        | options_B_pan_2_reverse                | Enable/Disable pan_2_reverse                | Disabled (`0`) |       |
| **4**        | options_B_tilt_2_reverse               | Enable/Disable tilt_2_reverse               | Disabled (`0`) |       |
| **5**        | options_B_prevent_single_axis_movement | Enable/Disable prevent_single_axis_movement | Disabled (`0`) |       |
| **6**        | options_B_absolute_silence             | Enable/Disable absolute_silence             | Disabled (`0`) |       |
| **7**  (MSB) | Reserved                               | Reserved for future use.                    | Disabled (`0`) |       |

---

## Options_C Byte (Bitfield Representation)

| Bit Position | Option                   | Description                    | Default Value  | Notes |
|--------------|--------------------------|--------------------------------|----------------|-------|
| **0**  (LSB) | options_C_pan_blackout   | Enable/Disable pan_blackout.   | Disabled (`0`) |       |
| **1**        | options_C_tilt_blackout  | Enable/Disable tilt_blackout.  | Disabled (`0`) |       |
| **2**        | options_C_color_blackout | Enable/Disable color_blackout. | Disabled (`0`) |       |
| **3**        | options_C_gobo_blackout  | Enable/Disable gobo_blackout.  | Disabled (`0`) |       |
| **4**        | Reserved                 | Reserved for future use.       | Disabled (`0`) |       |
| **5**        | Reserved                 | Reserved for future use.       | Disabled (`0`) |       |
| **6**        | Reserved                 | Reserved for future use.       | Disabled (`0`) |       |
| **7**  (MSB) | Reserved                 | Reserved for future use.       | Disabled (`0`) |       |

---
## Options_D Byte (Bitfield Representation)


| Bit Position | Option                                | Description                                 | Default Value     | Notes |
|--------------|---------------------------------------|---------------------------------------------|-------------------|-------|
| **0**  (LSB) | options_D_min_zoom_focus              | Enable/Disable min_zoom_focus.              | Disabled (`0`)    |       |
| **1**        | options_D_zoom_reverse                | Enable/Disable zoom_reverse.                | Disabled (`0`)    |       |
| **2**        | options_D_smart_zoom                  | Enable/Disable smart_zoom.                  | Disabled (`0`)    |       |
| **3**        | options_D_merge_zoom                  | Enable/Disable merge_zoom.                  | Disabled (`0`)    |       |
| **4**        | options_D_prevent_zoom_via_dmx        | Enable/Disable prevent_zoom_via_dmx.        | Disabled (`0`)    |       |
| **5**        | options_D_prevent_zoom_reset_on_power | Enable/Disable prevent_zoom_reset_on_power  | Disabled (`0`)    |       |
| **6**        | Reserved                              | Reserved for future use.                    | Disabled (`0`)    |       |
| **7**  (MSB) | Reserved                              | Reserved for future use.                    | Disabled (`0`)    |       |


---
## Options_E Byte (Bitfield Representation)


| Bit Position | Option                            | Description                             | Default Value          | Notes            |
|--------------|-----------------------------------|-----------------------------------------|------------------------|------------------|
| **0**  (LSB) | options_E_totem_orientation_down  | Enable/Disable totem_orientation_down.  | Disabled = Up (`0`)    | Up or Down       |
| **1**        | options_E_gobo_rotator_power      | Enable/Disable gobo_rotator_power.      | Disabled (`0`)         |                  |
| **2**        | options_E_fog_fluid_sensor        | Enable/Disable fog_fluid_sensor.        | Disabled (`0`)         |                  |
| **3**        | options_E_follow_spot_mode        | Enable/Disable follow_spot_mode.        | Disabled (`0`)         |                  |
| **4**        | options_E_follow_spot_mode_head_2 | Enable/Disable follow_spot_mode_head_2  | Disabled = HEAD1 (`0`) | HEAD_1 or HEAD_2 |
| **5**        | options_E_defrost_fan             | Enable/Disable defrost_fan              | Disabled (`0`)         |                  |
| **6**        | options_E_color_mixing_mode_cmy   | Enable/Disable color_mixing_mode_cmy.   | Disabled = RGB (`0`)   | RGB or CMY       |
| **7**  (MSB) | options_E_red_shift               | Enable/Disable red_shift.               | Disabled (`0`)         |                  |


---
## Options_F Byte (Bitfield Representation)


| Bit Position | Option                  | Description                   | Default Value            | Notes               |
|--------------|-------------------------|-------------------------------|--------------------------|---------------------|
| **0**  (LSB) | options_F_wdmx_activate | Enable/Disable wDMX Module.   | Disabled (`0`)           |                     |
| **1**        | options_F_wdmx_transmit | Enable/Disable wDMX Transmit. | Disabled = Receive (`0`) | Receive or Transmit |
| **2**        | options_F_wdmx2dmx      | Enable/Disable wDMX2DMX.      | Disabled (`0`)           |                     |
| **3**        | options_F_ethernet2dmx  | Enable/Disable Ethernet2DMX.  | Disabled (`0`)           |                     |
| **4**        | options_F_ir_activation | Enable/Disable IR.            | Disabled (`0`)           |                     |
| **5**        | options_F_Reserved      | Reserved for future use.      | Disabled (`0`)           |                     |
| **6**        | options_F_Reserved      | Reserved for future use.      | Disabled (`0`)           |                     |
| **7**  (MSB) | options_F_master_slave  | Enable/Disable Master.        | Disabled = Slave (`0`)   | Slave or Master     |


---
## Options_G Byte (Bitfield Representation)

| Bit Position | Option                       | Description                       | Default Value          | Notes            |
|--------------|------------------------------|-----------------------------------|------------------------|------------------|
| **0**  (LSB) | options_G_screen_lock        | Enable/Disable Screen Lock.       | Disabled (`0`)         |                  |
| **1**        | options_G_touchscreen_lock   | Enable/Disable Touchscreen Lock.  | Disabled (`0`)         |                  |
| **2**        | options_G_data_loss_blackout | Enable/Disable Data Los Blackout. | Disabled = Hold  (`0`) | Hold or Blackout |
| **3**        | options_G_flash_on_dmx       | Enable/Disable Flash On DMX.      | Disabled (`0`)         |                  |
| **4**        | options_G_tv_reset_mode      | Enable/Disable TV Reset Mode.     | Disabled (`0`)         |                  |
| **5**        | Reserved                     | Reserved for future use.          | Disabled (`0`)         |                  |
| **6**        | Reserved                     | Reserved for future use.          | Disabled (`0`)         |                  |
| **7**  (MSB) | Reserved                     | Reserved for future use.          | Disabled (`0`)         |                  |


---
## Options_H Byte (Bitfield Representation)

| Bit Position | Option                           | Description                            | Default Value           | Notes           |
|--------------|----------------------------------|----------------------------------------|-------------------------|-----------------|
| **0**  (LSB) | options_H_output_setting         | Enable/Disable Output Setting.         | Disabled (`0`)          |                 |
| **1**        | options_H_standby                | Enable/Disable Standby.                | Disabled (`0`)          |                 |
| **2**        | options_H_foot_pedal_control     | Enable/Disable Foot-pedal Control.     | Disabled (`0`)          |                 |
| **3**        | options_H_foot_pedal_mode_common | Enable/Disable foot_pedal_mode_common. | Disabled = Bound  (`0`) | Bound or Common |
| **4**        | Reserved                         | Reserved for future use.               | Disabled (`0`)          |                 |
| **5**        | Reserved                         | Reserved for future use.               | Disabled (`0`)          |                 |
| **6**        | Reserved                         | Reserved for future use.               | Disabled (`0`)          |                 |
| **7**  (MSB) | Reserved                         | Reserved for future use.               | Disabled (`0`)          |                 |

---
## Options_I Byte (Bitfield Representation)

| Bit Position | Option                 | Description                            | Default Value           | Notes           |
|--------------|------------------------|----------------------------------------|-------------------------|-----------------|
| **0** (LSB)  | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |
| **1**        | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |
| **2**        | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |
| **3**        | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |
| **4**        | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |
| **5**        | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |
| **6**        | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |
| **7** (MSB)  | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |


---
## Options_J Byte (Bitfield Representation)

| Bit Position | Option                 | Description                            | Default Value           | Notes           |
|--------------|------------------------|----------------------------------------|-------------------------|-----------------|
| **0** (LSB)  | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |
| **1**        | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |
| **2**        | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |
| **3**        | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |
| **4**        | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |
| **5**        | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |
| **6**        | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |
| **7** (MSB)  | Reserved               | Reserved for future use.               | Disabled (`0`)          |                 |

### **Version History:**
- **v001**: Initial version.
