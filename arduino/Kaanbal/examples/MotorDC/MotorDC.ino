#include <Kaanbal.h>

Motor motor_a(A0, A1);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  motor_a.turnLeft();
  delay(2000);
  motor_a.toStop();
  motor_a.turnLeft();
  delay(2000);
  motor_a.toStop();
}