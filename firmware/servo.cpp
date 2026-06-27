/******************************************************************************
 * File        : servo.cpp
 * Project     : Edge AI & IoT Smart Waste Classification System
 * Description : Servo Motor Control
 ******************************************************************************/

#include "servo.h"
#include "config.h"

Servo wasteServo;

static int currentPosition = SERVO_CENTER;

bool initializeServo()
{
    wasteServo.attach(SERVO_PIN);

    wasteServo.write(SERVO_CENTER);

    currentPosition = SERVO_CENTER;

    Serial.println("Servo Initialized");

    return true;
}

void moveToPaperBin()
{
    Serial.println("Sorting -> Paper");

    wasteServo.write(SERVO_LEFT);

    currentPosition = SERVO_LEFT;

    delay(SERVO_DELAY_MS);

    resetServo();
}

void moveToBatteryBin()
{
    Serial.println("Sorting -> Battery");

    wasteServo.write(SERVO_RIGHT);

    currentPosition = SERVO_RIGHT;

    delay(SERVO_DELAY_MS);

    resetServo();
}

void resetServo()
{
    wasteServo.write(SERVO_CENTER);

    currentPosition = SERVO_CENTER;

    Serial.println("Servo Reset");
}

int getServoPosition()
{
    return currentPosition;
}
