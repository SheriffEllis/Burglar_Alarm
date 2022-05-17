/*
The PIR Peripheral class is a sensor that reads the digital input
of a pin unless it has been disabled.

It also possess a calibrate() process that allows the physical component
time to calibrate at the start of the program.
*/

#ifndef PIR_H
#define PIR_H

#include "Peripheral.h"
#include "Arduino.h"


class PIR : public Peripheral{
  public:
    PIR(int input_pin);
    void calibrate(int seconds);
    bool measure();
};

#endif // PIR_H
