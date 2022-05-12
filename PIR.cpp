#include "PIR.h"
#include "Arduino.h"

PIR::PIR(int output_pin){
    io_pin = output_pin;
    state = false;
    enabled = true;
    pinMode(io_pin, INPUT);
}

bool PIR::measure(){
    state = digitalRead(io_pin);
    return state;
}
