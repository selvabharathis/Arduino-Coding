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
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
}
void loop() 
{
  if (radio.available()) 
  {
    radio.read(&payload, sizeof(payload));
    Serial.println(payload.North);
    Serial.println(payload.South);
    Serial.println(payload.East);
    Serial.println(payload.West);
  }
}
