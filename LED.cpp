#include "LED.h"
#include "Arduino.h"

// Constructor sets pins and default state to off
LED::LED(int output_pin){
    io_pin = output_pin;
    state = false;
    enabled = true;
    pinMode(io_pin, OUTPUT);
}

// Allows LED to be turned on or off and record state
void LED::setState(bool state){
    this->state = state;
    digitalWrite(io_pin, state);
}
