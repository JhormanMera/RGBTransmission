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
  int THRESHOLD= 6000;
  int PERIOD=15;
  int dataAmount;
  bool previous_state;
  bool current_state;
  Adafruit_TCS34725 tcs = Adafruit_TCS34725();
  public:
  boolean startPrint;
  float valueLedR; 
  float valueLedG; 
  float valueLedB;
  myReceiver();
  void setupReceiver();
  void XORChecksum16();
  int stringBinaryToInt(String val);
  bool getColor();
  String colorToBinary();
};
#endif
