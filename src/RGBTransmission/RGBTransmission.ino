#include "Adafruit_TCS34725.h"
int OUTPUTLEDR = 11;  //Definimos las 3 salidas digitales PWM
int OUTPUTLEDB = 10;
int OUTPUTLEDG = 9;
float valueLedR,valueLedG,valueLedB;
char currentLetter=' ';
char compareLetter=' ';
String binaryValue;
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);
/*
 * Tomamos ideas de:
 * https://github.com/systembolaget/Physical-computing-sensor-servo-tutorial-6a-Colour-finder-with-ams-TCS34725-and-HD-1900A
 * https://www.youtube.com/watch?v=FQnzRW4XukA
 * https://www.youtube.com/watch?v=TWKmbTITEes
 * https://create.arduino.cc/editor/ProfeGarcia/3e920fea-36c8-4fbc-a3a6-783f5ffa1902/preview
 * https://create.arduino.cc/editor/ProfeGarcia/f8bf6115-9715-4345-88f2-9c3cb1ecefca/preview
 * Bibliografía de conceptos:
 * https://en.wikipedia.org/wiki/Color_difference
 * https://www.calculadoraconversor.com/ascii-a-binario/
 * Calibracion sensor
 * https://learn.adafruit.com/calibrating-sensors/two-point-calibration
 */
void setup(){
 Serial.begin(9600);
 pinMode(OUTPUTLEDR,OUTPUT); // los pins digitales serán de salida
 pinMode(OUTPUTLEDG,OUTPUT);
 pinMode(OUTPUTLEDB,OUTPUT);
  if (!tcs.begin())  {//Verificamos la conexión del Sensor de color
  ; Serial.println("Error al iniciar TCS34725");
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
  ; Serial.println("Entraste Campeoooon");
    readVectorColor(valueLedR,valueLedG,valueLedB);
    readColor();
  }
  if(binaryValue!=""){
    readLetter();
; Serial.println("Se supone que ya pasó por el read letter");
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
// 00 1 (255,0,0)
// 01 2 (0,0,255)
// 10 3 (0,255,0)
// 11 4 (255,0,255)
 //Minúsculas
 if(currentLetter=='a'){representation_color("01","10","00","01"); return;}
 if(currentLetter=='b'){representation_color("01","10","00","10"); return;}
 if(currentLetter=='c'){representation_color("01","10","00","11"); return;}
 if(currentLetter=='d'){representation_color("01","10","01","00"); return;}
 if(currentLetter=='e'){representation_color("01","10","01","01"); return;}
 if(currentLetter=='f'){representation_color("01","10","01","10"); return;}
 if(currentLetter=='g'){representation_color("01","10","01","11"); return;}   
 if(currentLetter=='h'){representation_color("01","10","10","00"); return;}
 if(currentLetter=='i'){representation_color("01","10","10","01"); return;}
 if(currentLetter=='j'){representation_color("01","10","10","10"); return;}
 if(currentLetter=='k'){representation_color("01","10","10","11"); return;}
 if(currentLetter=='l'){representation_color("01","10","11","00"); return;}
 if(currentLetter=='m'){representation_color("01","10","11","01"); return;}     
 if(currentLetter=='n'){representation_color("01","10","11","10"); return;}
 if(currentLetter=='o'){representation_color("01","10","11","11"); return;}
 if(currentLetter=='p'){representation_color("01","11","00","00"); return;}
 if(currentLetter=='q'){representation_color("01","11","00","01"); return;}
 if(currentLetter=='r'){representation_color("01","11","00","10"); return;}
 if(currentLetter=='s'){representation_color(); return;}
 if(currentLetter=='t'){representation_color(); return;}
 if(currentLetter=='u'){representation_color(); return;}
 if(currentLetter=='v'){representation_color(); return;}
 if(currentLetter=='w'){representation_color(); return;} 
 if(currentLetter=='x'){representation_color(); return;}         
 if(currentLetter=='y'){representation_color(); return;}
 if(currentLetter=='z'){representation_color(); return;}
 //Mayúsculas
 if(currentLetter=='A'){representation_color(); return;}
 if(currentLetter=='B'){representation_color(); return;}
 if(currentLetter=='C'){representation_color(); return;}
 if(currentLetter=='D'){representation_color(); return;}
 if(currentLetter=='E'){representation_color(); return;}
 if(currentLetter=='F'){representation_color(); return;}
 if(currentLetter=='G'){representation_color(); return;}   
 if(currentLetter=='H'){representation_color(); return;}
 if(currentLetter=='I'){representation_color(); return;}
 if(currentLetter=='J'){representation_color(); return;}
 if(currentLetter=='K'){representation_color(); return;}
 if(currentLetter=='L'){representation_color(); return;}
 if(currentLetter=='M'){representation_color(); return;}     
 if(currentLetter=='N'){representation_color(); return;}
 if(currentLetter=='O'){representation_color(); return;}
 if(currentLetter=='P'){representation_color(); return;}
 if(currentLetter=='Q'){representation_color(); return;}
 if(currentLetter=='R'){representation_color(); return;}
 if(currentLetter=='S'){representation_color(); return;}
 if(currentLetter=='T'){representation_color(); return;}
 if(currentLetter=='U'){representation_color(); return;}
 if(currentLetter=='V'){representation_color(); return;}
 if(currentLetter=='W'){representation_color(); return;} 
 if(currentLetter=='X'){representation_color(); return;}         
 if(currentLetter=='Y'){representation_color(); return;}
 if(currentLetter=='Z'){representation_color(); return;}
 //Tildes minúsculas
 if(currentLetter=='á'){representation_color(); return;}
 if(currentLetter=='é'){representation_color(); return;}
 if(currentLetter=='í'){representation_color(); return;}
 if(currentLetter=='ó'){representation_color(); return;}
 if(currentLetter=='ú'){representation_color(); return;}
 //Tildes mayúsculas
 if(currentLetter=='Á'){representation_color(); return;}
 if(currentLetter=='É'){representation_color(); return;}
 if(currentLetter=='Í'){representation_color(); return;}
 if(currentLetter=='Ó'){representation_color(); return;}
 if(currentLetter=='Ú'){representation_color(); return;}
 //Números
 if(currentLetter=='0'){representation_color(); return;}
 if(currentLetter=='1'){representation_color(); return;}
 if(currentLetter=='2'){representation_color(); return;}
 if(currentLetter=='3'){representation_color(); return;}
 if(currentLetter=='4'){representation_color(); return;}
 if(currentLetter=='5'){representation_color(); return;}
 if(currentLetter=='6'){representation_color(); return;}
 if(currentLetter=='7'){representation_color(); return;}
 if(currentLetter=='8'){representation_color(); return;}
 if(currentLetter=='9'){representation_color(); return;}
 //Símbolos
 if(currentLetter=='%'){representation_color(); return;}
 if(currentLetter=='&'){representation_color(); return;}
 if(currentLetter=='*'){representation_color(); return;}
 if(currentLetter==' '){representation_color(); return;}
 if(currentLetter=='.'){representation_color(); return;}
 if(currentLetter==','){representation_color(); return;}
 if(currentLetter=='!'){representation_color(); return;}
 if(currentLetter=='"'){representation_color(); return;}
 if(currentLetter=='#'){representation_color(); return;}
 if(currentLetter=='$'){representation_color(); return;}
 if(currentLetter=='('){representation_color(); return;}
 if(currentLetter==')'){representation_color(); return;}
 if(currentLetter=='+'){representation_color(); return;}
 if(currentLetter=='-'){representation_color(); return;}
 if(currentLetter=='/'){representation_color(); return;}
 if(currentLetter==':'){representation_color(); return;}
 if(currentLetter==';'){representation_color(); return;}
 if(currentLetter=='<'){representation_color(); return;}
 if(currentLetter=='='){representation_color(); return;}
 if(currentLetter=='>'){representation_color(); return;}
 if(currentLetter=='?'){representation_color(); return;}
 if(currentLetter=='@'){representation_color(); return;}
 if(currentLetter=='['){representation_color(); return;}
 if(currentLetter==']'){representation_color(); return;}
 if(currentLetter=='^'){representation_color(); return;}
 if(currentLetter=='_'){representation_color(); return;}
 if(currentLetter=='{'){representation_color(); return;}
 if(currentLetter=='}'){representation_color(); return;}
 if(currentLetter=='|'){representation_color(); return;}
 if(currentLetter=='~'){representation_color(); return;}
}

void readVectorColor(float pos1,float pos2, float pos3){
// 00 1 (255,0,0)
// 01 2 (0,0,255)
// 10 3 (0,255,0)
// 11 4 (255,0,255)
  float comp1=255.00;
  float comp2= 255.00;
  float comp3 = 0.00;
  if((pos1==comp1)&&(pos2==comp3)&&(pos3==comp3)); binaryValue+= "00";
  if((pos1==comp3)&&(pos2==comp3)&&(pos3==comp1)); binaryValue+= "01";
  if((pos1==comp3)&&(pos2==comp1)&&(pos3==comp3)); binaryValue+= "10";
  if((pos1==comp2)&&(pos2==comp3)&&(pos3==comp3)); binaryValue+= "11";
  }



void readLetter(){
Serial.print(binaryValue);
     //Minúsculas
     if (binaryValue=="01100001"); Serial.print("a"); compareLetter='a';
     if (binaryValue==""); Serial.print("b"); compareLetter='b';
     if (binaryValue==""); Serial.print("c"); compareLetter='c';
     if (binaryValue==""); Serial.print("d"); compareLetter='d';
     if (binaryValue==""); Serial.print("e"); compareLetter='e';
     if (binaryValue==""); Serial.print("f"); compareLetter='f';
     if (binaryValue==""); Serial.print("g"); compareLetter='g';
     if (binaryValue==""); Serial.print("h"); compareLetter='h';
     if (binaryValue==""); Serial.print("i"); compareLetter='i';
     if (binaryValue==""); Serial.print("j"); compareLetter='j';
     if (binaryValue==""); Serial.print("k"); compareLetter='k';
     if (binaryValue=="01101100"); Serial.print("l"); compareLetter='l';
     if (binaryValue==""); Serial.print("m"); compareLetter='m';
     if (binaryValue==""); Serial.print("n"); compareLetter='n';
     if (binaryValue==""); Serial.print("o"); compareLetter='o';
     if (binaryValue=="01110000"); Serial.print("p"); compareLetter='p';
     if (binaryValue==""); Serial.print("q"); compareLetter='q';
     if (binaryValue==""); Serial.print("r"); compareLetter='r';
     if (binaryValue==""); Serial.print("s"); compareLetter='s';
     if (binaryValue==""); Serial.print("t"); compareLetter='t';
     if (binaryValue=="01110101"); Serial.print("u"); compareLetter='u';
     if (binaryValue==""); Serial.print("v"); compareLetter='v';
     if (binaryValue==""); Serial.print("w"); compareLetter='w';
     if (binaryValue==""); Serial.print("x"); compareLetter='x';
     if (binaryValue==""); Serial.print("y"); compareLetter='y';
     if (binaryValue==""); Serial.print("z"); compareLetter='z';
     //Mayusculas
     if (binaryValue==""); Serial.print("A"); compareLetter='A';
     if (binaryValue==""); Serial.print("B"); compareLetter='B';
     if (binaryValue==""); Serial.print("C"); compareLetter='C';
     if (binaryValue==""); Serial.print("D"); compareLetter='D';
     if (binaryValue==""); Serial.print("E"); compareLetter='E';
     if (binaryValue==""); Serial.print("F"); compareLetter='F';
     if (binaryValue==""); Serial.print("G"); compareLetter='G';
     if (binaryValue==""); Serial.print("H"); compareLetter='H';
     if (binaryValue==""); Serial.print("I"); compareLetter='I';
     if (binaryValue==""); Serial.print("J"); compareLetter='J';
     if (binaryValue==""); Serial.print("K"); compareLetter='K';
     if (binaryValue==""); Serial.print("L"); compareLetter='L';
     if (binaryValue==""); Serial.print("M"); compareLetter='M';
     if (binaryValue==""); Serial.print("N"); compareLetter='N';
     if (binaryValue==""); Serial.print("O"); compareLetter='O';
     if (binaryValue==""); Serial.print("P"); compareLetter='P';
     if (binaryValue==""); Serial.print("Q"); compareLetter='Q';
     if (binaryValue==""); Serial.print("R"); compareLetter='R';
     if (binaryValue==""); Serial.print("S"); compareLetter='S';
     if (binaryValue==""); Serial.print("T"); compareLetter='T';
     if (binaryValue==""); Serial.print("U"); compareLetter='U';
     if (binaryValue==""); Serial.print("V"); compareLetter='V';
     if (binaryValue==""); Serial.print("W"); compareLetter='W';
     if (binaryValue==""); Serial.print("X"); compareLetter='X';
     if (binaryValue==""); Serial.print("Y"); compareLetter='Y';
     if (binaryValue==""); Serial.print("Z"); compareLetter='Z';
     //Números
     if (binaryValue==""); Serial.print("0"); compareLetter='0';
     if (binaryValue==""); Serial.print("1"); compareLetter='1';
     if (binaryValue==""); Serial.print("2"); compareLetter='2';
     if (binaryValue==""); Serial.print("3"); compareLetter='3';
     if (binaryValue==""); Serial.print("4"); compareLetter='4';
     if (binaryValue==""); Serial.print("5"); compareLetter='5';
     if (binaryValue==""); Serial.print("6"); compareLetter='6';
     if (binaryValue==""); Serial.print("7"); compareLetter='7';
     if (binaryValue==""); Serial.print("8"); compareLetter='8';
     if (binaryValue==""); Serial.print("9"); compareLetter='9';
     //Tildes minúsculas
     if (binaryValue==""); Serial.print("á"); compareLetter='á';
     if (binaryValue==""); Serial.print("é"); compareLetter='é';
     if (binaryValue==""); Serial.print("í"); compareLetter='í';
     if (binaryValue==""); Serial.print("ó"); compareLetter='ó';
     if (binaryValue==""); Serial.print("ú"); compareLetter='ú';
     //Tildes mayúsculas
     if (binaryValue==""); Serial.print("Á"); compareLetter='Á';
     if (binaryValue==""); Serial.print("É"); compareLetter='É';
     if (binaryValue==""); Serial.print("Í"); compareLetter='Í';
     if (binaryValue==""); Serial.print("Ó"); compareLetter='Ó';
     if (binaryValue==""); Serial.print("Ú"); compareLetter='Ú';
     //Símbolos
     if(binaryValue==""){Serial.print("%"); compareLetter='%';return;}
     if(binaryValue==""){Serial.print("&"); compareLetter='&';return;}
     if(binaryValue==""){Serial.print("*"); compareLetter='*';return;}
     if(binaryValue==""){Serial.print(" "); compareLetter=' ';return;}
     if(binaryValue==""){Serial.print("."); compareLetter='.';return;}
     if(binaryValue==""){Serial.print(","); compareLetter=',';return;}
     if(binaryValue==""){Serial.print("!"); compareLetter='!';return;}
     if(binaryValue==""){Serial.print('"'); compareLetter='"';return;}
     if(binaryValue==""){Serial.print("#"); compareLetter='#';return;}
     if(binaryValue==""){Serial.print("$"); compareLetter='$';return;}
     if(binaryValue==""){Serial.print("("); compareLetter='(';return;}
     if(binaryValue==""){Serial.print(")"); compareLetter=')';return;}
     if(binaryValue==""){Serial.print("+"); compareLetter='+';return;}
     if(binaryValue==""){Serial.print("-"); compareLetter='-';return;}
     if(binaryValue==""){Serial.print("/"); compareLetter='/';return;}
     if(binaryValue==""){Serial.print(":"); compareLetter=':';return;}
     if(binaryValue==""){Serial.print(";"); compareLetter=';';return;}
     if(binaryValue==""){Serial.print("<"); compareLetter='<';return;}
     if(binaryValue==""){Serial.print("="); compareLetter='=';return;}
     if(binaryValue==""){Serial.print(">"); compareLetter='>';return;}
     if(binaryValue==""){Serial.print("?"); compareLetter='?';return;}
     if(binaryValue==""){Serial.print("@"); compareLetter='@';return;}
     if(binaryValue==""){Serial.print("["); compareLetter='[';return;}
     if(binaryValue==""){Serial.print("]"); compareLetter=']';return;}
     if(binaryValue==""){Serial.print("^"); compareLetter='^';return;}
     if(binaryValue==""){Serial.print("_"); compareLetter='_';return;}
     if(binaryValue==""){Serial.print("{"); compareLetter='{';return;}
     if(binaryValue==""){Serial.print("}"); compareLetter='}';return;}
     if(binaryValue==""){Serial.print("|"); compareLetter='|';return;}
     if(binaryValue==""){Serial.print("~"); compareLetter='~';return;}
}

void representation_color(String pos1, String pos2, String pos3, String pos4){
  vector_color(pos1);
  vector_color(pos2);
  vector_color(pos3);
  vector_color(pos4);
}
// 00 1 (255,0,0)
// 01 2 (0,0,255)
// 10 3 (0,255,0)
// 11 4 (255,0,255)
void vector_color(String pos){
  if(pos=="00"){
  digitalWrite(OUTPUTLEDR, HIGH);
  digitalWrite(OUTPUTLEDG, LOW);
  digitalWrite(OUTPUTLEDB, LOW);
  }else if(pos=="01"){
  digitalWrite(OUTPUTLEDR, LOW);
  digitalWrite(OUTPUTLEDG, LOW);
  digitalWrite(OUTPUTLEDB, HIGH);
  }else if(pos=="10"){
   digitalWrite(OUTPUTLEDR, LOW);
   digitalWrite(OUTPUTLEDG, HIGH);
   digitalWrite(OUTPUTLEDB, LOW);
  }else{
   digitalWrite(OUTPUTLEDR, HIGH);
   digitalWrite(OUTPUTLEDG, LOW);
   digitalWrite(OUTPUTLEDB, HIGH);
  }
 
}
