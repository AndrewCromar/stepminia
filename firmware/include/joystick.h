#pragma once

#include <Arduino.h>

class Joystick {
public:
  int8_t x = 0;
  int8_t y = 0;

  void begin(int pinX, int pinY);
  void update();
  void calibrate();

private:
  int _pinX;
  int _pinY;
  int _centerX = 512;
  int _centerY = 512;
  int _minX = 5;
  int _maxX = 1023;
  int _minY = 5;
  int _maxY = 1023;
  int _deadZone = 30;

  int8_t mapAxis(int raw, int minVal, int center, int maxVal);
};
