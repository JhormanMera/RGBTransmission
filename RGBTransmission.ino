#include "myEmitter.h"
#include "myReceiver.h"
boolean modeSelected;
myEmitter emitter = myEmitter();
myReceiver receiver = myReceiver();
String text = "Escribí un cuento de cien palabras perfecto. La gente lo leía con avidez, y lo enviaban entusiasmados a sus amigos. Me llamaron para hablar sobre el cuento en la tele, y desde Hollywood querían adaptarlo. Entonces alguien descubrió que había escrito porque, en vez de por qué, así que ahora sobraba una palabra. Pero quitar cualquiera de ellas desmontaba el delicado mecanismo de relojería que había conseguido construir. Finalmente eliminé un artículo, pero ya no es lo mismo. Los críticos literarios me ignoran, han cancelado el programa al que tenía que ir, y Scorsese ya no me coge el teléfono.~";
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
  //emitter.setupEmitter();
}
void loop() {
  modeSelected=false;
  char read_;
  if(Serial.available()>0){
    read_=Serial.read();
    if(read_=='&'){
     secondModeSelecter();
    }else if(read_=='*'){
      thirdModeSelecter();
    }
  }
}

void secondModeSelecter(){
  char read_;
  while(modeSelected==false){
    if(Serial.available()>0){
      read_=Serial.read();
      if(read_=='e'){
        delay(15);
        secondModeSend();
        modeSelected=true;
      }else if(read_=='r'){
        modeSelected=true;
        receiver.startPrint=true;
        printValueSecondMode();
        receiver.XORChecksum16();
      }
    }
  }
}

void secondModeSend(){
   for(int i = 0; i < text.length(); i ++){
      emitter.colorOutput(emitter.codeLetter(text.charAt(i)));
    }
    delay(15);
}

void printValueSecondMode(){
  String value;
  while(receiver.startPrint){
    if(value == '~'){
      receiver.startPrint = !receiver.startPrint;
    }
    if(receiver.startPrint){
        value=receiver.stringBinaryToInt(receiver.colorToBinary());
      Serial.print(value); 
    }
  }        
}

void thirdModeSelecter(){
  char read_;
  while(modeSelected==false){
    if(Serial.available()>0){
      read_=Serial.read();
      if(read_=='e'){
        delay(15);
        thirdModeSend();
        modeSelected=true;
      }else if(read_=='r'){
        modeSelected=true;
        thirdModeReceive();
      }
    }
  }
}

  void thirdModeSend(){
    String value;
    for(int i = 0; i < text.length(); i ++){
        emitter.colorOutput(emitter.codeLetter(text.charAt(i)));
        delay(20);
        value=receiver.stringBinaryToInt(receiver.colorToBinary());
         if(i==0){}else if(value!=text[i-1]){
            Serial.println("Error al recibir ECO");
            return;
         }
      }
       delay(15);
    }

void thirdModeReceive(){
  String value;
  while(receiver.startPrint){
    if(value == '~'){
      receiver.startPrint = !receiver.startPrint;
    }
    if(receiver.startPrint){
        value=receiver.stringBinaryToInt(receiver.colorToBinary());
        delay(15);
        emitter.colorOutput(value);
      } 
    }
  }     
