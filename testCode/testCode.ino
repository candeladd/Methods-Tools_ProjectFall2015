#include <Servo.h>

Servo serv;

void setup() {
  // put your setup code here, to run once:
  serv.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  //serv.write(0);
  sweep(0, 90, 20);
}

void sweep(int start, int en, int del) {
  for(int i = start; i <= en; i++) {
    serv.write(i);
    delay(del);
  }
  for(int i = en; i >= start; i--) {
    serv.write(i);
    delay(del+15);
  }
}

