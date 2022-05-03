#include <AFMotor.h>

AF_DCMotor motorLeft(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motorRight(3, MOTOR12_64KHZ); // create motor #3, 64KHz pwm
AF_DCMotor motorHat(4, MOTOR12_64KHZ); // create motor #4, 64KHz pwm

void up() { Serial.write('R');  // RED in Processing }
void down() { Serial.write('G');  // GREEN in Processing }
void left() { Serial.write('Y');  // YELLOW in Processing }
void right() { Serial.write('O');  // ORANGE in Processing }

void setup() {
  Serial.begin(115200); // set up Serial library at 115200 bps
  Serial.println("Motor test!");
  
  motorLeft.setSpeed(255); // set the speed to 200/255
  
  motorRight.setSpeed(255); // set the speed to 200/255
  
  motorHat.setSpeed(255); // set the speed to 200/255
  motorHat.run(FORWARD); // stopped
}

void loop() {
  char incomingChar = 0;   // for incoming serial data

  if (Serial.available() > 0) {
    incomingChar = Serial.read();
    switch (incomingChar) {
      case 'u':
//        up();
        motorLeft.run(FORWARD); // turn it on going forward
        motorRight.run(FORWARD); // turn it on going forward
        delay(50);
        break;
      case 'd':
//        down();
        motorLeft.run(BACKWARD); // turn it on going forward
        motorRight.run(BACKWARD); // turn it on going forward
        delay(50);
        break;
      case 'l':
//        left();
        motorLeft.run(BACKWARD); // turn it on going forward
        motorRight.run(FORWARD); // turn it on going forward
        delay(50);
        break;
      case 'r':
//        right();
        motorLeft.run(FORWARD); // turn it on going forward
        motorRight.run(BACKWARD); // turn it on going forward
        delay(50);
        break;
      default:
        Serial.write('B');  // BLACK
        break;
    }
  } else {
    delay(50);
    motorLeft.run(RELEASE); // stopped
    motorRight.run(RELEASE); // stopped
    incomingChar = 0; // not really needed but in case you want to do things in the loop upon receiving new chars. if (incomingChar == 0) then no new char was received, otherwise later in the loop you still have the char received
  }
}
