# AriesDMD Library

**Author:** Nishil Patel  
**Platform:** RISC-V (Vega Aries V3 – C-DAC)  
**Project Type:** Academic & Experimental  
**Status:** Stable / Actively Maintained  

---

## 🚀 Overview

**AriesDMD** is a modular display driver library designed for **HUB75 LED matrix panels**, supporting both:
- 🟢 **Monochrome P10 panels (32×16, 1/4 scan)**
- 🌈 **RGB panels (80×40, 1/20 scan and beyond)**

It is optimized specifically for **RISC-V based microcontrollers (Vega Aries V3)** where traditional Arduino libraries fail due to:
- SPI buffering issues  
- Non-deterministic execution  
- Hidden FIFO behavior  

---

## 🎯 Key Design Goals
- Deterministic and timing-safe scanning  
- Architecture-independent (RISC-V friendly)  
- Clean pixel mapping independent of wiring  
- Scalable to **large panel arrays (up to 100 panels)**  
- Modular structure (RGB / Mono / Fonts separated)  
- Future-ready for **WiFi / IoT text streaming**

---
## 🟢 Supported Hardware

### Microcontroller
- Vega Aries V3 (RISC-V)

### Displays

#### Monochrome
- P10 (32×16)
- 1/4 Scan (A, B lines)
- Multi-panel cascading

#### RGB
- HUB75 panels (80×40 tested)
- 1/20 Scan (A–E lines)
- Multi-panel cascading 

---

## ⚙️ Features

### Core
- Deterministic refresh engine  
- Hardware-level control (CLK, LAT, OE, Row select)  
- Pixel-level drawing  
- Multi-panel cascading  

### RGB Engine
- Supports large tiled displays   
- Scalable architecture for high panel count  

### Font System (NEW)
- Multiple fonts support  
- Font scaling  
- Arduino-style text rendering  
- Shared across RGB & Mono  

### Text Features
- Static text rendering  
- Multi-panel text positioning  
- Ready for scrolling (future upgrade)

---

## 🧠 Display Architecture

### Monochrome (P10)
- Resolution: 32 × 16  
- Scan: 1/4  
- Framebuffer: 64 bytes per panel  

### RGB (HUB75)
- Resolution: 80 × 40 per panel  
- Scan: 1/20  
- Framebuffer: RGB per pixel  

---

## 📐 Pixel Coordinate Mapping

### Single Panel
- Top-left: (0, 0)  
- Bottom-right: (W-1, H-1)

### Multi-Panel

Panels are treated as a **continuous canvas**

