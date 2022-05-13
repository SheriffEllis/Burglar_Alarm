#include "Buzzer.h"

#include "Peripheral.h"
#include "Arduino.h"

Buzzer::Buzzer(int loud_pin, int _quiet_pin){
    io_pin = loud_pin;
    quiet_pin = _quiet_pin;
    tone_freq = 400;
    pulse_freq = 1;
    duration = 0;
    start_time = 0;
}

void Buzzer::setTone(int tone_freq){

}

void Buzzer::setPulseFreq(int pulse_freq){

}

void Buzzer::pulsate(long duration, bool is_quiet){

}

void Buzzer::stop(){

}

void Buzzer::update(){

}
