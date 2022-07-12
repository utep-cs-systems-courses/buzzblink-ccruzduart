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
  
  or_sr(0x18);			/* CPU off, GIE on */
}

// global state var to count time
int secondCount = 0;
int ledState = 0;
void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  secondCount ++;
  if (secondCount >= 125) { 	/* once each sec... */
                                /*by changing the 250 to a smaller number we can make it faster
				  to making it twice as fast we set it to 125*/
    secondCount = 0;		/* reset count */
    switch (ledState) {         /* by creating a switch case we can alternate from red to green*/
	case 0:
	  P1OUT |= LED_GREEN;		/* toggle green LED */
	  P1OUT &= ~LED_RED;
	  ledState = 1;
	  break;
    case 1:
      P1OUT |= LED_RED;
      P1OUT &= ~LED_GREEN;
      ledState = 0;
      break;
      
    }
  }
} 

