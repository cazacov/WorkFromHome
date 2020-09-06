#ifndef _DISPLAY_h
#define _DISPLAY_h


#include<FastLED.h>

//define number of LED and pin
#define DATA_PIN 13
#define DISPLAY_WIDTH 28
#define DISPLAY_HEIGHT 12

class Display {
private:
  CRGB leds[DISPLAY_WIDTH * DISPLAY_HEIGHT];
public:
  Display();
  void clear();  
  void set_pixel(byte x, byte y, CRGB color);
  void show();
  int width() { return DISPLAY_WIDTH;}
  int height() { return DISPLAY_HEIGHT;}
};

#endif
