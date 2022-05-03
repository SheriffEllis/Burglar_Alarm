#include "LED.h"
#include "Arduino.h"

LED::LED(int output_pin){
    io_pin = output_pin;
    state = false;
    enabled = true;
    pinMode(io_pin, OUTPUT);
}

void LED::setState(bool _state){
    state = _state;
    digitalWrite(io_pin, state);
}
