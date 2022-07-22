#include <msp430.h>
#include "led.h"

int secondCount = 0;
void __interrupt_vec(WDT_VECTOR) WDT() {
  if(++secondCount >= 250) {
    led_update();
    secondCount = 0;
  }
}
