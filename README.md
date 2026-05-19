# AriesDMD Library

**Author:** Nishil Patel  
**Platform:** RISC-V (Vega Aries V3 – C-DAC)  
**Project Type:** Academic & Experimental  
**Status:** Stable / Actively Maintained  
---

# 🚀 Overview

AriesDMD is a modular display driver library designed specifically for P10 and HUB75 LED matrix panels on RISC-V based Vega Aries V3 boards.
It supports:
🟢 Monochrome P10 panels (32×16, 1/4 scan)
🌈 RGB HUB75 panels (32×16, 1/8 scan and beyond)

Most existing LED matrix libraries were written for AVR-based Arduino boards like Arduino UNO. Unlike traditional Arduino libraries designed for AVR microcontrollers, AriesDMD is built specifically for the Vega Aries architecture to provide:
- Stable scanning
- Correct pixel mapping
- Flicker-free refresh
- Multi-panel support
- Clean framebuffer rendering

---

**🎯 Key Design Goals** 
- Deterministic and timing-safe scanning
- RISC-V friendly architecture
- Clean pixel mapping independent of wiring
- Modular RGB / Mono architecture
- Large multi-panel scalability
- Future-ready for IoT text streaming

---

**🟢 Supported Hardware**
Microcontroller
Vega Aries V3 (C-DAC)

**🖥 Supported Displays**
Monochrome Panels
Panel	Resolution	Interface	Scan
P10	32×16	HUB12	1/4
Features
Multi-panel cascading
SPI-based scanning
Text rendering
Pixel drawing
RGB Panels
Panel	Resolution	Interface	Scan
HUB75 RGB	32×16	HUB75	1/8
Features
RGB framebuffer
Multi-panel cascading
Text rendering
Basic RGB color support
⚙️ Features
Core Engine
Deterministic refresh engine
Hardware-level CLK/LAT/OE control
Pixel-level drawing
Framebuffer-based rendering
Multi-panel support
Scalable architecture
RGB Engine
HUB75 RGB panel support
Multi-panel RGB canvas
8 basic RGB colors
Shared font rendering system
Font System
5×7 font rendering
Shared between RGB & Mono
Lightweight implementation
Arduino-style API
Text Features
Static text rendering
Multi-panel text positioning
Scrolling text support
Shared font engine

