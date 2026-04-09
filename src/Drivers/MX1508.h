#pragma once
#include <Arduino.h>

class MX1508
{
public:
    explicit MX1508(uint8_t pin1, uint8_t pin2) : _pin1(pin1), _pin2(pin2) {}

    void begin()
    {
        pinMode(_pin1, OUTPUT);
        pinMode(_pin2, OUTPUT);
    }

    void forward()
    {
        digitalWrite(_pin1, HIGH);
        digitalWrite(_pin2, LOW);
    }

    void backward()
    {
        digitalWrite(_pin1, LOW);
        digitalWrite(_pin2, HIGH);
    }

    void stop()
    {
        digitalWrite(_pin1, LOW);
        digitalWrite(_pin2, LOW);
    }

private:
    uint8_t _pin1;
    uint8_t _pin2;
};