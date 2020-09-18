#ifndef _DISPLAY_h
#define _DISPLAY_h

#include "display_defines.h"

//define number of LED and pin
#define DATA_PIN 13
#define DISPLAY_WIDTH 28
#define DISPLAY_HEIGHT 12

class Display {
private:
#ifdef DISPLAY_ADAFRUIT
  Adafruit_NeoPixel* pixels;
#elif defined(DISPLAY_FASTLED)
  CRGB leds[DISPLAY_WIDTH * DISPLAY_HEIGHT];
#endif

  
public:
  Display();
  void clear();  
  void set_pixel(byte x, byte y, COLOR_TYPE  color);
  void show();
  int width() { return DISPLAY_WIDTH;}
  int height() { return DISPLAY_HEIGHT;}
};

#endif
