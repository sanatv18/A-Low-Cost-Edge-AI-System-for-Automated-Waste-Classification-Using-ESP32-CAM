/******************************************************************************
 * Project : Edge AI & IoT Smart Waste Classification System
 * Platform: ESP32-CAM (AI Thinker)
 *
 * Authors:
 *   - Sanat Vasisht
 *   - Varun Shankar
 *
 * Description:
 * Central configuration file containing GPIO assignments,
 * Wi-Fi credentials, ThingSpeak settings,
 * OLED configuration, servo parameters,
 * and application constants.
 ******************************************************************************/

#ifndef CONFIG_H
#define CONFIG_H

/*====================================================
                    PROJECT INFO
====================================================*/

#define PROJECT_NAME        "Edge AI Smart Waste Classifier"
#define PROJECT_VERSION     "2.0.0"

/*====================================================
                    DEBUG
====================================================*/

#define DEBUG_MODE true

/*====================================================
                  Wi-Fi SETTINGS
====================================================*/

const char* WIFI_SSID     = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

/*====================================================
                THINGSPEAK SETTINGS
====================================================*/

const unsigned long THINGSPEAK_CHANNEL_ID = 0000000;
const char* THINGSPEAK_WRITE_API_KEY = "YOUR_WRITE_API_KEY";

/*====================================================
                  CAMERA MODEL
====================================================*/

#define CAMERA_MODEL_AI_THINKER

/*====================================================
                 OLED SETTINGS
====================================================*/

#define SCREEN_WIDTH        128
#define SCREEN_HEIGHT       64
#define OLED_RESET          -1
#define OLED_ADDRESS        0x3C

// Actual pins from your working project
#define I2C_SDA             15
#define I2C_SCL             14

/*====================================================
                 SERVO SETTINGS
====================================================*/

#define SERVO_PIN           12

#define SERVO_LEFT          0
#define SERVO_CENTER        90
#define SERVO_RIGHT         180

/*====================================================
              CAMERA IMAGE SETTINGS
====================================================*/

#define CAMERA_FRAME_WIDTH      320
#define CAMERA_FRAME_HEIGHT     240
#define CAMERA_FRAME_CHANNELS   3

/*====================================================
             OBJECT DETECTION SETTINGS
====================================================*/

#define CONFIDENCE_THRESHOLD    0.80

/*====================================================
                TIMING SETTINGS
====================================================*/

#define SERVO_DELAY_MS          2000
#define DETECTION_DELAY_MS      5
#define WIFI_TIMEOUT_MS         15000
#define CLOUD_UPLOAD_DELAY_MS   15000

/*====================================================
                CLOUD FIELDS
====================================================*/

#define FIELD_WASTE_TYPE        1
#define FIELD_CONFIDENCE        2
#define FIELD_DETECTION_COUNT   3
#define FIELD_SERVO_POSITION    4
#define FIELD_DEVICE_STATUS     5
#define FIELD_WIFI_RSSI         6
#define FIELD_UPTIME            7
#define FIELD_FREE_HEAP         8

/*====================================================
                 DEVICE STATUS
====================================================*/

#define DEVICE_RUNNING          "Running"
#define DEVICE_OFFLINE          "Offline"

#endif
