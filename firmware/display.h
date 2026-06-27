/******************************************************************************
 * File        : display.h
 * Project     : Edge AI & IoT Smart Waste Classification System
 * Description : OLED Display Manager
 ******************************************************************************/

#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

bool initializeDisplay();

void clearScreen();

void showWelcomeScreen();

void showBootScreen();

void showPrediction(
    String label,
    float confidence
);

void showCloudStatus(bool uploaded);

void showError(String message);

#endif
