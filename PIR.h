#ifndef PIR_H
#define PIR_H

#include "Peripheral.h"
#include "Arduino.h"


class PIR : public Peripheral{
  public:
    long time_of_last_measure;
    PIR(int input_pin);
    bool measure();
};

#endif // PIR_H
