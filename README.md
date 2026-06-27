# A Low-Cost Edge AI & IoT System for Automated Waste Classification Using ESP32-CAM

![Platform](https://img.shields.io/badge/Platform-ESP32--CAM-blue)
![AI](https://img.shields.io/badge/AI-Edge%20Impulse-green)
![Cloud](https://img.shields.io/badge/Cloud-ThingSpeak-orange)
![Language](https://img.shields.io/badge/Language-C++-blue)
![Status](https://img.shields.io/badge/Status-Completed-success)

---

## 📌 Project Overview

This project presents a **low-cost Edge AI and IoT-based Smart Waste Classification System** developed using an **ESP32-CAM**, **Edge Impulse Machine Learning**, and **ThingSpeak Cloud**.

The ESP32-CAM captures images of waste objects and performs **real-time on-device object detection** using a trained Edge Impulse model. Once classified, a servo motor automatically directs the waste into the appropriate compartment while an OLED display shows the detected waste category along with its confidence score.

To enable remote monitoring, the ESP32 uploads classification results to the **ThingSpeak Cloud Platform**, allowing real-time visualization, historical data logging, and analytics.

This project demonstrates the integration of **Embedded Systems**, **Computer Vision**, **Machine Learning**, and **IoT Cloud Technologies** into a compact, low-cost, and energy-efficient smart waste management solution.

---

# ✨ Features

- Real-time Edge AI inference on ESP32-CAM
- Fully offline object detection using Edge Impulse
- Automatic waste segregation using servo motor
- OLED display showing prediction and confidence
- Wi-Fi enabled cloud connectivity
- Real-time data logging using ThingSpeak
- Historical analytics through cloud dashboard
- Low-cost and energy-efficient embedded solution

---

# 🛠 Hardware Components

| Component | Purpose |
|------------|-----------------------------|
| ESP32-CAM | Image Capture & AI Inference |
| SG90 Servo Motor | Automatic Waste Segregation |
| OLED SSD1306 Display | Prediction Display |
| Breadboard | Prototyping |
| Jumper Wires | Connections |
| 5V Power Supply | System Power |

---

# 💻 Software & Tools

- Arduino IDE
- Embedded C++
- Edge Impulse
- ThingSpeak Cloud
- ESP32 Camera Library
- ESP32Servo Library
- Adafruit SSD1306
- Adafruit GFX
- Git & GitHub

---

# 🏗 System Architecture

```text
                 Waste Object
                      │
                      ▼
                ESP32-CAM Camera
                      │
                      ▼
              Image Acquisition
                      │
                      ▼
           Edge Impulse ML Model
                      │
                      ▼
             Waste Classification
                      │
          ┌───────────┼────────────┐
          ▼           ▼            ▼
      OLED Display  Servo Motor   Wi-Fi
          │           │            │
          ▼           ▼            ▼
 Prediction &     Waste Bin    ThingSpeak
 Confidence       Selection      Cloud
                                   │
                                   ▼
                         Real-Time Dashboard
                         Historical Analytics
```

---

# ⚙ Working Principle

1. ESP32-CAM captures an image of the waste object.
2. The image is preprocessed and sent to the Edge Impulse model.
3. The model classifies the object as biodegradable or non-biodegradable.
4. Prediction label and confidence score are displayed on the OLED.
5. Servo motor rotates to the appropriate waste compartment.
6. Classification data is transmitted to ThingSpeak over Wi-Fi.
7. ThingSpeak stores and visualizes the data through cloud dashboards.
8. Servo returns to its default position and waits for the next object.

---

# 🤖 Machine Learning Model

### Framework

Edge Impulse

### Model Type

Object Detection

### Waste Categories

- Paper (Biodegradable)
- Battery (Non-Biodegradable)

### Training Dataset

The model was trained using images captured under:

- Multiple lighting conditions
- Different viewing angles
- Various backgrounds

to improve model robustness.

---

# ☁ IoT Cloud Integration

The ESP32 uploads classification data to the **ThingSpeak Cloud Platform** through Wi-Fi.

### Cloud Parameters

- Waste Category
- Confidence Score
- Detection Count
- Timestamp
- System Status

### Cloud Features

- Live Dashboard
- Historical Data Storage
- Automatic Graph Generation
- Remote Monitoring
- IoT Analytics

---

# 📊 Performance

| Metric | Value |
|----------|---------|
| Classification Accuracy | ~90% |
| Processing Mode | Edge AI |
| Cloud Platform | ThingSpeak |
| Internet Required | Only for Cloud Upload |
| Display | OLED SSD1306 |
| Servo Response | Real-Time |
| Waste Segregation | Automatic |

---

# 🔌 Hardware Connections

| ESP32 Pin | Connected Device |
|------------|----------------|
| GPIO12 | Servo Signal |
| GPIO15 | OLED SDA |
| GPIO2 | OLED SCL |
| 5V | Servo Power |
| 3.3V | OLED Power |

---
## 📁 Repository Structure

```text
.
├── README.md
├── LICENSE
├── .gitignore
│
├── firmware/
│   ├── README.md
│   ├── SmartWasteClassifier.ino
│   ├── config.h
│   ├── camera.cpp
│   ├── camera.h
│   ├── classifier.cpp
│   ├── classifier.h
│   ├── display.cpp
│   ├── display.h
│   ├── servo.cpp
│   ├── servo.h
│   ├── wifi.cpp
│   ├── wifi.h
│   ├── thingspeak.cpp
│   ├── thingspeak.h
│   ├── utils.cpp
│   ├── utils.h
│   └── libraries.md
│
├── hardware/
│   ├── README.md
│   ├── System.png
│   ├── block_diagram.png
│   ├── circuit_diagram.png
│   ├── wiring_diagram.png
│   ├── pin_connections.md
│   ├── bill_of_materials.md
│   └── demo_video/
│       ├── Output.mp4
│       └── System setup.mp4
│
├── edge_impulse/
│   ├── README.md
│   ├── dataset.md
│   ├── evaluation_metrics.json
│   └── model_metrics.md
│
├── docs/
│   ├── README.md
│   └── Project_Report.pdf
│
└── LICENSE
```

# 🚧 Challenges Faced

### Memory Constraints

Large image buffers exceeded available RAM on the ESP32.

**Solution**

Optimized image resolution and memory allocation.

---

### Lighting Variations

Detection accuracy decreased under poor illumination.

**Solution**

Collected images under multiple lighting conditions and viewing angles.

---

### Continuous Servo Movement

Repeated detections caused unnecessary servo rotations.

**Solution**

Implemented a cooldown timer using `millis()`.

---

### Cloud Connectivity

Wi-Fi interruptions occasionally delayed cloud uploads.

**Solution**

Added reconnection logic before uploading data to ThingSpeak.

---

# 📈 Results

- Successfully implemented Edge AI on ESP32-CAM
- Achieved approximately **90% object classification accuracy**
- Automated waste segregation using servo motor
- OLED-based real-time prediction display
- Cloud data logging through ThingSpeak
- Enabled remote monitoring and historical analytics
- Fully functional embedded Edge AI + IoT prototype

---

# 🚀 Future Improvements

- Support Plastic, Metal, Glass and Organic Waste
- Multi-bin waste segregation
- MQTT-based cloud communication
- Mobile application dashboard
- TensorFlow Lite Micro optimization
- OTA firmware updates
- Solar-powered standalone system
- Smart waste analytics using AI

---

# 🌍 Applications

- Smart Cities
- Smart Dustbins
- Waste Management Systems
- Environmental Monitoring
- Industrial Automation
- Edge AI Applications
- IoT Monitoring Systems

---

# 📄 Bill of Materials

| Component | Approx. Cost |
|------------|-------------|
| ESP32-CAM | ₹650 |
| Servo Motor | ₹180 |
| OLED Display | ₹250 |
| Breadboard | ₹120 |
| Jumper Wires | ₹80 |

**Estimated Total Cost:** **₹1280**

---

# Authors

### Sanat Vasisht
- Edge Impulse machine learning model development
- Hardware architecture and system design
- ThingSpeak cloud integration
- Embedded firmware development
- GitHub documentation and project maintenance

### Varun Shankar
- Embedded firmware development
- Hardware implementation and integration
- System testing and validation

## Contribution Summary

This project was developed collaboratively by both authors. Responsibilities were divided across machine learning, embedded firmware, hardware design, IoT cloud integration, system testing, and documentation.

---

# 📜 License

This project is licensed under the MIT License.
