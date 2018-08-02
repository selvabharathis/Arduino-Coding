// S.Selvabharathi B.Tech  IT  Rajalakshmi Engineering College
//this is a sample code to take any device to work with microcontroller,such as to run and stop a motor,fan,led,ldr etc.
const int fanpin=16;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  delay(10);
  pinMode(fanpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//delay(100000000);
// digitalWrite(fanpin,LOW);
// delay(100000000);
  digitalWrite(fanpin,HIGH);
}

