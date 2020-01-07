#include <Servo.h>

int angle;

Servo leftServo;
Servo centerServo;
Servo rightServo;

void setup() {
  // put your setup code here, to run once:
  leftServo.attach(6);
  rightServo.attach(7);
}

void loop() {
   //Right Servo Code: 
    servoMovement(100, 190, rightServo); 
}

void servoMovement(int start, int end, Servo servo){
      for(angle = start; angle < end; angle += 1)    // command to move from 0 degrees to 180 degrees 
      {                                  
      servo.write(angle);
      //command to rotate the servo to the specified angle
      delay(15);                       
      } 
  
  delay(1000);
  
    for(angle = end; angle>start; angle-=5)     // command to move from 180 degrees to 0 degrees 
    {                                
      
      servo.write(angle);   //command to rotate the servo to the specified angle
      delay(5);                       
    } 
  delay(1000);
  }
