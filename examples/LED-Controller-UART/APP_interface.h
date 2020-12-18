#ifndef _APP_INTERFACE_H
#define _APP_INTERFACE_H

void APP_vidInit(void);
void APP_vidCountOneSec(void);
void APP_vidControl(void);
void APP_vidReceiveControlFrame(void);

/*Macros*/
#define MESSAGESIZE 4
#define SECOND_OVF 183


#endif
