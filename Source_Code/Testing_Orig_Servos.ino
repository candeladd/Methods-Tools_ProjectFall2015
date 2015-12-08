/** @file
 *  This is code for running two servos.
 *
 *  this is a simple program that attaches two
 *  servos to the arduino and spins them from 0 to 180 degrees
 *  and back to 0.
 */

#include <Servo.h>

/** Test servo 1*/
Servo myservo;
/** Test servo 2*/
Servo myservo2;

/** Sets up the servo.
 *
 *  The setup function runs once at the beginning of the program
 *  before anything else. This attaches the 2 test servos to output
 *  pins on the arduino.
 *  
 *  @param void
 *  @return void
 */
void setup() {
 myservo.attach(3);
 myservo2.attach(5);
}

/** Runs the servos.
 *
 *  The loop function runs repeaditly till the power is disconnected.
 *  This rotates the motors on both servos at the same time from 0 
 *  up to 180 degrees and back to 0.
 *  
 *  @param void
 *  @return void
 */
void loop() {
 for(int i=0; i<180; i++) {
  myservo.write(i);
  myservo2.write(i);
  delay(15);
 } 
 delay(100);
  for(int i=180; i>180; i--) {
  myservo.write(i);
  myservo2.write(i);
  delay(15);
 } 
 delay(100);
}
