#include "keyboard_input.h"
#include <string.h>

static uint8_t const desc_hid_report[] = {
  TUD_HID_REPORT_DESC_KEYBOARD()
};

void KeyboardInput::begin() {
  _hid.setPollInterval(2);
  _hid.setReportDescriptor(desc_hid_report, sizeof(desc_hid_report));
  _hid.begin();

  while (!TinyUSBDevice.mounted()) {
    delay(1);
  }
}

void KeyboardInput::update(Buttons& buttons) {
  if (!_hid.ready()) return;

  uint8_t keycodes[6] = {0, 0, 0, 0, 0, 0};
  uint8_t i = 0;
  if (buttons.up)    keycodes[i++] = HID_KEY_ARROW_UP;
  if (buttons.down)  keycodes[i++] = HID_KEY_ARROW_DOWN;
  if (buttons.left)  keycodes[i++] = HID_KEY_ARROW_LEFT;
  if (buttons.right) keycodes[i++] = HID_KEY_ARROW_RIGHT;
  if (buttons.plus)  keycodes[i++] = HID_KEY_ENTER;
  if (buttons.minus) keycodes[i++] = HID_KEY_ESCAPE;

  if (memcmp(keycodes, _lastKeycodes, 6) != 0) {
    _hid.keyboardReport(0, 0, keycodes);
    memcpy(_lastKeycodes, keycodes, 6);
  }
}
