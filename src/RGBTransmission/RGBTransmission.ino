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
