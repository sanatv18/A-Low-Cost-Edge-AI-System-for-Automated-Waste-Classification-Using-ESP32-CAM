/******************************************************************************
 * File        : display.cpp
 * Project     : Edge AI & IoT Smart Waste Classification System
 * Description : OLED Display Manager
 ******************************************************************************/

#include "display.h"
#include "config.h"

TwoWire I2CBus = TwoWire(0);

Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &I2CBus,
    OLED_RESET
);

bool initializeDisplay()
{
    I2CBus.begin(I2C_SDA, I2C_SCL);

    if(!display.begin(
        SSD1306_SWITCHCAPVCC,
        OLED_ADDRESS))
    {
        Serial.println("OLED Initialization Failed");
        return false;
    }

    display.clearDisplay();
    display.display();

    return true;
}

void clearScreen()
{
    display.clearDisplay();
    display.display();
}

void showWelcomeScreen()
{
    display.clearDisplay();

    display.setTextSize(2);
    display.setCursor(5,5);
    display.print("Edge AI");

    display.setTextSize(1);
    display.setCursor(0,35);
    display.println("Smart Waste");

    display.setCursor(0,50);
    display.println("Classification");

    display.display();
}

void showBootScreen()
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0,0);
    display.println("Initializing...");

    display.setCursor(0,18);
    display.println("Camera");

    display.setCursor(0,30);
    display.println("OLED");

    display.setCursor(0,42);
    display.println("WiFi");

    display.setCursor(0,54);
    display.println("ThingSpeak");

    display.display();
}

void showPrediction(
    String label,
    float confidence)
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0,0);
    display.println("Detected");

    display.setTextSize(2);

    display.setCursor(0,18);
    display.println(label);

    display.setTextSize(1);

    display.setCursor(0,52);
    display.print("Confidence: ");

    display.print(confidence);

    display.print("%");

    display.display();
}

void showCloudStatus(bool uploaded)
{
    display.setTextSize(1);

    display.setCursor(90,0);

    if(uploaded)
    {
        display.print("Cloud OK");
    }
    else
    {
        display.print("Cloud X");
    }

    display.display();
}

void showError(String message)
{
    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0,0);
    display.println("ERROR");

    display.setCursor(0,20);
    display.println(message);

    display.display();
}
