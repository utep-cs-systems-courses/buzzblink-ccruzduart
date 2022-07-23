#include <msp430.h>
#include "led.h"
#include "states.h"
#include "buzzer.h"


int blinkLimitRed = 0, blinkCountRed = 0;
int blinkLimitGreen = 10, blinkCountGreen = 0;
void dimLeds() {
  blinkCountRed ++;
  if (blinkCountRed >= blinkLimitRed) {
    blinkCountRed = 0;
    toggle_red(1);
  } else {
    toggle_red(0);
  }

  blinkCountGreen ++;
  if (blinkCountGreen >= blinkLimitGreen) {
    blinkCountGreen = 0;
    toggle_green(1);
  } else {
    toggle_green(0);
  }
}

void dimLimitControl() {
  blinkLimitRed ++;
  blinkLimitGreen --;
  if (blinkLimitRed >= 10)
    blinkLimitRed = 0;
  if (blinkLimitGreen <= 0)
    blinkLimitGreen = 10;
}

int count = 0;
void songOfHealing() {
  count ++;
  if (count == 125) {
    buzzer_set_period2(tuned/B_4);
    toggle_red(1);
    toggle_green(0);
  }
  if (count == 250) {
    buzzer_set_period2(tuned/A_4);
    toggle_red(0);
    toggle_green(1);
  }
  if (count == 375) {
    buzzer_set_period2(tuned/F_s4);
    toggle_red(1);
    toggle_green(1);
  }
  if (count == 500) {
    buzzer_set_period2(tuned/B_4);
    toggle_red(1);
    toggle_green(0);
  }
  if (count == 625) {
    buzzer_set_period2(tuned/A_4);
    toggle_red(0);
    toggle_green(1);
  }
  if (count == 750) {
    buzzer_set_period2(tuned/F_s4);
    toggle_red(1);
    toggle_green(1);
  }
  if (count == 875) {
    buzzer_set_period2(tuned/B_4);
    toggle_red(1);
    toggle_green(0);
  }
  if (count == 1000) {
    buzzer_set_period2(tuned/A_4);
    toggle_red(0);
    toggle_green(1);
  }
  if (count == 1125) {
    buzzer_set_period2(tuned/E_4);
    toggle_red(1);
    toggle_green(1);
  }
  if (count == 1189) {
    buzzer_set_period2(tuned/D_4);
    toggle_red(0);
    toggle_green(0);
  }
  if (count == 1250) {
    buzzer_set_period2(tuned/E_4);
    toggle_red(1);
    toggle_green(1);
  }
  if (count == 1500) {
    count = 0;
    toggle_red(0);
    toggle_green(0);
  }
}
