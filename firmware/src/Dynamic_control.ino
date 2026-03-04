#include <QTRSensors.h>

// ================= PID TUNING =================
float Kp = 0.3;        // Reactivity (Increase if it misses turns)
float Kd = 3.0;        // Brakes/Damping (Increase if it wobbles on straights)

// --- DYNAMIC SPEED LIMITS ---
int STRAIGHT_SPEED = 255;  // Punch it to the absolute limit on straightaways
int TURN_SPEED = 120;      // Drop down to this safe speed for curves
int MAX_SPEED = 255;       // Absolute maximum speed limit for motors

QTRSensors qtr;
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

// --- RIGHT MOTOR PINS --- (A Motor)
const int R_PWM = 11;    
const int R_DIR1 = 10;   
const int R_DIR2 = 9;   

// --- LEFT MOTOR PINS --- (B Motor)
const int L_PWM = 3;   
const int L_DIR1 = 5;   
const int L_DIR2 = 6;   

const int LED_PIN = 13;
int lastError = 0;
unsigned long lastDebugTime = 0; // Timer for serial print

void setMotorSpeeds(int leftSpeed, int rightSpeed);
void printDebugInfo(int position, int error, int leftSpeed, int rightSpeed);

void setup() {
  Serial.begin(115200); 

  // Motor Pins Setup
  pinMode(L_DIR1, OUTPUT); pinMode(L_DIR2, OUTPUT); pinMode(L_PWM, OUTPUT);
  pinMode(R_DIR1, OUTPUT); pinMode(R_DIR2, OUTPUT); pinMode(R_PWM, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Analog Sensors Setup
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){A7, A6, A5, A4, A3, A2, A1, A0}, SensorCount);

  Serial.println(">> Get Ready! <<");
  
  // 5 quick flashes to give you time to prepare
  for(int i = 0; i < 5; i++){
    digitalWrite(LED_PIN, HIGH); delay(500);
    digitalWrite(LED_PIN, LOW); delay(500);
  }
  
  // --- MANUAL CALIBRATION ---
  Serial.println(">> SLIDE ROBOT OVER LINE NOW <<");
  digitalWrite(LED_PIN, HIGH); // LED ON means recording!
  
  // Calibrate for ~3 seconds
  for(int i = 0; i <= 150; i++){
    qtr.calibrate();
    delay(20); 
  }
  digitalWrite(LED_PIN, LOW);
  
  Serial.println(">> Calibration Done. Put it in the center... <<");
  delay(3000); // 3 seconds to place it perfectly on the track
  
  // Flash once right before launch
  digitalWrite(LED_PIN, HIGH); delay(500); digitalWrite(LED_PIN, LOW);
  
  Serial.println(">> GO! <<");
}

void loop() {
  // 1. Read the Line (0 to 7000, 3500 is center)
  uint16_t position = qtr.readLineBlack(sensorValues);
  
  // 2. Calculate the Error
  int error = position - 3500;

  // 3. --- DYNAMIC SPEED CONTROL ---
  // Smoothly scales the base speed down as the robot gets further off-center
  int currentBaseSpeed = map(abs(error), 0, 3500, STRAIGHT_SPEED, TURN_SPEED);
  
  // 4. PID Math
  int PID_value = (Kp * error) + (Kd * (error - lastError));
  lastError = error;

  // 5. Calculate Target Motor Speeds
  int leftSpeed = currentBaseSpeed + PID_value;
  int rightSpeed = currentBaseSpeed - PID_value;
  
  // 6. Constrain Speeds to valid PWM range
  leftSpeed = constrain(leftSpeed, -MAX_SPEED, MAX_SPEED);
  rightSpeed = constrain(rightSpeed, -MAX_SPEED, MAX_SPEED);

  // 7. Drive Motors
  setMotorSpeeds(leftSpeed, rightSpeed);

  // 8. --- DEBUGGING SECTION ---
  // Print only every 200ms to allow the robot to run smoothly
  if (millis() - lastDebugTime > 200) {
    printDebugInfo(position, error, leftSpeed, rightSpeed);
    lastDebugTime = millis();
  }
}

// Function to print formatted data to Serial Monitor
void printDebugInfo(int position, int error, int leftSpeed, int rightSpeed) {
  Serial.print("Pos: "); Serial.print(position);
  Serial.print(" | Err: "); Serial.print(error);
  
  Serial.print(" | Action: ");
  if (error < -500) Serial.print("<< TURN LEFT  ");
  else if (error > 500) Serial.print("   TURN RIGHT >>");
  else Serial.print("   --CENTER--   ");

  Serial.print(" | M_Left: "); Serial.print(leftSpeed);
  Serial.print(" M_Right: "); Serial.print(rightSpeed);

  // Print individual sensor values
  Serial.print(" | Sens: [");
  for (uint8_t i = 0; i < SensorCount; i++) {
    Serial.print(sensorValues[i]);
    if (i < SensorCount - 1) Serial.print(" ");
  }
  Serial.println("]");
}

// Fixed Motor Control Function
void setMotorSpeeds(int leftSpeed, int rightSpeed) {
  // Left Motor
  if (leftSpeed >= 0) {
    digitalWrite(L_DIR1, HIGH); digitalWrite(L_DIR2, LOW);
    analogWrite(L_PWM, leftSpeed);  
  } else {
    digitalWrite(L_DIR1, LOW); digitalWrite(L_DIR2, HIGH);
    analogWrite(L_PWM, -leftSpeed); // Flips negative back to positive for PWM
  }
  
  // Right Motor
  if (rightSpeed >= 0) {
    digitalWrite(R_DIR1, HIGH); digitalWrite(R_DIR2, LOW);
    analogWrite(R_PWM, rightSpeed); 
  } else {
    digitalWrite(R_DIR1, LOW); digitalWrite(R_DIR2, HIGH);
    analogWrite(R_PWM, -rightSpeed); // Flips negative back to positive for PWM
  }
}