#include "myEmitter.h"
#include "myReceiver.h"

myEmitter emitter = myEmitter(100);
myReceiver receiver = myReceiver();

/*
 * Tomamos ideas de:
 * https://github.com/systembolaget/Physical-computing-sensor-servo-tutorial-6a-Colour-finder-with-ams-TCS34725-and-HD-1900A
 * https://www.youtube.com/watch?v=FQnzRW4XukA
 * https://www.youtube.com/watch?v=TWKmbTITEes
 * https://create.arduino.cc/editor/ProfeGarcia/3e920fea-36c8-4fbc-a3a6-783f5ffa1902/preview
 * https://create.arduino.cc/editor/ProfeGarcia/f8bf6115-9715-4345-88f2-9c3cb1ecefca/preview
 * https://www.youtube.com/watch?v=PPsUHX6nVow (Video ficheros)
 *  
 * Bibliografía de conceptos:
 * https://en.wikipedia.org/wiki/Color_difference
 * https://www.calculadoraconversor.com/ascii-a-binario/
 * Calibracion sensor
 * https://learn.adafruit.com/calibrating-sensors/two-point-calibration
 * https://www.youtube.com/watch?v=X4RevYjBJCU&t=176s
 */
void setup(){
  receiver.setupReceiver();
  emitter.setupEmitter();
  emitter.bit_Sync();
}

void loop() {
   float r = 0.0;
   float g = 0.0;
   float b = 0.0;
   String bin = "";
   char a = ' ';
   receiver.initializer(r,g,b,bin);
   emitter.letterToColor(a);
  
   
   
}
