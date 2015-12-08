/*! \brief This is the final demo code.
 *         We used this in the presentation.
 *
 *  This code sweeps the base of the robot, then the upper arm, then the claw.
 *  The code loops infinitely until power is cut from the arduino or the shield.
 */


#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMINBASE  150 // this is the 'minimum' pulse length base and claw
#define SERVOMAXBASE  300 // this is the 'maximum' pulse length base and claw

#define SERVOMINUP  150 // this is the 'minimum' pulse length upper arm
#define SERVOMAXUP  250 // this is the 'maximum' pulse length upper arm

// our servo # counter
uint8_t servonum = 0;

/*! \brief This sets up the Arduino code.
 *         Runs only once at the beginning.
 *
 *  Serial.begin(9600) sets up the serial monitor for debugging purposes.
 *  The next line simply prints to the serial monitor.
 *  The last chunk sets up the servo shield. It sets up the pwm and wires
 *  in the shield.
 */

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

#ifdef ESP8266
  Wire.pins(2, 14);   // ESP8266 can use any two pins, such as SDA to #2 and SCL to #14
#endif

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  yield();
}

/*! \brief This code loops through every cycle.
 *         It keeps cycling until power is disconnected.
 *
 *  There are two sets of for loops for each joint. The first for loop
 *  sweeps the servo up, the second for loop sweeps the servo down. 
 *  There are delays in between each loop to ensure that the servo doesn't
 *  move too fast and burn out. There are different servo min and maxes
 *  based on the physical arcitecture of the arm. We ensured that each part
 *  moved within range of the table, etc.
 */

void loop() {
  // Drive each servo one at a time
  //Serial.println(servonum);
  for (uint16_t pulselen = SERVOMINBASE; pulselen < SERVOMAXBASE; pulselen++) {
  //  pwm.setPWM(servonum, 0, pulselen);
    pwm.setPWM(0,0,pulselen);
    pwm.setPWM(1,0,pulselen);
//    pwm.setPWM(3,0,pulselen);
  }

  delay(700);
  for (uint16_t pulselen = SERVOMAXBASE; pulselen > SERVOMINBASE; pulselen--) {
 //   pwm.setPWM(servonum,0,pulselen);
    pwm.setPWM(0,0,pulselen);
    pwm.setPWM(1,0,pulselen);
//    pwm.setPWM(3,0,pulselen);
  }

  delay(1000);

  for (uint16_t pulselen = SERVOMINUP; pulselen < SERVOMAXUP; pulselen++) {
    pwm.setPWM(2, 0, pulselen);

  }

  delay(700);
  for (uint16_t pulselen = SERVOMAXUP; pulselen > SERVOMINUP; pulselen--) {
    pwm.setPWM(2,0,pulselen);

  }

  delay(1000);

  for (uint16_t pulselen = SERVOMINBASE; pulselen < SERVOMAXBASE; pulselen++) {
    pwm.setPWM(3, 0, pulselen);

  }

  delay(700);
  for (uint16_t pulselen = SERVOMAXBASE; pulselen > SERVOMINBASE; pulselen--) {
    pwm.setPWM(3,0,pulselen);

  }

  delay(2000);

//  servonum ++;
//  if (servonum > 1) servonum = 0;
}
