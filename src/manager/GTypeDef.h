//===============================================
#ifndef _GTypeDef_
#define _GTypeDef_
//===============================================
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
//===============================================
#define OSC_FREQ (4000000)
#define OSC_PER_INST (4)
//===============================================
#define GTR0 T0CON.TMR0ON
#define GET0 INTCON.TMR0IE
#define GTF0 INTCON.TMR0IF
#define GEA INTCON.GIE
//===============================================
#define FALSE (0)
#define TRUE (!FALSE)
//===============================================
#define LED_OFF (1)
#define LED_ON (!LED_OFF)
//===============================================
#define LIGHT_OFF (1)
#define LIGHT_ON (!LIGHT_OFF)
#define LIGHT_GREEN_DURATION (3)
#define LIGHT_AMBER_DURATION (2)
#define LIGHT_RED_RED_DURATION (1)
#define LIGHT_RED_DURATION (LIGHT_GREEN_DURATION)
#define LIGHT_RED_AMBER_DURATION (LIGHT_AMBER_DURATION)
#define LIGHT_RED_RED_1_DURATION (LIGHT_RED_RED_DURATION)
#define LIGHT_RED_RED_2_DURATION (LIGHT_RED_RED_DURATION)
//===============================================
#endif
//===============================================
