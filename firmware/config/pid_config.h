// PID Configuration
// Line Following Robot

// PID Gains
#define KP 0.3        // Reactivity — increase if it misses turns
#define KD 3.0        // Damping — increase if it wobbles on straights
#define KI 0          // Not used — no steady state error observed

// Speed Settings
#define STRAIGHT_SPEED 255  // Max speed on straightaways
#define TURN_SPEED 120      // Safe speed for curves
#define MAX_SPEED 255       // PWM ceiling

// Sensor Settings
#define NUM_SENSORS 8       // QTR-8A sensor count

// Calibration
#define CALIBRATION_SAMPLES 150   // Calibration loop iterations
#define CALIBRATION_DELAY 20      // Delay per sample in milliseconds
#define PLACEMENT_DELAY 3000      // Time to place bot on track after calibration