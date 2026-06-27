/******************************************************************************
 * File        : camera.cpp
 * Project     : Edge AI & IoT Smart Waste Classification System
 * Description : ESP32-CAM Driver
 ******************************************************************************/

#include "camera.h"
#include "config.h"

#include "esp_camera.h"
#include "edge-impulse-sdk/dsp/image/image.hpp"

static bool cameraInitialized = false;

uint8_t *snapshotBuffer = nullptr;

/*--------------------------------------------------
    Camera Configuration
--------------------------------------------------*/

static camera_config_t cameraConfig =
{
    // Paste your entire camera_config_t structure
    // from the original project here.
};

/*--------------------------------------------------
    Initialize Camera
--------------------------------------------------*/

bool initializeCamera()
{
    if(cameraInitialized)
        return true;

    esp_err_t err = esp_camera_init(&cameraConfig);

    if(err != ESP_OK)
    {
        Serial.printf("Camera Init Failed (0x%x)\n", err);
        return false;
    }

    sensor_t *sensor = esp_camera_sensor_get();

    if(sensor->id.PID == OV3660_PID)
    {
        sensor->set_vflip(sensor,1);
        sensor->set_brightness(sensor,1);
        sensor->set_saturation(sensor,0);
    }

    cameraInitialized = true;

    Serial.println("Camera Initialized");

    return true;
}

/*--------------------------------------------------
      Capture Image
--------------------------------------------------*/

bool captureImage(
    uint32_t width,
    uint32_t height,
    uint8_t *buffer)
{

    // Move the entire
    // ei_camera_capture()
    // function here

}

/*--------------------------------------------------
      Deinitialize Camera
--------------------------------------------------*/

void deinitializeCamera()
{
    esp_camera_deinit();

    cameraInitialized = false;
}

/*--------------------------------------------------
     Edge Impulse Callback
--------------------------------------------------*/

int getCameraData(
    size_t offset,
    size_t length,
    float *out_ptr)
{

    // Move
    // ei_camera_get_data()
    // here

}
