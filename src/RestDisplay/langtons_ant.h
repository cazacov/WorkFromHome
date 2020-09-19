#ifndef _LANGTONS_ANT_h
#define _LANGTONS_ANT_h

#include "display.h"
#include "display_defines.h"

#define N_COLORS 7

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
  COLOR_TYPE colors[N_COLORS] = { 0x000080, 0x008000, 0x008080, 0x800000, 0x800080, 0x808000, 0x808080 };
  size_t next_color;
public:  
  LangtonsAnt(Display* _display) { this->display = _display; maxx = display->width(); maxy = display->height(); }
  void init();
  void next_step(COLOR_TYPE color);
};

#endif
