#include "Arduino.h"
#include "Kaanbal.h"

// Single Digital Actuator 
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
// Single Digital Sensor
SingleDigitalSensor::SingleDigitalSensor(int pin){
    pinMode(pin, INPUT);
    _pin = pin;
}

bool SingleDigitalSensor::readState(){
    return digitalRead(_pin);
}

// Single DC Motor
Motor::Motor(int poloA, int poloB){
    _poloA = poloA;
    _poloB = poloB;
    pinMode(_poloA, OUTPUT);
    pinMode(_poloB, OUTPUT);
  }
void Motor::_changeStates(bool valueA, bool valueB){
    digitalWrite(_poloA, valueA);
    digitalWrite(_poloB, valueB);
}
void Motor::toTurn(bool valueA, bool valueB){
    if(valueA != valueB){
        _changeStates(valueA, valueB);
    }
}
void Motor::toStop(){
    _changeStates(LOW, LOW);
    delay(500);
}

void Motor::turnRight(){
    _changeStates(LOW, HIGH);
}
void Motor::turnLeft(){
    _changeStates(HIGH, LOW);
}