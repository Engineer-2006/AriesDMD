#ifndef ARIES_DMD_H
#define ARIES_DMD_H

#include <Arduino.h>

// ===== Display constants =====
#define DMD_PANEL_WIDTH   32
#define DMD_PANEL_HEIGHT  16
#define DMD_SCAN_PLANES   4
#define DMD_BYTES_PER_PLANE 16      // 4 rows × 4 bytes
#define DMD_RAM_BYTES_PER_PANEL 64  // 4 planes × 16 bytes

// ===== Graphics modes =====
#define GRAPHICS_NORMAL   0
#define GRAPHICS_INVERSE  1
#define GRAPHICS_TOGGLE   2

// ===== Pin configuration struct =====
struct AriesDMDPins {
  uint8_t data;
  uint8_t clk;
  uint8_t lat;
  uint8_t oe;
  uint8_t a;
  uint8_t b;
};

class AriesDMD {
public:
  AriesDMD(uint8_t panelsWide,
           uint8_t panelsHigh,
           AriesDMDPins pins);

  void begin();
  void clearScreen(bool normal = true);
  void writePixel(uint16_t x, uint16_t y, uint8_t mode, bool pixel);
  void scanDisplay();

  uint16_t width()  const;
  uint16_t height() const;

private:
  void shiftOutByte(uint8_t data);

  AriesDMDPins pins;

  uint8_t *screenRAM;
  uint8_t scanPlane;

  uint8_t panelsWide;
  uint8_t panelsHigh;
  uint16_t totalPanels;
};

#endif