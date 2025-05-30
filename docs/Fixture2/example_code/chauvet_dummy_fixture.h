// Chauvet Dummy Fixture
//
// Dummy fixture for testing of the NFC
// This is an example file only.
// This file will be replaced by the code of the fixture manufacturer


#ifndef CHAUVET_DUMMY_FIXTURE_H
#define CHAUVET_DUMMY_FIXTURE_H

#include "chauvet_nfc_demo.h"
#include <stdint.h>

#define DEVICE_MODEL_ID  0x0020                    // RDM Model ID

#define FIXTURE_STATUS_LAMP_ON 0x00000001			// Indicates fixture is lamped on


typedef struct DummyFixture {

	// Fixture info

    uint8_t device_uid[16];
    uint8_t rdm_uid[6];

    char device_serial_number[32];
    uint8_t mac_address[6];

    uint32_t software_version;
    char software_version_label[32];
    uint32_t boot_software_version;

    uint32_t lamp_strikes;
    uint32_t device_hours;
    uint32_t lamp_hours;
    uint32_t device_power_cycles;
    uint32_t device_status;
    uint32_t device_error_count;

    uint32_t time_last_powered_on;
    uint32_t time_last_powered_off;
    uint32_t time_last_lamped_on;
    uint32_t time_last_lamped_off;

    uint8_t battery_level;

    uint32_t trip_lamp_strikes;
    uint32_t trip_device_hours;
    uint32_t trip_lamp_hours;
    uint32_t trip_power_cycles;
    uint32_t trip_error_count;

    // Config data

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

    uint8_t pan_range;
    uint8_t tilt_range;

    uint8_t wireless_channel;
    uint8_t fan_speed;

    uint8_t display_level;
    uint8_t display_invert;
    uint8_t display_shutoff;

    uint8_t white_calibration;
    uint8_t dimmer_curve;
    uint8_t dimmer_response;
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

    uint8_t user_data[128];

    uint32_t status;

} DummyFixture_t;

extern DummyFixture_t dummy_fixture;


void create_fixture();            // Create our dummy fixture
void fixture_power_on();          // Power on the fixture
void fixture_base_loop(void);     // Dummy fixture base loop
void fixture_main();              // main function of the fixture

#endif

