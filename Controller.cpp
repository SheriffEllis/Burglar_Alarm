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
    Serial.begin(9600);
    system_state = 0;
}

void Controller::armAlarm(){
    armed_LED.setState(true);
    Serial.println("Arming alarm system...\n1 minute countdown begun");
    buzzer.setTone(400);
    for (int i = 60; i >= 0; i--)
    {
        Serial.print(i);
        Serial.println("s");
        buzzer.pulse(500, true); // quiet short pulses
        delay(1000);
    }
    buzzer.setTone(1000);
    buzzer.pulse(1000); // longer loud pulse
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
/*
 *  0 - Initial state
 *  1 - Alarm disabled, waiting on user to log in
 *  3 - Main menu
 *  4 - Arm Alarm
 *  6 - Armed state
 *  7 - Sensors triggered OR Facial recognition success
 *  10 - Alarm triggered: Set off all alerts
 *  11 - Waiting for PIN in triggered state
 *  13 - Check sensors
 *  14 - System Settings
 *  15 - Setting new pin
 *  16 - Setting facial recognition
 */
void Controller::processSysState(){
    switch(system_state){
        case 0: // Initial state
            {
                Serial.println("System unarmed");
                resetAlarm();
                system_state = 1; // Alarm disabled waiting on user to log in
            }break;

        case 1: // Alarm disabled, waiting on user to log in
            {
                Serial.println("Pin must be re-entered to continue");
                Serial.println("No limit to number of attempts.");
                if(pin_handler.verifyPin(keypad.getPin())){
                    system_state = 3; // Main menu
                };
                pin_handler.resetTries();
            }break;

        case 3: // Main menu
            {
                int choice = keypad.getChoice("0 - Back\n1 - System Setting\n2 - Check Sensors\n3 - Arm Alarm", 3);
                switch(choice){
                    case 0:
                        system_state = 0; // Initial state
                        break;
                    case 1:
                        system_state = 14; // System Settings
                        break;
                    case 2:
                        system_state = 13; // Check Sensors
                        break;
                    case 3:
                        system_state = 4; // Arm Alarm
                        break;
                    default:
                        system_state = 0;
                        break;
                }
            }break;
        
        case 4: // Arm Alarm
            {
                armAlarm();
                system_state = 6; // Armed state
            }break;

        case 6: // Armed state
            {
                // Check on sensors and facial recognition
            }break;

        default:
            {
                Serial.println("Invalid state detected, resetting system");
                system_state = 0;
            }break;
    }
}

void Controller::updateTimers(){
    solenoid.update();
}

void Controller::updateSensors(){
    if(magnetic_switch.getEnabled()){magnetic_switch.measure();}
    if(pir.getEnabled()){pir.measure();}
}