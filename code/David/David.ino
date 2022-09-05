#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int delaySmooth = 5;

void setup() {
  Serial.begin(115200);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  myservo.write(180);
  delay(1000);
  myservo.write(50);
  movement(50,0,20);
  delay(1000);
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
