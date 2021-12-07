#include "Adafruit_TCS34725.h"
int OUTPUTLEDR = 11;  //Definimos las 3 salidas digitales PWM
int OUTPUTLEDB = 10;
int OUTPUTLEDG = 9;
float valueLedR,valueLedG,valueLedB;
char currentLetter=' ';
char compareLetter=' ';
String binaryValue;
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);

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
 binaryValue = "";
readColor();
Serial.println("loop");
 Serial.println(valueLedR);
 Serial.println(valueLedG);
 Serial.println(valueLedB);
    while(valueLedR!=0 && valueLedG!=0 && valueLedB!=0){
    Serial.println("Entraste Campeoooon");
    readVectorColor(valueLedR,valueLedG,valueLedB);
    readColor();
  }
  if(binaryValue!=""){
    readLetter();
  Serial.println("Se supone que ya pasó por el read letter");
  binaryValue = "";
  }
}
void readColor(){
  tcs.setInterrupt(false);
  // Hacer rgb medición relativa y escalar rgb a bytes
  tcs.getRGB(&valueLedR,&valueLedG,&valueLedB);//Get RGB Tiene internamente un método de GetRawData y en Get Raw Data ya está el delay, no es necesario un delay externo
  tcs.setInterrupt(true);

 Serial.println("******************");
 Serial.println("readColor");
 Serial.println(valueLedR);
 Serial.println(valueLedG);
 Serial.println(valueLedB);
  valueLedR= comparate_interval(valueLedR);
   valueLedG= comparate_interval(valueLedG);
   valueLedB= comparate_interval(valueLedB);
}

float comparate_interval(float value){
  float comp1=255.00;
  float comp2= 127.00;
  float comp3 = 0.00;
  float ret;
  if(value>=comp3 && value<(comp2*0.75)){
    ret=comp3;
  }else if(value>=(comp2*0.75) && value<(comp1*0.7)){
    ret=comp2;
  }else if(value>=(comp1*0.7) && value<=(comp1*1.5)){
    ret=comp1;
  }
  return ret;
}
/*
void menu(){
 if(currentLetter=='%'); firstMenuOption();
 if(currentLetter=='&'); secondMenuOption();
 if(currentLetter=='*'); thirdMenuOption();
}
*/
/*
void firstMenuOption(){
  
}

void secondMenuOption(){
    letterToColor();
}

void thirdMenuOption(){
  
}
*/
void letterToColor(){
 while(Serial.available() > 0) {
      currentLetter = Serial.read(); //lee la letra del puerto serial
      sendLetter(); // Transforma la letra en color
 }
}


void sendLetter(){
  if(currentLetter=='A'); representation_color(2);representation_color(1);representation_color(1);representation_color(2);
  
  
  
}

  void readVectorColor(float pos1,float pos2, float pos3){
// 00 1 (255,0,0)
// 01 2 (0,0,255)
// 10 3 (0,255,0)
// 11 4 (127,0,0)
  float comp1=255.00;
  float comp2= 127.00;
  float comp3 = 0.00;
  if((pos1==comp1)&&(pos2==comp3)&&(pos3==comp3)); binaryValue+= "00";
  if((pos1==comp3)&&(pos2==comp3)&&(pos3==comp1)); binaryValue+= "01";
  if((pos1==comp3)&&(pos2==comp1)&&(pos3==comp3)); binaryValue+= "10";
  if((pos1==comp2)&&(pos2==comp3)&&(pos3==comp3)); binaryValue+= "11";
  }

/*
void sendLetter(){
  //PREGUNTAR SI SE NECESITAN LAS TILDES Y LAS MAYÚSCULAS
 if(currentLetter=='%') vector_color(comp3,comp3,0);
 if(currentLetter=='&') vector_color(0,0,0);
 if(currentLetter=='*') vector_color(0,0,0);
 if(currentLetter=='a') vector_color(128,0,0);
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
 irepresentation_color(2);f(currentLetter=='n') vector_color(0,0,0);
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
}*/


void readLetter(){
  Serial.print(binaryValue);
    //if ()  Serial.print("%"); compareLetter='%';
    //if ()  Serial.print("&"); compareLetter='&';
    //if ()  Serial.print("*"); compareLetter='*';
    if (binaryValue=="01100001")  Serial.print("a"); compareLetter='a';
    //if ()  Serial.print("b"); compareLetter='b';
    //if ()  Serial.print("c"); compareLetter='c';
    //if ()  Serial.print("d"); compareLetter='d';
    //if ((valueLedR == 0) && (valueLedG == 0) && (valueLedB == 1))  Serial.print("e"); compareLetter='e';
    //if ((valueLedR == 0) && (valueLedG == 0) && (valueLedB == 1))  Serial.print("f"); compareLetter='f';
    //if ((valueLedR == 0) && (valueLedG == 0) && (valueLedB == 1))  Serial.print("g"); compareLetter='g';
    //if ((valueLedR == 0) && (valueLedG == 1) && (valueLedB == 0))  Serial.print("h"); compareLetter='h';
    //if ((valueLedR == 0) && (valueLedG == 1) && (valueLedB == 0))  Serial.print("i"); compareLetter='i';
    //if ((valueLedR == 0) && (valueLedG == 1) && (valueLedB == 0))  Serial.print("j"); compareLetter='j';
    //if ((valueLedR == 0) && (valueLedG == 1) && (valueLedB == 0))  Serial.print("k"); compareLetter='k';
    if (binaryValue=="01101100")  Serial.print("l"); compareLetter='l';
    //if ((valueLedR == 0) && (valueLedG == 1) && (valueLedB == 1))  Serial.print("m"); compareLetter='m';
    //if ((valueLedR == 0) && (valueLedG == 1) && (valueLedB == 1))  Serial.print("n"); compareLetter='n';
    //if ((valueLedR == 0) && (valueLedG == 1) && (valueLedB == 1))  Serial.print("o"); compareLetter='o';
    if (binaryValue=="01110000")  Serial.print("p"); compareLetter='p';
    //if ((valueLedR == 1) && (valueLedG == 0) && (valueLedB == 0))  Serial.print("q"); compareLetter='q';
    //if ((valueLedR == 1) && (valueLedG == 0) && (valueLedB == 0))  Serial.print("r"); compareLetter='r';
    //if ((valueLedR == 1) && (valueLedG == 0) && (valueLedB == 0))  Serial.print("s"); compareLetter='s';
    //if ((valueLedR == 1) && (valueLedG == 0) && (valueLedB == 1))  Serial.print("t"); compareLetter='t';
    if (binaryValue=="01110101")  Serial.print("u"); compareLetter='u';
    /*
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
*/
}

void representation_color(int point){
  if (point==1); vector_color(255,0,0); 
  if (point==2); vector_color(0,0,255);
  if (point==3); vector_color(0,255,0);
  if (point==4); vector_color(127,0,0);
}

void vector_color(int red, int green, int blue){
  analogWrite(OUTPUTLEDR, red);
  analogWrite(OUTPUTLEDG, green);
  analogWrite(OUTPUTLEDB, blue);
}
