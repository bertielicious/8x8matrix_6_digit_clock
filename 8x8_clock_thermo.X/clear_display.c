#include "send_spi_byte.h"
#include "config.h"
void clear_display()
{
    char i;
    
    for (i = 1; i < 9; i++)
    {
        CS = 0;
        send_no_op_spi_byte();
        send_spi_byte(i, 0x00);
        CS = 1;
    }
    
    for (i = 1; i < 9; i++)
    {
        CS = 0;
        send_spi_byte(i, 0x00);
        send_no_op_spi_byte();
        CS = 1;
    }
    
}