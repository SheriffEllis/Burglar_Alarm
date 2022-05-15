#ifndef FACIALRECOGNITION_H
#define FACIALRECOGNITION_H

#define SPECIAL_CHAR 'f' // Special ASCII character that denotes a facial rec transmission

#include "Arduino.h"

class FacialRecognition{
    private:
        bool is_setup;
        bool pendResponse(long timeout);
    public:
        FacialRecognition();
        void setup();
        bool getIsSetup();
        bool addFace();
        bool resetFaces();
        bool checkFace();
};

#endif // FACIALRECOGNITION_H
