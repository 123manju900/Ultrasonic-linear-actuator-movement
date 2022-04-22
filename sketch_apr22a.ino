/*
Connect Pin 7 to IN1 of L298N Motor Driver
Connect Pin 8 to IN2 of L298N Motor Driver
Connect Pin 9 to EN of L298N Motor Driver to Control speed of the DC motor
*/

//Buttons
const int downButton = 2;     // the pin number of the downButton
const int upButton = 3;       // the pin number of the upButton
const int topKill = A5;       // the pin number of the topKill
const int bottomKill = A6;    // the pin number of the bottomKill
const int manule=12;          // the pin number of the Manule/Automatic control
//End Buttons
//Defualts Values
int topKillSwitch = 1;
int bottomKillSwitch =1;
int downButtonState = 0;
int upButtonState = 0;
int manuleState = 0;
//End Defualts Values
//HC-SR04 Defualts
#define echoPin 5             // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 6             //attach pin D3 Arduino to pin Trig of HC-SR04
int val = 0;   
long duration;                // variable for the duration of sound wave travel
int distance;                 // variable for the Distance
//End HC-SR04 Defualts


void setup(){
  Serial.begin(9600);
  pinMode(topKill, INPUT_PULLUP);
  pinMode(bottomKill, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(upButton, INPUT_PULLUP);
  pinMode(manule, INPUT_PULLUP);
  pinMode(trigPin, OUTPUT);               // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);                // Sets the echoPin as an INPUT
  pinMode(7, OUTPUT);                     //L298N Input1
  pinMode(8, OUTPUT);                     //L298N Input2
}

void loop(){
  manuleState = digitalRead(manule);
  //Serial.println(manuleState);
  if(manuleState==LOW){
    // To control using Push Buttons
    downButtonState = digitalRead(downButton);
    //Serial.println(downButtonState);
    upButtonState = digitalRead(upButton);
    //Serial.println(bbuttonState);
    //
    //TEST
    //
    //HC-SR04
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
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    topKillSwitch = digitalRead(topKill);
    bottomKillSwitch = digitalRead(bottomKill);
    //
    //TEST
    //
    if(downButtonState==LOW){
      analogWrite(9, 255);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);    
    }
    else if(upButtonState==LOW){
      analogWrite(9, 255);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
    }
    else{
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
    }
  }
  else{
    //HC-SR04
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
    /*Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");*/
    topKillSwitch = digitalRead(topKill);
    bottomKillSwitch = digitalRead(bottomKill);

    if (digitalRead(topKillSwitch) == LOW || digitalRead(bottomKillSwitch) == LOW){

      Serial.println("The button is pressed");
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
      
      if(downButtonState==LOW){
      analogWrite(9, 255);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);    
    }
    else if(upButtonState==LOW){
      
      analogWrite(9, 255);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
    }
    else{
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
    }
  }

  else {
    

    if(distance>30){
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
      analogWrite(9, 250);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      //Serial.println("Fowad");
    }
    else if(distance<28){
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
      analogWrite(9, 250);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      //Serial.println("Backwad");
    }
    else{
      //Serial.println("NO MOVEMENT");
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
  
    }
  }}
}

  

      
   
    
    
  
