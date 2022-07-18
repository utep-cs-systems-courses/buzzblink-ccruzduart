//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);		/* CPU off, GIE on */
}

void greenControl(int on)         //  in charge of turning on the green led
{
  if (on) {
    P1OUT |= LED_GREEN;
  } else {
    P1OUT &= ~LED_GREEN;
  }
}

// blink state machine
static int blinkLimit = 5;   //  state var representing reciprocal of duty cycle 
void blinkUpdate() // called every 1/250s to blink with duty cycle 1/blinkLimit
{
  static int blinkCount = 0; // state var representing blink state
  blinkCount ++;
  if (blinkCount >= blinkLimit) { // the light well be on when the blinkCount is equal to the limit
    blinkCount = 0;               // being off more often as the limit increses well make the light
    greenControl(1);              // dimmer
  } else                          // 
    greenControl(0);
}

void oncePerSecond() // repeatedly start bright and gradually lower duty cycle, one step/sec
{
  blinkLimit ++;  // reduce duty cycle
  if (blinkLimit >= 8)  // but don't let duty cycle go below 1/7.
    blinkLimit = 0;
}

void secondUpdate()  // called every 1/250 sec to call oncePerSecond once per second
{
  static int secondCount = 0; // state variable representing repeating time 0…1s
  secondCount ++;            // a better name could be interruptCount
  if (secondCount >= 250) { // once each second or every 250 interrupts 
    secondCount = 0;       // resets the state variable
    oncePerSecond();
  } }

void timeAdvStateMachines() // called every interrupt,250 times per sec
{
  blinkUpdate();
  secondUpdate();
}


void __interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts every sec */
{
  // handle blinking   
  timeAdvStateMachines();
} 

