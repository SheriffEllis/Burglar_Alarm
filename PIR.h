#ifndef PIR_H
#define PIR_H

#include "Peripheral.h"
#include "Arduino.h"


class PIR : public Peripheral{
  public:
    PIR(int output_pin);
    bool measure();
};

#endif // PIR_H
