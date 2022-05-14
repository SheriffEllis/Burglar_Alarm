#include "LED.h"
#include "Arduino.h"

LED::LED(int output_pin){
    io_pin = output_pin;
    state = false;
    enabled = true;
    pinMode(io_pin, OUTPUT);
}

void LED::setState(bool state){
    this->state = state;
    digitalWrite(io_pin, state);
}

void LED::disable(){
    enabled = false;
    setState(false);
}
