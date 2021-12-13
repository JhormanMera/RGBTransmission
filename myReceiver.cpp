#include "myReceiver.h"

myReceiver::myReceiver(){
}

void myReceiver::setupReceiver() {
  if (!tcs.begin())  {//Verificamos la conexión del Sensor de color
   Serial.println("Error al iniciar TCS34725");
   while (!tcs.begin()) delay(1000);
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

bool myReceiver::getColor(){
  uint16_t red, green, blue, c, luxes;
  tcs.getRawData(&red, &green, &blue, &c);
  luxes = tcs.calculateLux(red, green, blue);
  return luxes > THRESHOLD ? true : false;
}

String myReceiver::colorToBinary(){
  String ret = "";
  delay(PERIOD*1.5);
  for(int i = 0; i < 8; i++)
  {
   if(getColor()){
      ret.concat("1");
   }else{
      ret.concat("0");
   }
   delay(PERIOD);
  }
  dataAmount++;
  return ret;
}
