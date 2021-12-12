#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include "ColorConverterLib.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725();

#define THRESHOLD 6000
#define PERIOD 120

bool previous_state;
bool current_state;

void setup() {
  Serial.begin(9600);
  if (!tcs.begin())
  {
    Serial.println("Error al iniciar TCS34725");
    while (1) delay(1000);
  }
}

void loop() {
  current_state = get_ldr();
  if(!current_state && previous_state)
  {
    print_byte(get_byte());
  }
  previous_state = current_state;
}
bool get_ldr()
{
  uint16_t r, g, b, c, lux;
  tcs.getRawData(&r, &g, &b, &c);
  lux = tcs.calculateLux(r, g, b);
  return lux > THRESHOLD ? true : false;
}
char get_byte()
{
  char ret = 0;
  delay(PERIOD*1.5);
  for(int i = 0; i < 8; i++)
  {
   ret = ret | get_ldr() << i; 
   delay(PERIOD);
  }
  return ret;
}
void print_byte(char my_byte)
{
  char buff[2];
  sprintf(buff, "%c", my_byte);
  Serial.print(buff);
}
