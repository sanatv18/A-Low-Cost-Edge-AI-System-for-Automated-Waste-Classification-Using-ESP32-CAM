# A Low-Cost Edge AI System for Automated Waste Classification Using ESP32-CAM

![Platform](https://img.shields.io/badge/Platform-ESP32--CAM-blue)
![Edge AI](https://img.shields.io/badge/AI-Edge%20Impulse-green)
![Language](https://img.shields.io/badge/Language-C%2B%2B-orange)
![Status](https://img.shields.io/badge/Status-Completed-success)

---

## Project Overview

This project presents a **low-cost Edge AI waste classification system** that performs **real-time object detection directly on an ESP32-CAM** using an Edge Impulse machine learning model.

Unlike cloud-based AI systems, the complete inference process runs locally on the microcontroller, enabling **offline operation**, **low latency**, and **minimal power consumption**.

After classifying the waste object, the system automatically rotates a servo motor to direct the object into the correct compartment while simultaneously displaying the detected class and confidence score on an OLED display.

---

## Project Highlights

- Developed a complete Embedded AI system using ESP32-CAM
- Implemented real-time on-device object detection using Edge Impulse
- Designed automatic waste segregation using servo motor control
- Displayed prediction labels and confidence scores on OLED display
- Achieved approximately **90% classification accuracy**
- Fully offline Edge AI inference without cloud connectivity
- Developed using Embedded C++ and Arduino Framework

---

## Demonstration

> **Demo Video:** *(Insert YouTube or Drive Link Here)*

<p align="center">
<img src="images/classification_demo.gif" width="750">
</p>

---

# System Architecture

```text
Waste Object
      │
      ▼
ESP32-CAM
      │
      ▼
Image Capture
      │
      ▼
Edge Impulse ML Model
      │
      ▼
Object Detection
      │
      ▼
Prediction
      │
 ┌────┴─────┐
 ▼          ▼
OLED      Servo Motor
Display     Control
              │
              ▼
 Waste Segregation
```

---

# Hardware Components

| Component | Purpose |
|------------|----------------------------|
| ESP32-CAM | Image Capture & AI Inference |
| Servo Motor (SG90) | Waste Segregation |
| OLED SSD1306 | Prediction Display |
| Breadboard | Prototyping |
| Jumper Wires | Hardware Connections |
| 5V Power Supply | System Power |

---

# Software & Tools

- Arduino IDE
- Edge Impulse
- Embedded C++
- ESP32 Camera Library
- ESP32Servo Library
- Adafruit SSD1306
- Adafruit GFX
- Git & GitHub

---

# Working Principle

1. ESP32-CAM continuously captures images.
2. Images are resized and preprocessed.
3. Edge Impulse performs object detection.
4. Prediction label and confidence score are generated.
5. OLED displays classification results.
6. Servo rotates toward the corresponding waste compartment.
7. Servo returns to the default position.
8. System waits for the next object.

---

# Machine Learning Model

### Framework

Edge Impulse

### Model Type

Object Detection

### Classes

- Paper (Biodegradable)
- Battery (Non-Biodegradable)

### Dataset

The model was trained using images captured under different

- Lighting conditions
- Viewing angles
- Background environments

to improve robustness and generalization.

---

# Performance

| Metric | Value |
|---------|-------|
| Classification Accuracy | ~90% |
| Processing Mode | On-device Inference |
| Internet Required | No |
| Display Output | OLED |
| Waste Segregation | Automatic |
| Inference | Real-Time |

---

# Hardware Connections

| ESP32 Pin | Connected Device |
|------------|----------------|
| GPIO12 | Servo Signal |
| GPIO15 | OLED SDA |
| GPIO2 | OLED SCL |
| 5V | Servo Supply |
| 3.3V | OLED |

---

# Repository Structure

```text
.
├── firmware/
│   └── SmartWasteClassifier.ino
│
├── hardware/
│   ├── wiring_diagram.png
│   ├── circuit_diagram.png
│   └── bill_of_materials.md
│
├── edge_impulse/
│   ├── dataset.md
│   ├── confusion_matrix.png
│   └── training_metrics.png
│
├── images/
│   ├── system_setup.jpg
│   ├── oled_output.jpg
│   ├── architecture.png
│   └── classification_demo.gif
│
├── docs/
│   └── Project_Report.pdf
│
└── README.md
```

---

# Challenges Faced

### Memory Constraints

Large image buffers exceeded the available RAM on the ESP32.

**Solution**

Reduced image resolution and optimized memory allocation.

---

### Lighting Variations

Object detection accuracy decreased under poor lighting.

**Solution**

Collected training images under multiple lighting conditions and viewing angles.

---

### Continuous Servo Movement

Servo repeatedly rotated after each prediction.

**Solution**

Implemented a cooldown mechanism using `millis()` to prevent repeated actuation.

---

### OLED Flickering

Continuous screen refresh caused display flickering.

**Solution**

Updated OLED only after successful object detection.

---

# Results

✔ Successful on-device AI inference

✔ Automatic waste segregation

✔ OLED-based prediction visualization

✔ Fully offline operation

✔ Approximately 90% detection accuracy

---

# Future Improvements

- Support additional waste categories (Plastic, Metal, Glass)
- Deploy quantized TensorFlow Lite model
- Improve detection accuracy using larger datasets
- Integrate MQTT for IoT monitoring
- Develop mobile application dashboard
- Implement OTA firmware updates
- Multi-bin segregation mechanism
- Battery-powered standalone operation

---

# Bill of Materials

| Component | Approx. Cost |
|------------|-------------|
| ESP32-CAM | ₹650 |
| Servo Motor | ₹180 |
| OLED Display | ₹250 |
| Breadboard | ₹120 |
| Jumper Wires | ₹80 |

**Total Estimated Cost:** ₹1280

---

# Applications

- Smart Cities
- Automated Recycling Systems
- Waste Management
- Educational Embedded AI Projects
- Industrial IoT

---

# Author

**Sanat Vasisht**

B.Tech Electronics and Communication Engineering

Vellore Institute of Technology

GitHub: https://github.com/sanatv18

---

# License

This project is released under the MIT License.
