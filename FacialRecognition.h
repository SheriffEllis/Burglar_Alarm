#ifndef FACIALRECOGNITION_H
#define FACIALRECOGNITION_H

#include "Arduino.h"

class FacialRecognition{
    private:
        const static char SPECIAL_CHAR = '-'; // Special ASCII character that denotes a facial rec transmission
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
