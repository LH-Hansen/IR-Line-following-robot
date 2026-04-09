#pragma once
#include <Arduino.h>

class LED
{
public:
    explicit LED(uint8_t pin) : _pin(pin) {}

    void begin()
    {
        pinMode(_pin, OUTPUT);
        off();
    }

    void set(bool state)
    {
        digitalWrite(_pin, state ? HIGH : LOW);
    }

    void on()
    {
        digitalWrite(_pin, HIGH);
    }

    void off()
    {
        digitalWrite(_pin, LOW);
    }

private:
    uint8_t _pin;
};