#ifndef SingleActuator_h
#define SingleActuator_h

#include "Arduino.h"

class SingleActuator {
    public:
        SingleActuator(int pin);
        void changeState(bool ref);
        void pwmValue(int value);
    private:
        int _pin;   
};

#endif