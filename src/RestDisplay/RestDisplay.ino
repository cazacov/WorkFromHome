// include library
#include "display.h"
//#include "gameoflife.h"
//#include "langtons_ant.h"
//#include "display_gfx.h"

//Display display;
//LangtonsAnt game(&display);

#include "display_gfx.h"

#include <Fonts/Org_01.h>
#include <Fonts/TomThumb.h>
#include <Fonts/Picopixel.h>



DisplayGFX display;

void setup() {
//  display.clear();
//  game.init();
}


void loop() {
//  display.setFont(&Picopixel );
  display.setCursor(3,3);
  display.setTextColor(0x07E0);
  display.setTextWrap(false);
  display.print("2020");

  //delay(5000);

//  game.next_step(COLOR_GOLD);
  //delay(100);
}
