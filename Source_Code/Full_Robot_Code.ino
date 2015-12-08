/** @file
 *  This is the final robot code.
 *
 *  This code attaches each of the servos to the pins on the arduino and attaches
 *  each of the potentiometers to the input pins. It then routes the output from the
 *  potentiometers to the input of the servos to accurately control their movement
 */

#include <Servo.h>

/**Servo to rotate at base of arm */
Servo rotate;
/**Servo for elevating lower arm */
Servo shoulder;
/**Servo for moving upper arm */
Servo elbow;
/**Servo for moving claw */
Servo wrist;
/**Servo for moving opening and closing claw fingers */
Servo hand;


/** Pin attached to rotate potentiometer*/
int rotatePin = 0;
/** Pin attached to shoulder potentiometer*/
int shoulderPin = 1;
/** Pin attached to shoulder potentiometer*/
int elbowPin = 2;
/** Pin attached to wrist potentiometer*/
int wristPin = 3;
/** Pin attached to claw pontetiometer*/
int handPin = 4;

/** Values for storing input from rotate potentiometer*/
int rotateIn = 0;
/** Values for storing input from shoulder potentiometer*/
int shoulderIn = 0;
/** Values for storing input from elbow potentiometer*/
int elbowIn = 0;
/** Values for storing input from wrist potentiometer*/
int wristIn = 0;
/** Values for storing input from hand potentiometer*/
int handIn = 0;

/** The code that runs once at the start.
 *
 *  Initializes variables for the program and attaches servos to
 *  analog output pins
 *  
 *  @param void
 *  @return void
 */


void setup() {
  // Attaching Servos to respective pins
  rotate.attach(3);
  shoulder.attach(5);
  elbow.attach(6);
  wrist.attach(9);
  hand.attach(10);
}

/** The code that loops repeatedly till power disconnect.
 *
 *  Reads in values from potentiometers, maps them to degrees, and
 *  outputs the values to the degrees of rotation for the servos.
 *  
 *  @param void
 *  @return void
 */

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

  // Map input from pot. to Base servo
  BaseIn = analogRead(wristPin);
  BaseIn = map(wristIn, 0, 1023, 0, 359);
  Base.write(wristIn);

  // Map input from pot. to hand servo
  handIn = analogRead(handPin);
  handIn = map(handIn, 0, 1023, 0, 359);
  hand.write(handIn);
  delay(15);
}
