#include "FacialRecognition.h"
#include "Arduino.h"

// Facial rec is not setup by default and will prompt the user to set it up
FacialRecognition::FacialRecognition(){
    is_setup = false;
}

// Would use the output of addFace() to determine success but in this implementation
// will always return true
void FacialRecognition::setup(){
    is_setup = addFace();
    if(is_setup){
        Serial.println("Facial Recognition successfully set up.");
    }else{
        Serial.println("Failed to set up Facial Recognition, please try again.");
    }
}

// Getter method for is_setup
bool FacialRecognition::getIsSetup(){
    return is_setup;
}

// Would return true if MATLAB returned positive confirmation of a new face added to the list
// but in this implementation just returns true
bool FacialRecognition::addFace(){
    Serial.println("Face added to allow list.");
    return true;
}

// Would prompt MATLAB to empty the face list. 
bool FacialRecognition::resetFaces(){
    Serial.println("Allow list reset.");
    is_setup = false;
    return true;
}

// In this implementation this scans serial input for the phrase "-f"
// first looking for the command character '-' normally MATLAB would output this automatically
bool FacialRecognition::checkFace(){
    if(Serial.available()){
        char codeChar = Serial.peek();
        if(codeChar == SPECIAL_CHAR){
            String message = Serial.readString();
            if(message[1] == 'f'){
                Serial.println("Valid Face Detected");
                return true;
            }else{
                // If the output is '-' followed by anything else this will be considered a failed attempt
                Serial.println("Failed to Detect a Valid Face");
            }
        }
    }
    return false; // otherwise return false
}
