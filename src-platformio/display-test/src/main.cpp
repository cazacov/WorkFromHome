#include <Arduino.h>
#include "LedDisplayGFX.h"

LedDisplayGFX display(28, 12); // 28x12 LEDs

void setup() {
   // put your setup code here, to run once:
}

double phi = 0;
double x = 3;
double y = 3;

int xx = 3;
int yy = 3;

void loop() {

   phi += (rand() % 10) / 100.0;
   x += cos(phi);
   y += sin(phi);

   if (x < -0.4) {
      x = -0.4;
      phi = PI - phi;
   }
   if (x > 5.4) {
      x = 5.4;
      phi = PI - phi;
   }

   if (y < -0.4) {
      y = -0.4;
      phi = - phi;
   }
   if (y > 5.4) {
      y = 5.4;
      phi = -phi;
   }

   display.writeFillRect(xx, yy, 23, 7, 0);
   xx = x;
   yy = y;

   display.setCursor(xx, yy);
   display.setTextColor(0x07FF);
   display.print("2020");
   delay(500);
}