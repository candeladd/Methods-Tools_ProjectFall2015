#include <Servo.h>

Servo serv;
int sensorPin = A0;
int pinput = 0;

void setup() {
  // put your setup code here, to run once:
  serv.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  pinput = analogRead(sensorPin);
  pinput = map(pinput, 0, 1023, 0, 45);
  serv.write(pinput);
}


