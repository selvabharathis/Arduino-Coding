// S.Selvabharathi  B.Tech IT  Rajalakshmi Engineering College
// this code is used to get signal(ppm) from gassensor and if ppm is above certain level led will glow. 
//note: led is pin 16 to your microcontroller
#include "MQ135.h"
int airquality;
MQ135 gasSensor=MQ135(A0);
const int led=16;


void setup() 
{
  Serial.begin(115200);
  delay(10);
  pinMode(led,OUTPUT);
  
}
void loop() 
{
  delay(500);
  float airquality=gasSensor.getPPM();
  Serial.println( airquality);
  if(airquality<=40)
  {
    digitalWrite(led,LOW);
  }
  else 
  {
    digitalWrite(led,HIGH);
  }
  
 }



