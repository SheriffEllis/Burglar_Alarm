#ifndef FACIALRECOGNITION_H
#define FACIALRECOGNITION_H

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
        bool checkFace();
};

#endif // FACIALRECOGNITION_H
