#ifndef myEmitter_h
#define myEmitter_h
#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#define OUTPUTLED 11  //Definimos la salida digital del LED

class myEmitter{
  private:
  int PERIOD=15;
  public:
  myEmitter();
  String codeLetter(char currentLetter);
  void setupEmitter();
  void colorOutput(String bitLetter);
  
};
#endif
