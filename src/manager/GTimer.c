//===============================================
#include "GTimer.h"
#include "GLed.h"
//===============================================
#define PRESCALER (32)
#define PRELOAD (65536 - (uint)(((ulong)OSC_FREQ * 1000)/((ulong)OSC_PER_INST * PRESCALER * 1000))) // ms
#define PRELOADH (PRELOAD /256)
#define PRELOADL (PRELOAD % 256)
//===============================================
void GTimer_Reload_T0();
//===============================================
void GTimer_Reload_T0() {
    GTR0 = 0;
    TMR0H = PRELOADH;
    TMR0L = PRELOADL;
    GTR0 = 1;
}
//===============================================
void GTimer_Init_T0() {
    // Stop Timer : 0
    // Mode 16-bit : 0
    // 32 Prescaler Value : 100
    T0CON = 0x04;
    GTimer_Reload_T0();
    GET0 = 1;
}
//===============================================
void GInterrupt_Start() {
    GEA = 1;
}
//===============================================
void interrupt2() {
    GTF0 = 0;
    GTimer_Reload_T0();
    GLed_Chasing_Linear(4);
}
//===============================================
