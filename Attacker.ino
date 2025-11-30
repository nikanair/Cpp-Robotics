#include <Servo.h>
int redled = 13;
int greenled = 12;
int trigPin = 11;
int echoPin = 10;
Servo myservo;
long duration, distance;
void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);
  myservo.write(0);
  
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance = 0.034*duration;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  Serial.print("There is an intruder!!!");
  Serial.println();
  if(distance<=100){
    digitalWrite(redled, HIGH);
    digitalWrite(greenled,LOW);   
    myservo.write(180);

  }  
  else{
    digitalWrite(redled, LOW);
    digitalWrite(greenled, HIGH); 
    myservo.write(0);
    
  }  
  delay(100);
}


  
