#include <Arduino.h>
#include <OneButton.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("Streamdeck", "Raul Aquino", 100);

OneButton button1(23, true);
OneButton button2(17, true);

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
  
  bleKeyboard.begin();

}

void onClick(void *p){
  int index = *((int *)p);
  Serial.println("Button " + String(index + 1) + " Pressed");

  if(bleKeyboard.isConnected()) {
    // Serial.println("Sending 'Hello world'...");
    // bleKeyboard.print("Hello world");
    switch(index) {
      case 0:
        // bleKeyboard.press(KEY_LEFT_ALT);
        // bleKeyboard.press(KEY_UP_ARROW);
        // Serial.println("Recording started");
        bleKeyboard.press(KEY_MEDIA_PREVIOUS_TRACK);
        Serial.println("Previous track");
        break;
      case 1:
        // bleKeyboard.press(KEY_LEFT_ALT);
        // bleKeyboard.press(KEY_DOWN_ARROW);
        // Serial.println("Recording finished");
        bleKeyboard.press(KEY_MEDIA_NEXT_TRACK);
        Serial.println("Next track");
        break;
      default:
        break;
    }
  }
}

void loop() {

  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    buttons[i].tick();
  }
  delay(10);

}