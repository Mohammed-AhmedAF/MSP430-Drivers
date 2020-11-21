#include "Macros.h"
#include "STD_TYPES.h"
#include "msp430f5529.h"
#include "TIMERA0_interface.h"

void (*TIMERA0_ptf) (void);

void TIMERA0_vidPutISRFunction(void (*ptF) (void))
{
    TIMERA0_ptf = ptF;
}


void TIMERA0_vidInit(u8 u8TimerMode,u8 u8ClkSel, u8 u8ClkDivider, u16 u16CounterValue)
{
   /*Mode Control*/

   switch(u8TimerMode)
   {
   case TIMERA0_MODE_STOP:
       CLEAR_BIT(TA0CTL,4);
       CLEAR_BIT(TA0CTL,5);
       break;
   case TIMERA0_MODE_UP:
       SET_BIT(TA0CTL,4);
       CLEAR_BIT(TA0CTL,5);
       break;
   case TIMERA0_MODE_CONTINUOUS:
       CLEAR_BIT(TA0CTL,4);
       SET_BIT(TA0CTL,5);
       break;
   case TIMERA0_MODE_UPDOWN:
       SET_BIT(TA0CTL,4);
       SET_BIT(TA0CTL,5);
       break;
   }

   /*Divider*/
   switch(u8ClkDivider)
   {
   case TIMERA0_CLKDIV_1:
       CLEAR_BIT(TA0CTL,6);
       CLEAR_BIT(TA0CTL,7);
       break;
   case TIMERA0_CLKDIV_2:
       SET_BIT(TA0CTL,6);
       CLEAR_BIT(TA0CTL,7);
       break;
   case TIMERA0_CLKDIV_4:
       CLEAR_BIT(TA0CTL,6);
       SET_BIT(TA0CTL,7);
       break;
   case TIMERA0_CLKDIV_8:
       SET_BIT(TA0CTL,6);
       SET_BIT(TA0CTL,7);
       break;
   }


   if ((u8TimerMode == TIMERA0_MODE_CONTINUOUS) || (u8TimerMode == TIMERA0_MODE_UP) || (u8TimerMode == TIMERA0_MODE_UPDOWN))
   {
   /*Counter*/
       TA0CCR0 = u16CounterValue;
   }
   /*Selecting clock*/
   switch(u8ClkSel)
   {
   case TIMERA0_CLKSEL_TA0CLK:
       CLEAR_BIT(TA0CTL,8);
       CLEAR_BIT(TA0CTL,9);
       break;
   case TIMERA0_CLKSEL_AUX:
       SET_BIT(TA0CTL,8);
       CLEAR_BIT(TA0CTL,9);
       break;
   case TIMERA0_CLKSEL_SM:
       CLEAR_BIT(TA0CTL,8);
          SET_BIT(TA0CTL,9);
          break;
   case TIMERA0_CLKSEL_IN:
       SET_BIT(TA0CTL,8);
       SET_BIT(TA0CTL,9);
       break;
   }

   TA0CCTL0 = CCIE; // CCR0 interrupt enabled
}


void TIMERA0_vidClearTimer(void)
{
    SET_BIT(TA0CTL,2);
}


#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A0 (void)
{
  TIMERA0_ptf();
}
