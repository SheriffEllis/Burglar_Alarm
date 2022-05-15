#include "FacialRecognition.h"
#include "Arduino.h"

FacialRecognition::FacialRecognition(){
    is_setup = false;
}

bool FacialRecognition::pendResponse(long timeout){
    return true;
}

void FacialRecognition::setup(){
    is_setup = true;
}

bool FacialRecognition::getIsSetup(){
    return is_setup;
}

bool FacialRecognition::addFace(){
    return true;
}

bool FacialRecognition::resetFaces(){
    is_setup = false;
    return true;
}

bool FacialRecognition::checkFace(){
    char codeChar = Serial.peek();
    if(codeChar == SPECIAL_CHAR){
        Serial.read(); // dump codeChar
        char decision = Serial.read(); // Should be y or n
        Serial.flush();
        if(decision == 'y'){
            Serial.println("Valid Face Detected");
            return true;
        }else{
            Serial.println("Failed to Detect a Valid Face");
        }
    }
    return false; // otherwise return false
}
