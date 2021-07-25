#include <Arduino.h>

#define LED 1
#define Button1 23

void setup() {

  pinMode(LED, OUTPUT);
  pinMode(Button1, INPUT);
  
}

void loop() {
  int ButtonState = digitalRead(Button1);

  if(ButtonState == HIGH)
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }

}