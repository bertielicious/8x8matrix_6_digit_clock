#include<xc.h>
#include<pic.h>
void init_ports()
{
    TRISAbits.TRISA0 = 1;   // input for temperature sensor (analogue)(pin 2)
    TRISAbits.TRISA5 = 0;   // !SS SPI output to CS MAX7219 (pin 7)
    TRISCbits.TRISC3 = 0;   // SCK SPI output to CLK of MAX7219 (pin 18)
    TRISCbits.TRISC4 = 1;   // disable SDI facility as we don't want to
                            // receive data back from the slave (pin 23)
    TRISCbits.TRISC5 = 0;   // SDO SPI output to DIN of MAX7219 (pin 24)
    TRISCbits.TRISC6 = 0;   // OUTPUT to diagnostic LED (pin 25)
    TRISDbits.TRISD0 = 1;   // MINS push button input (pin 19)
    TRISDbits.TRISD1 = 1;   // HOURS push button input (pin 20)
}