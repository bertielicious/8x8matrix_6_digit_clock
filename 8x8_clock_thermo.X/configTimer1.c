#include <pic.h>
void configTimer1(void)
{
    PIR1bits.TMR1IF = 0;    // clear TMR1 interupt flag to enable counting
    TMR1H = 0xdf;           // preload TMR1 to generate a 10.24ms interrupt
    TMR1L = 0xff;           // max count - target count = preload number
                            //65535-1024 = 55295 = 0xD7FF (asumes 4MHz clock)
    T1CONbits.T1CKPS0 = 0;  // 1:1 prescale
    T1CONbits.T1CKPS1 = 0;
    PIE1bits.TMR1IE = 1;    // TMR1 interrupts are enabled
    INTCONbits.PEIE = 1;    // Peripheral interrupts are enabled
    INTCONbits.GIE = 1;     // Global interrupts are enabled
}
