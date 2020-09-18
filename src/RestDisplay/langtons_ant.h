#ifndef _LANGTONS_ANT_h
#define _LANGTONS_ANT_h

#include "display.h"
#include "display_defines.h"

class LangtonsAnt {
  Display* display;
  bool* field; 
  bool get_cell(int8_t x, int8_t y);
  void set_cell(int8_t x, int8_t y, bool value);
  int8_t maxx;
  int8_t maxy;
  byte direction;
  int8_t x;
  int8_t y;
public:  
  LangtonsAnt(Display* _display) { this->display = _display; maxx = display->width(); maxy = display->height(); }
  void init();
  void next_step(uint32_t color);
};

#endif
