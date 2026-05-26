#pragma once

#include <Arduino.h>
#include "pins.h"

class Buttons {
public:
  bool leftN = false;
  bool leftE = false;
  bool leftS = false;
  bool leftW = false;

  bool rightN = false;
  bool rightE = false;
  bool rightS = false;
  bool rightW = false;

  void begin();
  void update();
  bool anyPressed();
};
