int lmt1=5;
int lmt2=3;
int rmt1=6;
int rmt2=11;
int keyboard;
void setup() {
  Serial.begin(9600);
}

void loop() {
  keyboard = Serial.read();
  if(keyboard=='W')
  {
    forward();
    Serial.println("ROBOT: forward");
  }
  if(keyboard=='A')
  {
    left();
    Serial.println("ROBOT: left");
  }
  if(keyboard=='D')
  {
    right();
    Serial.println("ROBOT: right");
  }
  if(keyboard=='S')
  {
    stp();
    Serial.println("ROBOT: stopped");
  }

}
void forward()
 {
  analogWrite(lmt1,150);
  analogWrite(lmt2,0);
  analogWrite(rmt1,150);
  analogWrite(rmt2,0);
 }
 void left()
  {
  analogWrite(lmt1,0);
  analogWrite(lmt2,150);
  analogWrite(rmt1,150);
  analogWrite(rmt2,0);
  }
  void right()
  {
  analogWrite(lmt1,150);
  analogWrite(lmt2,0);
  analogWrite(rmt1,0);
  analogWrite(rmt2,150);
  }
  void stp()
  {
  analogWrite(lmt1,0);
  analogWrite(lmt2,0);
  analogWrite(rmt1,0);
  analogWrite(rmt2,0);
  }
