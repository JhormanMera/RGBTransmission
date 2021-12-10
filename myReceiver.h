#ifndef myReceiver_h
#define myReceiver_h
#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#include <Adafruit_TCS34725.h>
class myReceiver{
  private:
  char compareLetter;
  String binaryValue;
   void readVectorColor(float &pos1,float &pos2, float &pos3,String &binaryValue);
   void readLetter(String &binaryValue);
  public:
  myReceiver();
  void setupReceiver();
  void readColor(float &valueLedR, float &valueLedG, float &valueLedB);
  void setCompareLetter(char compare);
  char getCompareLetter();
  String getBinaryValue();
  void readText(float &valueLedR, float &valueLedG, float &valueLedB,String &binaryValue);
  void initializer(float &valueLedR, float &valueLedG, float &valueLedB,String &binaryValue);
  
};
#endif