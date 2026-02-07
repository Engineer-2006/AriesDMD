#include "AriesDMD.h"

// AriesDMD(panelsWide, panelsHigh, pinOE, pinA, pinB, pinLAT)
// panelsWide = 2  → two P10 panels connected horizontally (total width = 64 pixels)
// panelsHigh = 1  → one P10 panel vertically (total height = 16 pixels)
// pinOE  = 9  → Output Enable 
// pinA   = 6  → Row select A
// pinB   = 7  → Row select B
// pinLAT = 8  → Latch / STB pin
AriesDMD dmd(2, 1, 9, 6, 7, 8);

void setup() {
  dmd.begin();

  // Draw a horizontal line across the middle row (y = 8)
  // Width = 2 panels × 32 pixels = 64 pixels
  for (int x = 0; x < 64; x++) {
    dmd.writePixel(x, 8, GRAPHICS_NORMAL, true);
  }
}

void loop() {
  dmd.scanDisplay();
}
