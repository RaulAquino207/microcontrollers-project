#include <Arduino.h>
#include <OneButton.h>
#include <BleKeyboard.h>
#include "configs.h"

BleKeyboard bleKeyboard("Streamdeck DIY", "Raul Aquino", 100);

OneButton button1(23, true);
OneButton button2(22, true);
OneButton button3(21, true);
OneButton button4(4, true);
OneButton button5(14, true);
OneButton button6(12, true);

OneButton buttons[NUM_BUTTON] = {button1, button2, button3, button4, button5, button6};
int buttonIndexes[NUM_BUTTON] = {0, 1, 2, 3, 4, 5};

KeyboardConfig keyboardConfig = obsConfig;

void onClick(void *p);

void setup()
{
  while (!Serial)
  {
  }

  Serial.begin(9600);

  for (int i = 0; i < NUM_BUTTON; i++)
  {
    buttons[i].attachClick(onClick, &buttonIndexes[i]);
  }

  bleKeyboard.begin();
}

void onClick(void *p)
{
  int index = *((int *)p);
  Serial.print("Button ");
  Serial.print(index + 1);
  Serial.println(" Pressed");

  if (bleKeyboard.isConnected())
  {

    KeyConfig keyConfig = keyboardConfig.keysConfig[index];
    switch (keyConfig.actionType)
    {
    case KEY_COMBINATION:
    {
      int len = strlen((const char *)keyConfig.keys);
      for (int i = 0; i < len; i++)
      {
        bleKeyboard.press(keyConfig.keys[i]);
      }
      bleKeyboard.press(keyConfig.key);
      delay(100);
      bleKeyboard.releaseAll();
      break;
    }
    default:
      Serial.println("Unknow type");
      break;
    }
  }
}

void loop()
{
  for (int i = 0; i < NUM_BUTTON; i++)
  {
    buttons[i].tick();
  }
  delay(10);
}