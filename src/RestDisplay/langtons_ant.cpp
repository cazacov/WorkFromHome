#include "langtons_ant.h"
  
void LangtonsAnt::init() {
  field = (bool*)malloc(maxx * maxy);
  for (int i = 0; i < maxx*maxy; i++) {
    field[i] = false;
  }
  direction = 3;
  x = maxx/2;
  y = maxy/2;
}

void LangtonsAnt::next_step(CRGB color) {

  bool cell_state = get_cell(x, y);
  
  if (cell_state) {     
    // At a "black" square, turn 90° counter-clockwise
    direction += 3;
  } else {
    // At a "white" square, turn 90° clockwise
    direction += 1;   
  }
  direction &= 0x03;

  // flip the color of the square
  bool new_state = !cell_state;
  set_cell(x, y, new_state);
  display->set_pixel(x, y, new_state ? color : CRGB::Black);

  // move forward one unit
  switch (direction) {
    case 0: 
      y+=1;
      break;
    case 1:
      x+=1;
      break;
     case 2:
      y-=1;
      break;
     case 3:
      x-=1;
      break; 
  }
  x = (x+maxx) % maxx;
  y = (y+maxy) % maxy;
  display->set_pixel(x, y, CRGB::Green);
  display->show();
}

bool LangtonsAnt::get_cell(int8_t x, int8_t y) {
  y = (y + maxy) % maxy;
  x = (x + maxx) % maxx;
  return field[(int)y*maxx + x]; 
}

void LangtonsAnt::set_cell(int8_t x, int8_t y, bool value) {
  y = (y + maxy) % maxy;
  x = (x + maxx) % maxx;
  field[(int)y*maxx + x] = value; 
}
