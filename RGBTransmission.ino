#include "myEmitter.h"
#include "myReceiver.h"

myEmitter emitter = myEmitter(100);
myReceiver receiver = myReceiver();

/*
 * Tomamos ideas de:
 * https://github.com/systembolaget/Physical-computing-sensor-servo-tutorial-6a-Colour-finder-with-ams-TCS34725-and-HD-1900A
 * https://www.youtube.com/watch?v=FQnzRW4XukA
 * https://www.youtube.com/watch?v=TWKmbTITEes
 * https://create.arduino.cc/editor/ProfeGarcia/3e920fea-36c8-4fbc-a3a6-783f5ffa1902/preview
 * https://create.arduino.cc/editor/ProfeGarcia/f8bf6115-9715-4345-88f2-9c3cb1ecefca/preview
 * https://www.youtube.com/watch?v=PPsUHX6nVow (Video ficheros)
 * https://forum.arduino.cc/t/converting-binary-strings-to-bytes-integers/212848/5 (String to number)
 *  
 * Bibliografía de conceptos:
 * https://en.wikipedia.org/wiki/Color_difference
 * https://www.calculadoraconversor.com/ascii-a-binario/
 * Calibracion sensor
 * https://learn.adafruit.com/calibrating-sensors/two-point-calibration
 * https://www.youtube.com/watch?v=X4RevYjBJCU&t=176s
 */
void setup(){
   Serial.begin(9600);
  //receiver.setupReceiver();
  emitter.setupEmitter();
  emitter.bit_Final();
}

void loop() {
  char caracter;
  if(Serial.available()>0){
  caracter  = Serial.read();
    switch(caracter){
    case '%'://MODO CHAT
        //PROXIMAMENTE SOLO EN CINES
    break;
    case '&':// MODO BLOQUE DE INFO
      caracter = Serial.read();
      while(caracter!="0"){
        caracter = Serial.read();
        if(caracter=='e'){//Es el computador que envía información
          emitterEcoMode();
        }else if(caracter=='r'){//Es el computador que recibe
          receiver.out=false;
        }
      }
    break;
    case '*': //MODO ECO
      while(Serial.available()<=0){
        Serial.println("Tercero");
       caracter = Serial.read();
        if(caracter=='e'){//Es el computador que envía información
          
        }else if(caracter=='r'){//Es el computador Eco
          receiver.out=false;
        }
      }
    break;
    }
     Serial.println("SALIÓ DEL SWITCH");
  }
}

/*
 * if(caracter=='@'){//Es el computador que envía información
             while(Serial.available()<=0){
              Serial.println("JI");
                if(Serial.available()>0){
                 emitter.sendText(); 
                }
              } 
        }else if(caracter=='#'){//Es el computador recibe información
          receiver.out=false;
          receiverSecondMode();
          receiver.XORChecksum16();
        }
 */

 void emitterEcoMode(){
   while((Serial.available()<=0)){
    //Serial.println("JI");
    if(Serial.available()<0){
      Serial.println("ENTRO AL IF");
      emitter.sendText(); 
      
    }
  } 
  Serial.println("Salio del while emittereco");
}
void receiverEcoMode(){
  
  char current;
      while(Serial.available()<=0) {
      String fullText = Serial.readString(); //lee la letra del puerto serial
          for(int j=0; j < fullText.length();j++){
            current = fullText.charAt(j);
            emitter.bit_Sync();
            emitter.sendLetter(current); // Transforma la letra en color            /
     }       
   }
   emitter.bit_Final();
}

void receiverSecondMode(){
  while(receiver.out==false){
    receiver.readColor();
    if((receiver.valueLedR>=160)&&( receiver.valueLedG>=160)&&( receiver.valueLedB>=160)){
      receiver.readText();
    } 
  }
}
