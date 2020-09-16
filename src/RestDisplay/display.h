#ifndef _DISPLAY_h
#define _DISPLAY_h

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

//define number of LED and pin
#define DATA_PIN 13
#define DISPLAY_WIDTH 28
#define DISPLAY_HEIGHT 12

class Display {
private:
  Adafruit_NeoPixel* pixels;
public:
  Display();
  void clear();  
  void set_pixel(byte x, byte y, uint32_t  color);
  void show();
  int width() { return DISPLAY_WIDTH;}
  int height() { return DISPLAY_HEIGHT;}
};

#endif
