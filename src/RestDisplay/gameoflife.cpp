#include "gameoflife.h"

void Game::init() {
  field = (bool*)malloc(display->width()*display->height());
  field_next = (bool*)malloc(display->width()*display->height());

  for (int i = 0; i < maxx*maxy; i++) {
    field[i] = false;
    field_next[i] = false;
  }
}
  
void Game::next_step(CRGB color) {

  for (int8_t y = 0; y < maxy; y++) {
    for (int8_t x = 0; x < maxx; x++) {
      byte count = 0;
      for (int8_t i = -1; i <=1; i++) {
        for (int8_t j = -1; j <=1; j++) {
          if (!i && !j) {
            continue;
          }
          if (get_cell(x+i, y+j)) {
            count++;
          }
        }
      }
      if (get_cell(x, y)) {
        set_next_cell(x, y, count >1 && count < 4);  
      } else {
        set_next_cell(x, y, count == 3);
      }
    }
  }

  for (int i = 0; i < maxx*maxy; i++) {
    field[i] = field_next[i];
  }
  show(color);
}

bool Game::get_cell(int8_t x, int8_t y) {
  y = (y + maxy) % maxy;
  x = (x + maxx) % maxx;
  return field[(int)y*maxx + x]; 
}

void Game::set_cell(int8_t x, int8_t y, bool value) {
  y = (y + maxy) % maxy;
  x = (x + maxx) % maxx;
  field[(int)y*maxx + x] = value; 
}

bool Game::get_next_cell(int8_t x, int8_t y) {
  y = (y + maxy) % maxy;
  x = (x + maxx) % maxx;
  return field_next[(int)y*maxx + x]; 
}

void Game::set_next_cell(int8_t x, int8_t y, bool value) {
  y = (y + maxy) % maxy;
  x = (x + maxx) % maxx;
  field_next[(int)y*maxx + x] = value; 
}

void Game::put_glider(byte x, byte y) {
  set_cell(x, y, true);
  set_cell(x+1, y, true);
  set_cell(x+2, y, true);
  set_cell(x+2, y+1, true);
  set_cell(x+1, y+2, true);
}

void Game::show(CRGB color) {
  byte x = 0;
  byte y = 0;  
  for (int i = 0; i < maxx*maxy; i++) {
    if (field[i]) {
      display->set_pixel(x, y, color);
    } else {
      display->set_pixel(x, y, CRGB::Black);
    }
    x++;
    if (x == maxx) { x = 0; y++;}
  }
  display->show();
}
