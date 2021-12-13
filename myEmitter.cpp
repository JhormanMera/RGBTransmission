#include "myEmitter.h"

myEmitter::myEmitter(){}

void myEmitter::setupEmitter() {
 pinMode(OUTPUTLED,OUTPUT); // El pin digital será de salida
 digitalWrite(OUTPUTLED,HIGH);
}

void myEmitter::colorOutput(String letter){
  digitalWrite(OUTPUTLED, LOW);
  delay(PERIOD);
  for(int i =0;i<8;i++){
    if(letter[i]=="1"){
     digitalWrite(OUTPUTLED, HIGH);
    }else{
     digitalWrite(OUTPUTLED, LOW);
    }
    delay(PERIOD);
  } 
  digitalWrite(OUTPUTLED, HIGH);
  delay(PERIOD);
}

String myEmitter::codeLetter(char currentLetter){
 int convertido = int(currentLetter);
  String binary ="";
  String stringOne =  String(convertido, BIN);
  if(stringOne.length()==7){
    binary=String("0"+stringOne);
  }else if(stringOne.length()==6){
    binary=String("00"+stringOne);
  }
  return binary;
}
