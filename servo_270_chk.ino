#include <ESP32_Servo.h>

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(23); // Attach the servo to pin 23
}

void loop() {
  if (Serial.available() > 1) {
    int angle = Serial.parseInt(); // Read the angle value from serial

    // Ensure the angle is within the valid range (0 to 270 degrees)
    angle = constrain(angle, 0, 270);

    // Move the servo to the specified angle
    myServo.write(angle);

    // Print the angle to serial for verification
    Serial.print("Moved to angle: ");
    Serial.println(angle);
    delay(1000);
  }
}
