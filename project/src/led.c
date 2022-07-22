#include <msp430.h>
#include "led.h"

void led_init() {
  P1DIR |= LEDS;
}

int off = 0;
void led_update() {
  if (off) {
    P1OUT &= ~LED_RED;
    P1OUT &= ~LED_GREEN;
    off = 0;
  } else {
    P1OUT |= LED_RED;
    P1OUT |= LED_GREEN;
    off = 1;
  }
}
