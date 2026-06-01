# Edge AI Smart Waste Classification System using ESP32-CAM

![Platform](https://img.shields.io/badge/Platform-ESP32--CAM-blue)
![Edge AI](https://img.shields.io/badge/AI-Edge%20Impulse-green)
![Language](https://img.shields.io/badge/Language-C%2B%2B-orange)
![Status](https://img.shields.io/badge/Status-Completed-success)

## Overview

The **Edge AI Smart Waste Classification System** is a low-cost intelligent waste segregation solution that uses an **ESP32-CAM**, **Edge Impulse Machine Learning**, and **servo-based automation** to classify and sort waste materials in real time.

The system captures images of waste objects, performs on-device inference using a trained machine learning model, identifies the waste category, and automatically directs the waste into the appropriate bin section. An OLED display provides real-time feedback by showing the detected waste type and confidence score.

---

## Demonstration

<p align="center">
  <img src="https://github.com/user-attachments/assets/b126630b-567b-42f4-bc3d-97a1ae8297fc" width="800">
</p>

---

## Table of Contents

* Overview
* Features
* Hardware Components
* Software & Tools
* System Architecture
* System Workflow
* Machine Learning Model
* Results
* Installation & Setup
* Future Improvements
* Project Team
* License

---

## Features

* Real-time waste classification using Edge AI
* ESP32-CAM based image acquisition
* Edge Impulse machine learning integration
* Automated waste segregation using servo motor control
* OLED display for visual feedback
* Compact, low-cost, and energy-efficient design
* Fully on-device processing without cloud computation

---

## Hardware Components

| Component              | Description                 |
| ---------------------- | --------------------------- |
| ESP32-CAM              | Image capture and inference |
| Servo Motor            | Waste sorting mechanism     |
| OLED Display (SSD1306) | Result display              |
| Power Supply           | System power source         |
| Mechanical Structure   | Waste segregation setup     |

---

## Software & Tools

* Arduino IDE
* Edge Impulse
* ESP32 Camera Library
* ESP32Servo Library
* Adafruit SSD1306 Library
* Embedded C/C++

---

## System Architecture

```text
Waste Object
      │
      ▼
ESP32-CAM Image Capture
      │
      ▼
Edge Impulse ML Model
      │
      ▼
Waste Classification
      │
 ┌────┴────┐
 ▼         ▼
OLED     Servo Motor
Display    Control
             │
             ▼
      Waste Segregation
```

---

## System Workflow

1. ESP32-CAM captures an image of the waste object.
2. The image is processed using the Edge Impulse machine learning model.
3. The model predicts the waste category.
4. The classification result and confidence score are displayed on the OLED screen.
5. The servo motor rotates toward the corresponding waste bin section.
6. The waste object is deposited into the correct compartment.
7. The servo returns to its default position and waits for the next object.

---

## Machine Learning Model

The machine learning model was trained using **Edge Impulse** with images collected under varying:

* Lighting conditions
* Viewing angles
* Background environments

### Current Classification Categories

* Biodegradable Waste (Paper)
* Non-Biodegradable Waste (Battery)

The model performs inference directly on the ESP32-CAM, enabling fast and efficient edge processing without requiring internet connectivity.

---

## Results

### Performance Summary

| Metric                  | Value               |
| ----------------------- | ------------------- |
| Classification Accuracy | ~90%                |
| Processing Mode         | On-device Inference |
| Response Time           | Real-time           |
| Waste Sorting           | Automated           |

### Achievements

* Successfully classified waste objects in real time
* Automated segregation using servo-based actuation
* OLED display showed waste category and confidence score
* Reduced need for manual waste sorting

---

## Installation & Setup

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/your-repository-name.git
```

### 2. Open Arduino IDE

Install the required ESP32 board package and libraries.

### 3. Install Required Libraries

* ESP32 Camera Library
* ESP32Servo
* Adafruit SSD1306
* Adafruit GFX

### 4. Upload the Code

Connect the ESP32-CAM and upload the project firmware.

### 5. Run the System

Power the device and place waste objects in front of the camera for classification and sorting.

---

## Future Improvements

* Support for plastic waste classification
* Support for metal and glass waste
* Multi-bin segregation using multiple servo motors
* IoT-based waste analytics and monitoring
* Cloud dashboard for data visualization
* Improved accuracy using larger datasets
* Mobile application integration

---

## Repository Structure

```text
├── src/
├── model/
├── images/
├── hardware/
├── README.md
```

---

## Project Team

### Authors

* Sanat Vasisht
* Varun Shankar

Department of Electronics and Communication Engineering (ECE)

Vellore Institute of Technology (VIT)

---

## License

This project is developed for academic, educational, and research purposes.

© 2026 Vellore Institute of Technology (VIT)
