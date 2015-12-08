/** @file
 *  This is the final demo code.
 *  We used this in the presentation.
 *
 *  This code sweeps the base of the robot, then the upper arm, then the claw.
 *  The code loops infinitely until power is cut from the arduino or the shield.
 */


#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); /**<Driver for Servo Shield. It acts as the interface between the Servo Shield and the Arduino */

/**Minimum rotation in pulse length(pwm) for Servo motors at base */
#define SERVOMINBASE  150 
/**Maximum rotation in pulse length(pwm) for Servo motors at base */
#define SERVOMAXBASE  300 

/**Minimum rotation in pulse length for Servo motors at upperarm and claw */
#define SERVOMINUP  150
/**Maximum rotation in pulse length for Servo motors at upperarm and claw */
#define SERVOMAXUP  250

/** This sets up the Arduino code.
 *  Runs only once at the beginning.
 *
 *  Sets up the serial monitor for debugging and initializes
 *  the driver for the Servo Shield.
 *  @param void
 *  @return void
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

/** Sweeps a servo a specified distance on a specified channel.
 *  
 *  @param pwm The driver for the Servo Shield.
 *  @param channel The channel the Servo is connected to on the Shield.
 *  @param start The starting position in pulse length.
 *  @param stop The stopping position in pulse length.
 *  @param increment The amount to increase/decrease the pulse length every cycle of the loop.
 *  @return void
 */

void sweep(Adafruit_PWMServoDriver pwm, uint8_t channel, uint16_t start, uint16_t stop, uint16_t increment) {
  for (uint16_t pulselen = start; pulselen > stop; pulselen += increment) {
    pwm.setPWM(channel, 0, pulselen);
  }
}

/** This code loops through every cycle.
 *  keeps cycling until power is disconnected.
 *
 *  Calls the sweep function twice for each joint.
 *  There are delays in between each loop to ensure that the servo doesn't
 *  move too fast and burn out. There are different servo min and maxes
 *  based on the physical arcitecture of the arm. We ensured that each part
 *  moved within range of the table, etc.
 *  
 *  @param void
 *  @return void
 */

void loop() {
  for (uint16_t pulselen = SERVOMINBASE; pulselen < SERVOMAXBASE; pulselen++) {
    pwm.setPWM(0,0,pulselen);
    pwm.setPWM(1,0,pulselen);
  }

  delay(700);
  for (uint16_t pulselen = SERVOMAXBASE; pulselen > SERVOMINBASE; pulselen--) {
    pwm.setPWM(0,0,pulselen);
    pwm.setPWM(1,0,pulselen);
  }

  delay(1000);
  sweep(pwm, 2, SERVOMINUP, SERVOMAXUP, 1);

  delay(700);
  sweep(pwm, 2, SERVOMAXUP, SERVOMINUP, -1);

  delay(1000);
  sweep(pwm, 3, SERVOMINBASE, SERVOMAXBASE, 1);

  delay(700);
  sweep(pwm, 3, SERVOMAXBASE, SERVOMINBASE, -1);

  delay(2000);
}
