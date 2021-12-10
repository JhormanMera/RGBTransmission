#include "myEmitter.h"
Separador s;

myEmitter::myEmitter(int delayVal){ 
   delayValue=delayVal;
}

void myEmitter::bit_Sync(){
  //Bit Sync
   digitalWrite(OUTPUTLEDR, HIGH);
   digitalWrite(OUTPUTLEDG, HIGH);
   digitalWrite(OUTPUTLEDB, HIGH);
   delay(delayValue*2);
}
void myEmitter::bit_Final(){
  //Bit Sync
   digitalWrite(OUTPUTLEDR, HIGH);
   digitalWrite(OUTPUTLEDG, HIGH);
   digitalWrite(OUTPUTLEDB, LOW);
   delay(delayValue*2);
}

void myEmitter::setupEmitter() {
 Serial.begin(9600);
 pinMode(OUTPUTLEDR,OUTPUT); // los pins digitales serán de salida
 pinMode(OUTPUTLEDG,OUTPUT);
 pinMode(OUTPUTLEDB,OUTPUT);
}

void myEmitter::vector_color(String pos){
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

void myEmitter::representation_color(String pos1, String pos2, String pos3, String pos4){
  vector_color(pos1);
  vector_color(pos2);
  vector_color(pos3);
  vector_color(pos4);
}


void myEmitter::letterToColor(char *currentLetter){
 while(Serial.available() > 0) {
      currentLetter = Serial.read(); //lee la letra del puerto serial
      bit_Sync();
      sendLetter(currentLetter); // Transforma la letra en color
 }
 bit_Final();
}

void myEmitter::sendLetter(char currentLetter){
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

void myEmitter::sendText(){
  char current;
      while(Serial.available() > 0) {
      String fullText = Serial.readString(); //lee la letra del puerto serial
          for(int j=0; j < fullText.length();j++){
            current = fullText.charAt(j);
            bit_Sync();
            sendLetter(current); // Transforma la letra en color            /
     }
            
   }
   bit_Final();  
 }
