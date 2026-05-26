#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include "buttons.h"
#include "debug_logger.h"
#include "keyboard_input.h"

Buttons buttons;
DebugLogger logger;
KeyboardInput keyboard;

void setup() {
  TinyUSBDevice.setManufacturerDescriptor("Andrew Cromar");
  TinyUSBDevice.setProductDescriptor("Stepminia");

  logger.begin();
  buttons.begin();
  keyboard.begin();
}

void loop() {
  buttons.update();
  keyboard.update(buttons);
  logger.logButtons(buttons);
  delay(10);
}
