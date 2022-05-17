/*
The Peripheral class is a parent class to all peripherals including sensors and actuators.
The primary job of the Peripheral class is to store the io pin and state of a peripheral.
It also keeps track of whether or not certain peripherals such as the Magnetic switch
and PIR are enabled, allowing them to take measurements.

The Peripheral class cannot do anything on its own.
*/

#ifndef PERIPHERAL_H
#define PERIPHERAL_H

#include "Arduino.h"

class Peripheral{
  protected:
    bool state;
    int io_pin;
    bool enabled;
  public:
    void disable(){
      enabled = false;
      state = false; // state should also be set to false to prevent being locked HIGH
    }
    void enable(){
      enabled = true;
    }
    bool getEnabled(){
      return enabled;
    }
    bool getState(){
      return state;
    }
};

#endif // PERIPHERAL_H
