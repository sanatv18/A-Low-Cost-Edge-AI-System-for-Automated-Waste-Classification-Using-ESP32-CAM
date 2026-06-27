/******************************************************************************
 * File        : wifi.h
 * Project     : Edge AI & IoT Smart Waste Classification System
 * Description : Wi-Fi Manager
 ******************************************************************************/

#ifndef WIFI_H
#define WIFI_H

#include <WiFi.h>

bool initializeWiFi();

bool reconnectWiFi();

bool isWiFiConnected();

int getWiFiRSSI();

String getIPAddress();

void printWiFiStatus();

#endif
