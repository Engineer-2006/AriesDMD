AriesDMD Library
================

- Author: Nishil Patel  
- Compatiblility: RISC-V boards (Specifically Desgined for Vega Aries V3 by C-DAC)
- Project Type: Academic & Experimental  
- Status: Active Development  

---

### Overview

AriesDMD is a lightweight driver library for **P10 (32 × 16) LED matrix panels**,
designed with a focus on **deterministic timing and portability**.

The library was developed to address reliability issues observed when using
traditional Arduino DMD libraries on modern microcontrollers such as **RISC-V**,
where SPI buffering, FIFO, and non-deterministic execution can cause display
corruption.

AriesDMD avoids these issues by using **explicit GPIO-based control** for all
critical timing signals.

---

### Supported Hardware

- P10 LED Matrix Panel (32 × 16)
- 1/4 scan panels (A, B row select)
- HUB75-style interface
- Tested with RISC-V based Aries v3 board

---

### Features

- Deterministic display scanning (no SPI dependency)
- Compatible with RISC-V architectures
- User-defined pin configuration
- Supports multiple chained P10 panels
- Explicit control of OE, LAT, and row select signals
- Pixel-level access with multiple graphics modes

---

### Display Architecture

Each P10 panel consists of:
- Resolution: 32 × 16 pixels
- Scan type: 1/4 scan (4 row planes)
- Data format: 8 pixels per byte
- RAM usage: 64 bytes per panel

Multiple panels can be connected:
- Horizontally to increase width
- Vertically to increase height

---

### Example Usage

```cpp
#include <AriesDMD.h>

AriesDMDPins pins = {
  .data = 10,
  .clk  = 8,
  .lat  = 9,
  .oe   = 15,
  .a    = 6,
  .b    = 7
};

AriesDMD dmd(2, 1, pins); // 2 panels wide, 1 panel high

void setup() {
  dmd.begin();
  dmd.writePixel(5, 5, GRAPHICS_NORMAL, true);
}

void loop() {
  dmd.scanDisplay();
}
