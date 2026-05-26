#include "joystick.h"
#include <math.h>

void Joystick::begin(int pinX, int pinY) {
  _pinX = pinX;
  _pinY = pinY;
  pinMode(_pinX, INPUT);
  pinMode(_pinY, INPUT);
}

void Joystick::calibrate() {
  long sumX = 0, sumY = 0;
  for (int i = 0; i < 16; i++) {
    sumX += analogRead(_pinX);
    sumY += analogRead(_pinY);
    delay(2);
  }
  _centerX = sumX / 16;
  _centerY = sumY / 16;
}

int8_t Joystick::mapAxis(int raw, int minVal, int center, int maxVal) {
  int offset = raw - center;
  if (abs(offset) < _deadZone) return 0;

  int mapped;
  if (offset > 0) {
    mapped = map(offset, _deadZone, maxVal - center, 0, 127);
  } else {
    mapped = map(offset, minVal - center, -_deadZone, -127, 0);
  }

  return constrain(mapped, -127, 127);
}

void Joystick::update() {
  int rawX = mapAxis(analogRead(_pinX), _minX, _centerX, _maxX);
  int rawY = mapAxis(analogRead(_pinY), _minY, _centerY, _maxY);

  float mag = sqrtf((float)(rawX * rawX + rawY * rawY));
  if (mag > 127.0f) {
    float scale = 127.0f / mag;
    rawX = (int)(rawX * scale);
    rawY = (int)(rawY * scale);
  }

  x = rawX;
  y = rawY;
}
