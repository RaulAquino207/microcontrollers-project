#include <Arduino.h>
#include <OneButton.h>

OneButton button1(17, true);
OneButton button2(23, true);

#define NUM_BUTTONS 2
OneButton buttons[NUM_BUTTONS] = {button1, button2};
int buttonsIndexes[NUM_BUTTONS] = {0, 1};

void onClick(void *p);

void setup() {

  while (!Serial){}
  
  Serial.begin(9600);

  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    buttons[i].attachClick(onClick, &buttonsIndexes[i]);
  }
  
  
}

void onClick(void *p){
  int index = *((int *)p);
  Serial.println("Button ");
  Serial.println(index + 1);
  Serial.println(" Pressed");
}

void loop() {

  // Serial.println("Hello World");
  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    buttons[i].tick();
  }
  delay(10);

}