//===============================================
#include "GSch.h"
//===============================================
#define PRESCALER (32)
#define PRELOAD (65536 - (uint)(((ulong)OSC_FREQ * 1)/((ulong)OSC_PER_INST * PRESCALER * 1000))) // ms
#define PRELOADH (PRELOAD /256)
#define PRELOADL (PRELOAD % 256)
//===============================================
#define SCH_MAX_TASKS (2)
//===============================================
GTask Sch_Tasks_Map[SCH_MAX_TASKS];
//===============================================
void GSch_Reload();
void GSch_Go_To_Sleep();
void GSch_Delete_Task(const uchar index);
//===============================================
void GSch_Reload() {
    GTR0 = 0;
    TMR0H = PRELOADH;
    TMR0L = PRELOADL;
    GTR0 = 1;
}
//===============================================
void GSch_Go_To_Sleep() {
    OSCCON |= 0x80;
}
//===============================================
void GSch_Delete_Task(const uchar index) {
    Sch_Tasks_Map[index].pTask = 0x0000;
    Sch_Tasks_Map[index].delay = 0;
    Sch_Tasks_Map[index].period = 0;
    Sch_Tasks_Map[index].runMe = 0;
}
//===============================================
void GSch_Init() {
    uchar index;
    for(index = 0; index < SCH_MAX_TASKS; index++) {
        GSch_Delete_Task(index);
    }
    T0CON = 0x04;
    GSch_Reload();
    GET0 = 1;
}
//===============================================
void GSch_Start() {
    GEA = 1;
}
//===============================================
void GSch_Dispatch_Tasks() {
    uchar index;
    for(index = 0; index < SCH_MAX_TASKS; index++) {
        if(Sch_Tasks_Map[index].runMe > 0) {
            (*Sch_Tasks_Map[index].pTask)();
            Sch_Tasks_Map[index].runMe -= 1;
            if(Sch_Tasks_Map[index].period == 0) {
                GSch_Delete_Task(index);
            }
        }
    }
    GSch_Go_To_Sleep();
}
//===============================================
void GSch_Add_Task(void (*pTask)(), const uint delay, const uint period) {
    uchar index = 0;
    while((Sch_Tasks_Map[index].pTask != 0) && (index < SCH_MAX_TASKS)) index++;
    if(index == SCH_MAX_TASKS) return;
    Sch_Tasks_Map[index].pTask = pTask;
    Sch_Tasks_Map[index].delay = delay;
    Sch_Tasks_Map[index].period = period;
    Sch_Tasks_Map[index].runMe = 0;
}
//===============================================
void interrupt() {
    uchar index;
    GTF0 = 0;
    GSch_Reload();
    for(index = 0; index < SCH_MAX_TASKS; index++) {
        if(Sch_Tasks_Map[index].pTask != 0) {
            if(Sch_Tasks_Map[index].delay == 0) {
                Sch_Tasks_Map[index].runMe += 1;
                if(Sch_Tasks_Map[index].period != 0) {
                    Sch_Tasks_Map[index].delay = Sch_Tasks_Map[index].period;
                }
            }
            else {
                Sch_Tasks_Map[index].delay -= 1;
            }
        }
    }
}
//===============================================