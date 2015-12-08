/** @file
 *  This is code for testing servo functionality.
 *
 *  A simple program for testing servo functionality.
 *  It attaches one servo and rotates it to a certain
 *  angle and back repeatedly. Optional functionality
 *  to pass command through the serial monitor.
 */

#include <Servo.h>

/** Servo for testing */
Servo serv;

/** Setup code runs once at start up.
 *
 *  Attatches test servo to a analog output pin and
 *  starts the serial monitor.
 *  
 *  @param void
 *  @return void
 */

void setup() {
  // put your setup code here, to run once:
  serv.attach(9);
  Serial.begin(9600);
  while (! Serial); // Wait until Serial is ready
  Serial.println("Enter o or c to open or close the claw");
}

/** Loop code runs repeadtidly to power disconnect.
 *
 *  Exectutes main code. Either sweeps servo open and closed
 *  or takes open and close command from the serial monitor.
 *  
 *  @param void
 *  @return void
 */

void loop() {
  sweep(0, 48, 20);
  //serialInput(0, 48);
}

/** Gets input from Serial monitor and applies to servo.
 *
 *  Gets a command from the serial monitor. If command is 'o'
 *  the servo turns to the open state. If the command is 'c'
 *  the servo turns to the closed state. Otherwise, it does nothing.
 *  
 *  @param open degrees of rotation for servo to open.
 *  @param close degrees of rotation for servo to close.
 *  @return void
 */

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

/** Sweeps the servo to
 *
 *  Simple function to rotate the servo to a position and back.
 *  
 *  @param start position servo starts at.
 *  @param end position servo will move to.
 *  @param t time t in milliseconds servo will delay while sweeping. Determines speed of rotation.
 */

void sweep(int start, int end, int t) {
  for(int i = start; i <= end; i++) {
    serv.write(i);
    delay(t);
  }
  for(int i = end; i >= start; i--) {
    serv.write(i);
    delay(t);
  }
}

