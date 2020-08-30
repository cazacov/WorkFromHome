// include library
#include<FastLED.h>

//define number of LED and pin
#define NUM_LEDS 336
#define DATA_PIN 3

// create the ld object array
CRGB leds[NUM_LEDS];

// define 3 byte for the random color
byte  r, g, b;

void setup() {
  // init the LED object
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}


void loop() {
  // loop over the NUM_LEDS
  
  for (int cur = 0; cur < NUM_LEDS; cur++) {
    leds[cur] = CRGB (255, 0, 0);
    FastLED.show();
    FastLED.delay(50);
    leds[cur] = CRGB (0, 0, 0);
    FastLED.show();
  }

  for (int cur = 0; cur < NUM_LEDS; cur++) {
    leds[cur] = CRGB (0, 255, 0);
    FastLED.show();
    FastLED.delay(50);
    leds[cur] = CRGB (0, 0, 0);
    FastLED.show();
  }

  for (int cur = 0; cur < NUM_LEDS; cur++) {
    leds[cur] = CRGB (0, 0, 255);
    FastLED.show();
    FastLED.delay(50);
    leds[cur] = CRGB (0, 0, 0);
    FastLED.show();
  }
}
