#include <pic.h>
void tmr1On(void)
{
    TMR1H = 0xdf;           // preload TMR1 to generate a 10.24ms interrupt
    TMR1L = 0xff;           // max count - target count = preload number
                            //65535-1024 = 55295 = 0xD7FF (asumes 4MHz clock)
    T1CONbits.TMR1ON = 1;   // start TMR1 counting
}
