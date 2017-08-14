//===============================================
#include "GLed.h"
#include "GPortDef.h"
#include "GDataMap.h"
#include "GGlobal.h"
//===============================================
static uchar Led_Chasing_X;
static uchar Led_Chasing_Y;
//===============================================
uchar GLed_Get_Data_Ring(const uchar index, const uchar n, const uchar mod);
uchar GLed_Get_Data_Linear(const uchar index, const uchar n, const uchar mod);
uchar GLed_Get_Data_Pattern(const uchar index, char* pattern);
//===============================================
uchar GLed_Get_Data_Ring(const uchar index, const uchar n, const uchar mod) {
    uchar i, m_index;
    uchar m_data = 0x00;
    for(i = 0; i < n; i++) {
        m_index = (index + i) % mod;
        m_data |= Led_Chasing_DM[m_index];
    }
    return m_data;
}
//===============================================
uchar GLed_Get_Data_Linear(const uchar index, const uchar n, const uchar mod) {
    uchar i, m_index;
    uchar m_data = 0x00;
    for(i = 0; i < n; i++) {
        m_index = (index + i) % (mod + n);
        if(m_index >= mod) continue;
        m_data |= Led_Chasing_DM[m_index];
    }
    return m_data;
}
//===============================================
uchar GLed_Get_Data_Pattern(const uchar index, char* pattern) {
    uchar i, m_index;
    uchar m_data = 0x00;
    uchar m_length = strlen(pattern);
    for(i = 0; i < 8; i++) {
        m_index = (index + i) % (8 + m_length);
        if(m_index >= 8) continue;
        if(pattern[i] == '1') {
            m_data |= Led_Chasing_DM[m_index];
        }
    }
    return m_data;
}
//===============================================
void GLed_Init() {
    LED_CONF = 0x00;
    LED = 0xFF;
    Led_Chasing_X = 2;
    Led_Chasing_Y = 0;
    }
//===============================================
void GLed_Chasing_Selected() {
    uchar m_index = 8*Led_Chasing_X + Led_Chasing_Y; 
    LED = ~Led_Chasing_DM[m_index];
    if(++Led_Chasing_Y >= 8) Led_Chasing_Y = 0;
}
//===============================================
void GLed_Chasing_Ring(uchar n) {
    LED = ~GLed_Get_Data_Ring(Led_Chasing_Y, n, 8); 
    ++Led_Chasing_Y;
}
//===============================================
void GLed_Chasing_Linear(uchar n) {
    LED = ~GLed_Get_Data_Linear(Led_Chasing_Y, n, 8); 
    ++Led_Chasing_Y;
}
//===============================================
void GLed_Chasing_Pattern() {
    LED = ~GLed_Get_Data_Pattern(Led_Chasing_Y, "11011"); 
    ++Led_Chasing_Y;
}
//===============================================