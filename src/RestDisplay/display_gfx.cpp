#include "display_gfx.h"

DisplayGFX::DisplayGFX(): Adafruit_GFX(DISP_WIDTH, DISP_HEIGHT) {
  FastLED.addLeds<NEOPIXEL, DISP_PIN>(leds, DISP_WIDTH * DISP_HEIGHT);
  //FastLED.clear(true);
}

void DisplayGFX::drawPixel(int16_t x, int16_t y, uint16_t color) {

  if (x < 0 || x >= DISP_WIDTH) {
    return;
  }
  if (y < 0 || y >= DISP_HEIGHT) {
    return;
  }
  
  uint32_t r = (color & 0xF800) >> 8;
  uint32_t g = (color & 0x07E0) >> 3;
  uint32_t b = (color & 0x001F) << 3;

  y = DISP_HEIGHT - y - 1;
  
  int pos = (int)y * DISP_WIDTH;
  pos += (y & 1) ?  DISP_WIDTH - 1 -x : x;  
  leds[pos] = (r << 16) | (g << 8) | b;
  FastLED.show();
}
