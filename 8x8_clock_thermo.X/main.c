/*
 * File:   8x8_clock_thermo.c
 * Author: Phil
 *
 * Created on 17 February 2017, 11:07
 */


#include <xc.h>
#include <pic.h>
#include"config.h"
#include "send_spi_byte.h"
/***********Function Prototypes***********/
void init_ports();
void interrupt isr();
void init_spi();
void init1_max7219();
void init2_max7219();
void init3_max7219();
void configTimer1();
void tmr1On();
void num_lookup();
void clear_display();
void updateDisplay(char *tens_hours_digit, char *hours_digit, char *tens_mins_digit, char *mins_digit, char *tens_secs_digit, char *secs_digit);
void split_digits(void);
/****************************************/


char main(char)
{
    minutes = 0;
    init_ports();
    init_spi();
    init1_max7219();
    init2_max7219();
    init3_max7219();
    configTimer1();
    tmr1On();
    clear_display();
    
    

    while(1)
    {
        if(RD1 == 0)
        {
            hours = hours + 1;
            minutes = 0;
            seconds = 0;
            __delay_ms(15);
        }
        if(RD0 == 0)
        {
            minutes = minutes + 1;
            seconds = 0;
            __delay_ms(15);
        }
        
    }
}
