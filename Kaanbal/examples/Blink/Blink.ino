#include <Kaanbal.h>

SingleActuator led(13);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  led.changeState(HIGH);
  delay(1000);
  led.changeState(LOW);
  delay(1000);
}