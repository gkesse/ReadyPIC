//===============================================
#ifndef _GPort_
#define _GPort_
//===============================================
#include "GTypeDef.h"
//===============================================
void GPort_Write(GConst uchar d);
uchar GPort_Read();
void GPort_Bit_Write(GConst uchar pin, GConst uchar d);
uchar GPort_Bit_Read(GConst uchar pin);
//===============================================
#endif
//===============================================