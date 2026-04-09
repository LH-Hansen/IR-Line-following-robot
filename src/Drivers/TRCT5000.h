#pragma once
#include <Arduino.h>
#include "../Config.h"

class TCRT5000
{
public:
    explicit TCRT5000(uint8_t pin) : _pin(pin) {}

    void begin()
    {
        pinMode(_pin, INPUT);
    }

    bool isLineDetected()
    {
        return analogRead(_pin) > Config::Line::MIN && analogRead(_pin) < Config::Line::MAX;
    }

private:
    uint8_t _pin;
};