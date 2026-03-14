#include <Servo.h>

Servo lockServo;

int ledPin = 13;
int buzzerPin = 8;

void setup() {

  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lockServo.attach(9);

}

void loop() {

  if (Serial.available()) {

    char command = Serial.read();

    if (command == 'A') {

      digitalWrite(ledPin, HIGH);
      digitalWrite(buzzerPin, HIGH);
      lockServo.write(90); // lock
    }

    if (command == 'B') {

      digitalWrite(ledPin, LOW);
      digitalWrite(buzzerPin, LOW);
      lockServo.write(0); // unlock
    }
  }

}