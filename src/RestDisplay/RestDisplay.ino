// include library
#include "display.h"

Display display;

void setup() {
  display.clear();
}


void loop() {
  
  for (byte y = 0; y < display.height(); y++) {
    for (byte x = 0; x < display.width(); x++) {      
      display.set_pixel(x, y, CRGB::Red);
      display.show();
      FastLED.delay(10);  
      display.set_pixel(x, y, CRGB::Black);
    }
  }
}
