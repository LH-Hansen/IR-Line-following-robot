#pragma once
#include <Arduino.h>

namespace Config
{
    namespace Line
    {
        constexpr uint16_t MAX = 1000;
        constexpr uint16_t MIN = 700;
    }

    namespace Battery
    {
        constexpr float MIN_VOLTAGE = 6.0f;
        constexpr float MAX_VOLTAGE = 8.4f;
        constexpr float DIVIDER_RATIO = 2.0f;
        constexpr float ADC_REF = 5.0f;

        constexpr float SCALE = ADC_REF / 1023.0f * DIVIDER_RATIO;
    }
}