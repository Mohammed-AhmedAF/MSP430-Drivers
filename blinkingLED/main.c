#include <msp430.h>
#include "Macros.h"
#include "STD_TYPES.h"
#include "TIMERA0_interface.h"

void delayMS(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {

    }
}

volatile u8 u8Count = 0;
void vidBlink(void)
{

    P1OUT ^= BIT0;

    }

/**
 * main.c
 */
int main(void)
{
    TA0CCTL0 = CCIE; // CCR0 interrupt enabled

	 WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	 P1DIR |= BIT0; // Set P1.0 to output and P1.3 to input direction
	 P1OUT &= BIT0; // set P1.0 to Off


	 TIMERA0_vidInit();

	 TIMERA0_vidPutISRFunction(vidBlink);
	  _BIS_SR(CPUOFF + GIE);

	 while(1) {
	 }
	return 0;
}

