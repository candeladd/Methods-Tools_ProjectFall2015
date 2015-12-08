/** @file
 *  This code runs 2 servos off the input of a potentiometer.
 *
 *  This program uses 2 servo motors and one potentiometer.
 *  When the user turns the potentiometer, the input goes in
 *  to the Arduino and is then routed to the input of the two
 *  servos.
 */

#include <Servo.h>

/** First servo */
Servo serv;
/** Second servo */
Servo serv1;
/** Pin that the output from the potentiometer inputs to the Arduino*/
int sensorPin = A0;
/** Value for storing input from potentiometer */
int pinput = 45;

/** Code that attaches the servos.
 *
 *  This code is run once at the beginning of the program
 *  It just attaches the servos to two of the analog output
 *  pins
 *  
 *  @param void
 *  @return void
 */

void setup() {
  serv.attach(9);
  serv1.attach(10);
}

/** Code that runs the servos.
 *
 *  This code loops repeatidly for the duration
 *  that power is running through the arduino. 
 *  It reads the input from the pot. maps it to
 *  360 degrees of rotation then writes that to 
 *  both the servos.
 *  
 *  @param void
 *  @return void
 */

void loop() {
  pinput = analogRead(sensorPin);
  pinput = map(pinput, 0, 1023, 0, 45);
  serv.write(pinput);
  serv1.write(pinput);
}
