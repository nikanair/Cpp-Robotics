#include <Servo.h>
int redled = 13;
int greenled = 12;
int trigPin = 11;
int echoPin = 10;
int pos = 0;
Servo myservo;
long duration, distance;
void setup() {
  for(pos=0;pos<=180;pos+=1){
    myservo.write(pos);
    delay(15);
  }
  for(pos=180;pos<=0;pos-=1){
    myservo.write(pos);
    delay(15);
  }
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
   
  }
  else{
    digitalWrite(redled, LOW);
    digitalWrite(greenled, HIGH);
    
  }
   
  delay(100);
}


