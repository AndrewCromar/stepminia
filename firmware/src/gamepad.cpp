#include "gamepad.h"

static uint8_t const desc_hid_report[] = {
  0x05, 0x01,        // Usage Page (Generic Desktop)
  0x09, 0x05,        // Usage (Game Pad)
  0xA1, 0x01,        // Collection (Application)

  // Buttons
  0x05, 0x09,        //   Usage Page (Button)
  0x09, 0x01,        //   Usage (Button 1)  - A
  0x09, 0x02,        //   Usage (Button 2)  - B
  0x09, 0x05,        //   Usage (Button 5)  - X
  0x09, 0x04,        //   Usage (Button 4)  - Y
  0x09, 0x07,        //   Usage (Button 7)  - LB
  0x09, 0x08,        //   Usage (Button 8)  - RB
  0x09, 0x09,        //   Usage (Button 9)  - LT
  0x09, 0x0A,        //   Usage (Button 10) - RT
  0x09, 0x0B,        //   Usage (Button 11) - Select
  0x09, 0x0C,        //   Usage (Button 12) - Start
  0x15, 0x00,        //   Logical Minimum (0)
  0x25, 0x01,        //   Logical Maximum (1)
  0x75, 0x01,        //   Report Size (1)
  0x95, 0x0A,        //   Report Count (10)
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

  // Axes: LX, LY, RX, RY
  0x05, 0x01,        //   Usage Page (Generic Desktop)
  0x09, 0x30,        //   Usage (X)
  0x09, 0x31,        //   Usage (Y)
  0x09, 0x33,        //   Usage (Rx)
  0x09, 0x34,        //   Usage (Ry)
  0x15, 0x81,        //   Logical Minimum (-127)
  0x25, 0x7F,        //   Logical Maximum (127)
  0x75, 0x08,        //   Report Size (8)
  0x95, 0x04,        //   Report Count (4)
  0x81, 0x02,        //   Input (Data, Var, Abs)

  0xC0               // End Collection
};

uint8_t Gamepad::hatFromDpad(bool n, bool s, bool e, bool w) {
  if (n && e) return 2;
  if (n && w) return 8;
  if (s && e) return 4;
  if (s && w) return 6;
  if (n) return 1;
  if (e) return 3;
  if (s) return 5;
  if (w) return 7;
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

void Gamepad::sendReport(Buttons& buttons, Joystick& leftStick) {
  if (!_hid.ready()) return;

  _report.buttons = 0;
  if (buttons.rightS) _report.buttons |= (1 << 0);
  if (buttons.rightE) _report.buttons |= (1 << 1);
  if (buttons.rightW) _report.buttons |= (1 << 2);
  if (buttons.rightN) _report.buttons |= (1 << 3);

  _report.hat = hatFromDpad(buttons.leftN, buttons.leftS,
                            buttons.leftE, buttons.leftW);

  _report.rx = -leftStick.x;
  _report.ry = -leftStick.y;
  _report.lx = 0;
  _report.ly = 0;

  _hid.sendReport(0, &_report, sizeof(_report));
}
