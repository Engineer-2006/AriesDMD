#include "AriesDMD.h"

AriesDMD::AriesDMD(uint8_t w, uint8_t h, AriesDMDPins p)
  : pins(p), panelsWide(w), panelsHigh(h)
{
  totalPanels = panelsWide * panelsHigh;
  screenRAM = (uint8_t*)malloc(totalPanels * DMD_RAM_BYTES_PER_PANEL);
  scanPlane = 0;
}

void AriesDMD::begin() {
  pinMode(pins.data, OUTPUT);
  pinMode(pins.clk,  OUTPUT);
  pinMode(pins.lat,  OUTPUT);
  pinMode(pins.oe,   OUTPUT);
  pinMode(pins.a,    OUTPUT);
  pinMode(pins.b,    OUTPUT);

  digitalWrite(pins.oe, HIGH);
  clearScreen(true);
}

void AriesDMD::clearScreen(bool normal) {
  memset(screenRAM,
         normal ? 0xFF : 0x00,
         totalPanels * DMD_RAM_BYTES_PER_PANEL);
}

uint16_t AriesDMD::width() const {
  return panelsWide * DMD_PANEL_WIDTH;
}

uint16_t AriesDMD::height() const {
  return panelsHigh * DMD_PANEL_HEIGHT;
}

void AriesDMD::writePixel(uint16_t x, uint16_t y, uint8_t mode, bool pixel) {
  if (x >= width() || y >= height()) return;

  // Determine panel
  uint8_t panelX = x / DMD_PANEL_WIDTH;
  uint8_t panelY = y / DMD_PANEL_HEIGHT;
  uint16_t panelIndex = panelY * panelsWide + panelX;
  uint16_t panelBase = panelIndex * DMD_RAM_BYTES_PER_PANEL;

  // Local pixel
  uint8_t lx = x % DMD_PANEL_WIDTH;
  uint8_t ly = y % DMD_PANEL_HEIGHT;

  // Mapping for 1/4 scan P10
  uint8_t plane = ly & 0x03;
  uint8_t row   = ly >> 2;
  uint8_t col   = lx >> 3;
  uint8_t bit   = lx & 0x07;

  uint16_t index =
    panelBase +
    (plane << 4) +
    (row << 2) +
    col;

  uint8_t mask = 0x80 >> bit;

  switch (mode) {
    case GRAPHICS_NORMAL:
      pixel ? (screenRAM[index] &= ~mask)
            : (screenRAM[index] |=  mask);
      break;

    case GRAPHICS_INVERSE:
      pixel ? (screenRAM[index] |=  mask)
            : (screenRAM[index] &= ~mask);
      break;

    case GRAPHICS_TOGGLE:
      if (pixel) screenRAM[index] ^= mask;
      break;
  }
}

void AriesDMD::shiftOutByte(uint8_t data) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(pins.data, data & 0x80);
    digitalWrite(pins.clk, HIGH);
    digitalWrite(pins.clk, LOW);
    data <<= 1;
  }
}

void AriesDMD::scanDisplay() {
  digitalWrite(pins.oe, HIGH); 

  // Shift data for ALL panels (rightmost first)
  for (int p = totalPanels - 1; p >= 0; p--) {
    uint16_t base =
      p * DMD_RAM_BYTES_PER_PANEL +
      (scanPlane << 4);

    for (int i = 0; i < DMD_BYTES_PER_PLANE; i++) {
      shiftOutByte(screenRAM[base + i]);
    }
  }

  // Latch data
  digitalWrite(pins.lat, HIGH);
  digitalWrite(pins.lat, LOW);

  // Select row plane
  digitalWrite(pins.a, scanPlane & 0x01);
  digitalWrite(pins.b, (scanPlane >> 1) & 0x01);

  // Enable output
  digitalWrite(pins.oe, LOW);
  delayMicroseconds(80);
  digitalWrite(pins.oe, HIGH);

  scanPlane = (scanPlane + 1) & 0x03;
}
