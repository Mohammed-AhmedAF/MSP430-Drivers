/*
 * TIMERA0_interface.h
 *
 *  Created on: Oct 14, 2020
 *      Author: Mohammed
 */

#ifndef TIMERA0_INTERFACE_H_
#define TIMERA0_INTERFACE_H_

void TIMERA0_vidInit(u8 u8TimerMode,u8 u8ClkSel,u8 u8ClkDivider, u16 u16CounterValue);
void TIMERA0_vidInitCompare(void);
void TIMERA0_vidClearTimer(void);
void TIMERA0_vidEnableInterrupt(u8 u8InterruptID);
void TIMERA0_vidDisableInterrupt(u8 u8InterruptID);
void TIMERA0_vidPutISRFunction(void (*ptF) (void));

/*Macro definitions*/
#define TIMERA0_MODE_STOP 0
#define TIMERA0_MODE_UP 1
#define TIMERA0_MODE_CONTINUOUS 2
#define TIMERA0_MODE_UPDOWN 3

#define TIMERA0_CLKSEL_TA0CLK 0
#define TIMERA0_CLKSEL_AUX 1
#define TIMERA0_CLKSEL_SM 2
#define TIMERA0_CLKSEL_IN 3

#define TIMERA0_CLKDIV_1 0
#define TIMERA0_CLKDIV_2 1
#define TIMERA0_CLKDIV_4 2
#define TIMERA0_CLKDIV_8 3

/*Defining interrupt IDs*/
#define TIMERA0_INTERRUPT_TAIFG 0
#define TIMERA0_INTERRUPT_CAPCOMP0 1
#define TIMERA0_INTERRUPT_CAPCOMP1 2
#define TIMERA0_INTERRUPT_CAPCOMP2 2


#endif /* TIMERA0_INTERFACE_H_ */
