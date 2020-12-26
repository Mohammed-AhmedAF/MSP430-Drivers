#include <msp430.h> 
#include "Macros.h"
#include "STD_TYPES.h"
#include "GPIO_interface.h"


volatile u8 u8LEDID = 0;

void vidToggleLED(void)
{
    GPIO_vidTogglePinValue(GPIO_PORT3,u8LEDID);
}

void vidSwitchLEDs(void)
{
    u8LEDID++;
    if (u8LEDID == 3)
    {
        u8LEDID = 0;
    }
}

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	/*Configuring direction of LEDs*/
	GPIO_vidSetPinDirection(GPIO_PORT3, GPIO_PIN0, GPIO_DIR_OUT);
	GPIO_vidSetPinDirection(GPIO_PORT3, GPIO_PIN1, GPIO_DIR_OUT);
	GPIO_vidSetPinDirection(GPIO_PORT3, GPIO_PIN2, GPIO_DIR_OUT);


	/*Configuring left button P2.1*/
	GPIO_vidSetPinDirection(GPIO_PORT2, GPIO_PIN1,GPIO_DIR_IN);
	GPIO_vidSetPinResisPullUpDown(GPIO_PORT2, GPIO_PIN1, GPIO_RES_ENABLE);
	/*Selecting pull-up*/
	GPIO_vidSetPinValue(GPIO_PORT2, GPIO_PIN1, STD_HIGH);

	/*Interrupt Configuration*/
	GPIO_vidConfigPinInterrupt(GPIO_PORT2, GPIO_PIN1, GPIO_EDGE_HL);
	GPIO_vidEnablePinInterrupt(GPIO_PORT2,GPIO_PIN1);

	GPIO_vidPutISRFunction(GPIO_EXTIN_P2, vidSwitchLEDs);

	/*Configuring right button P1.1*/
	GPIO_vidSetPinDirection(GPIO_PORT1, GPIO_PIN1,GPIO_DIR_IN);
	GPIO_vidSetPinResisPullUpDown(GPIO_PORT1, GPIO_PIN1, GPIO_RES_ENABLE);

	/*Selecting pull-up*/
	GPIO_vidSetPinValue(GPIO_PORT1,GPIO_PIN1,STD_HIGH);

	/*Interrupt Configuration*/
	GPIO_vidConfigPinInterrupt(GPIO_PORT1, GPIO_PIN1, GPIO_EDGE_HL);
	GPIO_vidEnablePinInterrupt(GPIO_PORT1, GPIO_PIN1);

    GPIO_vidPutISRFunction(GPIO_EXTIN_P1, vidToggleLED);

	__bis_SR_register(GIE);
	while(1);


}
