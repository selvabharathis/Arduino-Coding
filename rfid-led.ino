//  S.Selvabharathi   B.Tech  IT   Rajalakshmi Engineering college   
// connect node mcu with RFID
//pin config:    3.3v->3.3v , RS->D2 , GND->GND , MISO->D6 , MOSI->D7 , SCK->D5 , SDA->D4
//upload the code , open serial monitor and press reset, and then if right rfid card is put on the reader the led will glow for a sec and off, and if wrong rfid then it wont glow. 

#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN D4
#define RST_PIN D2
const int led=D0;

MFRC522 mfrc522(SS_PIN, RST_PIN); 
void setup() 
{
   Serial.begin(9600);
   SPI.begin();      
   mfrc522.PCD_Init(); 
  pinMode(led,OUTPUT);
}



void loop() 
{
if ( ! mfrc522.PICC_IsNewCardPresent())
    {
    return;
    }
if (! mfrc522.PICC_ReadCardSerial())
    {
     return;
    }
String id= "";
byte letter;
Serial.print("Tag UID:");
for (byte i = 0; i < mfrc522.uid.size; i++) 
           {
                    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                    Serial.print(mfrc522.uid.uidByte[i], HEX);
                    id.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
                    id.concat(String(mfrc522.uid.uidByte[i], HEX));
           }
Serial.println();
Serial.print("Message : ");
id.toUpperCase();
        if (id.substring(1) == "8C 2D 10 79")
        {
          Serial.println("Authorized access");
          Serial.println();
          delay(500);
          digitalWrite(led, HIGH);
          delay(3000);
          digitalWrite(led, LOW);
        }
       else   
        {
          Serial.println(" Access denied");
          digitalWrite(led, LOW);
        }
}
 
