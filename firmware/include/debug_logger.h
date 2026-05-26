#pragma once

#include "buttons.h"

class DebugLogger {
public:
  void begin();
  void logButtons(Buttons& buttons);
};
