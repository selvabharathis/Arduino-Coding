#include<SoftwareSerial.h>
#include<ArduinoJson.h>

SoftwareSerial bluetooth(2,3);//rx,tx

typedef struct{
  int North;
  int South;
  int East;
  int West;
}data;

data payload;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
  payload.North = 1;
  payload.South = 0;
  payload.East = 1;
  payload.West = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  StaticJsonBuffer<200> jBuffer;
  JsonObject& root = jBuffer.createObject();
  root["north"] = payload.North;
  root["south"] = payload.South;
  root["east"] = payload.East;
  root["west"] = payload.West;
  String output="";
  root.printTo(output);
  if(bluetooth.available()>0){
    char rec  = bluetooth.read();
    if(rec == 'j')
      Serial.println(output);
      bluetooth.println(output);
  }
//  bluetooth.println('y');
}
