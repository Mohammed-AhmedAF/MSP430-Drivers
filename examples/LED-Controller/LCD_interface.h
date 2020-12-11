/*
 * LCD_interface.h
 *
 *  Created on: Nov 23, 2020
 *      Author: Mohammed
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_vidInit(void);
void LCD_vidSendCommand(u8 u8Command);
void LCD_vidWriteCharacter(u8 u8Character);
void LCD_vidWriteString(s8 * s8String);
void LCD_vidWriteNumber(u16 u16NumberCpy);
void LCD_vidGoToXY(u8 u8xCpy, u8 u8yCpy);
void LCD_vidWriteInPlace(u8 u8xCpy,u8 u8yCpy, u8 u8CharCpy);
void LCD_vidClearLine(u8 u8LineNumber);

/*Port and pin definition*/
#define LCD_D0_PORT GPIO_PORT6
#define LCD_D1_PORT GPIO_PORT6
#define LCD_D2_PORT GPIO_PORT6
#define LCD_D3_PORT GPIO_PORT6
#define LCD_D4_PORT GPIO_PORT6
#define LCD_D5_PORT GPIO_PORT6
#define LCD_D6_PORT GPIO_PORT7
#define LCD_D7_PORT GPIO_PORT8

#define LCD_D0_PIN GPIO_PIN0
#define LCD_D1_PIN GPIO_PIN1
#define LCD_D2_PIN GPIO_PIN2
#define LCD_D3_PIN GPIO_PIN3
#define LCD_D4_PIN GPIO_PIN4
#define LCD_D5_PIN GPIO_PIN5
#define LCD_D6_PIN GPIO_PIN0
#define LCD_D7_PIN GPIO_PIN1

#define LCD_8MODE_2L 0x38
#define LCD_ON_NOCURSOR 0x0C
#define LCD_CLEAR_SCREEN 0b00000001
#define LCD_RETURN_HOME 0b00000010

#define LCD_CTRL_PORT GPIO_PORT4
#define LCD_RS GPIO_PIN1
#define LCD_RW  GPIO_PIN2
#define LCD_EN  GPIO_PIN3

/*Entry mode*/
#define LCD_SET_ENTRY_MODE 0x04
#define LCD_MOVE_CURSOR_RIGHT 0x02
#define LCD_MOVE_CURSOR_LEFT 0x00
#define LCD_DISPLAY_SHIFT_ON 0x01
#define LCD_DISPLAY_SHIFT_OFF 0x00


/*Display on/off control */
#define LCD_DISPLAY_ON 0x0C
#define LCD_DISPLAY_OFF 0x08

#define LCD_CURSOR_ON 0x0A
#define LCD_CURSOR_OFF 0x08

#define LCD_CURSOR_BLINK_ON 0x09
#define LCD_CURSOR_BLINK_OFF 0x08

/*Function set*/
#define LCD_FUNCTION_SET 0x20
#define LCD_8BIT 0x10
#define LCD_4LINES 0x08

/*Macros defined to be used with the GoTOXY function*/
#define LCD_XPOS0 0
#define LCD_XPOS1 1
#define LCD_XPOS2 2
#define LCD_XPOS3 3
#define LCD_XPOS4 4
#define LCD_XPOS5 5
#define LCD_XPOS6 6
#define LCD_XPOS7 7
#define LCD_XPOS8 8
#define LCD_XPOS9 9
#define LCD_XPOS10 10
#define LCD_XPOS11 11
#define LCD_XPOS12 12
#define LCD_XPOS13 13
#define LCD_XPOS14 14
#define LCD_XPOS15 15
#define LCD_XPOS16 16
#define LCD_XPOS17 17
#define LCD_XPOS18 18
#define LCD_XPOS19 19

#define LCD_YPOS0 0
#define LCD_YPOS1 1
#define LCD_YPOS2 2
#define LCD_YPOS3 3


#endif /* LCD_INTERFACE_H_ */
