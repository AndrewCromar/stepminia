#pragma once

#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include "buttons.h"
#include "joystick.h"

struct GamepadReport {
  uint16_t buttons;
  uint8_t hat;
  int8_t lx;
  int8_t ly;
  int8_t rx;
  int8_t ry;
} __attribute__((packed));

class Gamepad {
public:
  void begin();
  void sendReport(Buttons& buttons, Joystick& leftStick);

private:
  Adafruit_USBD_HID _hid;
  GamepadReport _report;
  uint8_t hatFromDpad(bool n, bool s, bool e, bool w);
};
