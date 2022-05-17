#include "Solenoid.h"

#include "Peripheral.h"
#include "Arduino.h"

// Constructor sets output pin
Solenoid::Solenoid(int output_pin){
    io_pin = output_pin;
    enabled = true;
    pinMode(io_pin, OUTPUT);
}

// Opens the solenoid and sets state to true
void Solenoid::open(){ 
  state = true; // true = open, false = closed
  digitalWrite(io_pin, state);
}

// Closes the solenoid and sets state to false
void Solenoid::close(){
  state = false;
  digitalWrite(io_pin, state);
}
