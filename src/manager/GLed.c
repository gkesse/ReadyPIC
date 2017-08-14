//===============================================
#include "GLed.h"
#include "GPortDef.h"
#include "GDataMap.h"
//===============================================
static uchar Led_Chasing_X;
static uchar Led_Chasing_Y;
//===============================================
void GLed_Init() {
    LED_CONF = 0x00;
    LED = 0xFF;
    Led_Chasing_X = 2;
    Led_Chasing_Y = 0;
}
//===============================================
void GLed_Chasing() {
    uchar m_index = 8*Led_Chasing_X + Led_Chasing_Y; 
    LED = ~Led_Chasing_DM[m_index];
    if(++Led_Chasing_Y >= 8) Led_Chasing_Y = 0;
}
//===============================================
