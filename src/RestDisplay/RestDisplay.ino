// include library
#include "display.h"
#include "gameoflife.h"
#include "langtons_ant.h"

Display display;
//Game game(&display);
LangtonsAnt game(&display);

void setup() {
  display.clear();
  game.init();
}


void loop() {
  game.next_step(CRGB::Gold);
  delay(100);
}
