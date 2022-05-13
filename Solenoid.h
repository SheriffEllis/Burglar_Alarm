#ifndef SOLENOID_H
#define SOLENOID_H

#include "Peripheral.h"
#include "Arduino.h"

class Solenoid : public Peripheral{
  private:
    long duration;
    long start_time;
  public:
    Solenoid(int output_pin);
    void open(long duration);
    void update();
    void close();
};

#endif // SOLENOID_H
