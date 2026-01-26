\# System Architecture



\## Block-Level Architecture



Sensors → MCU → PID Controller → Motor Driver → Motors



---



\## Data Flow

\- Sensor array provides reflectance data

\- MCU computes line position

\- PID controller generates correction

\- Motor driver applies PWM to motors



---



\## Control Loop Frequency

~500–1000 Hz depending on sensor type



---



\## Design Philosophy

\- Tight feedback loop

\- Deterministic control

\- Minimal latency



