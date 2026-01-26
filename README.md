\# PID-Based Fast Line Follower Robot



\## Overview

This project implements a high-speed autonomous line follower robot designed for competitive environments. The robot follows a black line on a white surface using reflective optical sensors and PID control to achieve stable, smooth, and fast motion.



The system is fully autonomous, microcontroller-based, and compliant with standard robotics competition constraints (size, power, autonomy, and sensor usage).



---



\## Objectives

\- Accurate line detection at high speed

\- Smooth motion without oscillation

\- Reliable recovery from temporary line loss

\- Modular, well-documented embedded design



---



\## System Highlights

\- Arduino Nano (ATmega328P)

\- QTR-8RC / Reflective IR sensor array

\- PID-based motor control

\- TB6612FNG motor driver

\- Differential drive architecture



---



\## How It Works (High-Level)

1\. Sensors read reflectance values from the surface.

2\. Line position error is calculated.

3\. PID controller computes correction.

4\. Motor speeds are adjusted dynamically.

5\. Recovery logic handles line-loss scenarios.



---



\## Repository Structure

See the project tree for firmware, hardware, and documentation details.



---



