#include <AFMotor.h>

AF_DCMotor motorLeft(3, MOTOR12_64KHZ); // create motor #3, 64KHz pwm
AF_DCMotor motorRight(4, MOTOR12_64KHZ); // create motor #4, 64KHz pwm
AF_DCMotor motorHat(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

void up() { Serial.write('R');}  // RED in Processing }
void down() { Serial.write('G');}  // GREEN in Processing }
void left() { Serial.write('Y'); } // YELLOW in Processing }
void right() { Serial.write('O'); } // ORANGE in Processing }

void setup() {
  Serial.begin(115200); // set up Serial library at 115200 bps
  Serial.println("Motor test!");
  
  motorLeft.setSpeed(255); // set the speed to 200/255
  
  motorRight.setSpeed(255); // set the speed to 200/255
  
  motorHat.setSpeed(255); // set the speed to 200/255
  //motorHat.run(FORWARD); // stopped
}
int count_right= 0;
int count_left= 0;
int count_forward= 0;
int count_backward= 0;
int countvalue = 0;
int allcount = 0;

void loop() {
  char incomingChar = 0;   // for incoming serial data
  
  String incomingCommandchar;
  String countstring;
  
  if (Serial.available() > 0) {
    
    incomingCommandchar = Serial.readStringUntil('z');
    countstring = Serial.readStringUntil('z');
    Serial.println(incomingCommandchar);
    Serial.println(countstring);
    
    countvalue=countstring.toInt();
    Serial.println(countvalue);
    
    switch (incomingCommandchar[0]) {
      case 'f':
        count_forward=countvalue;
        count_right= 0;
        count_left= 0;
        count_backward= 0;
        Serial.println("count_forward");
        Serial.println(count_forward);
        motorLeft.run(FORWARD); // turn it on going forward
        motorRight.run(FORWARD); // turn it on going forward
        delay(50);
        break;
        
      case 'b':

        count_backward=countvalue;
        count_right= 0;
        count_left= 0;
        count_forward= 0;
        
        motorLeft.run(BACKWARD); // turn it on going forward
        motorRight.run(BACKWARD); // turn it on going forward
        delay(50);
        break;
      case 'l':

        count_left=countvalue;
        count_right= 0;
        count_forward= 0;
        count_backward= 0;
        
        motorLeft.run(BACKWARD); // turn it on going forward
        motorRight.run(FORWARD); // turn it on going forward
        delay(50);
        break;
      case 'r':

        count_right=countvalue;
        count_forward= 0;
        count_left= 0;
        count_backward= 0;
        Serial.println("count_right");
        Serial.println(count_right);
        
        motorLeft.run(FORWARD); // turn it on going forward
        motorRight.run(BACKWARD); // turn it on going forward
        delay(50);
        break;
      case 'q':
        motorHat.run(FORWARD);
        delay(50);
        break;
      case 'a':
        motorHat.run(BACKWARD);
        delay(50);
        break;
      default:
        Serial.write('B');  // BLACK
        break;
    }
    allcount=count_forward + count_backward + count_left + count_right;
    
  } else {
    delay(50);
    Serial.println("allcount");
    Serial.println(allcount);
    if (allcount<=0){
          motorLeft.run(RELEASE); // stopped
          motorRight.run(RELEASE); // stopped
          motorHat.run(RELEASE); //stopped
          count_right= 0;
          count_left= 0;
          count_forward= 0;
          count_backward= 0;
          
    }
    else {
      allcount--;
    }
    

    incomingChar = 0; // not really needed but in case you want to do things in the loop upon receiving new chars. if (incomingChar == 0) then no new char was received, otherwise later in the loop you still have the char received
  }
}
