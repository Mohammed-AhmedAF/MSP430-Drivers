#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

/*Function declarations*/
void UART_vidInit(void);
void UART_vidEnableInterrupt(u8 u8InterruptID);
void UART_vidDisableInterrupt(u8 u8InterruptID);
void UART_vidSendByte(u8 u8Byte);
u8 UART_u8GetReceivedByte(void);
void UART_vidPutISRFunction(u8 uInterruptSourceID, void (*ptrFun) (void));

#define UART_RX 2
#define UART_TX 4

#define UART_INTERRUPT_TRANS_COMPLETE 0
#define UART_INTERRUPT_STARTBIT 1
#define UART_INTERRUPT_TX 2
#define UART_INTERRUPT_RX 3


#endif
