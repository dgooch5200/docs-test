// Chauvet NFC handler
//
// Defines the layout of the sections of the Chauvet NFC data and constants required for managing the data


#ifndef CHAUVET_NFC_DEMO_H
#define CHAUVET_NFC_DEMO_H

#include "stdint.h"

// The Chauvet NFC memory is split into records:
//
// Capability Container 	Capability Container settings (8 bytes)
// TLV Header 				TLV Header indicating the start of the NDEF message (4 bytes)
// APP URL Record 			Application URL record (url, 108 bytes)
// Fixture Record 			Fixture information as defined in urn:nfc:ext:chauvet.com:fixtXXX
// Logging Record 			Logging data as defined in urn:nfc:ext:chauvet.com:loggXXX
// Rental Record 			Rental information as defined in urn:nfc:ext:chauvet.com:rentXXX
// Config Record 			Configuration settings as defined in urn:nfc:ext:chauvet.com:confXXX
// TLV Terminator 			TLV End indicator for NDEF message (4 bytes)


// The Fixture record of the NFC memory
// The Chauvet NFC App creates the NDEF record which contains this data
// Once created it is read only on the NFC side
// It is written by the fixture when the record is first detected, and when fixture status changes

typedef struct NFCFixtureData {
	uint8_t fixt_status;
	uint8_t reserved_1[3];
    uint16_t ndef_structure_type;
    uint16_t ndef_structure_version;
    uint8_t device_uid[16];
    uint8_t rdm_uid[6];
    uint8_t reserved_2[2];

    char device_serial_number[32];
    uint8_t device_model_id[2];
    uint8_t product_category[2];
    char manufacturer_label[32];

    uint8_t mac_address[6];
    uint8_t reserved_3[2];
    char device_model_description[32];                         // Same as Device Model Description reported via RDM

    uint32_t software_version;
    char software_version_label[32];
    uint32_t boot_software_version;
    char personality_description[32];                  // Same as Personality Mode Description reported via RDM for the current mode

    uint32_t lamp_strikes;
    uint32_t device_hours;
    uint32_t lamp_hours;
    uint32_t device_power_cycles;
    uint32_t device_error_count;
    uint32_t device_status;

    uint32_t time_last_powered_on;
    uint32_t time_last_powered_off;
    uint32_t time_last_lamped_on;
    uint32_t time_last_lamped_off;

    uint8_t battery_level;
    uint8_t reserved_4[3];

    uint32_t trip_lamp_strikes;
    uint32_t trip_device_hours;
    uint32_t trip_lamp_hours;
    uint32_t trip_power_cycles;
    uint32_t trip_error_count;

    uint8_t reserved_5[12];

    uint8_t capabilities_A;
    uint8_t capabilities_B;
    uint8_t capabilities_C;
    uint8_t capabilities_D;
    uint8_t capabilities_E;
    uint8_t capabilities_F;
    uint8_t capabilities_G;
    uint8_t capabilities_H;
    uint8_t capabilities_I;
    uint8_t capabilities_J;
    uint8_t capabilities_K;
    uint8_t capabilities_L;
    uint8_t capabilities_M;
    uint8_t capabilities_N;
    uint8_t capabilities_O;
    uint8_t capabilities_P;
    uint8_t capabilities_Q;
    uint8_t capabilities_R;
    uint8_t capabilities_S;
    uint8_t capabilities_T;
    uint8_t capabilities_U;
    uint8_t capabilities_V;
    uint8_t capabilities_W;
    uint8_t capabilities_X;
    uint8_t capabilities_Y;
    uint8_t capabilities_Z;

    uint8_t reserved_6[6];

} __attribute__((packed, aligned(4))) NFCFixtureRecord_t;


#define FIXT_STATUS_COMMISSIONING_INTIALIZED  0x01              // Written by the fixture when it has initialized the data
#define FIXT_STATUS_COMMISSIONING_FINALIZED   0x02              // Written by the NFC app when it has added the commisining fields (serial numbers)


#define CAPABILITIES_A_PAN_TILT_REVERSE      0x01
#define CAPABILITIES_A_PAN_TILT_2_REVERSE    0x02
#define CAPABILITIES_A_SWAP_PAN_TILT         0x04
#define CAPABILITIES_A_PAN_RANGE_V1          0x08
#define CAPABILITIES_A_TILT_RANGE_V1         0x20
#define CAPABILITIES_A_SINGLE_AXIS_MOVEMENT  0x80

#define CAPABILITIES_B_AUX                   0x01
#define CAPABILITIES_B_FAN_SPEED_V1          0x02
#define CAPABILITIES_B_FAN_SPEED_V2          0x04
#define CAPABILITIES_B_FAN_SPEED_V3          0x08
#define CAPABILITIES_B_FAN_SPEED_V4          0x10
#define CAPABILITIES_B_ABSOLUTE_SILENCE      0x80

#define CAPABILITIES_C_DISPLAY_LEVEL         0x01
#define CAPABILITIES_C_DISPLAY_INVERT_V1     0x02
#define CAPABILITIES_C_DISPLAY_INVERT_V2     0x04
#define CAPABILITIES_C_DISPLAY_SHUTOFF       0x08
#define CAPABILITIES_C_SCREEN_LOCK           0x10
#define CAPABILITIES_C_TOUCHSCREEN_LOCK      0x20
#define CAPABILITIES_C_WHITE_CALIBRATION_V1  0x40
#define CAPABILITIES_C_WHITE_CALIBRATION_V2  0x80

#define CAPABILITIES_D_DIMMER_CURVE_V1       0x01
#define CAPABILITIES_D_DIMMER_RESPONSE_V1    0x10
#define CAPABILITIES_D_DIMMER_RESPONSE_V2    0x20
#define CAPABILITIES_D_DIMMER_RESPONSE_V3    0x40

#define CAPABILITIES_E_LED_POWER             0x01
#define CAPABILITIES_E_LANGUAGE              0x02
#define CAPABILITIES_E_DATA_LOSS             0x04
#define CAPABILITIES_E_CELL_ORDER_V1         0x08
#define CAPABILITIES_E_CELL_ORDER_V2         0x10
#define CAPABILITIES_E_COLOR_MIXING_MODE     0x20

#define CAPABILITIES_F_NETWORK               0x01
#define CAPABILITIES_F_ETHERNET_MAIN         0x02
#define CAPABILITIES_F_ETHERNET_AUX          0x04
#define CAPABILITIES_F_ETHERNET_DMX          0x08

#define CAPABILITIES_G_ILS                   0x01
#define CAPABILITIES_G_RF                    0x02
#define CAPABILITIES_G_DFI                   0x04
#define CAPABILITIES_G_RED_SHIFT             0x10

#define CAPABILITIES_H_PAN_TILT_BLACKOUT     0x01
#define CAPABILITIES_H_COLOR_BLACKOUT        0x02
#define CAPABILITIES_H_GOBO_BLACKOUT         0x04
#define CAPABILITIES_H_STANDBY               0x10
#define CAPABILITIES_H_LAMP_OPTIONS          0x20
#define CAPABILITIES_H_OUTPUT_SETTING        0x40
#define CAPABILITIES_H_DEFROST_FAN           0x80

#define CAPABILITIES_I_TOTEM                 0x01
#define CAPABILITIES_I_FOOR_PEDAL            0x02
#define CAPABILITIES_I_IR                    0x04
#define CAPABILITIES_I_SWAP_PAN_TILT         0x08
#define CAPABILITIES_I_FLASH_ON_DMX          0x10
#define CAPABILITIES_I_GOBO_ROTATOR          0x20

#define CAPABILITIES_J_FACTORY_RESET         0x01
#define CAPABILITIES_J_PAN_TILT_RESET        0x02
#define CAPABILITIES_J_IRIS_PRISM_RESET      0x04
#define CAPABILITIES_J_COLOR_CMY_BLADE_RESET 0x08
#define CAPABILITIES_J_SHUTTER_RESET         0x10
#define CAPABILITIES_J_GOBO_RESET            0x20
#define CAPABILITIES_J_FROST_RESET           0x40
#define CAPABILITIES_J_ANIMATION_RESET       0x80

#define CAPABILITIES_K_ZOOM_RESET            0x01
#define CAPABILITIES_K_MOTORS_RESET          0x02
#define CAPABILITIES_K_TV_RESET_MODE         0x04
#define CAPABILITIES_K_PREVENT_ZOOM_RESET    0x08

#define CAPABILTIIES_L_WIRELESS_DMX          0x01
#define CAPABILTIIES_L_WIRELESS_DMX_MODE     0x02
#define CAPABILTIIES_L_BATTERY_RUN_TIME_V1   0x04
#define CAPABILTIIES_L_BATTERY_RUN_TIME_V2   0x08
#define CAPABILTIIES_L_LINE_VOLTAGE_POWER_LOSS  0x20

#define CAPABILITIES_M_FOG_TIMING            0x01
#define CAPABILITIES_M_FOG_SETTINGS          0x04

#define CAPABILITIES_N_FOLLOW_SPOT_MODE      0x01

#define CAPABILTIIES_O_ART_NET_MAIN          0x01
#define CAPABILTIIES_O_WDMX_MAIN             0x02
#define CAPABILTIIES_O_SACN_MAIN             0x04
#define CAPABILTIIES_O_KLING_NET_MAIN        0x08
#define CAPABILTIIES_O_ART_NET_AUX           0x10
#define CAPABILTIIES_O_WDMX_AUX              0x20
#define CAPABILTIIES_O_SACN_AUX              0x40
#define CAPABILTIIES_O_KLING_NET_AUX         0x80

#define CAPABIlITIES_P_MASTER_SLAVE          0x01

#define CAPABILITIES_Q_ZOOM_OFFSET           0x01
#define CAPABILITIES_Q_ZOOM_RANGE            0x02
#define CAPABILITIES_Q_MIN_ZOOM_FOCUS        0x04
#define CAPABILITIES_Q_ZOOM_REVERSE          0x08
#define CAPABILITIES_Q_SMART_ZOOM            0x10
#define CAPABILITIES_Q_MERGE_ZOOM            0x20
#define CAPABILITIES_Q_ZOOM_LEVEL            0x40
#define CAPABILITIES_Q_DISABLE_ZOOM_VIA_DMX  0x80

#define CAPABILITIES_S_PWM_FREQUENCY_V1      0x01
#define CAPABILITIES_S_PWM_FREQUENCY_V2      0x02
#define CAPABILITIES_S_PWM_FREQUENCY_V3      0x04
#define CAPABILITIES_S_PWM_FREQUENCY_V4      0x08
#define CAPABILITIES_S_PWM_FREQUENCY_V5      0x10
#define CAPABILITIES_S_PWM_FREQUENCY_V6      0x20

#define CAPABILITIES_T_RTC_TIMING            0x01
#define CAPABILITIES_T_POWER_TIMING          0x02
#define CAPABILITIES_T_LAMP_TIMING           0x04
#define CAPABILITIES_T_TRIP_TIMING           0x08



// The Logging record of the NFC memory
// The Chuavet NFC App creates the NDEF record which contains this data during commissioning
// Once created it is read only from the RF (App side)
// It is written by the fixture whenever a fixture log or error occurs
// It is cleared by the fixture when requested from the NFC Config data

typedef struct NFCLoggingRecord {
    uint16_t log_format;
    uint16_t max_log_records;
} __attribute__((packed, aligned(4))) NFCLoggingRecord_t;

// Log records follow the above header

#define LOG_FORMAT_NONE  0
#define LOG_FORMAT_CODE_ONLY 1
#define LOG_FORMAT_TIME_AND_CODE 2

typedef struct NFCLogTimeAndCode {
    uint32_t time;
    uint16_t log_code;
} __attribute__((packed, aligned(1))) NFCLogTimeAndCode_t;


// Log codes

// Info log codes

#define FIXTURE_POWER_ON             0x0000
#define LOG_THROTTLED                0x0001

#define ERROR_CODES_START            0x1000

// Pan/Tilt & Effect Motor Sensor error codes

#define CYAN_ERROR                   0x1000
#define MAGENTA_ERROR                0x1001
#define YELLOW_ERROR                 0x1002
#define CTO_ERROR                    0x1003
#define COLOR_ERROR                  0x1004
#define COLOR_2_ERROR                0x1005
#define GOBO_ERROR                   0x1006
#define GOBO_ROTATE_ERROR            0x1007
#define GOBO_2_ERROR                 0x1008
#define GOBO_2_ROTATE_ERROR          0x1009
#define EFFECT_ERROR                 0x100A
#define EFFECT_ROTATE_ERROR          0x100B
#define SHUTTER_ROTATE_ERROR         0x100C
#define IRIS_ERROR                   0x100D
#define PRISM_ERROR                  0x100E
#define PRISM_ROTATE_ERROR           0x100F
#define PRISM_2_ERROR                0x1010
#define PRISM_2_ROTATE_ERROR         0x1011
#define FOCUS_ERROR                  0x1012
#define ZOOM_ERROR                   0x1013
#define FROST_ERROR                  0x1014
#define FROST_H_ERROR                0x1015
#define BLADE_R_ERROR                0x1016
#define TILT_OPTOCOUPLER_ERROR       0x1017
#define TILT_ENCODER_ERROR           0x1018
#define TILT_ENCODER_2_ERROR         0x1019
#define TILT_DATA_ERROR              0x101A
#define PAN_OPTOCOUPLER_ERROR        0x101B
#define PAN_ENCODER_ERROR            0x101C
#define PAN_ENCODER_2_ERROR          0x101D
#define PAN_DATA_ERROR               0x101E
#define PAN_TIMEOUT_ERROR            0x101F
#define TILT_TIMEOUT_ERROR           0x1020
#define TILT_OPTOCOUPLER_1_ERROR     0x1021
#define TILT_OPTOCOUPLER_2_ERROR     0x1022
#define TILT_OPTOCOUPLER_3_ERROR     0x1023
#define TILT_OPTOCOUPLER_4_ERROR     0x1024
#define TILT_OPTOCOUPLER_5_ERROR     0x1025
#define TILT_OPTOCOUPLER_6_ERROR     0x1026
#define TILT_OPTOCOUPLER_7_ERROR     0x1027
#define TILT_OPTOCOUPLER_8_ERROR     0x1028
#define TILT_OPTOCOUPLER_9_ERROR     0x1029
#define TILT_OPTOCOUPLER_10_ERROR    0x102A
#define TILT_OPTOCOUPLER_11_ERROR    0x102B
#define TILT_OPTOCOUPLER_12_ERROR    0x102C

// PCB error codes

#define CTR1_PCB_ERROR               0x2000
#define CTR2_PCB_ERROR               0x2001
#define CTR3_PCB_ERROR               0x2002
#define NET_PCB_ERROR                0x2003
#define CTR1_XY_PCB_ERROR            0x2004
#define CTR2_MOTOR_PCB_ERROR         0x2005
#define CTR3_MOTOR_PCB_ERROR         0x2006
#define CTR4_MOTOR_PCB_ERROR         0x2007
#define CPU_A_PCB_ERROR              0x2008
#define CPU_B_PCB_ERROR              0x2009
#define CPU_C_PCB_ERROR              0x200A
#define CPU_D_PCB_ERROR              0x200B
#define CPU_E_PCB_ERROR              0x200C
#define CPU_F_PCB_ERROR              0x200D
#define CPU_G_PCB_ERROR              0x200E
#define CPU_H_PCB_ERROR              0x200F
#define CPU_I_PCB_ERROR              0x2010
#define CPU_J_PCB_ERROR              0x2011
#define CPU_K_PCB_ERROR              0x2012
#define CPU1_PCB_ERROR               0x2013
#define CPU2_PCB_ERROR               0x2014
#define CPU3_PCB_ERROR               0x2015
#define CPU4_PCB_ERROR               0x2016
#define CPU5_PCB_ERROR               0x2017
#define CPU6_PCB_ERROR               0x2018
#define CPU7_PCB_ERROR               0x2019
#define CPU8_PCB_ERROR               0x201A
#define CPU9_PCB_ERROR               0x201B
#define CPU10_PCB_ERROR              0x201C
#define CPU11_PCB_ERROR              0x201D
#define CPU12_PCB_ERROR              0x201E

// Temperature error codes

#define TEMPERATURE_A_ERROR          0x3000
#define TEMPERATURE_B_ERROR          0x3001
#define TEMPERATURE_C_ERROR          0x3002
#define TEMPERATURE_MINUS_40         0x3003
#define TEMPERATURE_125              0x3004
#define TEMPERATURE_ERROR            0x3005
#define LED_1_HEAT_ERROR             0x3006
#define LED_2_HEAT_ERROR             0x3007
#define LED_3_HEAT_ERROR             0x3008
#define LED_4_HEAT_ERROR             0x3009
#define LED_5_HEAT_ERROR             0x300A
#define LED_6_HEAT_ERROR             0x300B
#define LED_7_HEAT_ERROR             0x300C
#define LED_8_HEAT_ERROR             0x300D
#define LED_9_HEAT_ERROR             0x300E
#define LED10_HEAT_ERROR             0x300F
#define LED11_HEAT_ERROR             0x3010
#define LED12_HEAT_ERROR             0x3011
#define HEAT_SENSOR_1_OPEN           0x3012
#define HEAT_SENSOR_2_OPEN           0x3013
#define HEAT_SENSOR_3_OPEN           0x3014
#define HEAT_SENSOR_4_OPEN           0x3015
#define HEAT_SENSOR_5_OPEN           0x3016
#define HEAT_SENSOR_6_OPEN           0x3017
#define HEAT_SENSOR_7_OPEN           0x3018
#define HEAT_SENSOR_8_OPEN           0x3019
#define HEAT_SENSOR_9_OPEN           0x301A
#define HEAT_SENSOR_10_OPEN          0x301B
#define HEAT_SENSOR_11_OPEN          0x301C
#define HEAT_SENSOR_12_OPEN          0x301D
#define HEAT_SENSOR_1_SHORT          0x301E
#define HEAT_SENSOR_2_SHORT          0x301F
#define HEAT_SENSOR_3_SHORT          0x3020
#define HEAT_SENSOR_4_SHORT          0x3021
#define HEAT_SENSOR_5_SHORT          0x3022
#define HEAT_SENSOR_6_SHORT          0x3023
#define HEAT_SENSOR_7_SHORT          0x3024
#define HEAT_SENSOR_8_SHORT          0x3025
#define HEAT_SENSOR_9_SHORT          0x3026
#define HEAT_SENSOR_10_SHORT         0x3027
#define HEAT_SENSOR_11_SHORT         0x3028
#define HEAT_SENSOR_12_SHORT         0x3029
#define LED_HEAT_ERROR               0x302A
#define HEAT_SENSOR_OPEN             0x302B
#define HEAT_SENSOR_SHORT            0x302C
#define LAMP_HEAT_ERROR              0x302D
#define LAMP_PROTECTION_ACTIVATED    0x302E
#define DRIVER_2X_HEAT_ERROR         0x302F
#define POE_X_HEAT_ERROR             0x3030
#define MR16DNS_HEAT_ERROR           0x3031
#define AR111DNS_HEAT_ERROR          0x3032
#define AR111DNM_HEAT_ERROR          0x3033
#define GZS_HEAT_ERROR               0x3034
#define CVS_HEAT_ERROR               0x3035
#define INJECT_HEAT_ERROR            0x3036

// Fan error codes

#define FAN_A1_ERROR                 0x4000
#define FAN_A1J_ERROR                0x4001
#define FAN_A2_ERROR                 0x4002
#define FAN_A4J_ERROR                0x4003
#define FAN_A5J_ERROR                0x4004
#define FAN_BASE_1_ERROR             0x4005
#define FAN_BASE_2_ERROR             0x4006
#define FAN_BASE_3_ERROR             0x4007
#define FAN_BASE_4_ERROR             0x4008
#define FAN_BASE_5_ERROR             0x4009
#define FAN_BASE_6_ERROR             0x400A
#define FAN_B1_ERROR                 0x400B
#define FAN_B1J_ERROR                0x400C
#define FAN_B2_ERROR                 0x400D
#define FAN_B3_ERROR                 0x400E
#define FAN_B4_ERROR                 0x400F
#define FAN_B5_ERROR                 0x4010
#define FAN_F1_ERROR                 0x4011
#define FAN_F2_ERROR                 0x4012
#define FAN_F3_ERROR                 0x4013
#define FAN_F4_ERROR                 0x4014
#define FAN_F5_ERROR                 0x4015
#define FAN_F6_ERROR                 0x4016
#define FAN_F7_ERROR                 0x4017
#define FAN_LAMP_M1_ERROR            0x4018
#define FAN_LAMP_M2_ERROR            0x4019
#define FAN_LAMP_M3_ERROR            0x401A
#define FAN_LAMP_M4_ERROR            0x401B
#define FAN_1_ERROR                  0x401C
#define FAN_2_ERROR                  0x401D
#define FAN_3_ERROR                  0x401E
#define FAN_4_ERROR                  0x401F
#define FAN_5_ERROR                  0x4020
#define FAN_6_ERROR                  0x4021
#define FAN_7_ERROR                  0x4022
#define FAN_8_ERROR                  0x4023
#define FAN_9_ERROR                  0x4024
#define FAN_10_ERROR                 0x4025
#define FAN_HEAD_1_ERROR             0x4026
#define FAN_HEAD_2_ERROR             0x4027
#define FAN_HEAD_3_ERROR             0x4028
#define FAN_HEAD_4_ERROR             0x4029
#define FAN_HEAD_5_ERROR             0x402A
#define FAN_HEAD_6_ERROR             0x402B
#define FAN_D1_ERROR                 0x402C
#define FAN_D5_ERROR                 0x402D
#define FAN_X_ERROR                  0x402E
#define FAN_Z1_ERROR                 0x402F
#define FAN_Z2_ERROR                 0x4030
#define FAN_Z3_ERROR                 0x4031
#define FAN_Z4_ERROR                 0x4032
#define FAN_Z5_ERROR                 0x4033
#define FAN_Z6_ERROR                 0x4034
#define FAN_SPA_ERROR                0x4035
#define FAN_SP1_ERROR                0x4036
#define FAN_J1_ERROR                 0x4037
#define FAN_J2_ERROR                 0x4038
#define FAN_J3_ERROR                 0x4039
#define FAN_J4_ERROR                 0x403A
#define FAN_G1_ERROR                 0x403B
#define FAN_G2_ERROR                 0x403C
#define FAN_G3_ERROR                 0x403D
#define FAN_G4_ERROR                 0x403E
#define FAN_G5_ERROR                 0x403F
#define FAN_G6_ERROR                 0x4040
#define FAN_G7_ERROR                 0x4041
#define FAN_DEFROST_1_ERROR          0x4042
#define FAN_DEFROST_2_ERROR          0x4043
#define FAN_DEFROST_X2_ERROR         0x4044
#define FAN_M1_ERROR                 0x4045
#define FAN_M2_ERROR                 0x4046
#define FAN_M3_ERROR                 0x4047
#define FAN_M4_ERROR                 0x4048
#define FAN_M5_ERROR                 0x4049
#define FAN_M6_ERROR                 0x404A
#define FAN_M7_ERROR                 0x404B

// Miscellaneous error codes

#define MEMORY_ERROR                 0x5000
#define FILE_NOT_FOUND               0x5001
#define MODEL_ERROR                  0x5002
#define PORT_A_OVERLOAD              0x5003
#define PORT_B_OVERLOAD              0x5004
#define RECONFIG_ERROR               0x5005
#define LIGHT_BLOCK_ERROR            0x5006
#define MISC_ERROR                   0x5007
#define DMX_SIGNAL_LOST              0x5008            // Note this error for internal error, not external loss of DMX
#define NETWORK_DISCONNECT           0x5009            // Note this error for internal error, not external loss of network
#define ARTNET_SIGNAL_LOST           0x500A            // Note this error for internal error, not external loss of Art-Net
#define SACN_SIGNAL_LOST             0x500B            // Note this error for internal error, not external loss of sACN
#define OUTPUT_1_OVERCURRENT         0x500C
#define OUTPUT_2_OVERCURRENT         0x500D
#define OUTPUT_1_SHORT_CIRCUIT       0x500E
#define OUTPUT_2_SHORT_CIRCUIT       0x500F
#define DEVICE_NO_LONGER_CONNECTED   0x5010
#define UNDEFINED_ERROR              0x5011
#define OVER_CURRENT_PROTECTION      0x5012
#define NETWORK_HARDWARE_ERROR       0x5013
#define PORT_1_EXCESS_ERROR          0x5014
#define PORT_2_EXCESS_ERROR          0x5015
#define PORT_1_2_EXCESS_ERROR        0x5016
#define NETWORK_CHIP_ERROR           0x5017
#define PSE_ERROR                    0x5018

// The Fixture Rental data section of the NFC memory
// The Chauvet NFC App creates the NDEF record which contains this data during commissioning
// This section is read/write from the RF (App side), but has optional password write protection
// The fixture does not write this section, except to clear the trip reset flags after clearing the trip data

typedef struct NFCRentalRecord {
	uint8_t trip_reset_flags;
    uint8_t reserved_1[3];
    uint8_t reserved_2[4];

    char rental_company_name[32];
    char trip_name[32];
    uint32_t trip_time_start;

    uint8_t rental_custom_data[128];
} __attribute__((packed, aligned(4))) NFCRentalRecord_t;

#define TRIP_RESET_LOGS_RESET    0x01
#define TRIP_RESET_TRIP_RESET    0x02



// The Config section of the NFC memory
// The Chuavet NFC App creates the NDEF record which contains this data during commissioning
// This section is read/write from the RF (App side)
// On start up, the fixture reads this section and if the Config Change flag is set then configures the fixture internal parameters to match the data
// The fixture updates the Config data when Fixture parameters are changed via the fixture front panel / RDM

typedef struct NFCConfigRecord {
    uint8_t conf_status;
    uint8_t reserved_1[3];

    uint8_t property_change_A;
    uint8_t property_change_B;
    uint8_t property_change_C;
    uint8_t property_change_D;
    uint8_t property_change_E;
    uint8_t property_change_F;
    uint8_t property_change_G;
    uint8_t property_change_H;

    uint8_t option_change_A;
    uint8_t option_change_B;
    uint8_t option_change_C;
    uint8_t option_change_D;
    uint8_t option_change_E;
    uint8_t option_change_F;
    uint8_t option_change_G;
    uint8_t option_change_H;
    uint8_t option_change_I;
    uint8_t option_change_J;

    uint8_t reserved_2[2];

    uint8_t action_A;
    uint8_t action_B;
    uint8_t action_C;
    uint8_t action_D;

    uint16_t start_address_main;
    uint16_t personality_main;
    uint16_t control_mode_main;
    uint16_t start_address_aux;
    uint16_t personality_aux;
    uint16_t control_mode_aux;

    char device_label[32];

    uint8_t option_A;
    uint8_t option_B;
    uint8_t option_C;
    uint8_t option_D;
    uint8_t option_E;
    uint8_t option_F;
    uint8_t option_G;
    uint8_t option_H;
    uint8_t option_I;
    uint8_t option_J;

    uint8_t reserved_3[2];

    uint8_t pan_range;
    uint8_t tilt_range;
    uint8_t reserved_4;
    uint8_t fan_speed;

    uint8_t display_level;
    uint8_t display_invert;
    uint8_t display_shutoff;

    uint8_t white_calibration;
    uint8_t dimmer_curve;
    uint8_t dimmer_response;
    uint8_t reserved_5[2];

    uint16_t language;
    uint8_t pwm_frequency;

    uint8_t ip_mode;
    uint8_t ip_address[4];
    uint8_t subnet_mask[4];
    uint8_t gateway_address[4];

    uint16_t universe_main;
    uint16_t universe_aux;
    uint16_t user_observation_error_code;
    uint8_t ils_channel;
    uint8_t rf_channel;
    uint8_t wireless_channel;
    uint8_t reserved_6[3];

    uint8_t shared1_A;
    uint8_t shared1_B;
    uint8_t shared1_C;
    uint8_t shared1_D;
    uint8_t shared1_E;
    uint8_t shared1_F;
    uint8_t shared1_G;
    uint8_t shared1_H;
    uint8_t reserved_7[4];
    uint16_t shared2_A;
    uint16_t shared2_B;

    uint8_t reserved_8[12];

    uint8_t user_data[128];
} __attribute__((packed, aligned(4))) NFCConfigRecord_t;


// Change bits for the App to indicate to the Fixture which Config section settings it has changed

#define CONF_STATUS_ACTION_CHANGED 0x01
#define CONF_STATUS_PROPERTY_CHANGED  0x02
#define CONF_STATUS_OPTION_CHANGED 0x04

#define CONF_STATUS_CHANGED (CONF_STATUS_ACTION_CHANGED|CONF_STATUS_PROPERTY_CHANGED|CONF_STATUS_OPTION_CHANGED)

#define NUM_PROPERTY_CHANGE_BYTES 6
#define NUM_OPTION_CHANGE_BYTES 10
#define NUM_ACTION_BYTES 4

#define PROPERTY_CHANGE_A_START_ADDRESS_MAIN           0x01
#define PROPERTY_CHANGE_A_PERSONALITY_MAIN             0x02
#define PROPERTY_CHANGE_A_CONTROL_MODE_MAIN            0x04
#define PROPERTY_CHANGE_A_START_ADDRESS_AUX            0x10
#define PROPERTY_CHANGE_A_PERSONALITY_AUX              0x20
#define PROPERTY_CHANGE_A_CONTROL_MODE_AUX             0x40

#define PROPERTY_CHANGE_B_PAN_RANGE                    0x01
#define PROPERTY_CHANGE_B_TILT_RANGE                   0x02
#define PROPERTY_CHANGE_B_FAN_SPEED                    0x04
#define PROPERTY_CHANGE_B_DISPLAY_LEVEL                0x08
#define PROPERTY_CHANGE_B_DISPLAY_INVERT               0x10
#define PROPERTY_CHANGE_B_DISPLAY_SHUTOFF              0x20
#define PROPERTY_CHANGE_B_WHITE_CALIBRATION            0x40
#define PROPERTY_CHANGE_B_DIMMER_CURVE                 0x80

#define PROPERTY_CHANGE_C_DIMMER_RESPONSE              0x01
#define PROPERTY_CHANGE_C_LANGUAGE                     0x02
#define PROPERTY_CHANGE_C_PWM_FREQUENCY                0x04
#define PROPERTY_CHANGE_C_IP_MODE                      0x08
#define PROPERTY_CHANGE_C_IP_ADDRESS                   0x10
#define PROPERTY_CHANGE_C_SUBNET_MASK                  0x20
#define PROPERTY_CHANGE_C_GATEWAY_ADDRESS              0x40
#define PROPERTY_CHANGE_C_UNIVERE_MAIN                 0x80

#define PROPERTY_CHANGE_D_UNIVERSE_AUX                 0x01
#define PROPERTY_CHANGE_D_ILS_CHANNEL                  0x02
#define PROPERTY_CHANGE_D_RF_CHANNEL                   0x04
#define PROPERTY_CHANGE_D_SHARED1_A                    0x08
#define PROPERTY_CHANGE_D_SHARED1_B                    0x10
#define PROPERTY_CHANGE_D_SHARED1_C                    0x20
#define PROPERTY_CHANGE_D_SHARED1_D                    0x40
#define PROPERTY_CHANGE_D_SHARED1_E                    0x80

#define PROPERTY_CHANGE_E_SHARED1_F                    0x01
#define PROPERTY_CHANGE_E_SHARED1_G                    0x02
#define PROPERTY_CHANGE_E_SHARED1_H                    0x04
#define PROPERTY_CHANGE_E_SHARED2_A                    0x08
#define PROPERTY_CHANGE_E_SHARED2_B                    0x10

#define OPTION_CHANGE_A_PREVENT_LAMP_STRIKE_ON_POWER       0x01
#define OPTION_CHANGE_A_PREVENT_LAMP_OFF_VIA_DMX           0x02
#define OPTION_CHANGE_A_PREVENT_LAMP_ON_VIA_DMX            0x04
#define OPTION_CHANGE_A_PREVENT_LAMP_OFF_WHEN_NO_DMX       0x08
#define OPTION_CHANGE_A_LAMP_STRIKE_DELAY                  0x10
#define OPTION_CHANGE_A_LAMP_LOW_POWER_DELAY               0x20

#define OPTION_CHANGE_B_PAN_REVERSE                        0x01
#define OPTION_CHANGE_B_TILT_REVERSE                       0x02
#define OPTION_CHANGE_B_SWAP_PAN_TILT                      0x04
#define OPTION_CHANGE_B_PAN2_REVERSE                       0x08
#define OPTION_CHANGE_B_TILT2_REVERSE                      0x10
#define OPTION_CHANGE_B_PREVENT_SINGLE_AXIS_MOVEMENT       0x20
#define OPTION_CHANGE_B_ABSOLUTE_SILENCE                   0x40

#define OPTION_CHANGE_C_PAN_BLACKOUT                       0x01
#define OPTION_CHANGE_C_TILT_BLACKOUT                      0x02
#define OPTION_CHANGE_C_COLOR_BLACKOUT                     0x04
#define OPTION_CHANGE_C_GOBO_BLACKOUT                      0x08

#define OPTION_CHANGE_D_MIN_ZOOM_FOCUS                     0x01
#define OPTION_CHANGE_D_ZOOM_REVERSE                       0x02
#define OPTION_CHANGE_D_SMART_ZOOM                         0x04
#define OPTION_CHANGE_D_MERGE_ZOOM                         0x08
#define OPTION_CHANGE_D_PREVENT_ZOOM_VIA_DMX               0x10
#define OPTION_CHANGE_D_PREVENT_ZOOM_RESET_ON_POWER        0x20

#define OPTION_CHANGE_E_TOTEM_ORIENTATION_UP_DOWN          0x01
#define OPTION_CHANGE_E_BOBO_ROTATOR_POWER                 0x02
#define OPTION_CHANGE_E_FOG_FLUID_SENSOR                   0x04
#define OPTION_CHANGE_E_FOLLOW_SPOT_MODE                   0x08
#define OPTION_CHANGE_E_FOLLOW_SPOT_MODE_HEAD_SELECTION    0x10
#define OPTION_CHANGE_E_DEFROST_FAN                        0x20
#define OPTION_CHANGE_E_COLOR_MIXING_MODE_CMY              0x40
#define OPTION_CHANGE_E_RED_SHIFT                          0x80

#define OPTION_CHANGE_F_WDMX_ACTIVATE                      0x01
#define OPTION_CHANGE_F_WDMX_TRANSMIT_RECEIVE              0x02
#define OPTION_CHANGE_F_WDMX_2_DMX                         0x04
#define OPTION_CHANGE_F_ETHERNET_2_DMX                     0x08
#define OPTION_CHANGE_F_IR_ACTIVATION                      0x10

#define OPTION_CHANGE_G_SCREEN_LOCK                        0x01
#define OPTION_CHANGE_G_TOUCHSCREEN_LOCK                   0x02
#define OPTION_CHANGE_G_DATA_LOSS_HOLD_BLACKOUT            0x04
#define OPTION_CHANGE_G_FLASH_ON_DMX                       0x08
#define OPTION_CHANGE_G_TV_RESET_MODE                      0x10

#define OPTION_CHANGE_H_OUTPUT_SETTING                     0x01
#define OPTION_CHANGE_H_OUTPUT_STANDBY                     0x02
#define OPTION_CHANGE_H_OUTPUT_FOOT_PEDAL_CONTROL          0x04
#define OPTION_CHANGE_H_OUTPUT_FOOT_PEDAL_BOUND_COMMON     0x08


// Actions in the Action fields

#define ACTION_A_FACTORY_RESET     0x01
#define ACTION_A_WIRELESS_RESET    0x02
#define ACTION_A_PAN_TILT_RESET    0x04
#define ACTION_A_IRIS_PRISM_RESET  0x08
#define ACTION_A_COLOR_BLADE_RESET 0x10
#define ACTION_A_SHUTTER_RESET     0x20
#define ACTION_A_GOBO_RESET        0x40
#define ACTION_A_FROST_RESET       0x80

#define ACTION_B_ANIMATION_RESET   0x01
#define ACTION_B_ZOOM_RESET        0x02
#define ACTION_B_ALL_MOTORS_RESET  0x04
#define ACTION_B_RF_BIND           0x08
#define ACTION_B_FOOT_PEDAL_BIND   0x10


// Config Options

#define OPTION_A_PREVENT_LAMP_STRIKE_ON_POWER       0x01
#define OPTION_A_PREVENT_LAMP_OFF_VIA_DMX           0x02
#define OPTION_A_PREVENT_LAMP_ON_VIA_DMX            0x04
#define OPTION_A_PREVENT_LAMP_OFF_WHEN_NO_DMX       0x08
#define OPTION_A_LAMP_STRIKE_DELAY                  0x10
#define OPTION_A_LAMP_LOW_POWER_DELAY               0x20

#define OPTION_B_PAN_REVERSE                        0x01
#define OPTION_B_TILT_REVERSE                       0x02
#define OPTION_B_SWAP_PAN_TILT                      0x04
#define OPTION_B_PAN2_REVERSE                       0x08
#define OPTION_B_TILT2_REVERSE                      0x10
#define OPTION_B_PREVENT_SINGLE_AXIS_MOVEMENT       0x20
#define OPTION_B_ABSOLUTE_SILENCE                   0x40

#define OPTION_C_PAN_BLACKOUT                       0x01
#define OPTION_C_TILT_BLACKOUT                      0x02
#define OPTION_C_COLOR_BLACKOUT                     0x04
#define OPTION_C_GOBO_BLACKOUT                      0x08

#define OPTION_D_MIN_ZOOM_FOCUS                     0x01
#define OPTION_D_ZOOM_REVERSE                       0x02
#define OPTION_D_SMART_ZOOM                         0x04
#define OPTION_D_MERGE_ZOOM                         0x08
#define OPTION_D_PREVENT_ZOOM_VIA_DMX               0x10
#define OPTION_D_PREVENT_ZOOM_RESET_ON_POWER        0x20

#define OPTION_E_TOTEM_ORIENTATION_UP_DOWN          0x01
#define OPTION_E_BOBO_ROTATOR_POWER                 0x02
#define OPTION_E_FOG_FLUID_SENSOR                   0x04
#define OPTION_E_FOLLOW_SPOT_MODE                   0x08
#define OPTION_E_FOLLOW_SPOT_MODE_HEAD_SELECTION    0x10
#define OPTION_E_DEFROST_FAN                        0x20
#define OPTION_E_COLOR_MIXING_MODE_CMY              0x40
#define OPTION_E_RED_SHIFT                          0x80

#define OPTION_F_WDMX_ACTIVATE                      0x01
#define OPTION_F_WDMX_TRANSMIT_RECEIVE              0x02
#define OPTION_F_WDMX_2_DMX                         0x04
#define OPTION_F_ETHERNET_2_DMX                     0x08
#define OPTION_F_IR_ACTIVATION                      0x10

#define OPTION_G_SCREEN_LOCK                        0x01
#define OPTION_G_TOUCHSCREEN_LOCK                   0x02
#define OPTION_G_DATA_LOSS_HOLD_BLACKOUT            0x04
#define OPTION_G_FLASH_ON_DMX                       0x08
#define OPTION_G_TV_RESET_MODE                      0x10

#define OPTION_H_OUTPUT_SETTING                     0x01
#define OPTION_H_OUTPUT_STANDBY                     0x02
#define OPTION_H_OUTPUT_FOOT_PEDAL_CONTROL          0x04
#define OPTION_H_OUTPUT_FOOT_PEDAL_BOUND_COMMON     0x08



// Timers
// Note to reduce EEPROM wear it is important that the EEPROM is not written repeatedly
// EEPROM supports 1,000,000 writes at 25 degrees
// Assuming 10 year life 10*365*24*60*60 seconds = 315,360,000 seconds
// Regular writes should be no more frequent than every 315 seconds.

#define CHECK_NFC_INTERVAL      (1)             // Interval in seconds between checking for NFC changes
#define BACKUP_TO_NFC_INTERVAL  (15*60)			// Interval in seconds between backing up NFC (Note that this should be 15 minutes or more to prevent EEPROM wear
#define DEV_HOURS_INTERVAL      (60*60)			// Interval in seconds between increasing device / lamp hours


// Functions

int nfc_startup(void);                          // Call on startup of fixture
uint32_t nfc_get_last_powered_off_utc(void);    // Retrieve the UTC of the last time the fixture was powered off
void nfc_update_fixture_record(void);           // Update Fixture record in the NFC to match our fixture data
void nfc_backup_times(void);                    // Call to update the device hours and other times in the Fixture section of the NFC
void nfc_reset_logs(void);                      // Reset and clear the log records
void nfc_add_log_record(uint16_t log_code);     // Add a log record to the log
void nfc_init_rental(void);                     // Initialises the rental record

int nfc_check_changed(void);                    // Call every second to poll for changes to the NFC by the App
void nfc_update_config_record(void);            // Update Config record in the NFC to match our fixture data

void nfc_update_dmx_start(void);
void nfc_update_dmx_personality(void);

#endif // CHAUVET_NFC_DEMO_H
