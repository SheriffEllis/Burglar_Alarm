#include "Arduino.h"
#include "Controller.h"

#include "KeyPad.h"
#include "FacialRecognition.h"
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
    timer_start = 0;
}

void Controller::armAlarm(){
    Serial.println("Arming alarm system...\n20 second countdown begun");
    solenoid.open(); // Open door until end of countdown
    buzzer.setTone(400);
    for (int i = 20; i >= 0; i--) // TODO: update timer for demo
    {
        Serial.print(i);
        Serial.println("s");
        buzzer.pulse(500, true); // quiet short pulses
        delay(1000);
    }
    Serial.println("System Armed.");
    armed_LED.setState(true);
    solenoid.close();
    buzzer.setTone(1000);
    buzzer.pulse(1000); // longer loud pulse
}

bool Controller::armedCheck(){
    if(magnetic_switch.getState() or pir.getState() or solenoid.getState()){ // Also check status of solenoid for when facial rec succeeds
        if(!solenoid.getState()){
            Serial.println("Sensors triggered, 20s countdown started.");
            Serial.println("Successful facial recognition must occur before");
            Serial.println("PIN can be entered to stop the countdown.");
        }
        timer_start = millis(); // Start timer
        buzzer.pulse(COUNTDOWN, true);
        pin_handler.resetTries();
        return true;
    }
    return false;
}

// TODO
void Controller::triggerAlarm(){
    triggered_LED.setState(true);
    buzzer.start(); // Buzzer will stop on its own after 20 minutes
    Serial.println("ALARM TRIGGERED");
    // TODO take log
    // TODO send alert
}

void Controller::resetAlarm(){
    armed_LED.setState(false);
    triggered_LED.setState(false);
    solenoid.close();
    pin_handler.resetTries();
    buzzer.stop();
    logger.logEvent(Event::alarmReset);
}

// TODO
void Controller::sendAlert(int event_type){

}

/*
 *  TODO: add logger statements throughout
 *  0 - Initial state
 *  1 - Alarm disabled, waiting on user to log in
 *  3 - Main menu
 *  4 - Arm Alarm
 *  6 - Armed state
 *  7 - Sensors triggered OR Facial recognition success
 *  11 - Waiting for PIN in triggered state
 *  13 - Check sensors and Log TODO
 *  14 - System Settings TODO
 *  15 - Setting new pin TODO
 *  16 - Setting facial recognition TODO
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
                Serial.println("your PIN must be re-entered to continue");
                Serial.println("There is no limit to the number of attempts.");
                if(pin_handler.verifyPin(keypad.getPin())){
                    system_state = 3; // Main menu
                };
                pin_handler.resetTries(); // Incorrect pin entry, try again (main loop)
            }break;

        case 3: // Main menu
            {
                int choice = keypad.getChoice("0 - Back\n1 - System Settings\n2 - Check Sensors\n3 - Arm Alarm", 3);
                switch(choice){
                    case 0:
                        system_state = 0; // Initial state
                        break;
                    case 1:
                        system_state = 14; // System Settings
                        break;
                    case 2:
                        system_state = 13; // Check Sensors and Log
                        break;
                    case 3:
                        if(facial_recognition.getIsSetup()){
                            system_state = 4; // Arm Alarm
                        }else{
                            Serial.println("Please set up facial recognition before arming the alarm.");
                            system_state = 16; // Setting up facial recognition
                        }
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
                if(armedCheck()){
                    system_state = 7;
                }
            }break;

        case 7: // Sensors triggered OR Facial recognition success
            {
                if(pin_handler.getTries() > 3 or (millis() - timer_start) >= COUNTDOWN){ // If tries or timer exceeded
                    triggerAlarm();
                    system_state = 11; // Waiting for PIN in triggered state
                }
                if(solenoid.getState()){ // If facial rec succeeded, await PIN
                    while(pin_handler.getTries() <= 3 and (millis() - timer_start) < COUNTDOWN){ // While tries haven't been exceeded, nor timer
                        if(pin_handler.verifyPin(keypad.getPin(timer_start, COUNTDOWN))){ // If correct pin successfully entered
                            system_state = 0; // Return to unarmed state
                            return;
                        }else if((millis() - timer_start) < COUNTDOWN){ // If timer exceeded, skip this
                            // Display number of tries left
                            Serial.print(3 - pin_handler.getTries());
                            Serial.println(" tries remain.");
                        }
                    }
                }
            }break;

        case 11: // Waiting for PIN in triggered state
            {
                while(!pin_handler.verifyPin(keypad.getPin())){ // Wait for correct PIN
                    // TODO take a log of additional failed pins
                }
                system_state = 0; // Return to unarmed state
            }break;

        case 16: // Setting up facial recognition
            {
                facial_recognition.setup();
                if(facial_recognition.getIsSetup()){
                    system_state = 3; // Return to Main Menu
                }
            }break;

        default:
            {
                Serial.println("Invalid state detected, resetting system");
                system_state = 0;
            }break;
    }
}

void Controller::updateSensors(){
    if(magnetic_switch.getEnabled()){magnetic_switch.measure();}
    if(pir.getEnabled()){pir.measure();}

    if(facial_recognition.checkFace()){
        solenoid.open(); // Will remain open until pin successfully entered or alarm triggered
    }
}