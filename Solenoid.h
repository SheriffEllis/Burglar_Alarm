#ifndef SOLENOID_H
#define SOLENOID_H

#include "Peripheral.h"
#include "Arduino.h"

class Solenoid : public Peripheral{
  private:
    unsigned long duration; // Stored in milliseconds
    unsigned long start_time;
  public:
    Solenoid(int output_pin);
    void open(unsigned long duration);
    void update();
    void close();
};

#endif // SOLENOID_H
