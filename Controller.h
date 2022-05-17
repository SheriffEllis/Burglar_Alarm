/*
 * The Controller class is in charge of managing all of the other sensor and actuator classes
 * as well as using the keypad to provide the user interface. Its two public functions,
 * processSysState() and updateSensors() are intended to be run in the main loop and handle
 * the system's logic internally.
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Arduino.h"

#include "KeyPad.h"
#include "FacialRecognition.h"
#include "PinHandler.h"
#include "Logger.h"
#include "LED.h"
#include "Buzzer.h"
#include "Solenoid.h"
#include "MagneticSwitch.h"
#include "PIR.h"

class Controller{
  private:
    // keeps track of the system state loosely based on the UML state diagram
    int system_state;
    
    // system setting for how long to allow for pin entry before setting off alarm
    // also decides countdown of system before arming to let user leave building
    unsigned long countdown;

    // variable for use with non-delay timers
    unsigned long timer_start; 

    KeyPad keypad;
    FacialRecognition facial_recognition;
    PinHandler pin_handler;
    Logger logger;

    // armed LED indicates system is listening for sensor input
    // triggered LED indicates alarm has been fully set off and alerts have been sent
    LED armed_LED, triggered_LED;
    
    Buzzer buzzer;
    Solenoid solenoid;
    MagneticSwitch magnetic_switch;
    PIR pir;

    void armAlarm();
    bool armedCheck();
    void triggerAlarm();
    void resetAlarm();
    void sendAlert();
    void displaySensors();
  public:
    Controller(int armed_LED_pin, int triggered_LED_pin, int loud_buzz_pin, int quiet_buzz_pin, int solenoid_pin, int magswitch_pin, int PIR_pin);
    void processSysState();
    void updateSensors();
    void calibrate(int seconds);
};

#endif // CONTROLLER_H
