//===============================================
#include "G7Seg.h"
#include "GPortDef.h"
//===============================================
extern uchar code eG7Seg_DM[];
//===============================================
static uchar eG7Seg_Index;
//===============================================
void G7Seg_Init() {
    G7SEG_CONF &= 0x80;
    G7SEG |= 0x7F;
    eG7Seg_Index = 0;
}
//===============================================
void G7Seg_Count() {
    uchar m_index = eG7Seg_Index % 10;
    LED = ~eG7Seg_DM[m_index];
    eG7Seg_Index++;
}
//===============================================