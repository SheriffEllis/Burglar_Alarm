#include "Solenoid.h"

#include "Peripheral.h"
#include "Arduino.h"

Solenoid::Solenoid(int output_pin){
    io_pin = output_pin;
    enabled = true;
    pinMode(io_pin, OUTPUT);
}

void Solenoid::open(){ 
  state = true; // true = open, false = closed, used as a flag to let update() know to keep running
  digitalWrite(io_pin, state);
}

void Solenoid::close(){
  state = false;
  digitalWrite(io_pin, state);
}

void Solenoid::disable(){
  enabled = false;
  close();
}
