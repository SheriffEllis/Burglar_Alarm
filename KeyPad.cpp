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

// wait for input from user without a timeout
void KeyPad::waitForInput(){
    while(!Serial.available()){
        // Do nothing
    }
}

// wait for input from user with a timeout
void KeyPad::waitForInput(unsigned long timer_start, unsigned long timeout){
    while(!Serial.available() and (millis() - timer_start) < timeout){
        // Do nothing
    }
}

// gets a number within the range specified from user input
int KeyPad::getNumber(int upper, int lower){
    bool valid = false;
    int number = 0;
    while(!valid){
        flushSerial();
        Serial.print("\nPlease input a number from ");
        Serial.print(lower);
        Serial.print(" to ");
        Serial.println(upper);
        waitForInput();
        number = Serial.parseInt();
        if(number < lower or number > upper){
            Serial.println("Error: Invalid number. Please input only digits and no letters or characters.");
            Serial.println("Number must be within range specified");
        }else{
            valid = true;
        }
    }
    flushSerial();
    return number;
}

// gets a valid pin (value from 0001 to 9999) without a timer
int KeyPad::getPin(){
    bool valid = false;
    int pin = 0;
    while(!valid){
        flushSerial();
        Serial.println("\nPlease input a 4-digit pin:");
        waitForInput();
        pin = Serial.parseInt();
        if(pin <= 0 or pin > 9999){
            Serial.println("Error: Invalid pin. Please input only 4 digits and no letters or characters.");
            Serial.println("The pin 0000 will not be accepted.");
        }else{
            valid = true;
        }
    }
    flushSerial();
    return pin;
}

// gets a valid pin (value from 0001 to 9999) with a timer
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
        if(pin <= 0 or pin > 9999){
            Serial.println("Error: Invalid pin. Please input only 4 digits and no letters or characters.");
            Serial.println("The pin 0000 will not be accepted.");
        }else{
            valid = true;
        }
    }
    flushSerial();
    return pin;
}

// gets a choice (a number from 0 to 9) from the user
// the largest number that can be chosen is max_choice_num
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
