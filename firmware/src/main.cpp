#include <Arduino.h>
#include "buttons.h"
#include "joystick.h"
#include "debug_logger.h"
#include "gamepad.h"

Buttons buttons;
Joystick rightStick;
DebugLogger logger;
Gamepad gamepad;

void setup() {
  logger.begin();
  buttons.begin();
  rightStick.begin(PIN_JOY_LX, PIN_JOY_LY);
  rightStick.calibrate();
  gamepad.begin();
}

void loop() {
  buttons.update();
  rightStick.update();
  gamepad.sendReport(buttons, rightStick);
  logger.logButtons(buttons);
  delay(10);
}
