#include <Servo.h>

Servo myservo;  
const int potPin = A0;  // Potentiometer connected to analog pin A0
const int ledM = 3;

void setup() {
  Serial.begin(9600);   // Initialize serial communication
  myservo.attach(9);    // Attaches the servo on pin 9
}

void loop() {
  int potValue = analogRead(potPin);               // Read potentiometer (0 to 1023)
  int angle = map(potValue, 0, 1023, 0, 180);  // Convert to 0-180 degrees
  
  myservo.write(angle);                        // Move the servo
  
  // Send the angle to the Python script
  Serial.println(angle);
  
  delay(100);  
  if (potValue > 511)
  {
    digitalWrite(ledM,HIGH);
  }
  
  else 
  {
    digitalWrite(ledM,LOW);  
  }
}

