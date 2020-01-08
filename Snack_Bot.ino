#include <Servo.h>

int angle;

Servo leftServo;
Servo centerServo;
Servo rightServo;

const int leftSensorTrig = 13;
const int leftSensorEcho = 12;
const int rightSensorTrig = 0;
const int rightSensorEcho = 0;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  leftServo.attach(6);
  rightServo.attach(7);
  pinMode(leftSensorTrig, OUTPUT); 
  pinMode(leftSensorEcho, INPUT);
//  pinMode(rightSensorTrig, OUTPUT); 
//  pinMode(rightSensorEcho, INPUT);
}

void loop() {
   //Right Servo Code:
     distance = calculateDistance();
     
  if(distance < 20){
    servoMovement(85, 160, leftServo); 
    delay(1000);
  }

//servoMovement(70, 200, rightServo);     
}

//Sensor
int calculateDistance(){ 
  
  digitalWrite(leftSensorTrig, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(leftSensorTrig, HIGH); 
  delayMicroseconds(10);
  digitalWrite(leftSensorTrig, LOW);
  duration = pulseIn(leftSensorEcho, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
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
