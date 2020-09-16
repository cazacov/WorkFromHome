#include "display.h"

Display::Display() {
  pixels = new Adafruit_NeoPixel(DISPLAY_WIDTH * DISPLAY_HEIGHT, DATA_PIN, NEO_GRB + NEO_KHZ800);
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels->begin();
}

void Display::clear() {
  pixels->clear();    
  pixels->show();
}


void Display::set_pixel(byte x, byte y, uint32_t color) {

    int pos = (int)y * DISPLAY_WIDTH;
    pos += (y & 1) ?  DISPLAY_WIDTH - 1 -x : x;  

/*    if (pos < 300) {
      int tmp = color.r;
      color.r = color.g;
      color.g = tmp;
    } */
    pixels->setPixelColor(pos, color);
//    leds[pos] = color;
}    

void Display::show() {
  pixels->show();
}
