/*
 * GPIO_interface.h
 *
 *  Created on: Nov 24, 2020
 *      Author: Mohammed
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*Function definition*/
void GPIO_vidSetPinDirection(u8 u8PortNumber, u8 u8PinNumber, u8 u8Direction);
void GPIO_vidSetPinValue(u8 u8PortNumber, u8 u8PinNumber, u8 u8Value);
u8 GPIO_u8GetPinValue(u8 u8PortNumber, u8 u8PinNumber);
void GPIO_vidTogglePin(u8 u8PortNumber, u8 u8PinNumber);
void GPIO_vidSetPinResisPullUpDown(u8 u8PortNumber, u8 u8PinNumber,u8 u8ResistanceFlag);
void GPIO_vidTogglePin(u8 u8PortNumber, u8 u8PinNumber);
void GPIO_vidPutISRFunction(u8 u8ExtInterruptID,void (*ptrFun) (void));
void GPIO_vidConfigPinInterrupt(u8 u8PortNumber, u8 u8PinNumber, u8 u8Edge);
void GPIO_vidEnablePinInterrupt(u8 u8PortNumber, u8 u8PinNumber);

#define GPIO_RES_ENABLE 0
#define GPIO_RES_DISABLE 1

#define GPIO_PORT1 0
#define GPIO_PORT2 1
#define GPIO_PORT3 2
#define GPIO_PORT4 3
#define GPIO_PORT5 4
#define GPIO_PORT6 5
#define GPIO_PORT7 6
#define GPIO_PORT8 7

#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7

#define GPIO_DIR_IN 0
#define GPIO_DIR_OUT 1


/*External interrupt IDs*/
#define GPIO_EXTIN_P1 0
#define GPIO_EXTIN_P2 1

#define GPIO_EDGE_HL 0
#define GPIO_EDGE_LH 1

#endif /* GPIO_INTERFACE_H_ */
