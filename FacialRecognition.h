/*
This facial recognition class has not been fully implemented due to time constraints.
Normally this would listen for input from MATLAB on the results of facial recognition
as well as send prompts for actions to the MATLAB script. However in this program it
simply returns fake positives for setting up faces and listens in the serial monitor for
the phrase "-f" to indicate a successful facial recognition.
*/

#ifndef FACIALRECOGNITION_H
#define FACIALRECOGNITION_H

#include "Arduino.h"

class FacialRecognition{
    private:
        const static char SPECIAL_CHAR = '-'; // Special ASCII character that denotes a facial rec transmission
        bool is_setup;
    public:
        FacialRecognition();
        void setup();
        bool getIsSetup();
        bool addFace();
        bool resetFaces();
        bool checkFace();
};

#endif // FACIALRECOGNITION_H
