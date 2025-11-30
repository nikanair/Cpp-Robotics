int keyboard;
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  keyboard = Serial.read();
  if(keyboard==H)
  {
    digitalWrite(13,HIGH);
    Serial.println("Yaay it's turned on !!");
  }
  if(keyboard==L)
  {
    digitalWrite(13,LOW);
    Serial.println("Hey it's turned off !!");
  }

}
