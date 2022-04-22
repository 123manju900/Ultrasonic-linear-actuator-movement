/* Arduino Stepper Control with Potentiometer
*/

#include "AccelStepper.h" 
// Library created by Mike McCauley at http://www.airspayce.com/mikem/arduino/AccelStepper/
#define echoPin 5 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 6 //attach pin D3 Arduino to pin Trig of HC-SR04
// AccelStepper Setup
AccelStepper stepper(1, 2, 3);  // 1 = Easy Driver interface
                                  // Nano Pin 2 connected to STEP pin of Easy Driver
                                  // Nano Pin 3 connected to DIR pin of Easy Driver

// Variables to store current, previous and move position
int val = 0;
int previous = 0;
int long newval = 0;    
long duration; // variable for the duration of sound wave travel
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600);
  stepper.setMaxSpeed(6000);  //4800 Set speed fast enough to follow pot rotation
  stepper.setAcceleration(6000);  // 4800 High Acceleration to follow pot rotation  
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
 //Serial.print("Distance: ");
 //Serial.print(distance);
 //Serial.println(" cm");
  val = distance;  //  Read Potentiometer current value
  //Serial.print(val);
 // Serial.println(" Inches");
 stepper.setSpeed(1400);
 stepper.runSpeed(); 
 if ( previous+8 > val ) {
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  stepper.runToNewPosition(1200);
 }

 else if ( val-8 > previous ){
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  stepper.runToNewPosition(-1200);
 }

 previous = val;
 }
