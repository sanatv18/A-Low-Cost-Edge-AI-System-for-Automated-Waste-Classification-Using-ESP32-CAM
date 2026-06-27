# ESP32-CAM Pin Connections

| ESP32-CAM Pin | Connected Device | Description |
|---------------|------------------|-------------|
| GPIO12 | SG90 Servo Signal | Servo Control |
| GPIO15 | OLED SDA | I2C Data |
| GPIO14 | OLED SCL | I2C Clock |
| 5V | Servo Power | Power Supply |
| 3.3V | OLED VCC | OLED Power |
| GND | Common Ground | Shared Ground |

---

## Camera Module

The onboard OV2640 camera is connected internally to the ESP32-CAM module and is configured using the AI Thinker camera pin definitions.
