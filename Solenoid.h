/*
 * The Solenoid Peripheral class is a simple actuator class that
 * opens and closes the solenoid and keeps track of its current state
 * open: state = true, closed: state = false
 */

#ifndef SOLENOID_H
#define SOLENOID_H

#include "Peripheral.h"
#include "Arduino.h"

class Solenoid : public Peripheral{
  public:
    Solenoid(int output_pin);
    void open();
    void close();
};

#endif // SOLENOID_H
