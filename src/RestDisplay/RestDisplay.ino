// include library
#include "display.h"
//#include "gameoflife.h"
#include "langtons_ant.h"

Display display;
LangtonsAnt game(&display);

void setup() {
  display.clear();
  game.init();
}


void loop() {
  game.next_step(0x00FFFF00);
  //delay(100);
}
