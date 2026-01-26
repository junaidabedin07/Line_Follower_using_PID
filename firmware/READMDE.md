\# Firmware Overview



The firmware implements a real-time PID control loop for line following.



---



\## Modules

\- Sensor acquisition

\- Error computation

\- PID control

\- Motor actuation

\- Line-loss recovery



---



\## Control Logic

\- Error = desired\_position − detected\_position

\- Correction = PID(error)

\- Motor speeds adjusted accordingly



