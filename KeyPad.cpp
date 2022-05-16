#include "Arduino.h"
#include "KeyPad.h"

// empties the serial input and output buffer
// Serial.flush alone doesn't do what I need this to do
void KeyPad::flushSerial(){
    Serial.flush();
    while(Serial.available()){
        Serial.read();
    }
}

// wait for input without a timeout
void KeyPad::waitForInput(){
    while(!Serial.available()){
        // Do nothing
    }
}

// wait for input with a timeout
void KeyPad::waitForInput(unsigned long timer_start, unsigned long timeout){
    while(!Serial.available() and (millis() - timer_start) < timeout){
        // Do nothing
    }
}

int KeyPad::getPin(){
    bool valid = false;
    int pin = 0;
    while(!valid){
        flushSerial();
        Serial.println("\nPlease input a 4-digit pin:");
        waitForInput();
        pin = Serial.parseInt();
        if(pin == 0 or pin > 9999){
            Serial.println("Error: Invalid pin. Please input only 4 digits and no letters or characters.");
            Serial.println("The pin 0000 will not be accepted.");
        }else{
            valid = true;
        }
    }
    flushSerial();
    return pin;
}

int KeyPad::getPin(unsigned long timer_start, unsigned long timeout){
    bool valid = false;
    int pin = 0;
    while(!valid){
        flushSerial();
        Serial.println("\nPlease input a 4-digit pin:");
        waitForInput(timer_start, timeout);
        if((millis() - timer_start) >= timeout){
            Serial.println("TIMEOUT EXCEEDED");
            flushSerial();
            return -1; // -1 represents failed pin entry
        }
        pin = Serial.parseInt();
        if(pin == 0 or pin > 9999){
            Serial.println("Error: Invalid pin. Please input only 4 digits and no letters or characters.");
            Serial.println("The pin 0000 will not be accepted.");
        }else{
            valid = true;
        }
    }
    flushSerial();
    return pin;
}

int KeyPad::getChoice(int max_choice_num){
    bool valid = false;
    char choice;
    while(!valid){
        Serial.print("\nChoose an option by inputting a digit from 0 to ");
        Serial.println(max_choice_num);
        flushSerial();
        waitForInput();
        choice = Serial.read();
        if(choice < '0' or choice > '0' + max_choice_num){
            Serial.print("Error: Please input a SINGLE digit from 0 to ");
            Serial.println(max_choice_num);
        }else{
            valid = true;
        }
    }
    flushSerial();
    return choice-'0'; // Convert number char to int
}
