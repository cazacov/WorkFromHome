#include "display.h"

Display::Display() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, DISPLAY_WIDTH * DISPLAY_HEIGHT);
}

void Display::clear() {
  FastLED.clear(true);    
}


void Display::set_pixel(byte x, byte y, CRGB color) {

    int pos = y * DISPLAY_WIDTH;
    pos += (y & 1) ?  DISPLAY_WIDTH - 1 -x : x;  

    if (pos < 300) {
      int tmp = color.r;
      color.r = color.g;
      color.g = tmp;
    }
    leds[pos] = color;
}    

void Display::show() {
  FastLED.show();
}
