#include "debug_logger.h"

void DebugLogger::begin() {
  Serial.begin(115200);
}

void DebugLogger::logButtons(Buttons& buttons) {
  if (buttons.leftN)  Serial.println("LEFT_N");
  if (buttons.leftE)  Serial.println("LEFT_E");
  if (buttons.leftS)  Serial.println("LEFT_S");
  if (buttons.leftW)  Serial.println("LEFT_W");
  if (buttons.rightN) Serial.println("RIGHT_N");
  if (buttons.rightE) Serial.println("RIGHT_E");
  if (buttons.rightS) Serial.println("RIGHT_S");
  if (buttons.rightW) Serial.println("RIGHT_W");
}
