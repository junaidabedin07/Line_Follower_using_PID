\# Design Decisions



\## Microcontroller: Arduino Nano

Nano → ESP32 (Day 2) → Nano (Day 6).

Returned because Vin (7–12V) matched battery directly,

no heating issues, simpler codebase, sufficient pins.



\## Sensor: QTR-8A (Analog)

Misidentified as QTR-8RC for first 5 days.

Analog readings sufficient for accurate line detection.



\## Motor Driver: TB6612FNG

Two driver failures before switching.

TB6612FNG has built-in protection, lower heat, better efficiency.

Dual setup (×2) for independent motor control.



\## Power: Single 2S LiPo

Started with dual battery packs, simplified on Day 9.

Nano Vin matched 2S directly — no buck converters needed,

less weight, less wiring.



\## PCB: Zero PCB

Moved from loose wiring on Day 10.

Eliminated all brownout and loose connection failures.



\## PID: PD Controller

No I term — no steady state error observed.

D term alone sufficient for smooth cornering.



\## Speed: Dynamic

Fixed speed caused instability on straights.

Dynamic (255 straight / 120 turns) gave best lap times.

