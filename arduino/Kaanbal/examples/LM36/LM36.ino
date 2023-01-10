#include <Kaanbal.h>

TemperatureSensor temperatureSensor(A5, 3.3);

void setup() {
  // open serial monitor
  Serial.begin(9600);
  Serial.println("Serial...");
}

void loop() {
  float temperatureSensorValue = temperatureSensor.getValue();
  Serial.println("Value -> " + String(temperatureSensorValue));
  delay(300);
}