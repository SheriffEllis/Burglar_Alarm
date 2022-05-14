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
      state = false;
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
