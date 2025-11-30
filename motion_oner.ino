int redled = 13;
int trigPin = 11;
int echoPin = 10;
int whiteled = 9;
int count;
long duration, distance;
void setup() {
  Serial.begin(9600);
  pinMode(redled, OUTPUT);
  pinMode(whiteled, OUTPUT);
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);

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
  if(distance<=100){
    digitalWrite(whiteled, LOW);
    digitalWrite(redled, HIGH);
    if(whiteled==LOW){
      while(1){
        digitalWrite(whiteled, HIGH);
      }
      
    }
    
    
  }
  else{
    digitalWrite(redled, LOW);
    if(whiteled==HIGH){
      while(1){
        digitalWrite(whiteled, LOW);
      }
    }
  }
  
  delay(100);
}


