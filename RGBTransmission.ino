#include <Adafruit_TCS34725.h>
int OUTPUTLEDR = 11;  //Definimos las 3 salidas digitales PWM
int OUTPUTLEDB = 10;
int OUTPUTLEDG = 9;
int delayValue=1000;
char currentLetter;
float valueLedR,valueLedG,valueLedB;
char compareLetter=' ';
String binaryValue;
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);
/*
 * Tomamos ideas de:
 * https://github.com/systembolaget/Physical-computing-sensor-servo-tutorial-6a-Colour-finder-with-ams-TCS34725-and-HD-1900A
 * https://www.youtube.com/watch?v=FQnzRW4XukA
 * https://www.youtube.com/watch?v=TWKmbTITEes
 * https://create.arduino.cc/editor/ProfeGarcia/3e920fea-36c8-4fbc-a3a6-783f5ffa1902/preview
 * https://create.arduino.cc/editor/ProfeGarcia/f8bf6115-9715-4345-88f2-9c3cb1ecefca/preview
 * https://www.youtube.com/watch?v=PPsUHX6nVow (Video ficheros)
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
  ;Serial.println("Error al iniciar TCS34725");
   while (!tcs.begin()) delay(1000);
  }
}

void loop() {
 letterToColor();
 readColor();
 if((valueLedR>=160)&&(valueLedG>=160)&&(valueLedB>=160)){
    readText();
  } 
}

void letterToColor(){
 while(Serial.available() > 0) {
      currentLetter = Serial.read(); //lee la letra del puerto serial
      bit_Sync();
      sendLetter(); // Transforma la letra en color
      bit_Sync();
 }
}

void readColor(){
  tcs.setInterrupt(false);
  // Hacer rgb medición relativa y escalar rgb a bytes
  tcs.getRGB(&valueLedR,&valueLedG,&valueLedB);//Get RGB Tiene internamente un método de GetRawData y en Get Raw Data ya está el delay, no es necesario un delay externo
  tcs.setInterrupt(true);  
}

void readVectorColor(float pos1,float pos2, float pos3){
// 00 1 (255,0,0)
// 01 2 (0,0,255)
// 10 3 (0,255,0)
// 11 4 (0,255,255)
  if((pos1>=160)&&(pos2<=120)&&(pos3<=120)){ binaryValue+= "00";return;}
  if((pos1<=120)&&(pos2<=120)&&(pos3>=160)){ binaryValue+= "01";return;}
  if((pos1<=120)&&(pos2>=160)&&(pos3<=120)){ binaryValue+= "10";return;}
  if((pos1<=120)&&(pos2>=160)&&(pos3>=160)){ binaryValue+= "11";return;}
}

void readLetter(){
Serial.println(binaryValue);
     //Minúsculas
     if (binaryValue=="01100001"){ Serial.print("a"); compareLetter='a';return;}
     if (binaryValue=="01100010"){ Serial.print("b"); compareLetter='b';return;}
     if (binaryValue=="01100011"){ Serial.print("c"); compareLetter='c';return;}
     if (binaryValue=="01100100"){ Serial.print("d"); compareLetter='d';return;}
     if (binaryValue=="01100101"){ Serial.print("e"); compareLetter='e';return;}
     if (binaryValue=="01100110"){ Serial.print("f"); compareLetter='f';return;}
     if (binaryValue=="01100111"){ Serial.print("g"); compareLetter='g';return;}
     if (binaryValue=="01101000"){ Serial.print("h"); compareLetter='h';return;}
     if (binaryValue=="01101001"){ Serial.print("i"); compareLetter='i';return;}
     if (binaryValue=="01101010"){ Serial.print("j"); compareLetter='j';return;}
     if (binaryValue=="01101011"){ Serial.print("k"); compareLetter='k';return;}
     if (binaryValue=="01101100"){ Serial.print("l"); compareLetter='l';return;}
     if (binaryValue=="01101101"){ Serial.print("m"); compareLetter='m';return;}
     if (binaryValue=="01101110"){ Serial.print("n"); compareLetter='n';return;}
     if (binaryValue=="01101111"){ Serial.print("o"); compareLetter='o';return;}
     if (binaryValue=="01110000"){ Serial.print("p"); compareLetter='p';return;}
     if (binaryValue=="01110001"){ Serial.print("q"); compareLetter='q';return;}
     if (binaryValue=="01110010"){ Serial.print("r"); compareLetter='r';return;}
     if (binaryValue=="01110011"){ Serial.print("s"); compareLetter='s';return;}
     if (binaryValue=="01110100"){ Serial.print("t"); compareLetter='t';return;}
     if (binaryValue=="01110101"){ Serial.print("u"); compareLetter='u';return;}
     if (binaryValue=="01110110"){ Serial.print("v"); compareLetter='v';return;}
     if (binaryValue=="01110111"){ Serial.print("w"); compareLetter='w';return;}
     if (binaryValue=="01111000"){ Serial.print("x"); compareLetter='x';return;}
     if (binaryValue=="01111001"){ Serial.print("y"); compareLetter='y';return;}
     if (binaryValue=="01111010"){ Serial.print("z"); compareLetter='z';return;}
     //Mayusculas
     if (binaryValue=="01000001"){ Serial.print("A"); compareLetter='A';return;}
     if (binaryValue=="01000010"){ Serial.print("B"); compareLetter='B';return;}
     if (binaryValue=="01000011"){ Serial.print("C"); compareLetter='C';return;}
     if (binaryValue=="01000100"){ Serial.print("D"); compareLetter='D';return;}
     if (binaryValue=="01000101"){ Serial.print("E"); compareLetter='E';return;}
     if (binaryValue=="01000110"){ Serial.print("F"); compareLetter='F';return;}
     if (binaryValue=="01000111"){ Serial.print("G"); compareLetter='G';return;}
     if (binaryValue=="01001000"){ Serial.print("H"); compareLetter='H';return;}
     if (binaryValue=="01001001"){ Serial.print("I"); compareLetter='I';return;}
     if (binaryValue=="01001010"){ Serial.print("J"); compareLetter='J';return;}
     if (binaryValue=="01001011"){ Serial.print("K"); compareLetter='K';return;}
     if (binaryValue=="01001100"){ Serial.print("L"); compareLetter='L';return;}
     if (binaryValue=="01001101"){ Serial.print("M"); compareLetter='M';return;}
     if (binaryValue=="01001110"){ Serial.print("N"); compareLetter='N';return;}
     if (binaryValue=="01001111"){ Serial.print("O"); compareLetter='O';return;}
     if (binaryValue=="01010000"){ Serial.print("P"); compareLetter='P';return;}
     if (binaryValue=="01010001"){ Serial.print("Q"); compareLetter='Q';return;}
     if (binaryValue=="01010010"){ Serial.print("R"); compareLetter='R';return;}
     if (binaryValue=="01010011"){ Serial.print("S"); compareLetter='S';return;}
     if (binaryValue=="01010100"){ Serial.print("T"); compareLetter='T';return;}
     if (binaryValue=="01010101"){ Serial.print("U"); compareLetter='U';return;}
     if (binaryValue=="01010110"){ Serial.print("V"); compareLetter='V';return;}
     if (binaryValue=="01010111"){ Serial.print("W"); compareLetter='W';return;}
     if (binaryValue=="01011000"){ Serial.print("X"); compareLetter='X';return;}
     if (binaryValue=="01011001"){ Serial.print("Y"); compareLetter='Y';return;}
     if (binaryValue=="01011010"){ Serial.print("Z"); compareLetter='Z';return;}
     //Números
     if (binaryValue=="00110000"){ Serial.print("0"); compareLetter='0';return;}
     if (binaryValue=="00110001"){ Serial.print("1"); compareLetter='1';return;}
     if (binaryValue=="00110010"){ Serial.print("2"); compareLetter='2';return;}
     if (binaryValue=="00110011"){ Serial.print("3"); compareLetter='3';return;}
     if (binaryValue=="00110100"){ Serial.print("4"); compareLetter='4';return;}
     if (binaryValue=="00110101"){ Serial.print("5"); compareLetter='5';return;}
     if (binaryValue=="00110110"){ Serial.print("6"); compareLetter='6';return;}
     if (binaryValue=="00110111"){ Serial.print("7"); compareLetter='7';return;}
     if (binaryValue=="00111000"){ Serial.print("8"); compareLetter='8';return;}
     if (binaryValue=="00111001"){ Serial.print("9"); compareLetter='9';return;}
     //Tildes minúsculas
     if (binaryValue=="11100001"){ Serial.print("á"); compareLetter='á';return;}
     if (binaryValue=="11101001"){ Serial.print("é"); compareLetter='é';return;}
     if (binaryValue=="11101101"){ Serial.print("í"); compareLetter='í';return;}
     if (binaryValue=="11110011"){ Serial.print("ó"); compareLetter='ó';return;}
     if (binaryValue=="11111010"){ Serial.print("ú"); compareLetter='ú';return;}
     //Tildes mayúsculas
     if (binaryValue=="11000001"){ Serial.print("Á"); compareLetter='Á';return;}
     if (binaryValue=="11001001"){ Serial.print("É"); compareLetter='É';return;}
     if (binaryValue=="11001101"){ Serial.print("Í"); compareLetter='Í';return;}
     if (binaryValue=="11010011"){ Serial.print("Ó"); compareLetter='Ó';return;}
     if (binaryValue=="11011010"){ Serial.print("Ú"); compareLetter='Ú';return;}
     //Símbolos
     if(binaryValue=="00100101"){Serial.print("%"); compareLetter='%';return;}
     if(binaryValue=="00100110"){Serial.print("&"); compareLetter='&';return;}
     if(binaryValue=="00101010"){Serial.print("*"); compareLetter='*';return;}
     if(binaryValue=="00100000"){Serial.print(" "); compareLetter=' ';return;}
     if(binaryValue=="00101110"){Serial.print("."); compareLetter='.';return;}
     if(binaryValue=="00101100"){Serial.print(","); compareLetter=',';return;}
     if(binaryValue=="00100001"){Serial.print("!"); compareLetter='!';return;}
     if(binaryValue=="00100010"){Serial.print('"'); compareLetter='"';return;}
     if(binaryValue=="00100011"){Serial.print("#"); compareLetter='#';return;}
     if(binaryValue=="00100100"){Serial.print("$"); compareLetter='$';return;}
     if(binaryValue=="00101000"){Serial.print("("); compareLetter='(';return;}
     if(binaryValue=="00101001"){Serial.print(")"); compareLetter=')';return;}
     if(binaryValue=="00101011"){Serial.print("+"); compareLetter='+';return;}
     if(binaryValue=="00101101"){Serial.print("-"); compareLetter='-';return;}
     if(binaryValue=="00101111"){Serial.print("/"); compareLetter='/';return;}
     if(binaryValue=="00111010"){Serial.print(":"); compareLetter=':';return;}
     if(binaryValue=="00111011"){Serial.print(";"); compareLetter=';';return;}
     if(binaryValue=="00111100"){Serial.print("<"); compareLetter='<';return;}
     if(binaryValue=="00111101"){Serial.print("="); compareLetter='=';return;}
     if(binaryValue=="00111110"){Serial.print(">"); compareLetter='>';return;}
     if(binaryValue=="00111111"){Serial.print("?"); compareLetter='?';return;}
     if(binaryValue=="01000000"){Serial.print("@"); compareLetter='@';return;}
     if(binaryValue=="01011011"){Serial.print("["); compareLetter='[';return;}
     if(binaryValue=="01011101"){Serial.print("]"); compareLetter=']';return;}
     if(binaryValue=="01011110"){Serial.print("^"); compareLetter='^';return;}
     if(binaryValue=="01011111"){Serial.print("_"); compareLetter='_';return;}
     if(binaryValue=="01111011"){Serial.print("{"); compareLetter='{';return;}
     if(binaryValue=="01111101"){Serial.print("}"); compareLetter='}';return;}
     if(binaryValue=="01111100"){Serial.print("|"); compareLetter='|';return;}
     if(binaryValue=="01111110"){Serial.print("~"); compareLetter='~';return;}
}

void readText(){
  while(binaryValue.length()<8){
    Serial.println("En el while READTEXT");
    readColor();
    readVectorColor(valueLedR,valueLedG,valueLedB);
    Serial.println(binaryValue);
  }
  if(binaryValue.length()==8){
      Serial.println("Entro para el read letter");
      readLetter();
      binaryValue = ""; 
  }
}

void bit_Sync(){
  //Bit Sync
   digitalWrite(OUTPUTLEDR, HIGH);
   digitalWrite(OUTPUTLEDG, HIGH);
   digitalWrite(OUTPUTLEDB, HIGH);
   delay(delayValue*2);
}
void vector_color(String pos){
  if(pos=="00"){
  digitalWrite(OUTPUTLEDR, HIGH);
  digitalWrite(OUTPUTLEDG, LOW);
  digitalWrite(OUTPUTLEDB, LOW);
  delay(delayValue);
  return;
  }else if(pos=="01"){
  digitalWrite(OUTPUTLEDR, LOW);
  digitalWrite(OUTPUTLEDG, LOW);
  digitalWrite(OUTPUTLEDB, HIGH);
  delay(delayValue);
  return;
  }else if(pos=="10"){
   digitalWrite(OUTPUTLEDR, LOW);
   digitalWrite(OUTPUTLEDG, HIGH);
   digitalWrite(OUTPUTLEDB, LOW);
   delay(delayValue);
   return;
  }else{
   digitalWrite(OUTPUTLEDR, LOW);
   digitalWrite(OUTPUTLEDG, HIGH);
   digitalWrite(OUTPUTLEDB, HIGH);
   delay(delayValue);
   return;
  }
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
// 11 4 (0,255,255)

void sendLetter(){
// 00 1 (255,0,0)
// 01 2 (0,0,255)
// 10 3 (0,255,0)
// 11 4 (0,255,255)
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
 if(currentLetter=='s'){representation_color("01","11","00","11"); return;}
 if(currentLetter=='t'){representation_color("01","11","01","00"); return;}
 if(currentLetter=='u'){representation_color("01","11","01","01"); return;}
 if(currentLetter=='v'){representation_color("01","11","01","10"); return;}
 if(currentLetter=='w'){representation_color("01","11","01","11"); return;} 
 if(currentLetter=='x'){representation_color("01","11","10","00"); return;}         
 if(currentLetter=='y'){representation_color("01","11","10","01"); return;}
 if(currentLetter=='z'){representation_color("01","11","10","10"); return;}
 //Mayúsculas
 if(currentLetter=='A'){representation_color("01","00","00","01"); return;}
 if(currentLetter=='B'){representation_color("01","00","00","10"); return;}
 if(currentLetter=='C'){representation_color("01","00","00","11"); return;}
 if(currentLetter=='D'){representation_color("01","00","01","00"); return;}
 if(currentLetter=='E'){representation_color("01","00","01","01"); return;}
 if(currentLetter=='F'){representation_color("01","00","01","10"); return;}
 if(currentLetter=='G'){representation_color("01","00","01","11"); return;}   
 if(currentLetter=='H'){representation_color("01","00","10","00"); return;}
 if(currentLetter=='I'){representation_color("01","00","10","01"); return;}
 if(currentLetter=='J'){representation_color("01","00","10","10"); return;}
 if(currentLetter=='K'){representation_color("01","00","10","11"); return;}
 if(currentLetter=='L'){representation_color("01","00","11","00"); return;}
 if(currentLetter=='M'){representation_color("01","00","11","01"); return;}     
 if(currentLetter=='N'){representation_color("01","00","11","10"); return;}
 if(currentLetter=='O'){representation_color("01","00","11","11"); return;}
 if(currentLetter=='P'){representation_color("01","01","00","00"); return;}
 if(currentLetter=='Q'){representation_color("01","01","00","01"); return;}
 if(currentLetter=='R'){representation_color("01","01","00","10"); return;}
 if(currentLetter=='S'){representation_color("01","01","00","11"); return;}
 if(currentLetter=='T'){representation_color("01","01","01","00"); return;}
 if(currentLetter=='U'){representation_color("01","01","01","01"); return;}
 if(currentLetter=='V'){representation_color("01","01","01","10"); return;}
 if(currentLetter=='W'){representation_color("01","01","01","11"); return;} 
 if(currentLetter=='X'){representation_color("01","01","10","00"); return;}         
 if(currentLetter=='Y'){representation_color("01","01","10","01"); return;}
 if(currentLetter=='Z'){representation_color("01","01","10","10"); return;}
 //Tildes minúsculas
 if(currentLetter=='á'){representation_color("11","10","00","01"); return;}
 if(currentLetter=='é'){representation_color("11","10","10","01"); return;}
 if(currentLetter=='í'){representation_color("11","10","11","01"); return;}
 if(currentLetter=='ó'){representation_color("11","11","00","11"); return;}
 if(currentLetter=='ú'){representation_color("11","11","10","10"); return;}
 //Tildes mayúsculas
 if(currentLetter=='Á'){representation_color("11","00","00","01"); return;}
 if(currentLetter=='É'){representation_color("11","00","10","01"); return;}
 if(currentLetter=='Í'){representation_color("11","00","11","01"); return;}
 if(currentLetter=='Ó'){representation_color("11","01","00","11"); return;}
 if(currentLetter=='Ú'){representation_color("11","01","10","10"); return;}
 //Números
 if(currentLetter=='0'){representation_color("00","11","00","00"); return;}
 if(currentLetter=='1'){representation_color("00","11","00","01"); return;}
 if(currentLetter=='2'){representation_color("00","11","00","10"); return;}
 if(currentLetter=='3'){representation_color("00","11","00","11"); return;}
 if(currentLetter=='4'){representation_color("00","11","01","00"); return;}
 if(currentLetter=='5'){representation_color("00","11","01","01"); return;}
 if(currentLetter=='6'){representation_color("00","11","01","10"); return;}
 if(currentLetter=='7'){representation_color("00","11","01","11"); return;}
 if(currentLetter=='8'){representation_color("00","11","10","00"); return;}
 if(currentLetter=='9'){representation_color("00","11","10","01"); return;}
 //Símbolos
 if(currentLetter=='%'){representation_color("00","10","01","01"); return;}
 if(currentLetter=='&'){representation_color("00","10","01","10"); return;}
 if(currentLetter=='*'){representation_color("00","10","10","10"); return;}
 if(currentLetter==' '){representation_color("00","10","00","00"); return;}
 if(currentLetter=='.'){representation_color("00","10","11","10"); return;}
 if(currentLetter==','){representation_color("00","10","11","00"); return;}
 if(currentLetter=='!'){representation_color("00","10","00","01"); return;}
 if(currentLetter=='"'){representation_color("00","10","00","10"); return;}
 if(currentLetter=='#'){representation_color("00","10","00","11"); return;}
 if(currentLetter=='$'){representation_color("00","10","01","00"); return;}
 if(currentLetter=='('){representation_color("00","10","10","00"); return;}
 if(currentLetter==')'){representation_color("00","10","10","01"); return;}
 if(currentLetter=='+'){representation_color("00","10","10","11"); return;}
 if(currentLetter=='-'){representation_color("00","10","11","01"); return;}
 if(currentLetter=='/'){representation_color("00","10","11","11"); return;}
 if(currentLetter==':'){representation_color("00","11","10","10"); return;}
 if(currentLetter==';'){representation_color("00","11","10","11"); return;}
 if(currentLetter=='<'){representation_color("00","11","11","00"); return;}
 if(currentLetter=='='){representation_color("00","11","11","01"); return;}
 if(currentLetter=='>'){representation_color("00","11","11","10"); return;}
 if(currentLetter=='?'){representation_color("00","11","11","11"); return;}
 if(currentLetter=='@'){representation_color("01","00","00","00"); return;}
 if(currentLetter=='['){representation_color("01","01","10","11"); return;}
 if(currentLetter==']'){representation_color("01","01","11","01"); return;}
 if(currentLetter=='^'){representation_color("01","01","11","10"); return;}
 if(currentLetter=='_'){representation_color("01","01","11","11"); return;}
 if(currentLetter=='{'){representation_color("01","11","10","11"); return;}
 if(currentLetter=='}'){representation_color("01","11","11","01"); return;}
 if(currentLetter=='|'){representation_color("01","11","11","00"); return;}
 if(currentLetter=='~'){representation_color("01","11","11","10"); return;}
}
