#include "Arduino.h"
#include "commands.h"
#include "morse.h"
#include "leds.h"

bool morseMode = false;

void showMenu() {
  Serial.println();
  Serial.println("Navigator Beacon");
  Serial.println("----------------");
  Serial.println("help");
  Serial.println("sos");
  Serial.println("red");
  Serial.println("green");
  Serial.println("blue");
  Serial.println("status");
  Serial.println();
}

void enableMorseInput() {
  Serial.println("Type in text you want to tranlsate into Morse Code.");
  Serial.println("Type exit to disable Morse translation");
  morseMode = true;
}

void disableMorseInput() {
  Serial.println("Morse Translation Disabled");
  morseMode = false;
}

void executeCommand(String cmd) {
  if (cmd == "sos") {
    sendSOS();
  } else if (cmd == "morse") {
    enableMorseInput();
  } else if (cmd == "help") {
    showMenu();
  } else if (cmd == "red") {
    setLEDColor(LED_RED);
  } else if (cmd == "green") {
    setLEDColor(LED_GREEN);
  } else if (cmd == "blue") {
    setLEDColor(LED_BLUE);
  } else if (cmd == "status") {
    Serial.println("System OK");
  } else {
    Serial.println("Unknown command");
  }
}

void translateMorseInput(String input) {
  if (input == "exit") {
    disableMorseInput();
  } else {
    sendMorse(input);
  }
}

void processCommands() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (morseMode) {
      Serial.println("Morse Mode Active");
      translateMorseInput(cmd);
    } else {
      executeCommand(cmd);
    }
  }
}