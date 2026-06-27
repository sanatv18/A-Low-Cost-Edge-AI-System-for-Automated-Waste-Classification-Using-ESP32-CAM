/******************************************************************************
 * Project : Edge AI & IoT Smart Waste Classification System
 *
 * Authors:
 *  - Sanat Vasisht
 *  - Varun Shankar
 *
 * Description:
 * Main application entry point.
 ******************************************************************************/

#include "config.h"

#include "camera.h"
#include "classifier.h"
#include "display.h"
#include "servo.h"
#include "wifi.h"
#include "thingspeak.h"
#include "utils.h"

int detectionCount = 0;

void setup()
{
    Serial.begin(115200);

    printSystemInfo();

    initializeDisplay();

    showWelcomeScreen();

    initializeServo();

    initializeCamera();

    initializeClassifier();

    initializeWiFi();

    initializeThingSpeak();

    Serial.println("System Ready");
}

void loop()
{
    DetectionResult result = runInference();

    if(result.detected)
    {
        detectionCount++;

        printDetection(
            result.label,
            result.confidence);

        showPrediction(
            result.label,
            result.confidence);

        if(result.type == PAPER)
        {
            moveToPaperBin();
        }

        else if(result.type == BATTERY)
        {
            moveToBatteryBin();
        }

        bool uploaded =
            uploadToThingSpeak(
                result.label,
                result.confidence,
                detectionCount,
                getServoPosition(),
                DEVICE_RUNNING);

        showCloudStatus(uploaded);
    }

    delay(DETECTION_DELAY_MS);
}
