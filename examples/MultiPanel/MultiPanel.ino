#include <AriesDMD.h>

AriesDMDPins pins = {
  10, 8, 9, 15, 6, 7
};

AriesDMD dmd(2, 1, pins); // 2 panels wide

void setup() {
  dmd.begin();
  for (int x = 0; x < dmd.width(); x++) {
    dmd.writePixel(x, x % dmd.height(), GRAPHICS_NORMAL, true);
  }
}

void loop() {
  dmd.scanDisplay();
}