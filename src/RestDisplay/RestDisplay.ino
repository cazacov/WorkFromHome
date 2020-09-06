// include library
#include "display.h"
#include "gameoflife.h"

Display display;
Game game(&display);

void setup() {
  display.clear();
  game.init();
  game.put_glider(12, 5);
  game.show(CRGB::Gold);
}


void loop() {
  game.next_step(CRGB::Gold);
  delay(50);
}
