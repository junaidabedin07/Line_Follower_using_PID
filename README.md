# Line Following Robot

A PID-controlled line following robot built for competitive racing.
Competed in two events — won 1st place at GIFT Festronix.

---

## Hardware
| Component | Details |
|---|---|
| Microcontroller | Arduino Nano |
| Sensor | QTR-8A (8-channel analog) |
| Motor Driver | TB6612FNG |
| Motors | N20 × 2 |
| Power | 2S LiPo → Nano Vin (7–12V) |
| PCB | Hand-soldered Zero PCB |
→ [Schematic](hardware/schematics/schematics.jpg)

---

## How It Works
The QTR-8A reads the line position across 8 analog sensors.
Error is calculated relative to center, fed into a PD controller,
and output as differential PWM to the two motors via TB6612FNG drivers.

Speed is dynamic — maximum on straight sections, reduced on turns
for tighter cornering without losing stability.

---

## PID Configuration
| Parameter | Value |
|---|---|
| Kp | 0.3 |
| Kd | 3.0 |
| Straight Speed | 255 |
| Turn Speed | 120 |
| Max PWM | 255 |

---

## Project Structure
```
firmware/     → Arduino source code and PID config
hardware/     → Pin mapping and bill of materials
docs/         → Architecture, design decisions, risk log
logs/         → Debug notes and troubleshooting history
```

---

## Competition Results
| Event | Result |
|---|---|
| IIT Pravaah | Did not compete (circuitry damage) |
| GIFT Festronix | 🏆 1st Place |

---

## Build Journey
A full 15-day development log covering every hardware failure,
platform switch, and tuning session that led to the final build.

→ [DEVLOG.md](DEVLOG.md)