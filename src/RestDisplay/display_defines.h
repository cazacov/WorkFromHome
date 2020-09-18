#ifndef _DISPLAY_DEFINES_h
#define _DISPLAY_DEFINES_h

#define DISPLAY_FASTLED

#ifdef DISPLAY_ADAFRUIT
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define COLOR_GOLD 0x00808000
#define COLOR_GREEN 0x00008000
#define COLOR_TYPE uint32_t
#endif

#ifdef DISPLAY_FASTLED
#include<FastLED.h>
//#define COLOR_TYPE CRGB
//#define COLOR_GOLD CRGB::Gold
//#define COLOR_GREEN CRGB::Green
#define COLOR_GOLD 0x00808000
#define COLOR_GREEN 0x00800000
#define COLOR_TYPE uint32_t
#endif

#define swapRG(color) do \
{ \
  uint32_t dif = ((color & 0x00FF0000) >> 16) ^ ((color & 0x0000FF00) >> 8); \
  color ^= dif << 8;  \
  color ^= dif << 16; \
} while(0) 

#endif
