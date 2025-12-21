#include<AFMotor.h>

#define ir_r  A4
#define ir_c  A5
#define ir_l  A3

AF_DCMotor M1(1,MOTOR12_1KHZ);
AF_DCMotor M3(3,MOTOR34_1KHZ);

void setup() {
  pinMode(ir_r,INPUT);
  pinMode(ir_c,INPUT);
  pinMode(ir_l,INPUT);


}
void loop() {
  if ((digitalRead(ir_r)==1) && (digitalRead(ir_c)==1) && (digitalRead(ir_l)==1)){
    M1.setSpeed(200);
    M1.run(FORWARD);
    M3.setSpeed(200);
    M3.run(FORWARD);
  }
  else if ((digitalRead(ir_r)==0) && (digitalRead(ir_c)==1) && (digitalRead(ir_l)==0)){
    M1.setSpeed(200);
    M1.run(FORWARD);
    M3.setSpeed(200);
    M3.run(FORWARD);
  }
  else if ((digitalRead(ir_r)==0) && (digitalRead(ir_c)==1) && (digitalRead(ir_l)==1)or(digitalRead(ir_r)==0) && (digitalRead(ir_c)==0) && (digitalRead(ir_l)==1)){
    M1.setSpeed(200);
    M1.run(BACKWARD);
    M3.setSpeed(200);
    M3.run(FORWARD);
  }
  else if ((digitalRead(ir_r)==1) && (digitalRead(ir_c)==1) && (digitalRead(ir_l)==0)or(digitalRead(ir_r)==1) && (digitalRead(ir_c)==0) && (digitalRead(ir_l)==0)){
    M1.setSpeed(200);
    M1.run(FORWARD);
    M3.setSpeed(200);
    M3.run(BACKWARD);
  }
  else if ((digitalRead(ir_r)==0) && (digitalRead(ir_c)==0) && (digitalRead(ir_l)==0)){
    M1.setSpeed(0);
    M1.run(RELEASE);
    M3.setSpeed(0);
    M3.run(RELEASE);
  
  }
}

