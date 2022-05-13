#ifndef MAGNETICSWITCH_H
#define MAGNETICSWITCH_H

#include "Peripheral.h"
#include "Arduino.h"


class MagneticSwitch : public Peripheral{
  public:
    MagneticSwitch(int input_pin);
    bool measure();
};

#endif // MAGNETICSWITCH_H
