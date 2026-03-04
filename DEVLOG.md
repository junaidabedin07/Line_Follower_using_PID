# Development Log — Line Following Robot

**Duration:** 15 Days  
**Outcome:** 🏆 1st Place

---

## Overview

A 15-day build log documenting the development of a line-following robot — from first power-on to competition victory. The journey covers three microcontroller switches, two competition appearances, a full PCB rebuild, and progressive PID tuning.

---

## Day 1 — First Tests & Chassis

**Work Done:**
- Tested Arduino and QTR-8RC sensor (both unsuccessful)
- Soldered QTR-8RC
- Designed and cut aluminum-coated chassis panels

**Problems Faced:**
- Arduino IDE shows COM port access denied
- Insufficient GPIO pins on Arduino Nano

**Solutions:**
- Arduino Nano blocks COM port access when multiple IDE windows are open or the Serial Monitor is running simultaneously
- Pin count limitation noted for future hardware decisions

---

## Day 2 — Platform Switch to ESP32

**Work Done:**
- Switched microcontroller from Arduino to ESP32
- Re-soldered QTR-8RC
- Successfully tested motors, ESP32, and QTR-8RC
- Tuned buck converters to 3.3V and 11.67V

**Problems Faced:**
- Soldering iron tip too large for precise work
- Soldering iron burnt during session

---

## Day 3 — Soldering & Hardware Discovery

**Work Done:**
- Purchased new soldering iron tip
- Soldered QTR-8RC ×2 and N20 motors ×2

**Problems Faced:**
- Discovered ESP32 operates at 5V, conflicting with 3.3V buck converter setup

**Solution:**
- Removed one LM2596 buck converter
- Retuned the remaining buck converter accordingly

---

## Day 4 — Power Issues

**Problems Faced:**
- 3.3V buck converter dims on connection (suspected short at IR sensor pin)
- Buck converter heating
- ESP32 heating

**Solutions:**
- Heating issue self-resolved — a loose wire had re-seated during troubleshooting
- ESP32 heating resolved after re-soldering GND and VCC wires

---

## Day 5 — First Movement

**Milestone:** Bot moved for the first time.

**Problems Faced:**
- Right motor behaving erratically
- Motor driver failed

---

## Day 6 — Second Platform Switch & Sensor Discovery

**Work Done:**
- Switched microcontroller from ESP32 back to Arduino Nano
- Confirmed QTR-8A sensor readings (previously misidentified as QTR-8RC)
- Fixed bent chassis to resolve calibration offset

**Problems Faced:**
- Motor driver burnt
- Arduino brownout
- Calibration distance incorrect
- Sensor misidentification: QTR-8RC was actually QTR-8A

**Solutions:**
- Purchased new motor driver
- Configured firmware for QTR-8A analog readings
- Straightened chassis for accurate sensor calibration

---

## Day 7 — Brownout Troubleshooting

**Work Done:**
- Added capacitors to address brownout issue
- Fixed logical error in code (negative PWM values)

**Findings:**
- Calibration works correctly when powered from bench supply
- Calibration fails when powered from battery

> ⚠️ **Brownout issue unresolved at end of day.**

---

## Day 8 — Competition Day #1 (IIT Pravaah)

**Changes Made:**
- Added separate 12V battery pack dedicated to motors
- Brownout appeared resolved
- Calibration performing correctly

**Problems During Competition:**
- Left/right motor direction inverted in code
- Bot circuitry damaged during event

**Result:** Did not compete.

---

## Day 9 — Reassessment & Simplification

**Discoveries:**
- Arduino Nano Vin range is 7–12V; only 2 battery cells required
- LM2596 buck converter no longer needed
- Separate motor battery pack no longer needed
- Wire reduction identified as priority

**Action Items:**
- Simplify power architecture
- Reduce overall wiring

---

## Day 10 — PCB Rebuild Begins

**Work Done:**
- Began transferring circuit to Zero PCB
- Soldered Arduino Nano and motor driver onto PCB

---

## Day 11 — PCB Wiring Complete

**Work Done:**
- Soldering and wiring completed on Zero PCB
- Motors functional, no brownout observed

**Discovery:**
- QTR-8A sensor found to be burnt (damage traced back to Day 8 incident)

---

## Day 12 — New Components Acquired

**Purchased:**
- TB6612FNG motor driver ×2
- Larger Zero PCB
- Female header pins

---

## Day 13 — First Steps on New PCB & PID Tuning

**Milestone:** Bot took its first steps on the rebuilt PCB.

**PID Tuning Results:**

| Case | Kp | Kd | Base Speed | Max Speed | Notes |
|------|----|----|------------|-----------|-------|
| 1 | 0.1 | 1.0 | 90 | 180 | — |
| 2 | 0.15 | 1.5 | 165 | 255 | — |
| 3 | 0.3 | 3.0 | 175 | 255 | 2nd best |
| 4 | 0.3 | 3.0 | — | 255 | **Best** — Dynamic speed (255 on straights, 120 on turns) |

---

## Day 14 — Competition Day #2 (GIFT Festronix)

**Round 1:**
- Actual time: 41 seconds *(includes 13 seconds mid-round calibration)*
- Penalized time: 66 seconds *(3 × 5s hand touch + 1 × 10s loop skip)*

**Round 2:**
- Actual time: 25 seconds
- Penalized time: 35 seconds *(2 × 5s hand touch)*

**Post-Competition Notes for Next Iteration:**
- Reduce chassis dimensions (length and width)
- Improve cable management (use proper spacing)
- Relocate battery above electronics
- Add dedicated buttons for STBY ON/OFF control

---

## Day 15 — Result Day

> **🏆 Won by a landslide — 1st Place**

---

## Summary

| Metric | Detail |
|--------|--------|
| Microcontrollers Used | Arduino Nano → ESP32 → Arduino Nano |
| Motor Drivers Burnt | 2 |
| Sensors Burnt | 1 (QTR-8A) |
| PCB Rebuilds | 1 (breadboard → Zero PCB) |
| Competitions Entered | 2 (IIT Pravaah, GIFT Festronix) |
| Final PID (Kp / Kd) | 0.3 / 3.0 with dynamic speed |
| Final Result | **1st Place** |
