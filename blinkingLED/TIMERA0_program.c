#include "Macros.h"
#include "STD_TYPES.h"
#include "msp430f5529.h"
#include "TIMERA0_interface.h"

void (*TIMERA0_ptf) (void);

void TIMERA0_vidPutISRFunction(void (*ptF) (void))
{
    TIMERA0_ptf = ptF;
}


void TIMERA0_vidInit(void)
{
   /*Selecting the mode: Continuous*/
   SET_BIT(TA0CTL,4);
   CLEAR_BIT(TA0CTL,5);

   /*Divider*/
   SET_BIT(TA0CTL,6);
   SET_BIT(TA0CTL,7);

   TA0CCR0 = 10000;

   /*Selecting clock*/
   CLEAR_BIT(TA0CTL,8);
   SET_BIT(TA0CTL,9);


}


#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A0 (void)
{
  TIMERA0_ptf();
}
