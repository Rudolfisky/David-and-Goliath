int switch_pin = A0;
int led_pin = 13;


void setup() {
  pinMode(switch_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int value = analogRead(switch_pin);
  Serial.println(value);
  
  if(value == HIGH){
    digitalWrite(led_pin, LOW);
  }
  if(value == LOW){
    digitalWrite(led_pin, HIGH);
  }

}
