//===============================================
#include "GPort.h"
//===============================================
void main() {
    static uchar ok = 0;
    while(TRUE) {
        ok = !ok;
        GPort_Bit_Write(7, ok);
        GPort_Bit_Write(1, ok);
        GPort_Bit_Write(4, ok);
        delay_ms(1000);
    }
}
//===============================================
