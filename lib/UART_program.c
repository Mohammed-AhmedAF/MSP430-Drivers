#include "msp430.h"
#include "Macros.h"
#include "STD_TYPES.h"
#include "UART_interface.h"

/*Array of pointer to functions used in callback*/
void (*arrPtrFun[4]) (void);

void UART_vidInit(void) {
      P3SEL |= BIT3+BIT4;                       // P3.3,4 = USCI_A0 TXD/RXD
      UCA0CTL1 |= UCSWRST;                      // **Put state machine in reset**
      UCA0CTL1 |= UCSSEL_2;                     // SMCLK
      UCA0BR0 = 104;                              // 12MHz 115200 (see User's Guide)
      UCA0BR1 = 0;                              // 12MHz 115200
      UCA0MCTL |= UCBRS_1 + UCBRF_0;            // Modulation UCBRSx=1, UCBRFx=0
      UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
      UCA0IE |= UCRXIE;                         // Enable USCI_A0 RX interrupt
}

void UART_vidEnableInterrupt(u8 u8InterruptID)
{
    switch(u8InterruptID)
    {
    case UART_INTERRUPT_TRANS_COMPLETE:
        SET_BIT(UCA0IE,3);
        break;
    case UART_INTERRUPT_STARTBIT:
        SET_BIT(UCA0IE,2);
        break;
    case UART_INTERRUPT_TX:
        SET_BIT(UCA0IE,1);
        break;
    case UART_INTERRUPT_RX:
        SET_BIT(UCA0IE,0);
        break;

    }
}


void UART_vidDisableInterrupt(u8 u8InterruptID)
{
    switch (u8InterruptID)
    {
    case UART_INTERRUPT_TRANS_COMPLETE:
        CLEAR_BIT(UCA0IE,3);
        break;
    case UART_INTERRUPT_STARTBIT:
        CLEAR_BIT(UCA0IE,2);
        break;
    case UART_INTERRUPT_TX:
        CLEAR_BIT(UCA0IE,1);
        break;
    case UART_INTERRUPT_RX:
        CLEAR_BIT(UCA0IE,0);
        break;

    }
}

void UART_vidSendByte(u8 u8Byte)
{
    while(!(UCTXIFG));
    UCA0TXBUF = u8Byte;
}

u8 UART_u8GetReceivedByte(void)
{
    return UCA0RXBUF;
}

void UART_vidPutISRFunction(u8 u8InterruptSourceID, void (*ptrFun) (void))
{
    arrPtrFun[u8InterruptSourceID] = ptrFun;
}

#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void)
{
  switch(__even_in_range(UCA0IV,4))
  {
  case 0:break;                             // Vector 0 - no interrupt
  case 2:                                   // Vector 2 - RXIFG
    while (!(UCA0IFG&UCTXIFG));             // USCI_A0 TX buffer ready?
    arrPtrFun[UART_RX]();
    break;
  case 4:break;                             // Vector 4 - TXIFG
  default: break;
  }
}
