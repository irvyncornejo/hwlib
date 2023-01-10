#include <Kaanbal.h>

SingleDigitalSensor touchButton(5);

void setup() {
  // open serial monitor
  Serial.begin(9600);
  Serial.println("Serial...");
}

void loop() {
  String touchSensorValue = touchButton.readState() ? "HIGH" : "LOW";
  Serial.println("Value -> "+ touchSensorValue);
  delay(300);
}