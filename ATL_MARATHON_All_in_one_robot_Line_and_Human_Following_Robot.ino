#include<NewPing.h>
#include<Servo.h>
#include<AFMotor.h>
#define RIGHT A4
#define LEFT A3
#define CENTER A5



int Right_Value;
int Left_Value;
int Center_Value;

AF_DCMotor Motor1(1, MOTOR12_1KHZ);
AF_DCMotor Motor2(2, MOTOR12_1KHZ);

void setup() {
  Serial.begin(9600); //Begins the Serial communication at baud rate 9600
  pinMode(RIGHT, INPUT);
  pinMode(LEFT, INPUT);
  
}

void loop() {
  
  Right_Value = digitalRead(RIGHT);
  Left_Value = digitalRead(LEFT);
  Center_Value = digitalRead(CENTER);

  if((Right_Value == 1)&&(Left_Value == 1)&&(Center_Value == 1)){  
    Motor1.setSpeed(200);  
    Motor1.run(FORWARD);  
    Motor2.setSpeed(200);  
    Motor2.run(FORWARD);
  }
  else if((Right_Value==0)&&(Center_Value == 1)&&(Left_Value==1)) {  
    Motor1.setSpeed(200);  
    Motor1.run(FORWARD);  
    Motor2.setSpeed(200);  
    Motor2.run(FORWARD);
  }  
  else if((Right_Value==1)&&(Center_Value==1)&&(Left_Value==0)) {  
    Motor1.setSpeed(200);  
    Motor1.run(FORWARD);  
    Motor2.setSpeed(200);  
    Motor2.run(FORWARD);
  }
  else if((Right_Value==0)&&(Center_Value==0)&&(Left_Value==1)) {  
    Motor1.setSpeed(200);  
    Motor1.run(BACKWARD);  
    Motor2.setSpeed(200);  
    Motor2.run(FORWARD);
  }
  else if((Right_Value==1)&&(Center_Value==0)&&(Left_Value==0)) {  
    Motor1.setSpeed(200);  
    Motor1.run(FORWARD);  
    Motor2.setSpeed(200);  
    Motor2.run(BACKWARD);
  }
  else if((Right_Value==0)&&(Center_Value==0)&&(Left_Value==0)) {  
    Motor1.setSpeed(0);  
    Motor1.run(RELEASE);  
    Motor2.setSpeed(0);  
    Motor2.run(RELEASE);
  }

}

