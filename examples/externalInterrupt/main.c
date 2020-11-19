#include <msp430.h> 


void initLeftBtnInterrupt(void)
{
    /*Configuring LEDs*/
        P1DIR |= (1<<0);
        P1OUT &= (0<<0);
        P1DS &= (1<<0);
        /*Input P2.1*/
        P2DIR &= (0<<1);
        P2REN |= (1<<1);

        /*Pull up selected*/
        P2OUT |= (1<<1);

        /*Enabling interrupt*/
        P2IES |= (1<<1); /*High to low transition*/

        P2IE |= (1<<1);
}

void initRightInterrupt(void)
{
    P4DIR |= (1<<7);
    P4OUT &= (0<<7);
    /*Right button P1.1*/
    P1DIR &= (0<<1);

    /*Enabling pullup/down unlock*/
    P1REN = (1<<1);

    /*Pull up enabled on pin P1.1*/
    P1OUT |= (1<<1);

    /*Hight to low transition*/
    P1IES |= (1<<1);

    /*Enabling interrupt*/
    P1IE |= (1<<1);

}

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	

	initLeftBtnInterrupt();


	__bis_SR_register(GIE);

	while(1);

}

#pragma vector=PORT2_VECTOR
__interrupt void ISR(void) {
    switch(P2IV) {
    case 0x04:
        P1OUT ^= (1<<0);

    }
}

#pragma vector=PORT1_VECTOR
__interrupt void secondButton(void)
{
    switch(P1IV) {
    case 0x04:
        P4OUT ^= (1<<7);
    }
}
