# AriesDMD Library

**Author:** Nishil Patel  
**Platform:** RISC-V (Vega Aries V3 – C-DAC)  
**Project Type:** Academic & Experimental  
**Status:** Stable / Actively Maintained  
---

# 🚀 Overview

AriesDMD is a modular display driver library designed specifically for P10 and HUB75 LED matrix panels on RISC-V based Vega Aries V3 boards.
It supports:
- 🟢 Monochrome P10 panels (32×16, 1/4 scan)
- 🌈 RGB HUB75 panels (32×16, 1/8 scan and beyond)

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

**1) Monochrome Panels**
- P10	32×16	Pixels 1/4 Scanning
  
--> Features:
- Multi-panel cascading
- SPI-based scanning
- Text rendering
- Pixel drawing

**2) RGB Panels**
- HUB75 RGB	32×16 Pixels	1/8 Scanning
- HUB75 RGB 80X40 Pixels 1/20 Scanning
  
--> Features:
- Multi-panel cascading
- Text rendering
- 8 colour options
