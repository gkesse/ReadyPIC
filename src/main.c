//===============================================
#include "GLed.h"
//===============================================
void main() {
    GLed_Init();
    while(1) {
        GLed_Chasing_Pattern();
        Delay_ms(1000);
    }
}
//===============================================