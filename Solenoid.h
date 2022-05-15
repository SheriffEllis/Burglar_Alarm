#ifndef SOLENOID_H
#define SOLENOID_H

#include "Peripheral.h"
#include "Arduino.h"

class Solenoid : public Peripheral{
  public:
    Solenoid(int output_pin);
    void open();
    void close();
    void disable();
};

#endif // SOLENOID_H
