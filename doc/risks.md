\# Risk Log



\## Brownout

Cause: Motor current spikes on shared power line.

Mitigation: Capacitors + Zero PCB + TB6612FNG.

Status: Resolved — Day 11.



\## Sensor Burn

Cause: Circuitry damage at IIT Pravaah.

Mitigation: Carry spare QTR-8A.

Status: Resolved — Day 12.



\## Motor Driver Failure

Cause: Overcurrent during early development.

Mitigation: TB6612FNG has built-in protection. Carry spare.

Status: Resolved — Day 12.



\## Sensor Misidentification

Cause: QTR-8RC and QTR-8A look identical physically.

Mitigation: Verify sensor model before writing driver code.

Status: Resolved — Day 6.



\## Motor Direction Inversion

Cause: Left/right PWM swapped in code.

Mitigation: Verify motor direction before competition.

Status: Resolved before GIFT Festronix.



\## Calibration Failure Mid-Run

Cause: Calibration not completed before run clock started.

Mitigation: Always complete calibration before entering track.

Status: Resolved — Round 2 ran clean.



\## COM Port Access Denied

Cause: Multiple IDE windows open simultaneously.

Mitigation: Single IDE window, close Serial Monitor before upload.

Status: Resolved — Day 1.

