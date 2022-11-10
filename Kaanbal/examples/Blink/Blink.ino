#include <Kaanbal.h>

SingleActuator led(13);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  led.changeState(1);
  delay(1000);
  led.changeState(0);
  delay(1000);
}