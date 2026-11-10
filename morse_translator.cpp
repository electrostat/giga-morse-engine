#include "Arduino.h"
#include "morse_translator.h"
#include "morse.h"

struct MorseMap {
    char character;
    const char* code;
};

const struct MorseMap morseTable[] = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."}
};

const int TABLE_SIZE = sizeof(morseTable) / sizeof(morseTable[0]);

// Function to look up Morse code by character
const char* getMorseCode(char c) {
  c = toupper(c);
  for (int i = 0; i < TABLE_SIZE; i++) {
      if (morseTable[i].character == c) {
          return morseTable[i].code;
      }
  }
  return "NULL"; // Not found
}

String translateIntoMorse(String input) {
  Serial.println("translating...");
  String output = "";
  for (char & c: input) {
    output = output + "|" + getMorseCode(c);
  }

  return output;
}

