#include "Macros.h"
#include "STD_TYPES.h"
#include "TIMERA0_interface.h"
#include "SCHEDULER_interface.h"

/*Counting the number of Timer OVFs*/
volatile u8 u8OVFCount;

Task_Type * Tasks_Array[SCHEDULER_MAXTASKS];

void SCHEDULER_vidInit(void)
{
    TIMERA0_vidInit(TIMERA0_MODE_UP, TIMERA0_CLKSEL_SM, TIMERA0_CLKDIV_1, 1000);
    TIMERA0_vidEnableInterrupt(TIMERA0_INTERRUPT_TAIFG);
    TIMERA0_vidPutISRFunction(SCHEDULER_vidCountTick);


    u8OVFCount = 0;
}

void SCHEDULER_vidInitExpanded(Scheduler_Config * schedulerConfig)
{
    TIMERA0_vidInit(TIMERA0_MODE_UP, schedulerConfig->u8TimerClkSrc, schedulerConfig->u8TimerClkDiv,
                    schedulerConfig->u16TimerCount);

    TIMERA0_vidEnableInterrupt(TIMERA0_INTERRUPT_TAIFG);
    TIMERA0_vidPutISRFunction(SCHEDULER_vidCountTick);

    u8OVFCount = 0;
}

void SCHEDULER_vidCreateTask(Task_Type * task, u8 u8TaskPriority)
{
    Tasks_Array[u8TaskPriority] = task;
}

void SCHEDULER_vidSchedule(void)
{
    static u8 u8TaskIndex = 0;
        for (u8TaskIndex = 0; u8TaskIndex < SCHEDULER_MAXTASKS; u8TaskIndex++) {
            if (Tasks_Array[u8TaskIndex] != SCHEDULER_NULLTASK) {
                if (Tasks_Array[u8TaskIndex]->u8State == SCHEDULER_TASKSTATE_RUNNING) {
                    if (Tasks_Array[u8TaskIndex]->u16FirstDelay == 0) {
                        Tasks_Array[u8TaskIndex]->ptrFunction();
                        Tasks_Array[u8TaskIndex]->u16FirstDelay = Tasks_Array[u8TaskIndex]->u16Periodicity-1;
                    }
                    else {
                        Tasks_Array[u8TaskIndex]->u16FirstDelay--;
                    }
                }
            }
        }
}

void SCHEDULER_vidCountTick(void)
{
    u8OVFCount++;
    if (u8OVFCount == SCHEDULER_ONETICK)
    {
        u8OVFCount = 0;
        SCHEDULER_vidSchedule();
    }

}
