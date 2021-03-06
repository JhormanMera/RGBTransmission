#ifndef myEmitter_h
#define myEmitter_h
#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#include <Separador.h>
#define OUTPUTLEDR 11  //Definimos las 3 salidas digitales PWM
#define OUTPUTLEDB 10
#define OUTPUTLEDG 9

class myEmitter{
  private:
    int delayValue;
    void vector_color(String pos);
    void representation_color(String pos1, String pos2, String pos3, String pos4);
    
  public:
  void sendLetter(char currentLetter);
  myEmitter(int delayVal);
  void bit_Sync();
  void bit_Final();
  void setupEmitter();
  void sendText();
};
#endif
