#ifndef Kaanbal_h
#define Kaanbal_h

#include "Arduino.h"

class SingleActuator {
    public:
        SingleActuator(int pin);
        void changeState(bool ref);
        void pwmValue(int value);
    private:
        int _pin;   
};

class SingleDigitalSensor {
    public:
        SingleDigitalSensor(int pin);
        bool readState();

    private:
        int _pin;
};

class Motor{
    public:
        Motor(int poloA, int poloB);
        void toTurn(bool valueA, bool valueB);
        void toStop();
    private:
        int _poloA;
        int _poloB;
};

#endif