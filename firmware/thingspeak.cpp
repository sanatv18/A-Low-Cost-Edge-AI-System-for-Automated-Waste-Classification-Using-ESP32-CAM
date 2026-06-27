/******************************************************************************
 * File        : thingspeak.cpp
 * Project     : Edge AI & IoT Smart Waste Classification System
 * Description : ThingSpeak Cloud Upload Module
 ******************************************************************************/

#include "thingspeak.h"
#include "wifi.h"
#include "config.h"

WiFiClient client;

bool initializeThingSpeak()
{
    ThingSpeak.begin(client);

    Serial.println("--------------------------------");
    Serial.println("ThingSpeak Initialized");
    Serial.println("--------------------------------");

    return true;
}

bool uploadToThingSpeak(
    String wasteType,
    float confidence,
    int detectionCount,
    int servoPosition,
    String deviceStatus)
{

    if (!isWiFiConnected())
    {
        reconnectWiFi();
    }

    ThingSpeak.setField(FIELD_WASTE_TYPE, wasteType);
    ThingSpeak.setField(FIELD_CONFIDENCE, confidence);
    ThingSpeak.setField(FIELD_DETECTION_COUNT, detectionCount);
    ThingSpeak.setField(FIELD_SERVO_POSITION, servoPosition);
    ThingSpeak.setField(FIELD_DEVICE_STATUS, deviceStatus);
    ThingSpeak.setField(FIELD_WIFI_RSSI, getWiFiRSSI());
    ThingSpeak.setField(FIELD_UPTIME, millis() / 1000);
    ThingSpeak.setField(FIELD_FREE_HEAP, ESP.getFreeHeap());

    int status = ThingSpeak.writeFields(
        THINGSPEAK_CHANNEL_ID,
        THINGSPEAK_WRITE_API_KEY
    );

    if(status == 200)
    {
        Serial.println("ThingSpeak Upload Successful");
        return true;
    }
    else
    {
        Serial.print("ThingSpeak Upload Failed : ");
        Serial.println(status);

        return false;
    }
}
