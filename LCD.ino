// S.Selvabharathi  B.Tech IT  Rajalakshmi Engineering College
//this code is used to connect the 16x2 LCD to the microcontroller
//note: be sure in connecting pins number correctly
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,13,10,4,15,2);// not necessory to give this pin only
void setup()
{
  lcd.begin(16,2);
}
void loop()
{
  lcd.setCursor(0,0);//first row first char
  lcd.print("hello guys");
  delay(10);
  lcd.setCursor(0,1);//second row first char
  lcd.print("welcome to ");
  lcd.print("peep for learning");
  delay(10);
}


