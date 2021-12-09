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
