#pragma once

#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include "buttons.h"

struct GamepadReport {
  uint8_t buttons;
  uint8_t hat;
} __attribute__((packed));

class Gamepad {
public:
  void begin();
  void sendReport(Buttons& buttons);

private:
  Adafruit_USBD_HID _hid;
  GamepadReport _report;
  uint8_t hatFromDpad(bool up, bool down, bool left, bool right);
};
