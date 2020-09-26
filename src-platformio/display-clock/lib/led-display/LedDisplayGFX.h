#ifndef LED_DISPLAY_GFX_H
#define LED_DISPLAY_GFX_H

#include <Adafruit_I2CDevice.h>
#include "Adafruit_GFX.h"
#include <FastLED.h>

#define DISP_PIN 13

// ws2812b stripes usualy are sold in 5 meter length and have 300 LEDs.
// In my case the first stripe was GRB, while the second had RGB order
#define INVERSE_RG_SECOND_STRIPE

class LedDisplayGFX : public Adafruit_GFX {
private:
   CRGB* leds;

public:
   LedDisplayGFX(uint16_t w, uint16_t h);
   void drawPixel(int16_t x, int16_t y, uint16_t color);
   void startWrite() {};
   void writePixel(int16_t x, int16_t y, uint16_t color);
   void writeFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
   void endWrite();
};

#endif