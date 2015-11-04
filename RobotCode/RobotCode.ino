#include <Servo.h>

//Servo for rotating arm at base
Servo rotate;
//Servo for elevating arm at base
Servo shoulder;
//Servo at middle joint for rotating forearm
Servo elbow;
//Servo attached to claw for rotating the claw
Servo wrist;
//Servo for grabbing with claw
Servo hand;

//Values for pins connected to servos
int elbowPin = 0;
int rotatePin = 0;
int shoulderPin = 0;
int wristPin = 0;
int handPin = 0;

//Values for reading in input from potentiometers
int elbowIn = 0;
int rotateIn = 0;
int shoulderIn = 0;
int wristIn = 0;
int handIn = 0;

void setup() {
  // Attaching Servos to respective pins
  rotate.attach(3);
  shoulder.attach(5);
  elbow.attach(6);
  wrist.attach(9);
  hand.attach(10);
}

void loop() {
  // Reads in input from potentiometer
  rotateIn = analogRead(rotatePin);
  // Maps potentiometer input to degrees of rotation for servo
  rotateIn = map(rotateIn, 0, 1023, 0, 359);
  // Spins the servo into position
  rotate.write(rotateIn);
  
  // Map input from pot. to elbow servo
  elbowIn = analogRead(elbowPin);
  elbowIn = map(elbowIn, 0, 1023, 0, 359);
  elbow.write(elbowIn);

  // Map input from pot. to shoulder servo
  shoulderIn = analogRead(shoulderPin);
  shoulderIn = map(shoulderIn, 0, 1023, 0, 359);
  shoulder.write(shoulderIn);

  // Map input from pot. to wrist servo
  wristIn = analogRead(wristPin);
  wristIn = map(wristIn, 0, 1023, 0, 359);
  wrist.write(wristIn);

  // Map input from pot. to hand servo
  handIn = analogRead(handPin);
  handIn = map(handIn, 0, 1023, 0, 359);
  hand.write(handIn);
  delay(15);
}
