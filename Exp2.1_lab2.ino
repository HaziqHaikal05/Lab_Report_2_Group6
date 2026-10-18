#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud
  myservo.attach(9);   // Attaches the servo on pin 9 to the servo object
}

void loop() {
  // Check if data is available to read from the serial port
  if (Serial.available() > 0) {
    // Read the incoming integer angle from Python
    int angle = Serial.parseInt();
    
    // Ensure the angle is within valid servo limits (0 to 180 degrees)
    if (angle >= 0 && angle <= 180) {
      myservo.write(angle);  // Move the servo to the specified angle
    }
  }
}