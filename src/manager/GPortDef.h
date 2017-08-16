//===============================================
#ifndef _GPortDef_
#define _GPortDef_
//===============================================
#define PORT_CONF TRISB
#define PORT PORTB
#define PIN0 PORT.B0
#define PIN1 PORT.B1
#define PIN2 PORT.B2
#define PIN3 PORT.B3
#define PIN4 PORT.B4
#define PIN5 PORT.B5
#define PIN6 PORT.B6
#define PIN7 PORT.B7
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
#define OUTPUT_CONF TRISD
#define OUTPUT PORTD
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