#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include "ColorConverterLib.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725();

#define MINVALUE 6000
#define DELAY 120
#define OUTPUTLED 10

char* text = "Escribí %Escribí un cuento de cien palabras perfecto. La gente lo leía con avidez, y lo enviaban entusiasmados a sus amigos. Me llamaron para hablar sobre el cuento en la tele, y desde Hollywood querían adaptarlo. Entonces alguien descubrió que había escrito porque, en vez de por qué, así que ahora sobraba una palabra. Pero quitar cualquiera de ellas desmontaba el delicado mecanismo de relojería que había conseguido construir. Finalmente eliminé un artículo, pero ya no es lo mismo. Los críticos literarios me ignoran, han cancelado el programa al que tenía que ir, y Scorsese ya no me coge el teléfono.%";
int textLength;
int dataAmount;
bool previous_state;
bool current_state;
bool start;
bool reading;
char selector;

void setup() {
  pinMode(OUTPUTLED, OUTPUT);
  textLength = strlen(text);
  digitalWrite(OUTPUTLED, HIGH);
  Serial.begin(9600);
  start = false;
  selector = '*';
  if (!tcs.begin())
  {
    Serial.println("Error al iniciar TCS34725");
    while (1) delay(1000);
  }
}

void loop() {
  if(selector == '*'){
    while(selector == '*'){
      if(Serial.available() > 0){
        selector = Serial.read();
      }
    }
  }
 
  if(selector=='r'){
      readInfoBlock();
    }else{ 
      writeInfoBlock(); 
    }
    if(selector=='r'){
      XORChecksum16();
    }
    selector='*';
}
void readInfoBlock()
{
  current_state = getColor();
  if(!current_state && previous_state)
  {
    printTextByte(receiveByte());
  }
  previous_state = current_state;
}
void writeInfoBlock()
{
  for(int i = 0; i < textLength; i ++)
  {
    transmitteByte(text[i]);
  }
  delay(DELAY);
  reading = true;
}
bool getColor()
{
  uint16_t r, g, b, c, lux;
  tcs.getRawData(&r, &g, &b, &c);
  lux = tcs.calculateLux(r, g, b);
  //Serial.println(lux);
  return lux > MINVALUE ? true : false;
}
char receiveByte()
{
  char ret = 0;
  delay(DELAY*1.5);
  for(int i = 0; i < 8; i++)
  {
   ret = ret | getColor() << i; 
   delay(DELAY);
  }
  return ret;
}
void printTextByte(char my_byte){
  if(start){
   Serial.print(my_byte);
   dataAmount++;
  }
  if(my_byte == '%'){
    start = !start;
  }
}

void transmitteByte(char currentByte){
  digitalWrite(OUTPUTLED, LOW);
  delay(DELAY);
  for(int i = 0; i < 8; i++) {
    colorByte(currentByte, i);
  }
  digitalWrite(OUTPUTLED, HIGH);
  delay(DELAY);
}

void colorByte(char currentByte, int i){
    digitalWrite(OUTPUTLED, (currentByte&(0x01 << i))!=0 );
    delay(DELAY);
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
