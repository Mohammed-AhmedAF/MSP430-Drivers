/*
 * SCHEDULER_interface.h
 *
 *  Created on: Nov 25, 2020
 *      Author: Mohammed
 */

#ifndef SCHEDULER_INTERFACE_H_
#define SCHEDULER_INTERFACE_H_

#define SCHEDULER_ONETICK 20
#define SCHEDULER_MAXTASKS 10

/*Macro function, used to get memory address of struct*/
#define _SCHEDULER_GETID(Task) &Task

/*Task that has nothing to do*/
#define SCHEDULER_NULLTASK 0

/*Task state definitions*/
#define SCHEDULER_TASKSTATE_WAITING 2
#define SCHEDULER_TASKSTATE_RUNNING 1
#define SCHEDULER_TASKSTATE_STOPPED 0

/*Clock configuration macros*/
#define SCHEDULER_CLKSRC_AUX TIMERA0_CLKSEL_AUX
#define SCHEDULER_CLKSRC_SM TIMERA0_CLKSEL_SM

#define SCHEDULER_CLKDIV_1 TIMERA0_CLKDIV_1
#define SCHEDULER_CLKDIV_2 TIMERA0_CLKDIV_2
#define SCHEDULER_CLKDIV_4 TIMERA0_CLKDIV_4
#define SCHEDULER_CLKDIV_8 TIMERA0_CLKDIV_8

/*Struct holding task data*/
typedef struct {
    u16 u16FirstDelay;
    u16 u16Periodicity;
    void (*ptrFunction) (void);
    u8 u8State;
} Task_Type;

typedef struct {
    u8 u8TimerClkSrc;
    u8 u8TimerClkDiv;
    u16 u16TimerCount;
} Scheduler_Config;

/*Task ID definitions*/
#define SCHEDULER_TASK0 0
#define SCHEDULER_TASK1 1
#define SCHEDULER_TASK2 2
#define SCHEDULER_TASK3 3
#define SCHEDULER_TASK4 4
#define SCHEDULER_TASK5 5
#define SCHEDULER_TASK6 6
#define SCHEDULER_TASK7 7
#define SCHEDULER_TASK8 8
#define SCHEDULER_TASK9 9
#define SCHEDULER_TASK10 10
#define SCHEDULER_TASK11 11

/*Function definitions*/
void SCHEDULER_vidInit(void);
void SCHEDULER_vidInitExpanded();
void SCHEDULER_vidCreateTask(Task_Type * task, u8 u8TaskPriority);
void SCHEDULER_vidScheduler(void);
void SCHEDULER_vidCountTick(void);


#endif /* SCHEDULER_INTERFACE_H_ */
