```markdown

\# Debug Notes



\## COM Port Access Denied

\*\*Symptom:\*\* Arduino IDE throws COM port access denied on upload.

\*\*Root Cause:\*\* Two IDE windows open simultaneously.

\*\*Fix:\*\* Keep single IDE window open. Close Serial Monitor before uploading.

\*\*Day:\*\* 1



---



\## Insufficient Pins on Arduino Nano

\*\*Symptom:\*\* Not enough GPIO pins for all components.

\*\*Root Cause:\*\* Arduino Nano pin count too low for this project.

\*\*Fix:\*\* Switched to ESP32.

\*\*Day:\*\* 1



---



\## Soldering Iron Burnt

\*\*Symptom:\*\* Soldering iron stopped working mid-session.

\*\*Root Cause:\*\* Tip too large, overheated during use.

\*\*Fix:\*\* Bought new soldering iron tip.

\*\*Day:\*\* 2



---



\## ESP32 5V Logic Issue

\*\*Symptom:\*\* ESP32 incompatible with 3.3V buck converter setup.

\*\*Root Cause:\*\* ESP32 operates at 5V, conflicting with tuned 3.3V output.

\*\*Fix:\*\* Removed one LM2596, retuned remaining buck converter.

\*\*Day:\*\* 3



---



\## Buck Converter Dimming

\*\*Symptom:\*\* 3.3V buck converter output drops when connected.

\*\*Root Cause:\*\* Suspected short at IR sensor pin.

\*\*Fix:\*\* Issue unresolved — buck converter removed entirely as part of power simplification.

\*\*Day:\*\* 4



---



\## Buck Converter and ESP32 Heating

\*\*Symptom:\*\* Both buck converter and ESP32 heating during operation.

\*\*Root Cause:\*\* Loose GND and VCC wires causing resistance.

\*\*Fix:\*\* Heating self-resolved — loose wire re-seated during troubleshooting.

ESP32 heating fully resolved after re-soldering GND and VCC wires.

\*\*Day:\*\* 4



---



\## Right Motor Erratic Behaviour

\*\*Symptom:\*\* Right motor spinning uncontrollably.

\*\*Root Cause:\*\* Motor driver failure following erratic motor behaviour.

\*\*Fix:\*\* Replaced motor driver.

\*\*Day:\*\* 5



---



\## Sensor Misidentification

\*\*Symptom:\*\* No valid sensor readings for first 5 days.

\*\*Root Cause:\*\* QTR-8RC and QTR-8A are physically identical — wrong driver used.

\*\*Fix:\*\* Identified as QTR-8A on Day 6, switched to analog readings.

\*\*Day:\*\* 6



---



\## Bent Chassis

\*\*Symptom:\*\* Calibration distance incorrect, sensor readings offset.

\*\*Root Cause:\*\* Chassis bent, causing uneven sensor positioning.

\*\*Fix:\*\* Straightened chassis manually.

\*\*Day:\*\* 6



---



\## Brownout

\*\*Symptom:\*\* Arduino resets mid-run during calibration or movement.

\*\*Root Cause:\*\* Motor current spikes pulling voltage down on shared power line.

\*\*What Was Tried:\*\*

\- Added capacitors (partial fix, Day 7)

\- Separate 12V battery pack for motors (appeared resolved, Day 8)

\*\*Final Fix:\*\* Rebuilt on Zero PCB + TB6612FNG drivers.

\*\*Day:\*\* 7 → Resolved Day 11



---



\## Negative PWM Values

\*\*Symptom:\*\* Motors behaving unexpectedly at certain error values.

\*\*Root Cause:\*\* Logical error — PID output producing negative PWM without direction handling.

\*\*Fix:\*\* Added direction logic — negative values flip motor direction pins,

absolute value passed to analogWrite().

\*\*Day:\*\* 7



---



\## Motor Direction Inversion

\*\*Symptom:\*\* Bot turns left when it should turn right and vice versa.

\*\*Root Cause:\*\* Left/right PWM outputs swapped in code.

\*\*Fix:\*\* Swapped motor pin assignments. Resolved before GIFT Festronix.

\*\*Day:\*\* 8 → Resolved before Day 14



---



\## Bot Circuitry Damage

\*\*Symptom:\*\* Bot circuitry damaged during IIT Pravaah.

\*\*Root Cause:\*\* Unknown — occurred during competition.

\*\*Fix:\*\* Full rebuild onto Zero PCB.

\*\*Day:\*\* 8



---



\## QTR-8A Burnt

\*\*Symptom:\*\* Sensor giving no readings after rebuild.

\*\*Root Cause:\*\* Damage sustained during IIT Pravaah (Day 8), discovered on Day 11.

\*\*Fix:\*\* Replaced QTR-8A sensor (purchased Day 12).

\*\*Day:\*\* 11



---



\## Calibration Failure Mid-Run

\*\*Symptom:\*\* Bot lost line during Round 1 at GIFT Festronix, required manual recalibration.

\*\*Root Cause:\*\* Calibration not completed before run clock started.

\*\*Fix:\*\* Complete full calibration sweep before entering track. Round 2 ran clean.

\*\*Day:\*\* 14

```

