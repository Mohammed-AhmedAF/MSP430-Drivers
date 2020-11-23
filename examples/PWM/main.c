#include <msp430.h> 
#include "Macros.h"
#include "STD_TYPES.h"
#include "TIMERA0_interface.h"


void vidBlink(void)
{
    P4OUT ^= (1<<7);
}
/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

	
	P1DIR |= (1<<2);
	P1DIR |= (1<<3);

	/*Selecting peripheral function*/
	P1SEL = (1<<2);
	P1SEL = (1<<3);

	TIMERA0_vidInit(TIMERA0_MODE_UP, TIMERA0_CLKSEL_AUX,TIMERA0_CLKDIV_1, 1000);
	//TIMERA0_vidPutISRFunction(vidBlink);

	__bis_SR_register(CPUOFF+GIE);


	while(1);
}
