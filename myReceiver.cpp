#include "myReceiver.h"

myReceiver::myReceiver(){
}

void myReceiver::setupReceiver() {
  if (!tcs.begin())  {//Verificamos la conexión del Sensor de color
   Serial.println("Error al iniciar TCS34725");
   while (!tcs.begin()) delay(1000);
  }
}

void myReceiver::readColor(){
  tcs.setInterrupt(false);
  // Hacer rgb medición relativa y escalar rgb a bytes
  tcs.getRGB(&valueLedR,&valueLedG,&valueLedB);//Get RGB Tiene internamente un método de GetRawData y en Get Raw Data ya está el delay, no es necesario un delay externo
  tcs.setInterrupt(true);
}

void myReceiver::readVectorColor(){
// 00 1 (255,0,0)
// 01 2 (0,0,255)
// 10 3 (0,255,0)
// 11 4 (0,255,255)
// Salida (255,255,0)
  if((valueLedR>=160)&&(valueLedG<=120)&&(valueLedB<=120)){ binaryValue+= "00";return;}
  if((valueLedR<=120)&&(valueLedG<=120)&&(valueLedB>=160)){ binaryValue+= "01";return;}
  if((valueLedR<=120)&&(valueLedG>=160)&&(valueLedB<=120)){ binaryValue+= "10";return;}
  if((valueLedR<=120)&&(valueLedG>=160)&&(valueLedB>=160)){ binaryValue+= "11";return;}
  if((valueLedR>=160)&&(valueLedG>=160)&&(valueLedB<=120)){ out=true;return;}//Bit de Salida
}

int myReceiver::readText(){
  while(binaryValue.length()<8){
    readColor();
    readVectorColor();
    Serial.println(binaryValue);
 }
  if(binaryValue.length()==8){
      int number=stringBinaryToInt(binaryValue);
      binaryValue = "";
      dataAmount++;
      return number;
  }
}

int myReceiver::stringBinaryToInt(String val){ 
    char s[10];
    val.toCharArray(s,10);
    int value = 0;
   for (int i=0; i< strlen(s); i++){  // for every character in the string  strlen(s) returns the length of a char array
    value *= 2; // double the result so far
  if (s[i] == '1') value++;  //add 1 if needed
  }
  return value;
}

void myReceiver::XORChecksum16(){
  const byte* data = 16;
  uint16_t value = 0;
  for (size_t i = 0; i < dataAmount / 2; i++){
    value ^= data[2*i] + (data[2*i+1] << 8);
  }
  if(dataAmount%2) value ^= data[dataAmount - 1];
  Serial.println(~value);
  dataAmount=0;
}
