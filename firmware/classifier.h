/******************************************************************************
 * File        : classifier.h
 * Project     : Edge AI & IoT Smart Waste Classification System
 * Description : Edge Impulse Inference Engine
 ******************************************************************************/

#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <Arduino.h>

/*----------------------------------------------------
                    Waste Types
----------------------------------------------------*/

enum WasteType
{
    PAPER,
    BATTERY,
    UNKNOWN
};

/*----------------------------------------------------
                Detection Result
----------------------------------------------------*/

struct DetectionResult
{
    WasteType type;
    String label;

    float confidence;

    bool detected;
};

/*----------------------------------------------------
                Public Functions
----------------------------------------------------*/

bool initializeClassifier();

DetectionResult runInference();

#endif
