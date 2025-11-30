
const int trigPin = 10;
const int echoPin = 11; 
long duration;
int distance;
int position_;
int keyboard;
int L_Motor1 = 6;
int L_Motor2 = 11;
int R_Motor1 = 3;
int R_Motor2 = 5;
void setup() {
  Serial.begin(9600);
  
  keyboard = Serial.read();
  pinMode(R_Motor1,OUTPUT);
  pinMode(L_Motor1,OUTPUT);
  pinMode(R_Motor2,OUTPUT);
  pinMode(L_Motor2,OUTPUT);    
}

void loop() {
  

  if (keyboard == 'F' or keyboard == 'r'){
    forward();
    Serial.println("Robot moved forward");
  }
  if (keyboard == 'R' or keyboard == 'r'){
    right();
    Serial.println("Robot moved right");
  }
  if (keyboard == 'B' or keyboard == 'b'){
    reverse();
    Serial.println("Robot moved backward");
  }
  if (keyboard == 'L' or keyboard == 'l'){
    left();
    Serial.println("Robot moved left");
  }
  if (keyboard == 'S' or keyboard == 's'){
    stp();
    Serial.println("Robot stopped");
  }
  if (distance < 5){
    stp();
    Serial.println("Robot detected an obstacle");
  }
  if (keyboard == "SR" or keyboard == "sr"){
    stp_right();
    Serial.println("Robot turned right");
  }
  if (keyboard == "SL" or keyboard == "sl"){
    stp_left();
    Serial.println("Robot turned left");
  }
  

}
//Forward: HLHL  Reverse: LHLH  Right: HLLH  Left: LHHL
void reverse(){
  analogWrite(L_Motor1,0);
  analogWrite(L_Motor1,150);
  analogWrite(R_Motor1,0);
  analogWrite(R_Motor1,150);
}
void forward(){
  analogWrite(L_Motor1,150);
  analogWrite(L_Motor1,0);
  analogWrite(R_Motor1,150);
  analogWrite(R_Motor1,0);
}
void left(){
  analogWrite(L_Motor1,0);
  analogWrite(L_Motor1,150);
  analogWrite(R_Motor1,150);
  analogWrite(R_Motor1,0);
}
void right(){
  analogWrite(L_Motor1,150);
  analogWrite(L_Motor1,0);
  analogWrite(R_Motor1,0);
  analogWrite(R_Motor1,150);
}
void stp(){
  analogWrite(L_Motor1,0);
  analogWrite(L_Motor1,0);
  analogWrite(R_Motor1,0);
  analogWrite(R_Motor1,0);
}
