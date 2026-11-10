#include "Arduino.h"
#include "commands.h"
#include "morse.h"

void setup() {
  Serial.begin(115200);

  while (!Serial) {
    delay(10);
  }

  initMorse();
  showMenu();
}

void loop() {
  processCommands();
}