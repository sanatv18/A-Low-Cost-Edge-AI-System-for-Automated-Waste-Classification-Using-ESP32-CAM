/******************************************************************************
 * File        : classifier.cpp
 * Project     : Edge AI & IoT Smart Waste Classification System
 * Description : Edge Impulse Inference Engine
 ******************************************************************************/

#include "classifier.h"

#include "camera.h"

#include "config.h"

#include <ai_and_iot_smart_bin_inferencing.h>

#include "edge-impulse-sdk/dsp/image/image.hpp"

/*----------------------------------------------------
            Initialize Classifier
----------------------------------------------------*/

bool initializeClassifier()
{
    Serial.println("--------------------------------");

    Serial.println("Edge Impulse Initialized");

    Serial.println("--------------------------------");

    return true;
}

/*----------------------------------------------------
             Run Edge AI Inference
----------------------------------------------------*/

DetectionResult runInference()
{
    DetectionResult result;

    result.detected = false;

    result.type = UNKNOWN;

    result.label = "Unknown";

    result.confidence = 0.0;

    /* Allocate Image Buffer */

    snapshotBuffer = (uint8_t*)malloc(
        CAMERA_FRAME_WIDTH *
        CAMERA_FRAME_HEIGHT *
        CAMERA_FRAME_CHANNELS);

    if(snapshotBuffer == nullptr)
    {
        Serial.println("Image Buffer Allocation Failed");

        return result;
    }

    ei::signal_t signal;

    signal.total_length =
        EI_CLASSIFIER_INPUT_WIDTH *
        EI_CLASSIFIER_INPUT_HEIGHT;

    signal.get_data = &getCameraData;

    if(!captureImage(
            EI_CLASSIFIER_INPUT_WIDTH,
            EI_CLASSIFIER_INPUT_HEIGHT,
            snapshotBuffer))
    {
        free(snapshotBuffer);

        return result;
    }

    ei_impulse_result_t inferenceResult = {0};

    EI_IMPULSE_ERROR err =
        run_classifier(
            &signal,
            &inferenceResult,
            DEBUG_MODE);

    if(err != EI_IMPULSE_OK)
    {
        Serial.println("Inference Failed");

        free(snapshotBuffer);

        return result;
    }

#if EI_CLASSIFIER_OBJECT_DETECTION == 1

    for(uint32_t i=0;
        i<inferenceResult.bounding_boxes_count;
        i++)
    {

        auto bb =
            inferenceResult.bounding_boxes[i];

        if(bb.value == 0)
            continue;

        result.detected = true;

        result.label = String(bb.label);

        result.confidence =
            bb.value * 100.0;

        if(result.label == "paper")
        {
            result.type = PAPER;
        }
        else if(result.label == "battery")
        {
            result.type = BATTERY;
        }
        else
        {
            result.type = UNKNOWN;
        }

        break;
    }

#endif

    free(snapshotBuffer);

    return result;
}
