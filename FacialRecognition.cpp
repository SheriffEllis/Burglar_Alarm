#include "FacialRecognition.h"
#include "Arduino.h"

FacialRecognition::FacialRecognition(){
    is_setup = false;
}

bool FacialRecognition::pendResponse(long timeout){
    return true;
}

void FacialRecognition::setup(){
    is_setup = addFace();
    if(is_setup){
        Serial.println("Facial Recognition successfully set up.");
    }else{
        Serial.println("Failed to set up Facial Recognition, please try again.");
    }
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
    if(Serial.available()){
        char codeChar = Serial.peek();
        if(codeChar == SPECIAL_CHAR){
            String message = Serial.readString();
            if(message[1] == 'f'){
                Serial.println("Valid Face Detected");
                return true;
            }else{
                Serial.println("Failed to Detect a Valid Face");
            }
        }
    }
    return false; // otherwise return false
}
