#ifndef _GAMEOFLIFE_h
#define _GAMEOFLIFE_h

#include "display.h"

class Game {
  Display* display;
  bool* field; 
  bool* field_next;
  bool get_cell(int8_t x, int8_t y);
  void set_cell(int8_t x, int8_t y, bool value);
  bool get_next_cell(int8_t x, int8_t y);
  void set_next_cell(int8_t x, int8_t y, bool value);
  int8_t maxx;
  int8_t maxy;
public:  
  Game(Display* _display) { this->display = _display; maxx = display->width(); maxy = display->height();}
  void init();
  void put_glider(byte x, byte y);
  void next_step(uint32_t color);
  void show(uint32_t color);
};

#endif
