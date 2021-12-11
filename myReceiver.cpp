#include "myReceiver.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_60MS, TCS34725_GAIN_1X);
boolean out;
int dataAmount;
myReceiver::myReceiver(){
  dataAmount = 0;
}

void myReceiver::setupReceiver() {
 Serial.begin(9600);
  if (!tcs.begin())  {//Verificamos la conexión del Sensor de color
   Serial.println("Error al iniciar TCS34725");
   while (!tcs.begin()) delay(1000);
  }
}
void myReceiver::readColor(float &valueLedR, float &valueLedG, float &valueLedB){
  tcs.setInterrupt(false);
  // Hacer rgb medición relativa y escalar rgb a bytes
  tcs.getRGB(&valueLedR,&valueLedG,&valueLedB);//Get RGB Tiene internamente un método de GetRawData y en Get Raw Data ya está el delay, no es necesario un delay externo
  tcs.setInterrupt(true);
}

void myReceiver::readVectorColor(float &pos1,float &pos2, float &pos3,String &binaryValue){
// 00 1 (255,0,0)
// 01 2 (0,0,255)
// 10 3 (0,255,0)
// 11 4 (0,255,255)
  if((pos1>=160)&&(pos2<=120)&&(pos3<=120)){ binaryValue+= "00";return;}
  if((pos1<=120)&&(pos2<=120)&&(pos3>=160)){ binaryValue+= "01";return;}
  if((pos1<=120)&&(pos2>=160)&&(pos3<=120)){ binaryValue+= "10";return;}
  if((pos1<=120)&&(pos2>=160)&&(pos3>=160)){ binaryValue+= "11";return;}
  if((pos1>=160)&&(pos2>=160)&&(pos3<=120)){ out = true; return;       }
}

void myReceiver::readText(float &valueLedR, float &valueLedG, float &valueLedB,String &binaryValue){
  while(binaryValue.length()<8){
    Serial.println("En el while READTEXT");
    readColor(valueLedR,valueLedG,valueLedB);
    readVectorColor(valueLedR,valueLedG,valueLedB,binaryValue);
    Serial.println(binaryValue);
 }
  if(binaryValue.length()==8){
      Serial.println("Entro para el read letter");
      Serial.print(binaryValue);
      
      binaryValue = "";
      dataAmount++;
  }
}

void myReceiver::initializer(float &valueLedR, float &valueLedG, float &valueLedB,String &binaryValue) {
 readColor(valueLedR,valueLedG,valueLedB);
 if((valueLedR>=160)&&(valueLedG>=160)&&(valueLedB>=160)){
    readText(valueLedR,valueLedG,valueLedB,binaryValue);
  } 
}

void myReceiver::beginReceive(float &r, float &g, float &b, String &bin){
   while(out==false){
   initializer(r,g,b,bin);       
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

void myReceiver::XORChecksum16(const byte *data)
{
  uint16_t value = 0;
  for (size_t i = 0; i < dataAmount / 2; i++)
  {
    value ^= data[2*i] + (data[2*i+1] << 8);
  }
  if(dataAmount%2) value ^= data[dataAmount - 1];
  Serial.println(~value);
}
