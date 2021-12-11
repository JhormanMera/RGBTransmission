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

String myReceiver::getBinaryValue(){
  return binaryValue;
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
      readLetter(binaryValue, valueLedR, valueLedB, valueLedG);
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

void myReceiver::readLetter(String &binaryValue, float &r, float &b, float &g){
Serial.println(binaryValue);
const byte a = 16; 
     //Minúsculas
     if (binaryValue=="01100001"){ Serial.print("a");return;}
     if (binaryValue=="01100010"){ Serial.print("b");return;}
     if (binaryValue=="01100011"){ Serial.print("c");return;}
     if (binaryValue=="01100100"){ Serial.print("d");return;}
     if (binaryValue=="01100101"){ Serial.print("e");return;}
     if (binaryValue=="01100110"){ Serial.print("f");return;}
     if (binaryValue=="01100111"){ Serial.print("g");return;}
     if (binaryValue=="01101000"){ Serial.print("h");return;}
     if (binaryValue=="01101001"){ Serial.print("i");return;}
     if (binaryValue=="01101010"){ Serial.print("j");return;}
     if (binaryValue=="01101011"){ Serial.print("k");return;}
     if (binaryValue=="01101100"){ Serial.print("l");return;}
     if (binaryValue=="01101101"){ Serial.print("m");return;}
     if (binaryValue=="01101110"){ Serial.print("n");return;}
     if (binaryValue=="01101111"){ Serial.print("o");return;}
     if (binaryValue=="01110000"){ Serial.print("p");return;}
     if (binaryValue=="01110001"){ Serial.print("q");return;}
     if (binaryValue=="01110010"){ Serial.print("r");return;}
     if (binaryValue=="01110011"){ Serial.print("s");return;}
     if (binaryValue=="01110100"){ Serial.print("t");return;}
     if (binaryValue=="01110101"){ Serial.print("u");return;}
     if (binaryValue=="01110110"){ Serial.print("v");return;}
     if (binaryValue=="01110111"){ Serial.print("w");return;}
     if (binaryValue=="01111000"){ Serial.print("x");return;}
     if (binaryValue=="01111001"){ Serial.print("y");return;}
     if (binaryValue=="01111010"){ Serial.print("z");return;}
     //Mayusculas
     if (binaryValue=="01000001"){ Serial.print("A");return;}
     if (binaryValue=="01000010"){ Serial.print("B");return;}
     if (binaryValue=="01000011"){ Serial.print("C");return;}
     if (binaryValue=="01000100"){ Serial.print("D");return;}
     if (binaryValue=="01000101"){ Serial.print("E");return;}
     if (binaryValue=="01000110"){ Serial.print("F");return;}
     if (binaryValue=="01000111"){ Serial.print("G");return;}
     if (binaryValue=="01001000"){ Serial.print("H");return;}
     if (binaryValue=="01001001"){ Serial.print("I");return;}
     if (binaryValue=="01001010"){ Serial.print("J");return;}
     if (binaryValue=="01001011"){ Serial.print("K");return;}
     if (binaryValue=="01001100"){ Serial.print("L");return;}
     if (binaryValue=="01001101"){ Serial.print("M");return;}
     if (binaryValue=="01001110"){ Serial.print("N");return;}
     if (binaryValue=="01001111"){ Serial.print("O");return;}
     if (binaryValue=="01010000"){ Serial.print("P");return;}
     if (binaryValue=="01010001"){ Serial.print("Q");return;}
     if (binaryValue=="01010010"){ Serial.print("R");return;}
     if (binaryValue=="01010011"){ Serial.print("S");return;}
     if (binaryValue=="01010100"){ Serial.print("T");return;}
     if (binaryValue=="01010101"){ Serial.print("U");return;}
     if (binaryValue=="01010110"){ Serial.print("V");return;}
     if (binaryValue=="01010111"){ Serial.print("W");return;}
     if (binaryValue=="01011000"){ Serial.print("X");return;}
     if (binaryValue=="01011001"){ Serial.print("Y");return;}
     if (binaryValue=="01011010"){ Serial.print("Z");return;}
     //Números
     if (binaryValue=="00110000"){ Serial.print("0");return;}
     if (binaryValue=="00110001"){ Serial.print("1");return;}
     if (binaryValue=="00110010"){ Serial.print("2");return;}
     if (binaryValue=="00110011"){ Serial.print("3");return;}
     if (binaryValue=="00110100"){ Serial.print("4");return;}
     if (binaryValue=="00110101"){ Serial.print("5");return;}
     if (binaryValue=="00110110"){ Serial.print("6");return;}
     if (binaryValue=="00110111"){ Serial.print("7");return;}
     if (binaryValue=="00111000"){ Serial.print("8");return;}
     if (binaryValue=="00111001"){ Serial.print("9");return;}
     //Tildes minúsculas
     if (binaryValue=="11100001"){ Serial.print("á");return;}
     if (binaryValue=="11101001"){ Serial.print("é");return;}
     if (binaryValue=="11101101"){ Serial.print("í");return;}
     if (binaryValue=="11110011"){ Serial.print("ó");return;}
     if (binaryValue=="11111010"){ Serial.print("ú");return;}
     //Tildes mayúsculas
     if (binaryValue=="11000001"){ Serial.print("Á");return;}
     if (binaryValue=="11001001"){ Serial.print("É");return;}
     if (binaryValue=="11001101"){ Serial.print("Í");return;}
     if (binaryValue=="11010011"){ Serial.print("Ó");return;}
     if (binaryValue=="11011010"){ Serial.print("Ú");return;}
     //Símbolos
     if(binaryValue=="00100101"){Serial.print("%");return;}
     if(binaryValue=="00100110"){Serial.print("&");out = false; beginReceive(r, b,g, binaryValue); XORChecksum16(a); }
     if(binaryValue=="00101010"){Serial.print("*");return;}
     if(binaryValue=="00100000"){Serial.print(" ");return;}
     if(binaryValue=="00101110"){Serial.print(".");return;}
     if(binaryValue=="00101100"){Serial.print(",");return;}
     if(binaryValue=="00100001"){Serial.print("!");return;}
     if(binaryValue=="00100010"){Serial.print('"');return;}
     if(binaryValue=="00100011"){Serial.print("#");return;}
     if(binaryValue=="00100100"){Serial.print("$");return;}
     if(binaryValue=="00101000"){Serial.print("(");return;}
     if(binaryValue=="00101001"){Serial.print(")");return;}
     if(binaryValue=="00101011"){Serial.print("+");return;}
     if(binaryValue=="00101101"){Serial.print("-");return;}
     if(binaryValue=="00101111"){Serial.print("/");return;}
     if(binaryValue=="00111010"){Serial.print(":");return;}
     if(binaryValue=="00111011"){Serial.print(";");return;}
     if(binaryValue=="00111100"){Serial.print("<");return;}
     if(binaryValue=="00111101"){Serial.print("=");return;}
     if(binaryValue=="00111110"){Serial.print(">");return;}
     if(binaryValue=="00111111"){Serial.print("?");return;}
     if(binaryValue=="01000000"){Serial.print("@");return;}
     if(binaryValue=="01011011"){Serial.print("[");return;}
     if(binaryValue=="01011101"){Serial.print("]");return;}
     if(binaryValue=="01011110"){Serial.print("^");return;}
     if(binaryValue=="01011111"){Serial.print("_");return;}
     if(binaryValue=="01111011"){Serial.print("{");return;}
     if(binaryValue=="01111101"){Serial.print("}");return;}
     if(binaryValue=="01111100"){Serial.print("|");return;}
     if(binaryValue=="01111110"){Serial.print("~");return;}
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
