#include <AriesDMD.h>

AriesDMDPins pins = {
  .data = 10,
  .clk  = 8,
  .lat  = 9,
  .oe   = 15,
  .a    = 6,
  .b    = 7
};

AriesDMD dmd(1, 1, pins); // Single Panel

void setup() {
  dmd.begin();
  dmd.writePixel(5, 5, GRAPHICS_NORMAL, true); // Fifth Row, Fifth Column Led will be high
}

void loop() {
  dmd.scanDisplay();
}