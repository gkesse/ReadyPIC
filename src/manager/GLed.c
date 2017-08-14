//===============================================
#include "GLed.h"
#include "GPortDef.h"
//===============================================
static uchar Led_Chasing;
//===============================================
void GLed_Init() {
    LED_CONF = 0x00;
    LED = 0xFF;
    Led_Chasing = 0x01;
}
//===============================================
void GLed_Chasing() {
    LED = ~Led_Chasing;
    Led_Chasing >>= 1;
    if(Led_Chasing == 0x00) Led_Chasing = 0x80;
}
//===============================================