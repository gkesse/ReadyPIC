//===============================================
#include "GPort.h"
#include "GPortDef.h"
//===============================================
static uchar m_pin;
//===============================================
void GPort_Write(GConst uchar d) {
#ifdef GCCSC
    PORT_CONF_WR(0x00);
    PORT_WR(d);
#else
    PORT_CONF = 0x00;
    PORT = d;
#endif
}
//===============================================
uchar GPort_Read() {
    uchar m_data;
#ifdef GCCSC
    PORT_CONF_WR(0xFF);
    m_data = PORT_RD();
#else
    PORT_CONF = 0xFF;
    m_data = PORT;
#endif
    return m_data;
}
//===============================================
void GPort_Bit_Write(GConst uchar pin, GConst uchar d) {
    uchar m_data;
    m_pin = 0x01;
    m_pin <<= pin;
#ifdef GCCSC
    m_data = PORT_CONF_RD();
    m_data &= ~m_pin;
    PORT_CONF_WR(m_data);
    m_data = PORT_RD();
    if(d == TRUE) {
        m_data |= m_pin;
        PORT_WR(m_data);
        return;
    }
    m_data &= ~m_pin;
    PORT_WR(m_data);
#else
    PORT_CONF &= ~m_pin;
    if(d == TRUE) {
        PORT |= m_pin;
        return;
    }
    PORT &= ~m_pin;
#endif
}
//===============================================
uchar GPort_Bit_Read(GConst uchar pin) {
    uchar m_data;
    m_pin = 0x01;
    m_pin <<= pin;
#ifdef GCCSC
    m_data = PORT_CONF_RD();
    m_data |= m_pin;
    PORT_CONF_WR(m_data);
    m_data = PORT_RD() & m_pin;
    if(m_data == 0) return 0;
    return 1;
#else
    PORT_CONF |= m_pin;
    m_data = PORT & m_pin;
    if(m_data == 0) return 0;
    return 1;
#endif
}
//===============================================