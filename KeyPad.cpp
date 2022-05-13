#include "Arduino.h"
#include "KeyPad.h"

void KeyPad::flushSerial(){
    Serial.flush();
    while(Serial.available()){
        Serial.read(); // Serial.flush alone wont work but this did
    }
}

void KeyPad::waitForInput(){
    while(!Serial.available()){
        // wait for input
    }
}

int KeyPad::getPin(){
    bool valid = false;
    int pin = 0;
    while(!valid){
        flushSerial();
        Serial.println("Please input a 4-digit pin:");
        waitForInput();
        pin = Serial.parseInt();
        if(pin == 0 or pin > 9999){
            Serial.println("Error: Please input only 4 digits and no letters or characters.");
            Serial.println("The pin 0000 will not be accepted.");
        }else{
            valid = true;
        }
    }
    flushSerial();
    return pin;
}

int KeyPad::getChoice(String choices, int maxChoiceNum){
    bool valid = false;
    char choice;
    while(!valid){
        flushSerial();
        Serial.println(choices);
        Serial.print("Choose an option by inputting a digit from 0 to ");
        Serial.println(maxChoiceNum);
        waitForInput();
        choice = Serial.read();
        if(choice < '0' or choice > '0' + maxChoiceNum){
            Serial.print("Error: Please input a SINGLE digit from 0 to ");
            Serial.println(maxChoiceNum);
        }else{
            valid = true;
        }
    }
    flushSerial();
    return choice-'0';
}
