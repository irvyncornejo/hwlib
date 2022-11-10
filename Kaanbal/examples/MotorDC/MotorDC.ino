#include <Kaanbal.h>

Motor motor_a(A0, A1);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  motor_a.toTurn(1,0);
  delay(2000);
  motor_a.toStop();
  delay(500);
  motor_a.toTurn(0,1);
  delay(2000);
}