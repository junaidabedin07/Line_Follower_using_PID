# System Architecture

## Block Diagram
Battery → Arduino Nano (Vin)
                        → TB6612FNG #1 → Left N20 Motor
                        → TB6612FNG #2 → Right N20 Motor
QTR-8A → Analog Pins (A0–A7) → Arduino Nano

## Power Architecture
- Single 2S LiPo (7.4V) directly into Arduino Nano Vin
- Nano Vin accepts 7–12V, regulates internally to 5V
- Motors powered directly from battery via TB6612FNG
- No buck converters in final design

## Control Loop
1. QTR-8A reads line position across 8 analog sensors
2. Weighted average calculated to find line position
3. Error calculated relative to center position
4. PD controller computes correction value
5. Dynamic speed assigned (255 straight / 120 turns)
6. Correction applied as differential PWM to both motors
7. Loop repeats continuously

## Communication
- No wireless communication
- Serial Monitor used during development for calibration and debugging only

## Calibration Sequence
1. Bot powered on
2. Manually swept over line for ~5 seconds
3. QTR-8A records min/max values per sensor
4. Calibration complete — bot begins following line