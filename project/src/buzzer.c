#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init() {
  timerAUpmode();                        // used to drive speaker
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

short cycles = 1000;
void buzzer_set_period() {
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void updateCycles() {
  cycles += 150;
  if (cycles >= 2000)
    cycles = 500;
}

void buzzerOff(){
  CCR0 = 1;
}

int siren = 0;
void updateCyclesFaster() {
  if (siren)
    cycles -= 250;
  else
    cycles += 250;
  
  if ( cycles >= 6000)
    siren = 1; 
  if ( cycles <= 3000)
      siren = 0;
}

void buzzer_set_period2(short cycles2) {
  CCR0 = cycles2;
  CCR1 = cycles2 >>1;
}
