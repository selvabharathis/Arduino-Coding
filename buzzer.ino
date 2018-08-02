//S.Selvabharathi  B.Tech IT  Rajalakshmi Engineering College
// code to ping the buzzer
const int buz=13;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buz,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(buz,HIGH);
}

