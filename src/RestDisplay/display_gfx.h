#ifndef DISPLAY_GFX_H
#define DISPLAY_GFX_H

#include "Adafruit_GFX.h"
#include<FastLED.h>

#define DISP_WIDTH 28
#define DISP_HEIGHT 12
#define DISP_PIN 13

class DisplayGFX : public Adafruit_GFX {
private:
  CRGB leds[DISP_WIDTH * DISP_HEIGHT];  
public:
  DisplayGFX();
  void drawPixel(int16_t x, int16_t y, uint16_t color);
};

#endif
