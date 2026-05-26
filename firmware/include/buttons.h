#pragma once

#include <Arduino.h>
#include "pins.h"

class Buttons {
public:
  bool up    = false;
  bool down  = false;
  bool left  = false;
  bool right = false;
  bool plus  = false;
  bool minus = false;

  void begin();
  void update();
  bool anyPressed();
};
