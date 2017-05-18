#include <pic.h>
#include "config.h"
#include "main.h"
void interrupt isr(void)
{
    if (PIR1bits.TMR1IF == 1)// check that the source of the interrupt if TMR1
    {
    DIAGNOSTIC_LED = ~DIAGNOSTIC_LED;
    
    //***************************INTERRUPT CODE*************************************
    
    TMR1H = 0xdf;           // preload TMR1 to generate a 1s interrupt
    TMR1L = 0xff;           // max count - target count = preload number
    seconds = seconds + 1;
                            //65535-8192 = 57343 = 0xDFFF (assumes 32.768kHz clock)
   
    if(seconds > 59)
    {
        seconds = 0;
        minutes = minutes + 1;
     }
    
    
    if (minutes > 59)
    {
        seconds = 0;
        minutes = 0;
        hours  = hours + 1;
    }
    if (hours > 23)
    {
        seconds = 0;
        minutes = 0;
        hours = 0;
    }
    split_digits();
    num_lookup();
    }
    PIR1bits.TMR1IF = 0;    // clear the TMR1 interrupt to allow further interrupts
}
