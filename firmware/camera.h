/******************************************************************************
 * File        : camera.h
 * Project     : Edge AI & IoT Smart Waste Classification System
 * Description : ESP32-CAM Driver
 ******************************************************************************/

#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include "esp_camera.h"

bool initializeCamera();

void deinitializeCamera();

bool captureImage(
    uint32_t width,
    uint32_t height,
    uint8_t *buffer
);

int getCameraData(
    size_t offset,
    size_t length,
    float *out_ptr
);

#endif
