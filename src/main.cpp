#include <Arduino.h>

#include "Controllers/DriveController.h"
#include "Controllers/BatteryIndicator.h"

DriveController driveController;
BatteryIndicator batteryIndicator;

void setup() {
    Serial.begin(9600);

    driveController.begin();
    batteryIndicator.begin();
}

void loop() {
    unsigned long lastBattery = 0;
    
    driveController.drive();

    if (millis() - lastBattery > 200) {
        batteryIndicator.show_power();
        lastBattery = millis();
    }
}

