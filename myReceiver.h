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
  int dataAmount;
  String binaryValue;
  Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_60MS, TCS34725_GAIN_1X);
  public:
  float valueLedR; 
  float valueLedG; 
  float valueLedB;
  myReceiver();
  void setupReceiver();
  void readColor();
  void readText();
  void XORChecksum16();
  int stringBinaryToInt(String val);
  void readVectorColor();
};
#endif
