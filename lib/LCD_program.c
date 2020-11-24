/*
 * LCD_program.c
 *
 *  Created on: Nov 23, 2020
 *      Author: Mohammed
 */

#include "Std_Types.h"
#include "Macros.h"
#include "GPIO_interface.h"
#include "LCD_interface.h"

void LCD_vidInit(void)
{
    /*Direction of data pins*/
    GPIO_vidSetPinDirection(LCD_D0_PORT,LCD_D0_PIN,GPIO_DIR_OUT);
    GPIO_vidSetPinDirection(LCD_D1_PORT,LCD_D1_PIN,GPIO_DIR_OUT);
    GPIO_vidSetPinDirection(LCD_D2_PORT,LCD_D2_PIN,GPIO_DIR_OUT);
    GPIO_vidSetPinDirection(LCD_D3_PORT,LCD_D3_PIN,GPIO_DIR_OUT);
    GPIO_vidSetPinDirection(LCD_D4_PORT,LCD_D4_PIN,GPIO_DIR_OUT);
    GPIO_vidSetPinDirection(LCD_D5_PORT,LCD_D5_PIN,GPIO_DIR_OUT);
    GPIO_vidSetPinDirection(LCD_D6_PORT,LCD_D6_PIN,GPIO_DIR_OUT);
    GPIO_vidSetPinDirection(LCD_D7_PORT,LCD_D7_PIN,GPIO_DIR_OUT);

    /*Direction of command pins*/
    GPIO_vidSetPinDirection(LCD_CTRL_PORT,LCD_RS,GPIO_DIR_OUT);
    GPIO_vidSetPinDirection(LCD_CTRL_PORT,LCD_RW,GPIO_DIR_OUT);
    GPIO_vidSetPinDirection(LCD_CTRL_PORT,LCD_EN,GPIO_DIR_OUT);



    LCD_vidSendCommand(LCD_CLEAR_SCREEN); /*Clear screen*/
    LCD_vidSendCommand(LCD_RETURN_HOME); /*Move to home*/
    LCD_vidSendCommand(LCD_SET_ENTRY_MODE|LCD_MOVE_CURSOR_RIGHT); /*Set entry mode*/
    LCD_vidSendCommand(LCD_DISPLAY_ON); /*Display On/Off control*/
    LCD_vidSendCommand(LCD_FUNCTION_SET|LCD_8BIT|LCD_4LINES); /*Function Set*/
}

void LCD_vidSendCommand(u8 u8Command)
{
    GPIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RS,STD_LOW);
    GPIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RW,STD_LOW);

    GPIO_vidSetPinValue(LCD_D0_PORT,LCD_D0_PIN,GET_BIT(u8Command,0));
    GPIO_vidSetPinValue(LCD_D1_PORT,LCD_D1_PIN,GET_BIT(u8Command,1));
    GPIO_vidSetPinValue(LCD_D2_PORT,LCD_D2_PIN,GET_BIT(u8Command,2));
    GPIO_vidSetPinValue(LCD_D3_PORT,LCD_D3_PIN,GET_BIT(u8Command,3));
    GPIO_vidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(u8Command,4));
    GPIO_vidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(u8Command,5));
    GPIO_vidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(u8Command,6));
    GPIO_vidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(u8Command,7));


    GPIO_vidSetPinValue(LCD_CTRL_PORT, LCD_EN, STD_HIGH);
    __delay_cycles(2000);
    GPIO_vidSetPinValue(LCD_CTRL_PORT, LCD_EN, STD_LOW);
    __delay_cycles(2000);
    GPIO_vidSetPinValue(LCD_CTRL_PORT, LCD_EN,STD_HIGH);
    __delay_cycles(2000);
}

void LCD_vidWriteCharacter(u8 u8Character)
{

    GPIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RS,STD_HIGH);
    GPIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RW,STD_LOW);

        GPIO_vidSetPinValue(LCD_D0_PORT,LCD_D0_PIN,GET_BIT(u8Character,0));
        GPIO_vidSetPinValue(LCD_D1_PORT,LCD_D1_PIN,GET_BIT(u8Character,1));
        GPIO_vidSetPinValue(LCD_D2_PORT,LCD_D2_PIN,GET_BIT(u8Character,2));
        GPIO_vidSetPinValue(LCD_D3_PORT,LCD_D3_PIN,GET_BIT(u8Character,3));
        GPIO_vidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(u8Character,4));
        GPIO_vidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(u8Character,5));
        GPIO_vidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(u8Character,6));
        GPIO_vidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(u8Character,7));


        GPIO_vidSetPinValue(LCD_CTRL_PORT, LCD_EN, STD_HIGH);
        __delay_cycles(2000);
        GPIO_vidSetPinValue(LCD_CTRL_PORT, LCD_EN, STD_LOW);
        __delay_cycles(2000);
        GPIO_vidSetPinValue(LCD_CTRL_PORT, LCD_EN,STD_HIGH);
        __delay_cycles(2000);

}


void LCD_vidWriteString(s8 * s8String)
{
    do {
            LCD_vidWriteCharacter(*s8String);
            (s8String++);
        }while(*s8String != '\0');
}


void LCD_vidWriteNumber(u16 u16NumberCpy) {
    if(u16NumberCpy < 10) {
        LCD_vidWriteCharacter('0');
        LCD_vidWriteCharacter(u16NumberCpy+'0');
    }
    else {
        if (u16NumberCpy < 100) {
            LCD_vidWriteCharacter(u16NumberCpy/10+'0');
            LCD_vidWriteCharacter(u16NumberCpy%10+'0');
        }
        else if (u16NumberCpy < 1000) {
            LCD_vidWriteCharacter((u16NumberCpy/100)+'0');
            LCD_vidWriteCharacter((u16NumberCpy%100)/10+'0');
            LCD_vidWriteCharacter((u16NumberCpy%100)%10+'0');
        }
        else if (u16NumberCpy < 10000)
        {
            LCD_vidWriteCharacter((u16NumberCpy/1000)+'0');
            LCD_vidWriteCharacter((u16NumberCpy%1000)/100+'0');
            LCD_vidWriteCharacter((u16NumberCpy%100)/10+'0');
            LCD_vidWriteCharacter((u16NumberCpy%100)%10+'0');
        }
    }
}

void LCD_vidGoToXY(u8 u8xCpy, u8 u8yCpy) {
    #define LCD_SET_CURSOR_LOCATION 0x80
    u8 u8address = u8xCpy;
    switch(u8yCpy) {
        case 0:
            u8address = u8xCpy;
            break;
        case 1:
            u8address = u8xCpy+0xC0;
            break;
        case 2:
            u8address = u8xCpy+0x94;
            break;
        case 3:
            u8address = u8xCpy+0xD4;
            break;
    }
    LCD_vidSendCommand(u8address | 0x80);
}

/*This function has been reedited to allow writing a character
 *on a specific row and a specific column.
 * */
void LCD_vidWriteInPlace(u8 u8xCpy,u8 u8yCpy, u8 u8CharCpy) {
    LCD_vidGoToXY(u8xCpy,u8yCpy);
    LCD_vidWriteCharacter(u8CharCpy);
}

void LCD_vidClearLine(u8 u8LineNumber)
{
    LCD_vidGoToXY(LCD_XPOS0,u8LineNumber);
    u8 u8xPos;
    for (u8xPos = 0; u8xPos < 20; u8xPos++)
    {
        LCD_vidWriteCharacter(' ');
    }
}
