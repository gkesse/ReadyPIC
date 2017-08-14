//===============================================
#include "GPort.h"
#include "GPortDef.h"
//===============================================
void GPort_Write(const uchar d) {
    PORT_CONF = 0x00;
    PORT_DATA = d;
}
//===============================================
uchar GPort_Read() {
    PORT_CONF = 0xFF;
    return PORT_DATA;
}
//===============================================
void GPort_Bit_Write(const uchar pin, const uchar d) {
    uchar m_pin = 0x01;
    m_pin <<= pin;
    PORT_CONF &= ~m_pin;
    if(d == TRUE) {
        PORT_DATA |= m_pin;
        return;
    }
    PORT_DATA &= ~m_pin;
}
//===============================================
uchar GPort_Bit_Read(const uchar pin) {
    uchar m_pin = 0x01;
    uchar m_data;
    m_pin <<= pin;
    PORT_CONF |= m_pin;
    m_data = PORT_DATA & m_pin;
    if(m_data == 0) return 0;
    return 1;
}
//===============================================