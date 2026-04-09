#pragma once
#include <Arduino.h>

#include "Drivers/LED.h"
#include "Drivers/VoltageDivider.h"

class BatteryIndicator
{
public:
    BatteryIndicator() : LED_GREEN(2), LED_YELLOW1(3), LED_YELLOW2(4), LED_RED(5), voltageDivider(A6) {}

    void begin()
    {
        LED_GREEN.begin();
        LED_YELLOW1.begin();
        LED_YELLOW2.begin();
        LED_RED.begin();
    }

    void show_power()
    {
        float v = voltageDivider.readVoltage();

        int level = 0;

        if (v >= 8.0f)
            level = 4;
        else if (v >= 7.6f)
            level = 3;
        else if (v >= 7.2f)
            level = 2;
        else if (v >= 6.8f)
            level = 1;

        LED_GREEN.set(level >= 4);
        LED_YELLOW1.set(level >= 3);
        LED_YELLOW2.set(level >= 2);
        LED_RED.set(level >= 1);
    }

private:
    LED LED_GREEN, LED_YELLOW1, LED_YELLOW2, LED_RED;
    VoltageDivider voltageDivider;
};