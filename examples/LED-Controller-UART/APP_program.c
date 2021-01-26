#include "msp430.h"
#include "Macros.h"
#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "TIMERA0_interface.h"
#include "UART_interface.h"
#include "APP_interface.h"


/*Count the number of overflows*/
volatile u16 u16OVFCount = 0;
volatile u8 u8Byte = 0;
volatile u8 u8index = 0;
volatile u8 u8MessageArray[MESSAGESIZE];
volatile u8 u8TimeArr[6];
/*Flag that is toggled when a second passes*/
volatile u8 u8SecFlag = 0;

void APP_vidInit(void)
{

    /*Configure GPIO pins*/
    GPIO_vidSetPinDirection(GPIO_PORT1,GPIO_PIN2,GPIO_DIR_OUT);
    GPIO_vidSetPinDirection(GPIO_PORT1,GPIO_PIN3,GPIO_DIR_OUT);
    GPIO_vidSetPinDirection(GPIO_PORT1,GPIO_PIN4,GPIO_DIR_OUT);
    GPIO_vidSetPinDirection(GPIO_PORT1,GPIO_PIN5,GPIO_DIR_OUT);

    GPIO_vidSetPinValue(GPIO_PORT1,GPIO_PIN2,STD_LOW);
    GPIO_vidSetPinValue(GPIO_PORT1,GPIO_PIN3,STD_LOW);
    GPIO_vidSetPinValue(GPIO_PORT1,GPIO_PIN4,STD_LOW);
    GPIO_vidSetPinValue(GPIO_PORT1,GPIO_PIN5,STD_LOW);


    /*Timer init*/
    TIMERA0_vidInit(TIMERA0_MODE_UP, TIMERA0_CLKSEL_SM, TIMERA0_CLKDIV_1, 65535);
    TIMERA0_vidEnableInterrupt(TIMERA0_INTERRUPT_TAIFG);
    TIMERA0_vidPutISRFunction(APP_vidCountOneSec);

    /*Init UART*/
    UART_vidInit();
    UART_vidPutISRFunction(UART_RX, APP_vidReceiveControlFrame);

    /*Enable global interrupt*/
    __bis_SR_register(GIE);

}

void APP_vidReceiveControlFrame(void)
{
    /*Get received bytes*/
    u8Byte = UART_u8GetReceivedByte();
    u8MessageArray[u8index] = u8Byte;
    u8index++;
    /*Check if the number of bytes received equals the message size*/
    if (u8index == MESSAGESIZE)
    {
        u8index = 0;
        if (u8MessageArray[0] == 'a')
        {
            GPIO_vidTogglePin(GPIO_PORT1,GPIO_PIN2);
            u8TimeArr[2] = u8MessageArray[1];
        }
        else if (u8MessageArray[0] == 'b')
        {
            GPIO_vidTogglePin(GPIO_PORT1,GPIO_PIN3);
            u8TimeArr[3] = u8MessageArray[1];
        }
        else if (u8MessageArray[0] == 'c')
        {
            GPIO_vidTogglePin(GPIO_PORT1,GPIO_PIN4);
            u8TimeArr[4] = u8MessageArray[1];
        }
        else if (u8MessageArray[0] == 'd')
        {
            GPIO_vidTogglePin(GPIO_PORT1,GPIO_PIN5);
            u8TimeArr[5] = u8MessageArray[1];
        }
        /*Toggling only*/
        else if (u8MessageArray[0] == 'A')
        {
            GPIO_vidTogglePin(GPIO_PORT1,GPIO_PIN2);
        }
        else if (u8MessageArray[0] == 'B')
        {
            GPIO_vidTogglePin(GPIO_PORT1,GPIO_PIN3);
        }
        else if (u8MessageArray[0] == 'C')
        {
            GPIO_vidTogglePin(GPIO_PORT1,GPIO_PIN4);
        }
        else if (u8MessageArray[0] == 'D')
        {
            GPIO_vidTogglePin(GPIO_PORT1,GPIO_PIN5);
        }

    }
}

void APP_vidCountOneSec(void)
{
    u16OVFCount++;
    if (u16OVFCount == SECOND_OVF)
    {
        u8SecFlag = 1;
        u16OVFCount = 0;
    }
}


void APP_vidControl(void)
{
    if (u8SecFlag == 1)
    {
    u8 u8LEDIndex = 0;
    for (u8LEDIndex = 2; u8LEDIndex < 6; u8LEDIndex++)
    {
        u8TimeArr[u8LEDIndex] -= 1;
        if (u8TimeArr[u8LEDIndex] == 0)
        {
            GPIO_vidSetPinValue(GPIO_PORT1,u8LEDIndex,STD_LOW);
        }



    }
    u8SecFlag = 0;
    }
}
