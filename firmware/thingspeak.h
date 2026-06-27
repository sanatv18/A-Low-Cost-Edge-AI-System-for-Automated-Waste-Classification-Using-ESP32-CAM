/******************************************************************************
 * File        : thingspeak.h
 * Project     : Edge AI & IoT Smart Waste Classification System
 * Description : ThingSpeak Cloud Interface
 ******************************************************************************/

#ifndef THINGSPEAK_MANAGER_H
#define THINGSPEAK_MANAGER_H

#include <ThingSpeak.h>

bool initializeThingSpeak();

bool uploadToThingSpeak(
    String wasteType,
    float confidence,
    int detectionCount,
    int servoPosition,
    String deviceStatus
);

#endif
