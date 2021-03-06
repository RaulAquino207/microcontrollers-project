#ifndef CONFIGS_H
#define CONFIGS_H

#include <Arduino.h>
#include <BleKeyboard.h>

#define NUM_BUTTON 6

enum Action
{
  KEY_COMBINATION
};

struct KeyConfig
{
  Action actionType;
  const uint8_t *keys;
  const uint8_t key;
};

struct KeyboardConfig
{
  KeyConfig keysConfig[NUM_BUTTON];
};

const uint8_t altShift[3] = {KEY_LEFT_SHIFT, KEY_LEFT_ALT, '\0'};

KeyboardConfig obsConfig = {
    .keysConfig = {
        KeyConfig{
            .actionType = KEY_COMBINATION,
            .keys = altShift,
            .key = '1',
        },
        KeyConfig{
            .actionType = KEY_COMBINATION,
            .keys = altShift,
            .key = '2',
        },
        KeyConfig{
            .actionType = KEY_COMBINATION,
            .keys = altShift,
            .key = '3',
        },
        KeyConfig{
            .actionType = KEY_COMBINATION,
            .keys = altShift,
            .key = '4',
        },
        KeyConfig{
            .actionType = KEY_COMBINATION,
            .keys = altShift,
            .key = '5',
        },
        KeyConfig{
            .actionType = KEY_COMBINATION,
            .keys = altShift,
            .key = '6',
        },
    },
};

#endif