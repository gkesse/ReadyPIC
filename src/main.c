//===============================================
#include "GPort.h"
//===============================================
void main() {
    GPort_Write(0xFF);
    while(TRUE) {
        GPort_Bit_Write(7, GPort_Bit_Read(0));
    }
}
//===============================================
