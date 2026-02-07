# AriesDMD Library

**Author:** Nishil Patel  
**Platform:** RISC-V (Specifically designed for Vega Aries V3 – C-DAC)  
**Project Type:** Academic & Experimental  
**Status:** Stable / Actively Maintained  

---

## Overview

**AriesDMD** is a lightweight and deterministic driver library for **P10 LED matrix panels**, specifically designed for **RISC-V based microcontrollers** such as **Vega Aries V3**.

Traditional Arduino DMD libraries were designed around **AVR timing assumptions** and often fail on modern architectures due to:

- SPI buffering  
- Non-deterministic execution  
- Hidden FIFO behavior  

AriesDMD solves these issues by implementing **explicit, timing-safe display scanning** while still using **hardware SPI for data transfer**, ensuring:

- Correct pixel indexing  
- Stable refresh  
- Flicker-free output 

---

## Supported Hardware

- Vega Aries V3 (RISC-V)
- P10 LED Matrix Panels (32 × 16)
- 1/4 Scan HUB75 panels (A, B row select)

---

## Key Features

- Deterministic display scanning
- Hardware SPI based data transfer
- User-defined control pins (OE, LAT, A, B)
- Supports multiple cascaded P10 panels
- Pixel-level graphics control
- Minimal RAM footprint
- Designed specifically for RISC-V timing behavior

---

## Display Architecture

Each **P10 panel**:

- **Resolution:** 32 × 16 pixels  
- **Scan type:** 1/4 scan  
- **Row planes:** 4  
- **Data format:** 8 pixels per byte  
- **Framebuffer size:** 64 bytes per panel  

When **multiple panels** are connected:

- Width scales as `32 × panelsWide`
- Height scales as `16 × panelsHigh`
- Framebuffer scales automatically
