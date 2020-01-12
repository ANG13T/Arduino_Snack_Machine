#include <Keypad.h>
#include <Servo.h>

int angle;

Servo leftServo;
Servo centerServo;
Servo rightServo;

//Keypad
const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {13,12,11,10};
byte colPins[COLS] = {9,8,7};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//Sensor
const int leftSensorTrig = 6;
const int leftSensorEcho = 5;
const int rightSensorTrig = 4;
const int rightSensorEcho = 3;

int leftDistance;
int rightDistance;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  leftServo.attach(1);
  rightServo.attach(2);
  pinMode(leftSensorTrig, OUTPUT); 
  pinMode(leftSensorEcho, INPUT);
  pinMode(rightSensorTrig, OUTPUT); 
  pinMode(rightSensorEcho, INPUT);
}

void loop() {

   char key = keypad.getKey(); 
  if (key == '1'){
    Serial.println(key);
  } 
    
  
   //Left Servo Code:
     leftDistance = calculateDistanceLeft();
     rightDistance = calculateDistanceRight();
     
  if(leftDistance < 3){
    servoMovement(85, 160, leftServo); 
    delay(1000);
  }

  if(rightDistance < 3){
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
