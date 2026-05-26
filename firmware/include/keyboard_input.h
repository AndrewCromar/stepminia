#pragma once

#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include "buttons.h"

class KeyboardInput {
public:
  void begin();
  void update(Buttons& buttons);

private:
  Adafruit_USBD_HID _hid;
  uint8_t _lastKeycodes[6] = {0, 0, 0, 0, 0, 0};
};
