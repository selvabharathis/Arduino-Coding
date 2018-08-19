//   S.Selvabharathi  B.Tech IT   Rajalakshmi Engineering College 
// vcc->3v to 5v , gnd->gnd ,out->analog pin of microcontroller
//NOTE: pir has sensitivity adjustment,duration adjestment and trigger(non-repeating and repeating) if trigger is in repeat mode the led will blink on and off , so becarefull with all the constrains.

int led = D6;
int pir=D7;
int state=0;

void setup() {
  pinMode(pir, INPUT); 
  pinMode(led, OUTPUT); 
}

void loop(){
  state = digitalRead(pir);
  delay(1000);
    if(state == HIGH)
    {
      digitalWrite (led, HIGH);
      
      }
    if(state == LOW)
    {
      digitalWrite (led, LOW);
    }
}

