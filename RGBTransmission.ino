#include <Adafruit_TCS34725.h>
boolean modeSelected;
boolean startPrint;
float valueLedR; 
float valueLedG; 
float valueLedB;
int PERIOD=120;
int THRESHOLD= 6000;
int OUTPUTLED=10;
int dataAmount;
bool previous_state;
bool current_state;
Adafruit_TCS34725 tcs = Adafruit_TCS34725();
String text = "Escribí un cuento de cien palabras perfecto. La gente lo leía con avidez, y lo enviaban entusiasmados a sus amigos. Me llamaron para hablar sobre el cuento en la tele, y desde Hollywood querían adaptarlo. Entonces alguien descubrió que había escrito porque, en vez de por qué, así que ahora sobraba una palabra. Pero quitar cualquiera de ellas desmontaba el delicado mecanismo de relojería que había conseguido construir. Finalmente eliminé un artículo, pero ya no es lo mismo. Los críticos literarios me ignoran, han cancelado el programa al que tenía que ir, y Scorsese ya no me coge el teléfono.~";
/*
 * Tomamos ideas de:
 * https://github.com/systembolaget/Physical-computing-sensor-servo-tutorial-6a-Colour-finder-with-ams-TCS34725-and-HD-1900A
 * https://www.youtube.com/watch?v=FQnzRW4XukA
 * https://www.youtube.com/watch?v=TWKmbTITEes
 * https://create.arduino.cc/editor/ProfeGarcia/3e920fea-36c8-4fbc-a3a6-783f5ffa1902/preview
 * https://create.arduino.cc/editor/ProfeGarcia/f8bf6115-9715-4345-88f2-9c3cb1ecefca/preview
 * https://www.youtube.com/watch?v=PPsUHX6nVow (Video ficheros)
 * https://forum.arduino.cc/t/converting-binary-strings-to-bytes-integers/212848/5 (String to number)
 * https://forum.arduino.cc/t/libreria-decimal-a-binario-y-binario-a-decimal/394353/3
 * https://github.com/SaadOjo/DIY_Li-Fi
 * 
 * Bibliografía de conceptos:
 * https://en.wikipedia.org/wiki/Color_difference
 * https://www.calculadoraconversor.com/ascii-a-binario/
 * Calibracion sensor
 * https://learn.adafruit.com/calibrating-sensors/two-point-calibration
 * https://www.youtube.com/watch?v=X4RevYjBJCU&t=176s
 */
 
void setup(){
  Serial.begin(9600);
  pinMode(OUTPUTLED,OUTPUT); // El pin digital será de salida
  digitalWrite(OUTPUTLED,HIGH);
  if (!tcs.begin())  {//Verificamos la conexión del Sensor de color
  Serial.println("Error al iniciar TCS34725");
  while (!tcs.begin()) delay(1000);
}
}
void loop() {
  modeSelected=false;
  char read_;
  if(Serial.available()>0){
    read_=Serial.read();
    if(read_=='&'){
     secondModeSelecter();
    }else if(read_=='*'){
      thirdModeSelecter();
    }
  }
}

void secondModeSelecter(){
  char read_;
  while(modeSelected==false){
    if(Serial.available()>0){
      read_=Serial.read();
      if(read_=='e'){
        delay(15);
        secondModeSend();
        modeSelected=true;
      }else if(read_=='r'){
        modeSelected=true;
        startPrint=true;
        printValueSecondMode();
       XORChecksum16();
      }
    }
  }
}

void secondModeSend(){
   for(int i = 0; i < text.length(); i ++){
      colorOutput(codeLetter(text.charAt(i)));
    }
    delay(15);
}

void printValueSecondMode(){
  String value;
  while(startPrint){
    if(value == '~'){
      startPrint = !startPrint;
    }
    if(startPrint){
        value=stringBinaryToInt(colorToBinary());
      Serial.print(value); 
    }
  }        
}

void thirdModeSelecter(){
  char read_;
  while(modeSelected==false){
    if(Serial.available()>0){
      read_=Serial.read();
      if(read_=='e'){
        delay(15);
        thirdModeSend();
        modeSelected=true;
      }else if(read_=='r'){
        modeSelected=true;
        thirdModeReceive();
      }
    }
  }
}

  void thirdModeSend(){
    String value;
    for(int i = 0; i < text.length(); i ++){
        colorOutput(codeLetter(text.charAt(i)));
        delay(20);
        value=stringBinaryToInt(colorToBinary());
         if(i==0){}else if(value!=text[i-1]){
            Serial.println("Error al recibir ECO");
            return;
         }
      }
       delay(15);
    }

void thirdModeReceive(){
  String value;
  while(startPrint){
    if(value == '~'){
      startPrint = !startPrint;
    }
    if(startPrint){
        value=stringBinaryToInt(colorToBinary());
        delay(15);
       colorOutput(value);
      } 
    }
  }   

  void colorOutput(String letter){
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

String codeLetter(char currentLetter){
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

int stringBinaryToInt(String val){ 
    char s[10];
    val.toCharArray(s,10);
    int value = 0;
   for (int i=0; i< strlen(s); i++){  // for every character in the string  strlen(s) returns the length of a char array
    value *= 2; // double the result so far
  if (s[i] == '1') value++;  //add 1 if needed
  }
  return value;
}

void XORChecksum16(){
  const byte* data = 16;
  uint16_t value = 0;
  for (size_t i = 0; i < dataAmount / 2; i++){
    value ^= data[2*i] + (data[2*i+1] << 8);
  }
  if(dataAmount%2) value ^= data[dataAmount - 1];
  Serial.println(~value);
  dataAmount=0;
}

bool getColor(){
  uint16_t red, green, blue, c, luxes;
  tcs.getRawData(&red, &green, &blue, &c);
  luxes = tcs.calculateLux(red, green, blue);
  return luxes > THRESHOLD ? true : false;
}

String colorToBinary(){
  String ret = "";
  delay(PERIOD*1.5);
  for(int i = 0; i < 8; i++)
  {
   if(getColor()==true){
      ret.concat("1");
   }else{
      ret.concat("0");
   }
   delay(PERIOD);
  }
  dataAmount++;
  return ret;
}
