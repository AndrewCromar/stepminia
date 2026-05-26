#include "debug_logger.h"

void DebugLogger::begin() {
  Serial.begin(115200);
}

void DebugLogger::logButtons(Buttons& buttons) {
  if (buttons.up)    Serial.println("UP");
  if (buttons.down)  Serial.println("DOWN");
  if (buttons.left)  Serial.println("LEFT");
  if (buttons.right) Serial.println("RIGHT");
  if (buttons.plus)  Serial.println("PLUS");
  if (buttons.minus) Serial.println("MINUS");
}
