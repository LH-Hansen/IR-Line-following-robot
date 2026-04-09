#pragma once
#include <Arduino.h>
#include "../Config.h"

class VoltageDivider
{
public:
    explicit VoltageDivider(uint8_t pin) : _pin(pin) {}

    void begin()
    {
        pinMode(_pin, INPUT);
    }

    float readVoltage()
    {
        return analogRead(_pin) * Config::Battery::SCALE;
    }

private:
    uint8_t _pin;
};