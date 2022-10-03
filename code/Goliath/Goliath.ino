#include <Servo.h>

Servo myservo;

int pos = 0;    // variable to store the servo position
int delaySmooth = 5;
const int switchPin = A0;

int switchState = 0;      
int switchPos;

void setup() {
  Serial.begin(115200);
  myservo.attach(9);
  pinMode(switchPin, INPUT);
}

void loop() {
  checkSwitchPos();
  switch (switchPos) {
    case 0:
      myservo.write(0);
      delay(750);
      break;
    case 1:
      myservo.write(180);
      delay(750);
      myservo.write(0);
      delay(750);
      break;
    case 2:
    myservo.write(0);
    delay(750);
      
      break;
    default:
      // statements
      break;
  }
  delay(100);
//  if (buttonState == HIGH) {
//    Serial.println("on");
//    myservo.write(190);
//  } else {
//    myservo.write(0);
//    Serial.println("off");
//
//  }
}

void checkSwitchPos(){
   switchState = analogRead(switchPin);
  
  if (switchState <= 100){
    switchPos = 0;
  }
  if (switchState >= 900){
    switchPos = 1;
  }
  if (switchState >= 400 && switchState <= 600){
    switchPos = 2;
  }
  Serial.println(switchPos);
}

void movement(int positionA, int positionB, int delayTime){
  Serial.println("movement");
  if (positionA >= positionB){
    Serial.println("test");
    for(int pos = positionA; pos >= positionB; pos += -1){
      myservo.write(pos);
      delay(delayTime);
      Serial.println(pos);
    };
  }else{
    for(int pos = positionA; pos <= positionB; pos += 1){
      myservo.write(pos);
      delay(delayTime);
      Serial.println(pos);
    };
  } 
}
