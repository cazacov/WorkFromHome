#include "display.h"

Display::Display() {
#ifdef DISPLAY_ADAFRUIT
  pixels = new Adafruit_NeoPixel(DISPLAY_WIDTH * DISPLAY_HEIGHT, DATA_PIN, NEO_GRB + NEO_KHZ800);
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels->begin();
#elif defined(DISPLAY_FASTLED)
   FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, DISPLAY_WIDTH * DISPLAY_HEIGHT);
#endif

}

void Display::clear() {
#ifdef DISPLAY_ADAFRUIT  
  pixels->clear();    
  pixels->show();
#elif defined(DISPLAY_FASTLED)
  FastLED.clear(true);
#endif
}


void Display::set_pixel(byte x, byte y, COLOR_TYPE color) {

    int pos = (int)y * DISPLAY_WIDTH;
    pos += (y & 1) ?  DISPLAY_WIDTH - 1 -x : x;  

    if (pos >= 300) {
      swapRG(color);        
    }
#ifdef DISPLAY_ADAFRUIT     
    pixels->setPixelColor(pos, color);
#elif defined(DISPLAY_FASTLED)
    leds[pos] = color;
#endif
}    

void Display::show() {
#ifdef DISPLAY_ADAFRUIT       
  pixels->show();
#elif defined(DISPLAY_FASTLED)
  FastLED.show();
#endif
}
