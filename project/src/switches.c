#include <msp430.h>
#include "switches.h"
#include "led.h"

static char switch_update_interrupt_sense() {         // detects when a button is being press
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);                        // Switch up, sense down 
  P2IES &= (p2val | ~SWITCHES);                       // switch down, sense up
  return p2val;
}

void switch_init() {                                  // initialize switches
  P2REN |= SWITCHES;                                  // enables resistors
  P2IE |= SWITCHES;                                   // enables interrupts
  P2OUT |= SWITCHES;                                  // switches pull ups
  P2DIR &= ~SWITCHES;                                 // set switches bits for input
}

void switch_interrupt_handler() {                    //handle state when button is press
  char p2val = switch_update_interrupt_sense();

  if((p2val & SW1) == 0) stateVal = 1;               // switch 1 -> state 1
  else if ((p2val & SW2) == 0) stateVal = 2;         // switch 2 -> state 2
  else if ((p2val & SW3) == 0) stateVal = 3;         // switch 3 -> state 3
  else if ((p2val & SW4) == 0) stateVal = 4;         // switch 4 -> state 4
}

void __interrupt_vec(PORT2_VECTOR) Port_2() {        //switch interrupts on P2
  if(P2IFG & SWITCHES) {                             //sense botton press
    P2IFG &= ~SWITCHES;                              //end last switch interrupts
    switch_interrupt_handler();
  }
}
