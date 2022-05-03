#ifndef PERIPHERAL_H
#define PERIPHERAL_H

#include "Arduino.h"

class Peripheral{
  protected:
    bool state;
    int io_pin;
  public:
    bool enabled;
    bool getState(){
      return state;
    }
};

#endif // PERIPHERAL_H
