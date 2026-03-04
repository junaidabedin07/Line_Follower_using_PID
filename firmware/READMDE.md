# Firmware

## Environment
- IDE: Arduino IDE (development), CLion (PID config editing)
- Board: Arduino Nano Every
- Language: C++

## File Structure
```
firmware/
├── src/
│   └── line_follower.ino
└── config/
    └── pid_config.h
```

## Dependencies
- QTRSensors (Pololu) — install via Arduino IDE Library Manager

## How to Flash
1. Open `src/line_follower.ino` in Arduino IDE
2. Connect Arduino Nano Every via USB
3. Select board: `Tools → Board → Arduino Nano Every`
4. Select port: `Tools → Port → (your COM port)`
5. Click Upload

## Calibration
1. Power on — LED flashes 5 times (preparation window)
2. When LED stays ON, sweep sensor over the line for ~3 seconds
3. LED turns OFF — place bot at center of track
4. 3 second window to position bot
5. LED flashes once — bot launches automatically

## Tuning
All parameters are in `config/pid_config.h`.
Never hardcode values directly in the sketch.

| Parameter | Value | Effect |
|-----------|-------|--------|
| KP | 0.3 | Correction strength — increase if it misses turns |
| KD | 3.0 | Damping — increase if it wobbles on straights |
| STRAIGHT_SPEED | 255 | Speed on straightaways |
| TURN_SPEED | 120 | Speed on turns |
| MAX_SPEED | 255 | PWM ceiling |
| CALIBRATION_SAMPLES | 150 | Calibration accuracy |
| PLACEMENT_DELAY | 3000 | Time to place bot after calibration (ms) |

## Serial Monitor
Baud rate: `115200`
Prints position, error, motor speeds, and all 8 sensor values every 200ms.
Useful for diagnosing sensor alignment and tuning PID values.