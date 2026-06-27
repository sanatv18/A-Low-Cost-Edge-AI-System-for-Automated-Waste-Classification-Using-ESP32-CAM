/******************************************************************************
 * File        : utils.cpp
 * Project     : Edge AI & IoT Smart Waste Classification System
 * Description : Utility Functions
 ******************************************************************************/

#include "utils.h"

#include "config.h"

void printDivider()
{
    Serial.println("==============================================");
}

void printSystemInfo()
{
    printDivider();

    Serial.println(PROJECT_NAME);

    Serial.print("Version : ");
    Serial.println(PROJECT_VERSION);

    Serial.print("Free Heap : ");
    Serial.print(ESP.getFreeHeap());
    Serial.println(" Bytes");

    Serial.print("CPU Frequency : ");
    Serial.print(getCpuFrequencyMhz());
    Serial.println(" MHz");

    printDivider();
}

void printMemoryUsage()
{
    Serial.print("Available Heap : ");

    Serial.print(ESP.getFreeHeap());

    Serial.println(" Bytes");
}

String wasteTypeToString(int type)
{
    switch(type)
    {
        case PAPER:

            return "Paper";

        case BATTERY:

            return "Battery";

        default:

            return "Unknown";
    }
}

void printDetection(
        String label,
        float confidence)
{
    Serial.println();

    printDivider();

    Serial.println("Detection");

    Serial.print("Waste Type : ");

    Serial.println(label);

    Serial.print("Confidence : ");

    Serial.print(confidence);

    Serial.println("%");

    printDivider();
}
