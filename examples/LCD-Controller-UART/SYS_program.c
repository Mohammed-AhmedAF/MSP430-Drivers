/*
 * SYS_program.c
 *
 *  Created on: Dec 13, 2020
 *      Author: Mohammed
 */

#include "driverlib.h"

#define UCS_MCLK_FREQ 12000
#define UCS_MCLK_FLLREF_RATIO 366

unsigned long mclk = 0;
unsigned long smclk = 0;
unsigned long aclk = 0;


void vidInitSystemClock(void)
{



    UCS_initClockSignal(UCS_FLLREF, UCS_REFOCLK_SELECT, UCS_CLOCK_DIVIDER_1);


    UCS_initFLLSettle(UCS_MCLK_FREQ, UCS_MCLK_FLLREF_RATIO);
    mclk = UCS_getMCLK();
    smclk = UCS_getSMCLK();
    aclk = UCS_getACLK();

}
