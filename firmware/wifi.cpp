/******************************************************************************
 * File        : wifi.cpp
 * Project     : Edge AI & IoT Smart Waste Classification System
 * Description : Handles Wi-Fi connectivity
 ******************************************************************************/

#include "wifi.h"
#include "config.h"

bool initializeWiFi()
{
    Serial.println();
    Serial.println("=================================");
    Serial.println("Connecting to Wi-Fi...");
    Serial.println("=================================");

    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    unsigned long startTime = millis();

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);

        Serial.print(".");

        if (millis() - startTime > WIFI_TIMEOUT_MS)
        {
            Serial.println("\nWi-Fi Connection Timeout");
            return false;
        }
    }

    Serial.println("\nWi-Fi Connected");
    Serial.print("IP Address : ");
    Serial.println(WiFi.localIP());

    Serial.print("RSSI : ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");

    return true;
}

bool reconnectWiFi()
{
    if (WiFi.status() == WL_CONNECTED)
        return true;

    Serial.println("Reconnecting Wi-Fi...");

    WiFi.disconnect();

    return initializeWiFi();
}

bool isWiFiConnected()
{
    return (WiFi.status() == WL_CONNECTED);
}

int getWiFiRSSI()
{
    return WiFi.RSSI();
}

String getIPAddress()
{
    return WiFi.localIP().toString();
}

void printWiFiStatus()
{
    Serial.println("========== Wi-Fi Status ==========");

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("Status : Connected");
        Serial.print("SSID   : ");
        Serial.println(WIFI_SSID);

        Serial.print("IP     : ");
        Serial.println(getIPAddress());

        Serial.print("RSSI   : ");
        Serial.print(getWiFiRSSI());
        Serial.println(" dBm");
    }
    else
    {
        Serial.println("Status : Disconnected");
    }

    Serial.println("==================================");
}
