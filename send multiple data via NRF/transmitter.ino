#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

typedef struct{
  int North;
  int South;
  int East;
  int West;
}data;

data payload;

void setup() 
{
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
  Serial.begin(9600);
}
void loop() 
{
  payload.North=1;
  payload.South=0;
  payload.East=1;
  payload.West=1;
  radio.setPayloadSize(32);
  radio.write(&payload, sizeof(payload));
  Serial.println(payload.North);
  Serial.println(payload.South);
  Serial.println(payload.East);
  Serial.println(payload.West);
  delay(1000);
}
