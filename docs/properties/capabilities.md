# Capabilities Property Details (v002)

The `Capabilities` byte (or multiple bytes) represents the features that are available on the device. Each bit or group
of bits in these bytes corresponds to a specific feature or features. By setting these bits, the device can indicate
to the App which features are available and can be used. The `Activated Options` column in the tables below lists the
options that will become available for each capability.  

All other `Activated Options`
will be represented by a minimum of 1 byte.

Some capabilities such as `Fan Speed` may have multiple versions, each with its own set of options and ranges. In such 
cases only one of the versions should be used, and the corresponding bit should be activated. If multiple versions of the 
same capability flag are used simultaneously, the App will reject the configuration during the commissioning stage.

In some instances, a `custom version` may be necessary to accommodate a specific feature or range that is not covered by
the standard versions. In such cases, the `custom version` should be used, and the corresponding bit should be activated. 
A `custom version`should only be used after careful discussion from all parties involved.



## Capabilities_A Byte (Bitfield Representation)

| Bit Position | Capability                          | Activated Attribute/Options                                                    | Default Value           | Data Type  | Notes                      |
|--------------|-------------------------------------|--------------------------------------------------------------------------------|-------------------------|------------|----------------------------|
| **0**  (LSB) | capabilities_A_pan_tilt_reverse     | options_B_pan_reverse, options_B_tilt_reverse                                  | Not Available (`0`)     | Boolean    | Set to `1` if available.   |
| **1**        | capabilities_A_pan_tilt_2_reverse   | options_B_pan_2_reverse, options_B_tilt_2_reverse                              | Not Available (`0`)     | Boolean    | Reserved for future use.   |
| **2**        | capabilities_A_swap_pan_tilt        | options_B_swap_pan_tilt                                                        | Not Available (`0`)     | Boolean    | Reserved for future use.   |
| **3**        | capabilities_A_pan_range_v1         | pan_range_v1                                                                   | Not Available (`0`)     | Boolean    | Set to `1` if available.   |
| **4**        | Reserved (for v2)                   | Reserved                                                                       | Not Available (`0`)     | N/A        | Reserved for future use.   |
| **5**        | capabilities_A_tilt_range_v1        | tilt_range_v1                                                                  | Not Available (`0`)     | Boolean    | Set to `1` if available.   |
| **6**        | Reserved (for v2)                   | Reserved                                                                       | Not Available (`0`)     | N/A        | Reserved for future use.   |
| **7**  (MSB) | capabilities_A_single_axis_movement | single_axis_movement_range {shared1_A}, options_B_prevent_single_axis_movement | Not Available (`0`)     | Boolean    | Set to `1` if available.   |

---
## Capabilities_B Byte (Bitfield Representation)

| Bit Position | Capability                      | Activated Attributes/Options                           | Default Value         | Data Type | Notes                      |
|--------------|---------------------------------|--------------------------------------------------------|-----------------------|-----------|----------------------------|
| **0**  (LSB) | capabilities_B_aux              | start_address_aux, personality_aux, control_mode_aux   | Not Available (`0`)   | Boolean   | Set to `1` if available.   |
| **1**        | capabilities_B_fan_speed_v1     | fan_speed_v1                                           | Not Available (`0`)   | Boolean   | Set to `1` if available.   |
| **2**        | capabilities_B_fan_speed_v2     | fan_speed_v2                                           | Not Available (`0`)   | Boolean   | Set to `1` if available.   |
| **3**        | capabilities_B_fan_speed_v3     | fan_speed_v3                                           | Not Available (`0`)   | Boolean   | Set to `1` if available.   |
| **4**        | capabilities_B_fan_speed_v4     | fan_speed_v4                                           | Not Available (`0`)   | Boolean   | Set to `1` if available.   |
| **5**        | Reserved (for v5)               | Reserved                                               | Not Available (`0`)   | N/A       | Reserved for future use.   |
| **6**        | Reserved (for v6)               | Reserved                                               | Not Available (`0`)   | N/A       | Reserved for future use.   |
| **7**  (MSB) | capabilities_B_absolute_silence | options_B_absolute_silence                             | Not Available (`0`)   | Boolean   | Set to `1` if available.   |


---
## Capabilities_C Byte (Bitfield Representation)

| Bit Position | Capability                                   | Activated Attributes/Options  | Default Value        | Data Type | Notes                       |
|--------------|----------------------------------------------|-------------------------------|----------------------|-----------|-----------------------------|
| **0**  (LSB) | capabilities_C_display_level                 | display_level                 | Not Available (`0`)  | Boolean   | Set to `1` if available.    |
| **1**        | capabilities_C_display_invert_v1             | display_invert_v1             | Not Available (`0`)  | Boolean   | Set to `1` if available.    |
| **2**        | capabilities_C_display_invert_v2             | display_invert_v2             | Not Available (`0`)  | Boolean   | Set to `1` if available.    |
| **3**        | capabilities_C_display_shutoff_v1            | display_shutoff_v1            | Not Available (`0`)  | Boolean   | Set to `1` if available.    |
| **4**        | capabilities_C_screen_lock                   | options_G_screen_lock         | Not Available (`0`)  | Boolean   | Set to `1` if available.    |
| **5**        | capabilities_C_touchscreen_Lock              | options_G_touchscreen_lock    | Not Available (`0`)  | Boolean   | Set to `1` if available.    |
| **6**        | capabilities_C_white_calibration_v1          | white_calibration_v1          | Not Available (`0`)  | Boolean   | Set to `1` if available.    |
| **7**  (MSB) | capabilities_C_white_calibration_v2 (custom) | white_calibration_v2 (custom) | Not Available (`0`)  | Boolean   | Set to `1` if available.    |



---
## Capabilities_D Byte (Bitfield Representation)

| Bit Position | Capability                        | Activated Attributes/Options | Default Value            | Data Type | Notes                      |
|--------------|-----------------------------------|------------------------------|--------------------------|-----------|----------------------------|
| **0**  (LSB) | capabilities_D_dimmer_curve_v1    | dimmer_curve_v1              | Not Available (`0`)      | Boolean   | Set to `1` if available.   |
| **1**        | capabilities_D_dimmer_curve_v2    | dimmer_curve_v2              | Not Available (`0`)      | Boolean   | Set to `1` if available.   |
| **2**        | Reserved (for v3)                 | Reserved                     | Not Available (`0`)      | N/A       | Reserved for future use.   |
| **3**        | Reserved (for v4)                 | Reserved                     | Not Available (`0`)      | N/A       | Reserved for future use.   |
| **4**        | capabilities_D_dimmer_response_v1 | dimmer_response_v1           | Not Available (`0`)      | Boolean   | Set to `1` if available.   |
| **5**        | capabilities_D_dimmer_response_v2 | dimmer_response_v2           | Not Available (`0`)      | Boolean   | Set to `1` if available.   |
| **6**        | capabilities_D_dimmer_response_v3 | dimmer_response v3           | Not Available (`0`)      | Boolean   | Set to `1` if available.   |
| **7**  (MSB) | Reserved (for v4)                 | Reserved                     | Not Available (`0`)      | N/A       | Reserved for future use.   |



---
## Capabilities_E Byte (Bitfield Representation)

| Bit Position | Capability                             | Activated Attributes/Options      | Default Value          | Data Type | Notes                        |
|--------------|----------------------------------------|-----------------------------------|------------------------|-----------|------------------------------|
| **0**  (LSB) | capabilities_E_led_power               | led_power  {shared1_B}            | Not Available (`0`)    | Boolean   | Set to `1` if available.     |
| **1**        | capabilities_E_language                | language                          | Not Available (`0`)    | Boolean   | Set to `1` if available.     |
| **2**        | capabilities_E_data_loss               | options_G_data_loss_blackout      | Not Available (`0`)    | Boolean   | Set to `1` if available.     |
| **3**        | capabilities_E_cell_order_v1           | cell_order_v1{shared1_C}          | Not Available (`0`)    | Boolean   | Set to `1` if available.     |
| **4**        | capabilities_E_cell_order_v2  (custom) | cell_order_v2 (custom){shared1_C} | Not Available (`0`)    | Boolean   | Set to `1` if available.     |
| **5**        | capabilities_E_color_mixing_mode       | options_G_color_mixing_mode_cmy   | Not Available (`0`)    | Boolean   | Set to `1` if available.     |
| **6**        | Reserved                               | Reserved                          | Not Available (`0`)    | N/A       | Reserved for future use.     |
| **7**  (MSB) | Reserved                               | Reserved                          | Not Available (`0`)    | N/A       | Reserved for future use.     |


---
## Capabilities_F Byte (Bitfield Representation)
| Bit Position | Capability                   | Activated Attributes/Options      | Default Value        | Data Type | Notes                     |
|--------------|------------------------------|-----------------------------------|----------------------|-----------|---------------------------|
| **0**  (LSB) | capabilities_F_network       | ip_mode, ip_address, subnet_mask  | Not Available (`0`)  | Boolean   | Set to `1` if available.  |
| **1**        | capabilities_F_ethernet_main | universe_main                     | Not Available (`0`)  | Boolean   | Set to `1` if available.  |
| **2**        | capabilities_F_ethernet_aux  | universe_aux                      | Not Available (`0`)  | Boolean   | Set to `1` if available.  |
| **3**        | capabilities_F_ethernet2dmx  | options_F_ethernet2dmx            | Not Available (`0`)  | Boolean   | Set to `1` if available.  |
| **4**        | capabilities_F_network_misc  | gateway_address                   | Not Available (`0`)  | Boolean   | Set to `1` if available.  |
| **5**        | Reserved                     | Reserved                          | Not Available (`0`)  | N/A       | Reserved for future use.  |
| **6**        | Reserved                     | Reserved                          | Not Available (`0`)  | N/A       | Reserved for future use.  |
| **7**  (MSB) | Reserved                     | Reserved                          | Not Available (`0`)  | N/A       | Reserved for future use.  |


---
## Capabilities_G Byte (Bitfield Representation)
| Bit Position | Capability               | Activated Attributes/Options   | Default Value        | Data Type | Notes                    |
|--------------|--------------------------|--------------------------------|----------------------|-----------|--------------------------|
| **0**  (LSB) | capabilities_G_ils       | ils_channel                    | Not Available (`0`)  | Boolean   | Set to `1` if available. |
| **1**        | capabilities_G_rf        | rf_channel, actions_B_rf_bind  | Not Available (`0`)  | Boolean   | Set to `1` if available. |
| **2**        | capabilities_G_dfi       | dfi_channel, dfi_mode          | Not Available (`0`)  | Boolean   | Set to `1` if available. |
| **3**        | Reserved                 | Reserved                       | Not Available (`0`)  | Boolean   | Reserved for future use. |
| **4**        | capabilities_G_red_shift | options_E_red_shift            | Not Available (`0`)  | N/A       | Set to `1` if available  |
| **5**        | Reserved                 | Reserved                       | Not Available (`0`)  | N/A       | Reserved for future use. |
| **6**        | Reserved                 | Reserved                       | Not Available (`0`)  | N/A       | Reserved for future use. |
| **7**  (MSB) | Reserved                 | Reserved                       | Not Available (`0`)  | N/A       | Reserved for future use. |


---
## Capabilities_H Byte (Bitfield Representation)
| Bit Position | Capability                       | Activated Attributes/Options                                                                                                                                                                               | Default Value        | Data Type | Notes                    |
|--------------|----------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------|-----------|--------------------------|
| **0**  (LSB) | capabilities_H_pan_tilt_blackout | options_C_pan_blackout, options_C_tilt_blackout                                                                                                                                                            | Not Available (`0`)  | Boolean   | Set to `1` if available. |
| **1**        | capabilities_H_color_blackout    | options_C_color_blackout                                                                                                                                                                                   | Not Available (`0`)  | Boolean   | Set to `1` if available. |
| **2**        | capabilities_H_gobo_blackout     | options_C_gobo_blackout                                                                                                                                                                                    | Not Available (`0`)  | Boolean   | Set to `1` if available. |
| **3**        | capabilities_H_Reserved          | Reserved                                                                                                                                                                                                   | Not Available (`0`)  | Boolean   | Reserved for future use. |
| **4**        | capabilities_H_standby           | options_H_standby                                                                                                                                                                                          | Not Available (`0`)  | Boolean   | Set to `1` if available  |
| **5**        | capabilities_H_lamp_options      | options_A_prevent_power_on_lamp_strike, options_A_prevent_lamp_off_via_dmx, options_A_prevent_lamp_on_via_dmx, options_A_lamp_off_when_no_dmx, options_A_lamp_strike_delay, options_A_lamp_low_power_delay | Not Available (`0`)  | Boolean   | Reserved for future use. |
| **6**        | capabilities_H_output_setting    | options_H_output_setting                                                                                                                                                                                   | Not Available (`0`)  | Boolean   | Reserved for future use. |
| **7**  (MSB) | capabilities_H_defrost_fan       | options_E_defrost_fan                                                                                                                                                                                      | Not Available (`0`)  | Boolean   | Reserved for future use. |


---
## Capabilities_I Byte (Bitfield Representation)
| Bit Position | Capability                  | Activated Attributes/Options                                                              | Default Value         | Data Type | Notes                    |
|--------------|-----------------------------|-------------------------------------------------------------------------------------------|-----------------------|-----------|--------------------------|
| **0**  (LSB) | capabilities_I_totem        | options_E_totem_orientation_down                                                          | Not Available (`0`)   | Boolean   | Set to `1` if available. |
| **1**        | capabilities_I_foot_pedal   | options_H_foot_pedal_control, options_H_foot_pedal_mode_common, actions_B_foot_pedal_bind | Not Available (`0`)   | Boolean   | Set to `1` if available. |
| **2**        | capabilities_I_ir           | options_F_ir_activation                                                                   | Not Available (`0`)   | Boolean   | Set to `1` if available. |
| **3**        | Reserved                    | Reserved                                                                                  | Not Available (`0`)   | Boolean   | Reserved for future use. |
| **4**        | capabilities_I_flash_on_dmx | options_G_flash_on_dmx                                                                    | Not Available (`0`)   | Boolean   | Set to `1` if available  |
| **5**        | capabilities_I_gobo_rotator | gobo_rotation_position {shared1_D}, options_E_gobo_rotator_power                          | Not Available (`0`)   | Boolean   | Reserved for future use. |
| **6**        | Reserved                    | Reserved                                                                                  | Not Available (`0`)   | N/A       | Reserved for future use. |
| **7**  (MSB) | Reserved                    | Reserved                                                                                  | Not Available (`0`)   | N/A       | Reserved for future use. |


---
## Capabilities_J Byte (Bitfield Representation)
| Bit Position | Capability                           | Activated Attributes/Options    | Default Value       | Data Type | Notes                    |
|--------------|--------------------------------------|---------------------------------|---------------------|-----------|--------------------------|
| **0**  (LSB) | capabilities_J_factory_reset         | actions_A_factory_reset         | Not Available (`0`) | Boolean   | Set to `1` if available. |
| **1**        | capabilities_J_pan_tilt_reset        | actions_A_pan_tilt_reset        | Not Available (`0`) | Boolean   | Set to `1` if available. |
| **2**        | capabilities_J_iris_prism_reset      | actions_A_iris_prism_reset      | Not Available (`0`) | Boolean   | Set to `1` if available. |
| **3**        | capabilities_J_color_cmy_blade_reset | actions_A_color_cmy_blade_reset | Not Available (`0`) | Boolean   | Set to `1` if available  |
| **4**        | capabilities_J_shutter_reset         | actions_A_shutter_reset         | Not Available (`0`) | Boolean   | Set to `1` if available  |
| **5**        | capabilities_J_gobo_reset            | actions_A_gobo_reset            | Not Available (`0`) | Boolean   | Set to `1` if available  |
| **6**        | capabilities_J_frost_reset           | actions_A_frost_reset           | Not Available (`0`) | Boolean   | Set to `1` if available  |
| **7**  (MSB) | capabilities_J_animation_reset       | actions_B_animation_reset       | Not Available (`0`) | Boolean   | Set to `1` if available  |


---
## Capabilities_K Byte (Bitfield Representation)
| Bit Position | Capability                        | Activated Attributes/Options          | Default Value        | Data Type | Notes                    |
|--------------|-----------------------------------|---------------------------------------|----------------------|-----------|--------------------------|
| **0**  (LSB) | capabilities_K_zoom_reset         | actions_B_zoom_reset                  | Not Available (`0`)  | Boolean   | Set to `1` if available. |
| **1**        | capabilities_K_motors_reset       | actions_B_motors_reset                | Not Available (`0`)  | Boolean   | Set to `1` if available. |
| **2**        | capabilities_K_tv_reset_mode      | options_G_tv_reset_mode               | Not Available (`0`)  | Boolean   | Set to `1` if available. |
| **3**        | capabilities_K_prevent_zoom_reset | options_D_prevent_zoom_reset_on_power | Not Available (`0`)  | Boolean   | Set to `1` if available  |
| **4**        | Reserved                          | Reserved                              | Not Available (`0`)  | N/A       | Reserved for future use. |
| **5**        | Reserved                          | Reserved                              | Not Available (`0`)  | N/A       | Reserved for future use. |
| **6**        | Reserved                          | Reserved                              | Not Available (`0`)  | N/A       | Reserved for future use. |
| **7**  (MSB) | Reserved                          | Reserved                              | Not Available (`0`)  | N/A       | Reserved for future use. |


---
## Capabilities_L Byte (Bitfield Representation)
| Bit Position | Capability                                  | Activated Attributes/Options                                                           | Default Value        | Data Type | Notes                    |
|--------------|---------------------------------------------|----------------------------------------------------------------------------------------|----------------------|-----------|--------------------------|
| **0**  (LSB) | capabilities_L_wireless_dmx                 | options_F_wireless_dmx_activate, options_F_wireless2dmx, actions_A_wireless_reset_link | Not Available (`0`)  | Boolean   | Set to `1` if available. |
| **1**        | capabilities_L_wireless_dmx_mode            | options_F_wdmx_transmit                                                                | Not Available (`0`)  | Boolean   | Set to `1` if available. |
| **2**        | capabilities_L_battery_run_time_v1          | battery_run_time_v1 {shared1_E}                                                        | Not Available (`0`)  | Boolean   | Set to `1` if available. |
| **3**        | capabilities_L_battery_run_time_v2 (Custom) | battery_run_time_v2 (Custom)                                                           | Not Available (`0`)  | Boolean   | Set to `1` if available  |
| **4**        | Reserved                                    | Reserved                                                                               | Not Available (`0`)  | N/A       | Reserved for future use. |
| **5**        | capabilities_L_line_voltage_power_loss      | line_voltage_power_loss {shared1_F}                                                    | Not Available (`0`)  | N/A       | Reserved for future use. |
| **6**        | Reserved                                    | Reserved                                                                               | Not Available (`0`)  | N/A       | Reserved for future use. |
| **7**  (MSB) | Reserved                                    | Reserved                                                                               | Not Available (`0`)  | N/A       | Reserved for future use. |

---
## Capabilities_M Byte (Bitfield Representation)
| Bit Position | Capability                  | Activated Attributes/Options                                                  | Default Value        | Data Type | Notes                      |
|--------------|-----------------------------|-------------------------------------------------------------------------------|----------------------|-----------|----------------------------|
| **0**  (LSB) | capabilities_M_fog_timing   | fog_interval {shared2_B}, fog_duration {shared2_A}                            | Not Available (`0`)  | Boolean   | Set to `1` if available.   |
| **1**        | Reserved                    | Reserved                                                                      | Not Available (`0`)  | N/A       | Reserved for future use.   |
| **2**        | capabilities_M_fog_settings | fog_volume {shared1_B}, fog_fan_speed {shared1_A}, options_Z_fog_fluid_sensor | Not Available (`0`)  | Boolean   | Set to `1` if available.   |
| **3**        | Reserved                    | Reserved                                                                      | Not Available (`0`)  | N/A       | Reserved for future use.   |
| **4**        | Reserved                    | Reserved                                                                      | Not Available (`0`)  | N/A       | Reserved for future use.   |
| **5**        | Reserved                    | Reserved                                                                      | Not Available (`0`)  | N/A       | Reserved for future use.   |
| **6**        | Reserved                    | Reserved                                                                      | Not Available (`0`)  | N/A       | Reserved for future use.   |
| **7**  (MSB) | Reserved                    | Reserved                                                                      | Not Available (`0`)  | N/A       | Reserved for future use.   |

---

## Capabilities_N Byte (Bitfield Representation)

| Bit Position | Capability                      | Activated Attributes/Options                             | Default Value       | Data Type | Notes                      |
|--------------|---------------------------------|----------------------------------------------------------|---------------------|-----------|----------------------------|
| **0**  (LSB) | capabilities_N_follow_spot_mode | options_E_follow_spot_mode, options_E_follow_spot_head_2 | Not Available (`0`) | Boolean   | Set to `1` if available.   |
| **1**        | Reserved                        | Reserved                                                 | Not Available (`0`) | N/A       | Reserved for future use.   |
| **2**        | Reserved                        | Reserved                                                 | Not Available (`0`) | N/A       | Reserved for future use.   |
| **3**        | Reserved                        | Reserved                                                 | Not Available (`0`) | N/A       | Reserved for future use.   |
| **4**        | Reserved                        | Reserved                                                 | Not Available (`0`) | N/A       | Reserved for future use.   |
| **5**        | Reserved                        | Reserved                                                 | Not Available (`0`) | N/A       | Reserved for future use.   |
| **6**        | Reserved                        | Reserved                                                 | Not Available (`0`) | N/A       | Reserved for future use.   |
| **7**  (MSB) | Reserved                        | Reserved                                                 | Not Available (`0`) | N/A       | Reserved for future use.   |


---
## Capabilities_O Byte (Bitfield Representation)
| Bit Position | Capability                   | Activated Attributes/Options | Default Value       | Data Type | Notes                    |
|--------------|------------------------------|------------------------------|---------------------|-----------|--------------------------|
| **0**  (LSB) | capabilities_O_artnet_main   | artnet_main                  | Not Available (`0`) | Boolean   | Set to `1` if available. |
| **1**        | capabilities_O_wdmx_main     | wdmx_main                    | Not Available (`0`) | Boolean   | Set to `1` if available. |
| **2**        | capabilities_O_sacn_main     | sacn_main                    | Not Available (`0`) | Boolean   | Set to `1` if available. |
| **3**        | capabilities_O_klingnet_main | klingnet_main                | Not Available (`0`) | Boolean   | Set to `1` if available  |
| **4**        | capabilities_O_artnet_aux    | artnet_aux                   | Not Available (`0`) | Boolean   | Set to `1` if available  |
| **5**        | capabilities_O_sacn_aux      | sacn_aux                     | Not Available (`0`) | Boolean   | Set to `1` if available  |
| **6**        | capabilities_O_klingnet_aux  | klingnet_aux                 | Not Available (`0`) | Boolean   | Set to `1` if available  |
| **7**  (MSB) | Reserved                     | Reserved                     | Not Available (`0`) | Boolean   | Set to `1` if available  |

---
## Capabilities_P Byte (Bitfield Representation)

| Bit Position | Capability                  | Activated Attributes/Options | Default Value       | Data Type | Notes                       |
|--------------|-----------------------------|------------------------------|---------------------|-----------|-----------------------------|
| **0**  (LSB) | capabilities_P_master_slave | options_F_master_slave       | Not Available (`0`) | N/A       | Reserved for future use.    |
| **1**        | Reserved                    | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **2**        | Reserved                    | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **3**        | Reserved                    | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **4**        | Reserved                    | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **5**        | Reserved                    | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **6**        | Reserved                    | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **7**  (MSB) | Reserved                    | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |

---
## Capabilities_Q Byte (Bitfield Representation)
| Bit Position | Capability                          | Activated Attributes/Options   | Default Value       | Data Type | Notes                    |
|--------------|-------------------------------------|--------------------------------|---------------------|-----------|--------------------------|
| **0**  (LSB) | capabilities_Q_zoom_offset          | zoom_offset {shared1_H)        | Not Available (`0`) | Boolean   | Set to `1` if available. |
| **1**        | capabilities_Q_zoom_range           | zoom_range {shared1_G}         | Not Available (`0`) | Boolean   | Set to `1` if available. |
| **2**        | capabilities_Q_min_zoom_focus       | options_D_min_zoom_focus       | Not Available (`0`) | Boolean   | Set to `1` if available. |
| **3**        | capabilities_Q_zoom_reverse         | options_D_zoom_reverse         | Not Available (`0`) | Boolean   | Set to `1` if available  |
| **4**        | capabilities_Q_smart_zoom           | options_D_smart_zoom           | Not Available (`0`) | Boolean   | Set to `1` if available  |
| **5**        | capabilities_Q_merge_zoom           | options_D_merge_zoom           | Not Available (`0`) | Boolean   | Set to `1` if available  |
| **6**        | capabilities_Q_zoom_level           | zoom_level                     | Not Available (`0`) | Boolean   | Set to `1` if available  |
| **7**  (MSB) | capabilities_Q_disable_zoom_via_dmx | options_D_prevent_zoom_via_dmx | Not Available (`0`) | Boolean   | Set to `1` if available  |

---

## Capabilities_R Byte (Bitfield Representation)

| Bit Position | Capability              | Activated Attributes/Options | Default Value       | Data Type  | Notes                     |
|--------------|-------------------------|------------------------------|---------------------|------------|---------------------------|
| **0**  (LSB) | capabilities_R_pwm_600  | PWM Option value 600Hz       | Not Available (`0`) | Boolean    | Set to `1` if available.  |
| **1**        | capabilities_R_pwm_1k   | PWM Option value 1kHz        | Not Available (`0`) | Boolean    | Set to `1` if available.  |
| **2**        | capabilities_R_pwm_1.2k | PWM Option value 1.2kHz      | Not Available (`0`) | Boolean    | Set to `1` if available.  |
| **3**        | capabilities_R_pwm_2k   | PWM Option value 2kHz        | Not Available (`0`) | Boolean    | Set to `1` if available.  |
| **4**        | capabilities_R_pwm_3k   | PWM Option value 3kHz        | Not Available (`0`) | Boolean    | Set to `1` if available.  |
| **5**        | capabilities_R_pwm_4k   | PWM Option value 4kHz        | Not Available (`0`) | Boolean    | Set to `1` if available.  |
| **6**        | capabilities_R_pwm_6k   | PWM Option value 6kHz        | Not Available (`0`) | Boolean    | Set to `1` if available.  |
| **7**  (MSB) | capabilities_R_pwm_15k  | PWM Option value 15kHz       | Not Available (`0`) | Boolean    | Set to `1` if available.  |


---
## Capabilities_S Byte (Bitfield Representation)
| Bit Position | Capability             | Activated Attributes/Options | Default Value       | Data Type | Notes                      |
|--------------|------------------------|------------------------------|---------------------|-----------|----------------------------|
| **0**  (LSB) | capabilities_R_pwm_25k | PWM Option value 25kHz       | Not Available (`0`) | Boolean   | Set to `1` if available.   |
| **1**        | Reserved               | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.   |
| **2**        | Reserved               | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.   |
| **3**        | Reserved               | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.   |
| **4**        | Reserved               | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.   |
| **5**        | Reserved               | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.   |
| **6**        | Reserved               | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.   |
| **7**  (MSB) | Reserved               | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.   |

---

## Capabilities_T Byte (Bitfield Representation)

| Bit Position | Capability                  | Activated Attributes/Options                                                                                          | Default Value       | Data Type | Notes                                                                                                        |
|--------------|-----------------------------|-----------------------------------------------------------------------------------------------------------------------|---------------------|-----------|--------------------------------------------------------------------------------------------------------------|
| **0**  (LSB) | capabilities_T_rtc_timing   | N/A                                                                                                                   | Not Available (`0`) | N/A       | Set to `1` if available. If Unavailable any timing is a timecode incrementing from 0 when first commissioned |
| **1**        | capabilities_T_power_timing | time_last_powered_on, time_last_powered_off, device_hours, power_cycles, (* trip_device_hours), (* trip_power_cycles) | Not Available (`0`) | N/A       | Set to `1` if available. (* available if Trip Timing)                                                        |
| **2**        | capabilities_T_lamp_timing  | time_last_lamped_on, time_last_lamped_off, lamp_hours,  (* trip_lamp_hours),                                          | Not Available (`0`) | N/A       | Set to `1` if available. (* available if Trip Timing)                                                        |
| **3**        | capabilities_T_error_count  | device_error_count, trip_error_count                                                                                  | Not Available (`0`) | N/A       | Set to `1` if available.                                                                                     |
| **4**        | Reserved                    | Reserved                                                                                                              | Not Available (`0`) | N/A       | Reserved for future use.                                                                                     |
| **5**        | Reserved                    | Reserved                                                                                                              | Not Available (`0`) | N/A       | Reserved for future use.                                                                                     |
| **6**        | Reserved                    | Reserved                                                                                                              | Not Available (`0`) | N/A       | Reserved for future use.                                                                                     |
| **7**  (MSB) | Reserved                    | Reserved                                                                                                              | Not Available (`0`) | N/A       | Reserved for future use.                                                                                     |

---

## Capabilities_U Byte (Bitfield Representation)

| Bit Position | Capability               | Activated Attributes/Options | Default Value       | Data Type | Notes                       |
|--------------|--------------------------|------------------------------|---------------------|-----------|-----------------------------|
| **0**  (LSB) | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **1**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **2**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **3**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **4**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **5**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **6**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **7**  (MSB) | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |

---

## Capabilities_V Byte (Bitfield Representation)

| Bit Position | Capability               | Activated Attributes/Options | Default Value       | Data Type | Notes                       |
|--------------|--------------------------|------------------------------|---------------------|-----------|-----------------------------|
| **0**  (LSB) | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **1**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **2**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **3**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **4**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **5**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **6**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **7**  (MSB) | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |

---

## Capabilities_W Byte (Bitfield Representation)

| Bit Position | Capability               | Activated Attributes/Options | Default Value       | Data Type | Notes                       |
|--------------|--------------------------|------------------------------|---------------------|-----------|-----------------------------|
| **0**  (LSB) | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **1**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **2**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **3**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **4**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **5**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **6**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **7**  (MSB) | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |

---

## Capabilities_X Byte (Bitfield Representation)

| Bit Position | Capability               | Activated Attributes/Options | Default Value       | Data Type | Notes                       |
|--------------|--------------------------|------------------------------|---------------------|-----------|-----------------------------|
| **0**  (LSB) | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **1**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **2**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **3**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **4**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **5**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **6**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **7**  (MSB) | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |

---

## Capabilities_Y Byte (Bitfield Representation)

| Bit Position | Capability               | Activated Attributes/Options | Default Value       | Data Type | Notes                       |
|--------------|--------------------------|------------------------------|---------------------|-----------|-----------------------------|
| **0**  (LSB) | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **1**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **2**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **3**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **4**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **5**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **6**        | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |
| **7**  (MSB) | Reserved                 | Reserved                     | Not Available (`0`) | N/A       | Reserved for future use.    |

---

## Capabilities_Z Byte (Bitfield Representation)

| Bit Position | Capability                        | Activated Attributes/Options | Default Value         | Data Type | Notes                       |
|--------------|-----------------------------------|------------------------------|-----------------------|-----------|-----------------------------|
| **0**  (LSB) | Reserved                          | Reserved                     | Not Available (`0`)   | N/A       | Reserved for future use.    |
| **1**        | Reserved                          | Reserved                     | Not Available (`0`)   | N/A       | Reserved for future use.    |
| **2**        | Reserved                          | Reserved                     | Not Available (`0`)   | N/A       | Reserved for future use.    |
| **3**        | Reserved                          | Reserved                     | Not Available (`0`)   | N/A       | Reserved for future use.    |
| **4**        | Reserved                          | Reserved                     | Not Available (`0`)   | N/A       | Reserved for future use.    |
| **5**        | Reserved                          | Reserved                     | Not Available (`0`)   | N/A       | Reserved for future use.    |
| **6**        | Reserved                          | Reserved                     | Not Available (`0`)   | N/A       | Reserved for future use.    |
| **7**  (MSB) | capabilities_C_display_shutoff_v2 | display_shutoff_v2           | Not Available (`0`)   | Boolean   | Set to `1` if available.    |

---




### **Default State for Capabilities Bytes:**
- If a capability byte is not set or is invalid, it defaults to `0x00`, meaning all capabilities are assumed to be unavailable or not supported.

### **Notes:**
- The `Capabilities` bytes should be carefully set to reflect the actual hardware and software features present on the device.
- For features that require more than a simple boolean (like IP configuration), additional bytes or a different field should be used to store the actual configuration, while the `Capabilities` byte simply indicates the presence or absence of the feature.

### **Version History:**
- **v001**: Initial version.
- **v002**: 
  - i) Modified `Capabilities_R` & `Capabilities_S` bytes to allow multiple selection of specific pwm frequencies instead of list selection.
  - ii) Modified `Capabilities_D` to include `capabilities_D_dimmer_curve_v2`.
  - iii) Modified `Capabilities_Z` to include `capabilities_Z_display_shutoff_v2`.
  - iv) Modified `Capabilities_F` to include `capabilities_F_network_misc` to allow for `Gateway Address` optional configuration.
