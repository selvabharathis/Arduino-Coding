//  S.Selvabharathi  B.Tech IT  Rajalakshmi Engineering College
// this code is used to connect the microcontroller with sd card and retrive the audio file
#include <SD.h>                           //include SD module library
#include <TMRpcm.h>                       //include speaker control library

#define SD_ChipSelectPin 4                //define CS pin

TMRpcm tmrpcm;                            //crete an object for speaker library

void setup(){
  
  tmrpcm.speakerPin = 9;                  //define speaker pin. 
                                     
  
  if (!SD.begin(SD_ChipSelectPin)) {      //see if the card is present and can be initialized
    
    return;                               //don't do anything more if not
  }
  
  tmrpcm.setVolume(6);                    //0 to 7. Set volume level
  tmrpcm.play("1.wav");         //the sound file "1" will play each time the arduino powers up, or is reset
}

void loop(){}


