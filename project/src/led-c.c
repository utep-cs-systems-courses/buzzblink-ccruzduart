#include <msp430.h>
#include "led.h"

void led_init() {
  P1DIR |= LEDS;
}

void led_update(int off) {
  if (off) {
    P1OUT &= ~LED_RED;
    P1OUT |= LED_GREEN;
    off = 0;
  } else {
    P1OUT |= LED_RED;
    P1OUT &= ~LED_GREEN;
    off = 1;
  }
}
void toggle_red(int on) {
  if(on) {
    P1OUT |= LED_RED;
  } else {
    P1OUT &= ~LED_RED;
  }
}

void toggle_green(int on) {
  if(on) {
    P1OUT |= LED_GREEN;
  } else {
    P1OUT &= ~LED_GREEN;
  }
}

