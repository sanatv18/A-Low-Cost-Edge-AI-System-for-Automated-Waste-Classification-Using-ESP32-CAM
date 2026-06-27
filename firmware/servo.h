/******************************************************************************
 * File        : servo.h
 * Project     : Edge AI & IoT Smart Waste Classification System
 * Description : Servo Motor Control
 ******************************************************************************/

#ifndef SERVO_MANAGER_H
#define SERVO_MANAGER_H

#include <ESP32Servo.h>

bool initializeServo();

void moveToPaperBin();

void moveToBatteryBin();

void resetServo();

int getServoPosition();

#endif
