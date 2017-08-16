//===============================================
#ifndef _GPortDef_
#define _GPortDef_
//===============================================
#ifdef GCCSC
#define PORT_CONF_WR SET_TRIS_B
#define PORT_CONF_RD GET_TRIS_B
#define PORT_WR OUTPUT_B
#define PORT_RD INPUT_B
#else
#define PORT_CONF TRISB
#define PORT PORTB
#endif
//===============================================
#ifdef GCCSC
#define OUTPUT_CONF_WR SET_TRIS_D
#define OUTPUT_CONF_RD GET_TRIS_D
#define OUTPUT_WR OUTPUT_D
#define OUTPUT_RD INPUT_D
#else
#define OUTPUT_CONF TRISD
#define OUTPUT PORTD
#endif
//===============================================
#define LIGHT_CONF TRISB
#define LIGHT PORTB
#define LIGHT_RED_L1 	PORT.B0
#define LIGHT_AMBER_L1 	PORT.B1
#define LIGHT_GREEN_L1 	PORT.B2
#define LIGHT_RED_L2 	PORT.B5
#define LIGHT_AMBER_L2 	PORT.B6
#define LIGHT_GREEN_L2  PORT.B7
//===============================================
#define LED_CONF TRISB
#define LED PORTB
//===============================================
#define G7SEG_CONF TRISB
#define G7SEG PORTB
#define G7SEG_COM G7SEG.B7
//===============================================
#endif
//===============================================