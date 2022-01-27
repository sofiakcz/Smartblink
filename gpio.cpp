#include "gpio.h"
#include <lgpio.h>

Gpio::Gpio(QObject *parent) : QObject(parent)
{
    m_handle = lgGpiochipOpen(0);
    int init_lvl = 0;
    for(int pin : LEDS)
        lgGpioClaimOutput(m_handle, LFLAGS, pin, init_lvl);
}

Gpio::~Gpio()
{
    int init_lvl = 0;
    for(int pin : LEDS)
        lgGpioWrite(m_handle, pin, init_lvl);
    lgGpiochipClose(m_handle);
}

void Gpio::set(int pin, bool wert)
{
    lgGpioWrite(m_handle, pin, wert);
}

void Gpio::set(unsigned int pattern)
{
    bool wert;
    int n = 0;
    unsigned int check = 0b0001;

    for(auto pin : LEDS){
        wert = check & pattern>>n;
        lgGpioWrite(m_handle, pin, wert);

        n++;
    }
}
