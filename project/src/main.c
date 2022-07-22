#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  configureClocks();
  led_init();
  enableWDTInterrupts();

  or_sr(0x18);
}
