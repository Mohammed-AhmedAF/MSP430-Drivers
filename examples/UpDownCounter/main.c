#include "Macros.h"
#include "STD_TYPES.h"
#include <msp430.h> 
#include "GPIO_interface.h"
#include "LCD_interface.h"
#include "TIMERA0_interface.h"

#define COUNTER_UP 0
#define COUNTER_DOWN 1


volatile u16 u16OVFCount = 0;
volatile u16 u16Count = 0;
volatile u8 u8CountDirection = 0;

void vidCount(void)
{
    u16OVFCount++;
    if (u16OVFCount == 1000)
    {
        u16OVFCount = 0;
        if (u8CountDirection == COUNTER_UP)
        {
            u16Count++;
        }
        else
        {
            if (u16Count == 1)
            {
                u8CountDirection = COUNTER_UP;
            }
            u16Count--;

        }
        GPIO_vidTogglePinValue(GPIO_PORT4,GPIO_PIN7);
        LCD_vidSendCommand(LCD_CLEAR_SCREEN);
        LCD_vidSendCommand(LCD_RETURN_HOME);
        LCD_vidGoToXY(3,0);
        LCD_vidWriteNumber(u16Count);
    }
}

void vidResetCount (void)
{
    u16Count = 0;
}

void vidChangeCountDirection (void) {
    if (u8CountDirection == COUNTER_UP)
    {
        u8CountDirection = COUNTER_DOWN;
    }
    else
    {
        u8CountDirection = COUNTER_UP;
    }
}


int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	//Stop timer
	
	GPIO_vidSetPinDirection(GPIO_PORT4, GPIO_PIN7, GPIO_DIR_OUT);


	TIMERA0_vidInit(TIMERA0_MODE_UP, TIMERA0_CLKSEL_SM, TIMERA0_CLKDIV_1, 1000);
	TIMERA0_vidPutISRFunction(vidCount);
	TIMERA0_vidEnableInterrupt(TIMERA0_INTERRUPT_TAIFG);

	GPIO_vidPutISRFunction(GPIO_EXTIN_P1,vidChangeCountDirection);
	GPIO_vidPutISRFunction(GPIO_EXTIN_P2,vidResetCount);

	/*Input P2.1*/
    P2DIR &= (0 << 1);
    P2REN |= (1 << 1);

    /*Pull up selected*/
    P2OUT |= (1 << 1);

    /*Enabling interrupt*/
    P2IES |= (1 << 1); /*High to low transition*/

    P2IE |= (1 << 1);

    /*Right button P1.1*/
    P1DIR &= (0 << 1);

    /*Enabling pullup/down unlock*/
    P1REN = (1 << 1);

    /*Pull up enabled on pin P1.1*/
    P1OUT |= (1 << 1);

    /*High to low transition*/
    P1IES |= (1 << 1);

    /*Enabling interrupt*/
    P1IE |= (1 << 1);

	LCD_vidInit();

	__bis_SR_register(GIE);
	while(1);

}

