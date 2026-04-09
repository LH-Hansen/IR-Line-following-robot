#pragma once
#include <Arduino.h>

#include "Drivers/MX1508.h"
#include "Drivers/TRCT5000.h"

class DriveController
{
public:
    DriveController()
        : R2(A0), R1(A1), M(A2), L1(A3), L2(A4),
          motorR(9, 10), motorL(11, 12) {}

    void begin()
    {
        R2.begin();
        R1.begin();
        M.begin();
        L1.begin();
        L2.begin();

        motorR.begin();
        motorL.begin();
    }

    void drive()
    {
        bool center = M.isLineDetected();
        bool right = R1.isLineDetected() || R2.isLineDetected();
        bool left = L1.isLineDetected() || L2.isLineDetected();

        if (center)
        {
            motorR.forward();
            motorL.forward();
        }
        else if (right)
        {
            motorR.backward();
            motorL.forward();
        }
        else if (left)
        {
            motorR.forward();
            motorL.backward();
        }
        else
        {
            motorR.stop();
            motorL.stop();
        }
    }

private:
    TCRT5000 R2, R1, M, L1, L2;
    MX1508 motorR, motorL;
};