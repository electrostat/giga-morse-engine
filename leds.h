#ifndef LEDS_H
#define LEDS_H

extern PinName led_color;

void setLEDColor(PinName led);
void flashLED(long time);

#endif