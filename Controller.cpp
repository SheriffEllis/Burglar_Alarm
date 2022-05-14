#include "Arduino.h"
#include "Controller.h"

#include "KeyPad.h"
//#include "FacialRecognition.h"
#include "PinHandler.h"
#include "Logger.h"
#include "LED.h"
#include "Buzzer.h"
#include "Solenoid.h"
#include "MagneticSwitch.h"
#include "PIR.h"

Controller::Controller(int armed_LED_pin, int triggered_LED_pin, int loud_buzz_pin,
    int quiet_buzz_pin, int solenoid_pin, int magswitch_pin, int PIR_pin):
        armed_LED(armed_LED_pin),
        triggered_LED(triggered_LED_pin),
        buzzer(loud_buzz_pin, quiet_buzz_pin),
        solenoid(solenoid_pin),
        magnetic_switch(magswitch_pin),
        pir(PIR_pin)
{
    system_state = 0;
}

// TODO
void Controller::armAlarm(){

}

// TODO
void Controller::triggerAlarm(){

}

void Controller::resetAlarm(){
    armed_LED.setState(false);
    triggered_LED.setState(false);
    buzzer.stop();
}

// TODO
void Controller::sendAlert(int event_type){

}

// TODO
void Controller::processSysState(){
    switch(system_state){
        case 0: // Initial state
            Serial.println("System unarmed");
            resetAlarm();
            system_state = 1; // Alarm disabled waiting on user to log in
            break;

        case 1: // Alarm disabled, waiting on user to log in
            Serial.println("Pin must be re-entered to continue");
            Serial.println("No limit to number of attempts.");
            if(pin_handler.verifyPin(keypad.getPin())){
                system_state = 2; // Enter main menu
            };
            pin_handler.resetTries();
            break;

        case 2: // Main menu
            
            break;

        default:
            Serial.println("Invalid state detected, resetting system");
            system_state = 0;
            break;
    }
}

void Controller::updateTimers(){
    solenoid.update();
}

void Controller::updateSensors(){
    if(magnetic_switch.getEnabled()){magnetic_switch.measure();}
    if(pir.getEnabled()){pir.measure();}
}