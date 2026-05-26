#include <Arduino.h>
#include "buttons.h"
#include "debug_logger.h"
#include "gamepad.h"

Buttons buttons;
DebugLogger logger;
Gamepad gamepad;

void setup() {
  logger.begin();
  buttons.begin();
  gamepad.begin();
}

void loop() {
  buttons.update();
  gamepad.sendReport(buttons);
  logger.logButtons(buttons);
  delay(10);
}
