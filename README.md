AriesDMD Library

Author: Nishil Patel
Target Platform: RISC-V (Vega Aries V3 by C-DAC)
Panel Type: HUB75 P10 (32×16)
Project Type: Academic & Experimental
Status: Stable & Actively Maintained

Overview

AriesDMD is a lightweight and deterministic driver library for P10 LED matrix panels, specifically designed for RISC-V based microcontrollers such as Vega Aries V3.

Traditional Arduino DMD libraries were designed around AVR timing assumptions and often fail on modern architectures due to:

SPI buffering

Non-deterministic execution

Hidden FIFO behavior

AriesDMD solves these issues by implementing explicit, timing-safe display scanning while still using hardware SPI for data transfer, ensuring:

Correct pixel indexing

Stable refresh

Flicker-free output

Key Highlights

✅ User-defined pin configuration

✅ Supports multiple chained P10 panels

✅ Hardware SPI based (deterministic control)

✅ Compatible with RISC-V architecture

✅ No dependency on AVR-specific behavior

✅ Pixel-accurate mapping (verified via full indexing tests)

Supported Hardware

P10 LED Matrix Panel (32 × 16)

HUB75 interface

1/4 scan panels (A, B row select)

Vega Aries V3 (RISC-V)

Display Architecture

Each single P10 panel:

Resolution: 32 × 16 pixels

Scan type: 1/4 scan

Memory usage: 64 bytes per panel

Data format: 8 pixels per byte
