#include "AriesDMD.h"

// panelsWide = 1  → number of P10 panels horizontally
// panelsHigh = 1  → number of P10 panels vertically
// pinOE  = 9  → Output Enable
// pinA   = 6  → Row select A
// pinB   = 7  → Row select B
// pinLAT = 8  → Latch (STB)
AriesDMD dmd(1, 1, 9, 6, 7, 8);

void setup() {
  dmd.begin();
  dmd.writePixel(0, 0, GRAPHICS_NORMAL, true); // First led on the top left corner will be on.
}

void loop() {
  dmd.scanDisplay();
}
