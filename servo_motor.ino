//   S.Selvabharathi B.Tech IT  Rajalakshmi Engineering College
//this code move to servo motor handle to the particular degree.
#include<Servo.h>
Servo servo;
void setup() {
  // put your setup code here, to run once:
  servo.attach(2);
  servo.write(0);
  delay(2000);

}

void loop() {
  // put your main code here, to run repeatedly:
servo.write(90);
delay(1000);
servo.write(0);
delay(1000);
}
