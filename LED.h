/*
 * LED Peripheral class allows LED to be turned on and off and keep track of its state
 */

#ifndef LED_H
#define LED_H

#include "Peripheral.h"
#include "Arduino.h"


class LED : public Peripheral{
  public:
    LED(int output_pin);
    void setState(bool state);
};

#endif // LED_H
