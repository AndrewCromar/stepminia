#include "gamepad.h"

static uint8_t const desc_hid_report[] = {
  0x05, 0x01,        // Usage Page (Generic Desktop)
  0x09, 0x05,        // Usage (Game Pad)
  0xA1, 0x01,        // Collection (Application)

  // Buttons: Select (Minus), Start (Plus)
  0x05, 0x09,        //   Usage Page (Button)
  0x09, 0x09,        //   Usage (Button 9)  - Select
  0x09, 0x0A,        //   Usage (Button 10) - Start
  0x15, 0x00,        //   Logical Minimum (0)
  0x25, 0x01,        //   Logical Maximum (1)
  0x75, 0x01,        //   Report Size (1)
  0x95, 0x02,        //   Report Count (2)
  0x81, 0x02,        //   Input (Data, Var, Abs)

  // Padding
  0x75, 0x01,        //   Report Size (1)
  0x95, 0x06,        //   Report Count (6)
  0x81, 0x03,        //   Input (Const, Var, Abs)

  // Hat switch (d-pad)
  0x05, 0x01,        //   Usage Page (Generic Desktop)
  0x09, 0x39,        //   Usage (Hat Switch)
  0x15, 0x01,        //   Logical Minimum (1)
  0x25, 0x08,        //   Logical Maximum (8)
  0x35, 0x00,        //   Physical Minimum (0)
  0x46, 0x3B, 0x01,  //   Physical Maximum (315)
  0x65, 0x14,        //   Unit (Eng Rot: Degree)
  0x75, 0x08,        //   Report Size (8)
  0x95, 0x01,        //   Report Count (1)
  0x81, 0x42,        //   Input (Data, Var, Abs, Null State)

  0xC0               // End Collection
};

uint8_t Gamepad::hatFromDpad(bool up, bool down, bool left, bool right) {
  if (up && right)   return 2;
  if (up && left)    return 8;
  if (down && right) return 4;
  if (down && left)  return 6;
  if (up)            return 1;
  if (right)         return 3;
  if (down)          return 5;
  if (left)          return 7;
  return 0;
}

void Gamepad::begin() {
  _hid.setPollInterval(2);
  _hid.setReportDescriptor(desc_hid_report, sizeof(desc_hid_report));
  _hid.begin();

  while (!TinyUSBDevice.mounted()) {
    delay(1);
  }

  memset(&_report, 0, sizeof(_report));
}

void Gamepad::sendReport(Buttons& buttons) {
  if (!_hid.ready()) return;

  _report.buttons = 0;
  if (buttons.minus) _report.buttons |= (1 << 0);
  if (buttons.plus)  _report.buttons |= (1 << 1);

  _report.hat = hatFromDpad(buttons.up, buttons.down, buttons.left, buttons.right);

  _hid.sendReport(0, &_report, sizeof(_report));
}
