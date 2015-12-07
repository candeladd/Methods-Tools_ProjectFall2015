#include <Servo.h>

Servo myservo;
//Servo myservo2;

void setup() {
 myservo.attach(3);
 //myservo2.attach(5);
}

void loop() {
  myservo.write(180);
  delay(100);
  myservo.write(0);
  delay(100);
// for(int i=0; i<180; i++) {
//  myservo.write(i);
//  myservo2.write(i);
//  delay(15);
// } 
//  for(int i=180; i>180; i--) {
//  myservo.write(i);
//  myservo2.write(i);
//  delay(15);
// } 
}
