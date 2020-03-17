// SELVABHARATHI
// NOTE: while sending multiple data over NRF look for the size, the max size allowed is 32bit.
// if you want to send data, which is much large, you can go with JSON formate of data sending,
// with JSON send the data in 32bit of packets each. you can't send the entire data at once.
// you can send it 32bit of packets only.
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
