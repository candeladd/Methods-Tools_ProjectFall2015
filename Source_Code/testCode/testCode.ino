#include <Servo.h>

Servo serv;

void setup() {
  // put your setup code here, to run once:
  serv.attach(9);
  //Serial.begin(9600);
  //while (! Serial); // Wait until Serial is ready
  //Serial.println("Enter o or c to open or close the claw");
}

void loop() {
  // put your main code here, to run repeatedly:
  serv.write(48);
  //sweep(0, 48, 20);
  //serialInput(0, 48);
}

void serialInput(int op, int cl) {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == 'o') {
      serv.write(op);
    } else if (c == 'c') {
      serv.write(cl);
    }
  }
}

void sweep(int start, int en, int del) {
  for(int i = start; i <= en; i++) {
    serv.write(i);
    delay(del);
  }
  for(int i = en; i >= start; i--) {
    serv.write(i);
    delay(del);
  }
}

