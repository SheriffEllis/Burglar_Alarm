#include "Buzzer.h"

#include "Peripheral.h"
#include "Arduino.h"

Buzzer::Buzzer(int loud_pin, int quiet_pin){
    io_pin = loud_pin;
    this->quiet_pin = quiet_pin;
    // Default parameters
    tone_freq = 400;
}

void Buzzer::setTone(int tone_freq){
    this->tone_freq = tone_freq;
}

void Buzzer::pulse(unsigned long duration, bool is_quiet = false){
    int pin;
    if(is_quiet){pin = quiet_pin;}else{pin = io_pin;}
    tone(pin, tone_freq, duration);
}

void Buzzer::start(bool is_quiet = false){
    int pin;
    if(is_quiet){pin = quiet_pin;}else{pin = io_pin;}
    tone(pin, tone_freq, TIMEOUT); // Run buzzer until the absolute upper limit (20 minutes)
}

void Buzzer::stop(){
    noTone(io_pin);
    noTone(quiet_pin);
}
