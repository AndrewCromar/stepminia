#include "buttons.h"

void Buttons::begin() {
  pinMode(PIN_LEFT_N, INPUT_PULLUP);
  pinMode(PIN_LEFT_E, INPUT_PULLUP);
  pinMode(PIN_LEFT_S, INPUT_PULLUP);
  pinMode(PIN_LEFT_W, INPUT_PULLUP);

  pinMode(PIN_RIGHT_N, INPUT_PULLUP);
  pinMode(PIN_RIGHT_E, INPUT_PULLUP);
  pinMode(PIN_RIGHT_S, INPUT_PULLUP);
  pinMode(PIN_RIGHT_W, INPUT_PULLUP);
}

void Buttons::update() {
  leftN  = digitalRead(PIN_LEFT_N) == LOW;
  leftE  = digitalRead(PIN_LEFT_E) == LOW;
  leftS  = digitalRead(PIN_LEFT_S) == LOW;
  leftW  = digitalRead(PIN_LEFT_W) == LOW;

  rightN = digitalRead(PIN_RIGHT_N) == LOW;
  rightE = digitalRead(PIN_RIGHT_E) == LOW;
  rightS = digitalRead(PIN_RIGHT_S) == LOW;
  rightW = digitalRead(PIN_RIGHT_W) == LOW;
}

bool Buttons::anyPressed() {
  return leftN || leftE || leftS || leftW ||
         rightN || rightE || rightS || rightW;
}
