# Randall’s Recorder – Controller Firmware
**Microcontroller firmware for the custom Controller PCB that interfaces with the RunCam Split-H DVR.**

This repository contains the firmware, hardware notes, and PlatformIO project structure for the *Randall’s Recorder* wearable DVR controller. The controller PCB provides power management, LED-based state sensing, buzzer feedback, and (in Phase 2) UART-based full digital control.

The PCB and its staged development plan are defined in the Controller PCB document, and the DVR reference behaviour is taken from the RunCam Split-H user manual.

---

## 📦 Project Structure

```
/src
    main.cpp        – Main firmware entry point
/include
/lib
/test
    test_basic/     – Unit tests & hardware simulation stubs
platformio.ini
README.md
```

---

## 🧪 The **test/** Folder

PlatformIO supports Unity-based unit tests that run on either:

1. The host computer (**native** environment), or  
2. The microcontroller (embedded test runner).

The `test/` directory includes:

- Test harness code  
- Pin-state simulation  
- Debounce tests  
- LED-pulse decoding tests  
- Mock DVR behaviours

Run tests:

```
pio test -e native
```

or

```
pio test -e attiny85
```

---

# 🧩 Development Stages

## Stage 1 — LED-Based Status Monitoring

Implements:

- DVR LED sensing  
- Button input  
- Buzzer feedback  
- Battery-level sensing  
- Over-discharge protection  
- 5–20V input / 5V regulated output  
- USB‑C pass‑through

Primary firmware includes logic for:

- LED interpretation  
- Button-to-action mapping  
- Power management  

---

# ⚙️ PlatformIO Overview

PlatformIO manages:

### ✔ Dependencies  
### ✔ Multi‑board environments  
Example:

```ini
[env:attiny85]
platform = atmelavr
board = digispark-tiny
framework = arduino

[env:native]
platform = native
```

### ✔ Building

```
pio run
```

### ✔ Uploading

```
pio run --target upload
```

### ✔ Testing

```
pio test
```

### ✔ Integrated VS Code workflow  

---

# 📄 License – MIT License (Recommended for Firmware Projects)

The MIT License is widely used for embedded/firmware projects due to its simplicity and permissiveness.

```
MIT License

Copyright (c) 2025 Dr. Richard M. Day

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

---
