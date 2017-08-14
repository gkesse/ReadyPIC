//===============================================
#ifndef _GPort_
#define _GPort_
//===============================================
#include "GTypeDef.h"
//===============================================
void GPort_Write(const uchar d);
uchar GPort_Read();
void GPort_Bit_Write(const uchar pin, const uchar d);
uchar GPort_Bit_Read(const uchar pin);
//===============================================
#endif
//===============================================