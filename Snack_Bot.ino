#include <Servo.h>

int angle;

Servo leftServo;
Servo centerServo;
Servo rightServo;

const int leftSensorTrig = 13;
const int leftSensorEcho = 12;
const int rightSensorTrig = 11;
const int rightSensorEcho = 10;

int leftDistance;
int rightDistance;

void setup() {
  // put your setup code here, to run once:
  leftServo.attach(6);
  rightServo.attach(7);
  pinMode(leftSensorTrig, OUTPUT); 
  pinMode(leftSensorEcho, INPUT);
  pinMode(rightSensorTrig, OUTPUT); 
  pinMode(rightSensorEcho, INPUT);
}

void loop() {
   //Left Servo Code:
     leftDistance = calculateDistanceLeft();
     rightDistance = calculateDistanceRight();
     
  if(leftDistance < 20){
    servoMovement(85, 160, leftServo); 
    delay(1000);
  }

  if(rightDistance < 20){
    servoMovement(70, 200, rightServo); 
    delay(1000);
  }  
}

//Left Sensor
int calculateDistanceLeft(){ 
  long duration;
  digitalWrite(leftSensorTrig, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(leftSensorTrig, HIGH); 
  delayMicroseconds(10);
  digitalWrite(leftSensorTrig, LOW);
  duration = pulseIn(leftSensorEcho, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  leftDistance= duration*0.034/2;
  return leftDistance;
}

//Right Sensor
int calculateDistanceRight(){ 
  long duration;
  digitalWrite(rightSensorTrig, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(rightSensorTrig, HIGH); 
  delayMicroseconds(10);
  digitalWrite(rightSensorTrig, LOW);
  duration = pulseIn(rightSensorEcho, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  rightDistance = duration*0.034/2;
  return rightDistance;
}


void servoMovement(int start, int end, Servo servo){
      for(angle = start; angle < end; angle += 1)    // command to move from 0 degrees to 180 degrees 
      {                                  
      servo.write(angle);
      //command to rotate the servo to the specified angle
      delay(15);                       
      } 
  
  delay(100);
  
    for(angle = end; angle>start; angle-=5)     // command to move from 180 degrees to 0 degrees 
    {                                
      
      servo.write(angle);   //command to rotate the servo to the specified angle
      delay(5);                       
    } 
  delay(100);
  }
