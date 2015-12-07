#include <Servo.h>

Servo serv;
//Servo serv1;
int sensorPin = A0;
int pinput = 45;

void setup() {
  // put your setup code here, to run once:
  serv.attach(9);
  //serv.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  pinput = analogRead(sensorPin);
  pinput = map(pinput, 0, 1023, 0, 45);
  serv.write(pinput);
  //serv1.write(pinput);
}
