#include "Arduino.h"
#include "SingleActuator.h"


SingleActuator::SingleActuator(int pin){
    pinMode(pin, OUTPUT);
    _pin = pin;
}

void SingleActuator::changeState(bool ref){
    digitalWrite(_pin, ref);
}

void SingleActuator::pwmValue(int value){
    analogWrite(_pin, value);
}
