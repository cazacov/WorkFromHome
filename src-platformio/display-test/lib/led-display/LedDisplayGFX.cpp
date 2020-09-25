#include "LedDisplayGFX.h"

LedDisplayGFX::LedDisplayGFX(uint16_t w, uint16_t h) : Adafruit_GFX(w, h)
{
   size_t size = w * h * sizeof(CRGB);
   leds = (CRGB *)malloc(size);
   memset(leds, 0 , size);
   FastLED.addLeds<NEOPIXEL, DISP_PIN>(leds, w * h);
}

void LedDisplayGFX::drawPixel(int16_t x, int16_t y, uint16_t color)
{
   if (x < 0 || x >= WIDTH)
   {
      return;
   }
   if (y < 0 || y >= HEIGHT)
   {
      return;
   }

   uint32_t r = (color & 0xF800) >> 8;
   uint32_t g = (color & 0x07E0) >> 3;
   uint32_t b = (color & 0x001F) << 3;

   // Adafruit GFX uses top-down Y direction
   y = HEIGHT - y - 1;
   int16_t pos = y * WIDTH;
   // LED stripe has zigzag direction with 0,0 in the bottom-left corner
   pos += (y & 1) ? 28 - 1 - x : x;

#ifdef INVERSE_RG_SECOND_STRIPE
   if (pos >= 300)
   {
      // swap R and G colors
      uint32_t temp = r;
      r = g;
      g = temp;
   }
#endif

   leds[pos] = (r << 16) | (g << 8) | b;
   FastLED.show();
}