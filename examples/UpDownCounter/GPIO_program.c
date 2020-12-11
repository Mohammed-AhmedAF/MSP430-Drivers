/*
 * GPIO_program.c
 *
 *  Created on: Nov 24, 2020
 *      Author: Mohammed
 */

#include <msp430.h>
#include "Macros.h"
#include "STD_TYPES.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"

void (*ExtInt[5]) (void);

void GPIO_vidSetPinDirection(u8 u8PortNumber, u8 u8PinNumber, u8 u8Direction)
{
   switch (u8PortNumber) {
   case GPIO_PORT1:
       if (u8Direction == GPIO_DIR_OUT)
       {
           SET_BIT(PORT1DIR,u8PinNumber);
       }
       else
       {
           CLEAR_BIT(PORT1DIR,u8PinNumber);
       }
       break;
   case GPIO_PORT2:
       if (u8Direction == GPIO_DIR_OUT)
              {
                  SET_BIT(P2DIR,u8PinNumber);
              }
              else
              {
                  CLEAR_BIT(P2DIR,u8PinNumber);
              }
       break;
   case GPIO_PORT3:
       if (u8Direction == GPIO_DIR_OUT)
              {
                  SET_BIT(P3DIR,u8PinNumber);
              }
       else
       {
                 CLEAR_BIT(P3DIR,u8PinNumber);
       }
       break;
   case GPIO_PORT4:
       if (u8Direction == GPIO_DIR_OUT)
              {
                  SET_BIT(P4DIR,u8PinNumber);
              }
              else
              {
                  CLEAR_BIT(P4DIR,u8PinNumber);
              }
       break;
   case GPIO_PORT5:
       break;
   case GPIO_PORT6:
       if (u8Direction == GPIO_DIR_OUT)
                     {
                         SET_BIT(P6DIR,u8PinNumber);
                     }
                     else
                     {
                         CLEAR_BIT(P6DIR,u8PinNumber);
                     }
       break;
   case GPIO_PORT7:
       if (u8Direction == GPIO_DIR_OUT)
                            {
                                SET_BIT(P7DIR,u8PinNumber);
                            }
                            else
                            {
         CLEAR_BIT(P7DIR,u8PinNumber);
       }
       break;
   case GPIO_PORT8:
       if (u8Direction == GPIO_DIR_OUT)
                            {
                                SET_BIT(P8DIR,u8PinNumber);
                            }
                            else
                            {
         CLEAR_BIT(P8DIR,u8PinNumber);
       }
   }
}

void GPIO_vidSetPinValue(u8 u8PortNumber, u8 u8PinNumber, u8 u8Value)
{
    switch (u8PortNumber)
    {
    case GPIO_PORT1:
        if (u8Value == STD_HIGH)
              {
                  SET_BIT(P1OUT,u8PinNumber);
              }
              else
              {
                  CLEAR_BIT(P1OUT,u8PinNumber);
              }
        break;
    case GPIO_PORT2:
        if (u8Value == STD_HIGH)
                     {
                         SET_BIT(P2OUT,u8PinNumber);
                     }
                     else
                     {
                         CLEAR_BIT(P2OUT,u8PinNumber);
                     }
        break;
    case GPIO_PORT3:
        if (u8Value == STD_HIGH)
                           {
                               SET_BIT(P3OUT,u8PinNumber);
                           }
                           else
                           {
                               CLEAR_BIT(P3OUT,u8PinNumber);
                           }
        break;
    case GPIO_PORT4:
        if (u8Value == STD_HIGH)
                      {
                          SET_BIT(P4OUT,u8PinNumber);
                      }
                      else
                      {
                          CLEAR_BIT(P4OUT,u8PinNumber);
                      }
        break;
    case GPIO_PORT5:
        break;
    case GPIO_PORT6:
        if (u8Value == STD_HIGH)
            {
              SET_BIT(P6OUT,u8PinNumber);
             }
        else
           {
               CLEAR_BIT(P6OUT,u8PinNumber);
           }
        break;
    case GPIO_PORT7:
        if (u8Value == STD_HIGH)
                    {
                      SET_BIT(P7OUT,u8PinNumber);
                     }
                else
                   {
                       CLEAR_BIT(P7OUT,u8PinNumber);
                   }
                break;
    case GPIO_PORT8:
        if (u8Value == STD_HIGH)
                           {
                             SET_BIT(P8OUT,u8PinNumber);
                            }
                       else
                          {
                              CLEAR_BIT(P8OUT,u8PinNumber);
                          }
                       break;
    }
}

u8 GPIO_u8GetPinValue(u8 u8PortNumber, u8 u8PinNumber)
{
    switch (u8PortNumber)
    {
    case GPIO_PORT1:
        return GET_BIT(P1IN,u8PinNumber);
    break;
    case GPIO_PORT2:
        return GET_BIT(P2IN,u8PinNumber);
        break;
    case GPIO_PORT3:
        return GET_BIT(P3IN,u8PinNumber);
        break;
    case GPIO_PORT4:
        return GET_BIT(P4IN,u8PinNumber);
        break;
    case GPIO_PORT5:
        return GET_BIT(P5IN,u8PinNumber);
        break;
    case GPIO_PORT6:
        return GET_BIT(P6IN,u8PinNumber);
        break;
    }
}


void GPIO_vidSetPinResisPullUpDown(u8 u8PortNumber, u8 u8PinNumber, u8 u8ResistanceFlag)
{
    switch(u8PortNumber)
    {
    case GPIO_PORT1:
        if (u8ResistanceFlag == GPIO_RES_ENABLE)
        {
            SET_BIT(P1REN,u8PinNumber);
        }
        else {
            CLEAR_BIT(P1REN,u8PinNumber);
        }
        break;
    case GPIO_PORT2:
        if (u8ResistanceFlag == GPIO_RES_ENABLE)
                {
                    SET_BIT(P2REN,u8PinNumber);
                }
                else {
                    CLEAR_BIT(P2REN,u8PinNumber);
                }
        break;
    case GPIO_PORT3:
        if (u8ResistanceFlag == GPIO_RES_ENABLE)
                {
                    SET_BIT(P3REN,u8PinNumber);
                }
                else {
                    CLEAR_BIT(P3REN,u8PinNumber);
                }
        break;
    case GPIO_PORT4:
        if (u8ResistanceFlag == GPIO_RES_ENABLE)
                {
                    SET_BIT(P4REN,u8PinNumber);
                }
                else {
                    CLEAR_BIT(P4REN,u8PinNumber);
                }
        break;
    case GPIO_PORT5:
        if (u8ResistanceFlag == GPIO_RES_ENABLE)
                {
                   SET_BIT(P5REN,u8PinNumber);
                }
                else {
                    CLEAR_BIT(P5REN,u8PinNumber);
                }
        break;
    case GPIO_PORT6:
        if (u8ResistanceFlag == GPIO_RES_ENABLE)
                {
                    SET_BIT(P6REN,u8PinNumber);
                }
                else {
                    CLEAR_BIT(P6REN,u8PinNumber);
                }
        break;
    case GPIO_PORT7:
        if (u8ResistanceFlag == GPIO_RES_ENABLE)
                {
                    SET_BIT(P7REN,u8PinNumber);
                }
                else {
                    CLEAR_BIT(P7REN,u8PinNumber);
                }
        break;
    case GPIO_PORT8:
        if (u8ResistanceFlag == GPIO_RES_ENABLE)
                {
                    SET_BIT(P8REN,u8PinNumber);
                }
                else {
                    CLEAR_BIT(P8REN,u8PinNumber);
                }
        break;

    }
}

void GPIO_vidTogglePinValue(u8 u8PortNumber, u8 u8PinNumber)
{
    switch(u8PortNumber)
    {
    case GPIO_PORT1:
        TOGGLE_BIT(P1OUT,u8PinNumber);
        break;
    case GPIO_PORT2:
        TOGGLE_BIT(P2OUT,u8PinNumber);
        break;
    case GPIO_PORT3:
        TOGGLE_BIT(P3OUT,u8PinNumber);
        break;
    case GPIO_PORT4:
        TOGGLE_BIT(P4OUT,u8PinNumber);
        break;
    case GPIO_PORT5:
        TOGGLE_BIT(P5OUT,u8PinNumber);
        break;
    case GPIO_PORT6:
        TOGGLE_BIT(P6OUT,u8PinNumber);
        break;
    case GPIO_PORT7:
        TOGGLE_BIT(P7OUT,u8PinNumber);
        break;
    case GPIO_PORT8:
        TOGGLE_BIT(P8OUT,u8PinNumber);
        break;

    }

}

void GPIO_vidPutISRFunction(u8 u8ExtInterruptID ,void (*ptrFun) (void)) {
    switch (u8ExtInterruptID)
    {
    case GPIO_EXTIN_P1:
            ExtInt[GPIO_EXTIN_P1] = ptrFun;
        break;
    case GPIO_EXTIN_P2:
            ExtInt[GPIO_EXTIN_P2] = ptrFun;
        break;
    }
}

#pragma vector=PORT2_VECTOR
__interrupt void ISR(void) {
    switch(P2IV) {
    case 0x04:
       ExtInt[GPIO_EXTIN_P2]();
       break;

    }
}


#pragma vector=PORT1_VECTOR
__interrupt void secondButton(void)
{
    switch(P1IV) {
    case 0x04:
        ExtInt[GPIO_EXTIN_P1]();
    }
}
