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
        // wait for input without a timeout
    }
}

void KeyPad::waitForInput(unsigned long timer_start){
    while(!Serial.available() and (millis() - timer_start) < TIMEOUT){
        // wait for input with a timeout
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
            Serial.println("Error: Invalid pin. Please input only 4 digits and no letters or characters.");
            Serial.println("The pin 0000 will not be accepted.");
        }else{
            valid = true;
        }
    }
    flushSerial();
    return pin;
}

int KeyPad::getPin(unsigned long timer_start){
    bool valid = false;
    int pin = 0;
    while(!valid){
        flushSerial();
        Serial.println("Please input a 4-digit pin:");
        waitForInput(timer_start);
        if((millis() - timer_start) >= TIMEOUT){
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

int KeyPad::getChoice(String choices[], int max_choice_num){
    bool valid = false;
    char choice;
    while(!valid){
        flushSerial();
        for (int i = 0; i <= max_choice_num; i++){
            Serial.println(choices[i]);
        }
        Serial.print("Choose an option by inputting a digit from 0 to ");
        Serial.println(max_choice_num);
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
    return choice-'0';
}
