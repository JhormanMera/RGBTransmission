#include <ColorConverterLib.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"
int OUTPUTLEDR = 11;  //Definimos las 3 salidas digitales PWM
int OUTPUTLEDG = 9;
int OUTPUTLEDB = 10;
float valueLedR;
float valueLedG;
float valueLedB;
char currentLetter=' ';
char compareLetter=' ';
boolean emitter;

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_24MS, TCS34725_GAIN_1X);

void setup(){
 Serial.begin(9600);
 pinMode(OUTPUTLEDR,OUTPUT); // los pins digitales serán de salida
 pinMode(OUTPUTLEDG,OUTPUT);
 pinMode(OUTPUTLEDB,OUTPUT);
 
  if (!tcs.begin())  {//Verificamos la conexión del Sensor de color
    Serial.println("Error al iniciar TCS34725");
    while (!tcs.begin()) delay(1000);
  }
}

void loop(){
vector_color(255,255,255);   // bit en Inicio, durante 2 tiempos de reloj para dar inicio a la trama
delay(46);                // espera de medio tiempo de reloj  
vector_color(0,0,0);
if (Serial.available() > 0){   // Solo si llegaron datos los lee y TX
    currentLetter= Serial.read();    // Lee el mensaje que llega por el puerto serial
 }
}

void menu(){
 if(currentLetter=='%'); firstMenuOption();
 if(currentLetter=='&'); secondMenuOption();
 if(currentLetter=='*'); thirdMenuOption();
}

void firstMenuOption(){
  
}

void secondMenuOption(){
  
    letterToColor();

}

void thirdMenuOption(){
  
}

void letterToColor(){
 while(Serial.available() > 0) {
      currentLetter = Serial.read(); //lee la letra del puerto serial
      sendLetter(); // Transforma la letra en color
 }
}

void readColor(){
  uint32_t sum;
  uint16_t clear, red, green, blue;
  tcs.setInterrupt(false);
  delay(50); // Cuesta 50ms capturar el color
  tcs.getRawData(&red, &green, &blue, &clear);
  tcs.setInterrupt(true);
  // Hacer rgb medición relativa y escalar rgb a bytes
  tcs.getRGB(&valueLedR,&valueLedG,&valueLedB);
  /*
  // Hacer rgb medición relativa
  sum = clear;
  valueLedR = red; valueLedR /= sum;
  valueLedG = green; valueLedG /= sum;
  valueLedB = blue; valueLedB /= sum;
  // Escalar rgb a bytes
  valueLedR*= 255; valueLedG *= 255; valueLedB *= 255;
*/
/*
  // Convertir a hue, saturation, value
  double hue, saturation, value;
  ColorConverter::RgbToHsv(static_cast<uint8_t>(valueLedR), static_cast<uint8_t>(valueLedG), static_cast<uint8_t>(valueLedB), hue, saturation, value);
  */
  readLetter();
  delay(1000);
  Serial.println("");
  Serial.print("R byte = ");Serial.println(String(valueLedR));
  Serial.print("G byte= ");Serial.println(String(valueLedG));
  Serial.print("B byte= ");Serial.println(String(valueLedB));
  Serial.print("Clear = ");Serial.println(String(sum));
  //Serial.print("Saturation = ");Serial.println(String(saturation));
  Serial.println("*************************");
}

void sendLetter(){
  //PREGUNTAR SI SE NECESITAN LAS TILDES Y LAS MAYÚSCULAS
 if(currentLetter=='%') vector_color(0,0,0);
 if(currentLetter=='&') vector_color(0,0,0); emitter = true;
 if(currentLetter=='*') vector_color(0,0,0); emitter=true;
 if(currentLetter=='a') vector_color(128,0,0);;
 if(currentLetter=='b') vector_color(0,0,0);
 if(currentLetter=='c') vector_color(0,0,0);
 if(currentLetter=='d') vector_color(0,0,0);
 if(currentLetter=='e') vector_color(0,0,0);
 if(currentLetter=='f') vector_color(0,0,0);
 if(currentLetter=='g') vector_color(0,0,0);   
 if(currentLetter=='h') vector_color(0,0,0);
 if(currentLetter=='i') vector_color(0,0,0);
 if(currentLetter=='j') vector_color(0,0,0);
 if(currentLetter=='k') vector_color(0,0,0);
 if(currentLetter=='l') vector_color(0,0,0);
 if(currentLetter=='m') vector_color(0,0,0);     
 if(currentLetter=='n') vector_color(0,0,0);
 if(currentLetter=='o') vector_color(0,0,0);
 if(currentLetter=='p') vector_color(0,0,0);
 if(currentLetter=='q') vector_color(0,0,0);
 if(currentLetter=='r') vector_color(0,0,0);
 if(currentLetter=='s') vector_color(0,0,0);
 if(currentLetter=='t') vector_color(0,0,0);
 if(currentLetter=='u') vector_color(0,0,0);
 if(currentLetter=='v') vector_color(0,0,0);
 if(currentLetter=='w') vector_color(0,0,0); 
 if(currentLetter=='x') vector_color(0,0,0);         
 if(currentLetter=='y') vector_color(0,0,0);
 if(currentLetter=='z') vector_color(0,0,0);
 if(currentLetter==' ') vector_color(0,0,0);
 if(currentLetter=='.') vector_color(0,0,0);
 if(currentLetter==',') vector_color(0,0,0);
 if(currentLetter=='0') vector_color(0,0,0);
 if(currentLetter=='1') vector_color(0,0,0);
 if(currentLetter=='2') vector_color(0,0,0);
 if(currentLetter=='3') vector_color(0,0,0);
 if(currentLetter=='4') vector_color(0,0,0);
 if(currentLetter=='5') vector_color(0,0,0);
 if(currentLetter=='6') vector_color(0,0,0);
 if(currentLetter=='7') vector_color(0,0,0);
 if(currentLetter=='8') vector_color(0,0,0);
 if(currentLetter=='9') vector_color(0,0,0);
}
void readLetter(){
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 1))  Serial.print("%"); compareLetter='%';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 1))  Serial.print("&"); compareLetter='&'; emitter=false;
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 1))  Serial.print("*"); compareLetter='*'; emitter=false;
    if ((valueLedR == 0) && (valueLedG == 0) && (valueLedB == 0))  Serial.print("a"); compareLetter='a';
    if ((valueLedR == 0) && (valueLedG == 0) && (valueLedB == 0))  Serial.print("b"); compareLetter='b';
    if ((valueLedR == 0) && (valueLedG == 0) && (valueLedB == 0))  Serial.print("c"); compareLetter='c';
    if ((valueLedR == 0) && (valueLedG == 0) && (valueLedB == 1))  Serial.print("d"); compareLetter='d';
    if ((valueLedR == 0) && (valueLedG == 0) && (valueLedB == 1))  Serial.print("e"); compareLetter='e';
    if ((valueLedR == 0) && (valueLedG == 0) && (valueLedB == 1))  Serial.print("f"); compareLetter='f';
    if ((valueLedR == 0) && (valueLedG == 0) && (valueLedB == 1))  Serial.print("g"); compareLetter='g';
    if ((valueLedR == 0) && (valueLedG == 1) && (valueLedB == 0))  Serial.print("h"); compareLetter='h';
    if ((valueLedR == 0) && (valueLedG == 1) && (valueLedB == 0))  Serial.print("i"); compareLetter='i';
    if ((valueLedR == 0) && (valueLedG == 1) && (valueLedB == 0))  Serial.print("j"); compareLetter='j';
    if ((valueLedR == 0) && (valueLedG == 1) && (valueLedB == 0))  Serial.print("k"); compareLetter='k';
    if ((valueLedR == 0) && (valueLedG == 1) && (valueLedB == 1))  Serial.print("l"); compareLetter='l';
    if ((valueLedR == 0) && (valueLedG == 1) && (valueLedB == 1))  Serial.print("m"); compareLetter='m';
    if ((valueLedR == 0) && (valueLedG == 1) && (valueLedB == 1))  Serial.print("n"); compareLetter='n';
    if ((valueLedR == 0) && (valueLedG == 1) && (valueLedB == 1))  Serial.print("o"); compareLetter='o';
    if ((valueLedR == 1) && (valueLedG == 0) && (valueLedB == 0))  Serial.print("p"); compareLetter='p';
    if ((valueLedR == 1) && (valueLedG == 0) && (valueLedB == 0))  Serial.print("q"); compareLetter='q';
    if ((valueLedR == 1) && (valueLedG == 0) && (valueLedB == 0))  Serial.print("r"); compareLetter='r';
    if ((valueLedR == 1) && (valueLedG == 0) && (valueLedB == 0))  Serial.print("s"); compareLetter='s';
    if ((valueLedR == 1) && (valueLedG == 0) && (valueLedB == 1))  Serial.print("t"); compareLetter='t';
    if ((valueLedR == 1) && (valueLedG == 0) && (valueLedB == 1))  Serial.print("u"); compareLetter='u';
    if ((valueLedR == 1) && (valueLedG == 0) && (valueLedB == 1))  Serial.print("v"); compareLetter='v';
    if ((valueLedR == 1) && (valueLedG == 0) && (valueLedB == 1))  Serial.print("w"); compareLetter='w';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 0))  Serial.print("x"); compareLetter='x';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 0))  Serial.print("y"); compareLetter='y';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 0))  Serial.print("z"); compareLetter='z';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 0))  Serial.print(" "); compareLetter=' ';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 1))  Serial.print(" "); compareLetter=' ';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 1))  Serial.print("."); compareLetter='0';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 1))  Serial.print(","); compareLetter='1';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 1))  Serial.print(","); compareLetter='2';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 1))  Serial.print(","); compareLetter='3';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 1))  Serial.print(","); compareLetter='4';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 1))  Serial.print(","); compareLetter='5';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 1))  Serial.print(","); compareLetter='6';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 1))  Serial.print(","); compareLetter='7';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 1))  Serial.print(","); compareLetter='8';
    if ((valueLedR == 1) && (valueLedG == 1) && (valueLedB == 1))  Serial.print(","); compareLetter='9';
}

void vector_color(int red, int green, int blue){
  analogWrite(OUTPUTLEDR, red);
  analogWrite(OUTPUTLEDG, green);
  analogWrite(OUTPUTLEDB, blue);
}
