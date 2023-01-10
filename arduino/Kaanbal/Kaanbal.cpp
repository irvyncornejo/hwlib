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
void Motor::toTurn(bool valueA, bool valueB, int velocity=0){
    if(valueA != valueB && velocity == 0){
        _changeStates(valueA, valueB);
    }
    if(valueA != valueB){
        int _first_state = valueA ? velocity : 0;
        int _second_state = valueB ? velocity : 0;
        analogWrite(_poloA, _first_state);
        analogWrite(_poloB, _second_state);
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

// Sensor LM36

TemperatureSensor::TemperatureSensor(int pin, float voltage_ref){
    _pin=pin;
    voltage_ref = voltage_ref;
}
float TemperatureSensor::getValue(){
    int valuePin = analogRead(_pin);
    float tempC = (voltage_ref * valuePin * 100.0)/1024;
    return tempC;
}