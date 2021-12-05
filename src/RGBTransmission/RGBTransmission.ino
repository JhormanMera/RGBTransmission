#include <ColorConverterLib.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"
int LEDR = 11;  //Definimos las 3 salidas digitales PWM
int LEDG = 9;
int LEDB = 10;

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);

void setup()
{
  
  Serial.begin(9600);
 pinMode(LEDR,OUTPUT); // los pins digitales serán de salida
 pinMode(LEDG,OUTPUT);
 pinMode(LEDB,OUTPUT);

  if (!tcs.begin())
  {
    Serial.println("Error al iniciar TCS34725");
    while (1) delay(1000);
  }
}

void loop()
{
  /*
   analogWrite(LEDR, 255); //De 0-255 para color
 analogWrite(LEDG, 0);
 analogWrite(LEDB, 0);
 delay(3000);
 */
  letterToColor();
  //readColorInfo();
  
}
void letterToColor(){
  
  while(Serial.available() > 0) {
     String letter = Serial.readString(); 
     Serial.print(letter);
     int redColor = numberForRed(letter);
     int blueColor = numberForBlue(letter);
     int greenColor = numberForGreen(letter);
     int duration = timeForLetter(letter);
     
     analogWrite(LEDR, redColor); //De 0-255 para color

     Serial.println("Rojo es: ");
     Serial.println(redColor);
     
     analogWrite(LEDG, greenColor);

     Serial.println("Verde es: ");
     Serial.println(greenColor);
     
     analogWrite(LEDB, blueColor);
     
     Serial.println("Azul es: ");
     Serial.println(blueColor);
     delay(duration);
     
     Serial.println("Debio cambiar el color");
     
 }

  
}
void readColorInfo(){
  
 uint16_t clear, red, green, blue;
  tcs.setInterrupt(false);
  delay(50); // Cuesta 50ms capturar el color
  tcs.getRawData(&red, &green, &blue, &clear);
  tcs.setInterrupt(true);

  // Hacer rgb medición relativa
  uint32_t sum = clear;
  float r, g, b;
 /*
  Serial.println("*************************");
  Serial.print("Red = ");Serial.println(String(red));
  Serial.print("Green = ");Serial.println(String(green));
  Serial.print("Blue = ");Serial.println(String(blue));
  */
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  /*
  Serial.println("");
  Serial.print("R = ");Serial.println(String(r));
  Serial.print("G = ");Serial.println(String(g));
  Serial.print("B = ");Serial.println(String(b));
  */
  // Escalar rgb a bytes
  r *= 255; g *= 255; b *= 255;

  // Convertir a hue, saturation, value
  double hue, saturation, value;
  ColorConverter::RgbToHsv(static_cast<uint8_t>(r), static_cast<uint8_t>(g), static_cast<uint8_t>(b), hue, saturation, value);
  delay(1000);
  Serial.println("");
  Serial.print("R byte = ");Serial.println(String(r));
  Serial.print("G byte= ");Serial.println(String(g));
  Serial.print("B byte= ");Serial.println(String(b));
   Serial.print("Clear = ");Serial.println(String(sum));
  Serial.print("Saturation = ");Serial.println(String(blue));
  Serial.println("*************************");
}


int numberForBlue(String letter){
  
      if(letter=="a"){
        int toReturn = 0;
        
      return toReturn;;
      }else if(letter=="e"){
      return 250;  
      }else{
      return 0;  
      }
      
}
int numberForGreen(String letter){
  
    if(letter=="a"){
      return 0;
      }else if(letter=="e"){
      return 0;  
      }else{
      return 250;  
      }

    
}
  


int numberForLetter(String letter){

    if(letter=="a"){
      return 600;
      }else if(letter=="e"){
      return 200;  
      }else{
      return 400;  
      }

    
  
  }

int timeForLetter(String letter){

      //Serial.println("Entro");
    if(letter=="a"){
      return 2000;
      }else if(letter=="e"){
      return 4000;  
      }else{
      return 6000;  
      }
  
  
  
  }
int numberForRed(String letter){
  
    if(letter=="a"){
      return 250;
      }else if(letter=="e"){
      return 150;  
      }else{
      return 0;  
      }
  
}
