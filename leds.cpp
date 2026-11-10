#include "Arduino.h"

PinName led_color = LED_BLUE;
const long led_shutdown = 200;
const long set_flash = 1000;

void flashLED(long time) {
  digitalWrite(led_color, LOW);
  delay(time);

  digitalWrite(led_color, HIGH);
  delay(led_shutdown);
} 

void setLEDColor(PinName led) {
  led_color = led;

  // Mbed's pinMode accepts PinName directly
  pinMode(led_color, OUTPUT);
  Serial.println("LED Color Set");
  flashLED(set_flash);
}