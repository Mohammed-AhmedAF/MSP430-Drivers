#include <msp430.h> 
#include "STD_TYPES.h"
#include "Macros.h"

void UART_vidInit() {
    P3SEL |= BIT3+BIT4;                       // P3.3,4 = USCI_A0 TXD/RXD
/*UART init*/
      UCA0CTL1 |= UCSWRST;                      // **Put state machine in reset**
      UCA0CTL1 |= UCSSEL_2;                     // SMCLK
      UCA0BR0 = 9;                              // 1MHz 115200 (see User's Guide)
      UCA0BR1 = 0;                              // 1MHz 115200
      UCA0MCTL |= UCBRS_1 + UCBRF_0;            // Modulation UCBRSx=1, UCBRFx=0
      UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
      UCA0IE |= UCRXIE;                         // Enable USCI_A0 RX interrupt


}

volatile u8 u8ReceivedByte = ' ';

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

	P1DIR |= (1<<2);

	UART_vidInit();

	
    __bis_SR_register(LPM0_bits + GIE);       // Enter LPM0, interrupts enabled

    while(1)
    {


    }

}

#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void)
{
  switch(__even_in_range(UCA0IV,4))
  {
  case 0:break;                             // Vector 0 - no interrupt
  case 2:                                   // Vector 2 - RXIFG
    while (!(UCA0IFG&UCTXIFG));             // USCI_A0 TX buffer ready?
    u8ReceivedByte = UCA0RXBUF;
    if (u8ReceivedByte == 'a')
                       {
                            u8ReceivedByte = ' ';
                           P1OUT ^= (1<<2);
                       }
    UCA0TXBUF = UCA0RXBUF;                  // TX -> RXed character
    break;
  case 4:break;                             // Vector 4 - TXIFG
  default: break;
  }
}
