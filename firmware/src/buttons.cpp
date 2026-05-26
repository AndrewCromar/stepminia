#include "buttons.h"

void Buttons::begin() {
  pinMode(PIN_UP,    INPUT_PULLUP);
  pinMode(PIN_DOWN,  INPUT_PULLUP);
  pinMode(PIN_LEFT,  INPUT_PULLUP);
  pinMode(PIN_RIGHT, INPUT_PULLUP);
  pinMode(PIN_PLUS,  INPUT_PULLUP);
  pinMode(PIN_MINUS, INPUT_PULLUP);
}

void Buttons::update() {
  up    = digitalRead(PIN_UP)    == LOW;
  down  = digitalRead(PIN_DOWN)  == LOW;
  left  = digitalRead(PIN_LEFT)  == LOW;
  right = digitalRead(PIN_RIGHT) == LOW;
  plus  = digitalRead(PIN_PLUS)  == LOW;
  minus = digitalRead(PIN_MINUS) == LOW;
}

bool Buttons::anyPressed() {
  return up || down || left || right || plus || minus;
}
