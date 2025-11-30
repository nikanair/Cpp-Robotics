int Ir=2;
int led=11;

void setup() {
  pinMode(Ir, INPUT);
  pinMode(led, OUTPUT);
   Serial.begin(9600);

}

void loop() {
  int statusSensor = digitalRead(Ir);
  Serial.println(led);
  if(led==1){
    digitalWrite(led, HIGH);

  }
  else{
    digitalWrite(led, LOW);

  }

}
