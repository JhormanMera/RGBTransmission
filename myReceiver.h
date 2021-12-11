#ifndef myReceiver_h
#define myReceiver_h
#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#include <Adafruit_TCS34725.h>
class myReceiver{
  public:
  myReceiver();
  void setupReceiver();
  void readColor(float &valueLedR, float &valueLedG, float &valueLedB);
  void readText(float &valueLedR, float &valueLedG, float &valueLedB,String &binaryValue);
  void initializer(float &valueLedR, float &valueLedG, float &valueLedB,String &binaryValue);
  boolean firstRead(float &valueLedR, float &valueLedG, float &valueLedB,String &binaryValue);
  void beginReceive(float &r, float &g, float &b, String &bin);
  void XORChecksum16(const byte *data);
  int stringBinaryToInt(String val);
  void readVectorColor(float &pos1,float &pos2, float &pos3,String &binaryValue);
};
#endif
