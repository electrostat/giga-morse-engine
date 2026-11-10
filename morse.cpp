#include "Arduino.h"
#include "leds.h"
#include "morse.h"
#include "morse_translator.h"

void initMorse() {
  setLEDColor(LED_RED);
}

void dot() {
  flashLED(200);
}

void dash() {
  flashLED(600);
}

void flashMorseCode(char c) {
  if (c == '-') {
    dash();
  } else if (c == '.') {
    dot();
  } else if (c == '|') {
    delay(500);
  } else {
    Serial.println("Unrecognized Char");
  }
}

void sendSOS() {
  Serial.println("sending SOS...");
  String sos = translateIntoMorse("sos");

  for (char & c: sos) { 
    flashMorseCode(c);
  }

  Serial.println("SOS Finished");
}

void sendMorse(String input) {
  String output = translateIntoMorse(input);

  Serial.println(output);

  for (char & c: output) { 
    flashMorseCode(c);
  }

  Serial.println("Morse Code Sent");
}