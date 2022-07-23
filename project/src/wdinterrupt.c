#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "states.h"
#include "buzzer.h"

char stateVal = 0;
int secondCount = 0;
void __interrupt_vec(WDT_VECTOR) WDT() {
  secondCount++;
  if (stateVal == 0) {                      //state 0
    toggle_red(0);                          // initialize state everything off
    toggle_green(0);
    buzzerOff();
    if (secondCount >= 250) {
      secondCount = 0;
    }
  }
  
  if (stateVal == 1) {                      //state 1 
    if (secondCount >= 250) {               // turn green on and red off and switch them
      led_update();
      secondCount = 0;
    }
    buzzerOff();
  }
  else if (stateVal == 2) {
    dimLeds();                             //state 2
    if (secondCount >= 250) {              // red bright to dim
      secondCount = 0;                     // green dim to bright
      dimLimitControl();
    }
    buzzerOff();
  }
  else if (stateVal == 3) {               //state 3
    buzzer_set_period();                  // siren from high pitch to low and back to high
    toggle_red(0);                        // leds off
    toggle_green(0);
    if (secondCount >= 125) {
      secondCount = 0;
      updateCycles();
    }
  }
  else if (stateVal == 4) {               //state 4

    songOfHealing();
    /*dimLeds();                            // siren with high to low
    buzzer_set_period();                  // but not jumping going back slowly
    if (secondCount >= 125) {             // with state 2 leds combine
      secondCount = 0;
      dimLimitControl();
      updateCyclesFaster();
      }*/
  }
}
