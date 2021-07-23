#include <Arduino.h>
#include "OneButton.h"

#define pinBotao 2
#define pinLED 1

void setup() {
  while (!Serial)
  {
    /* code */
  }

  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World");

  digitalWrite(pinLED, HIGH);
  delay(3000);

  digitalWrite(pinLED, LOW);
  delay(3000);
}