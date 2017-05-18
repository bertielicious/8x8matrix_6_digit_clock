#include <pic.h>
#include "config.h"
#include "send_spi_byte.h"
void updateDisplay(char *tens_hours_digit, char *hours_digit, char *tens_mins_digit, char *mins_digit,char *tens_secs_digit, char *secs_digit)         // function receives an array from the caller
{
    char i;
   {

        for (i = 0; i < 8; i++)         // write most left hand matrix
        {                               // hours_msb
            CS = 0;                     // hours_lsb
            if(i < 4)
            {
            send_no_op_spi_byte();
            send_no_op_spi_byte();
            send_spi_byte(i + 1, *tens_hours_digit);
            tens_hours_digit = tens_hours_digit + 1;
            }
            if (i >= 4)
            {
            send_no_op_spi_byte();
            send_no_op_spi_byte();
            send_spi_byte(i + 1, *hours_digit);
            hours_digit = hours_digit + 1;
            }
            CS = 1;
        }


        for (i = 0; i < 8; i++)         // write middle  matrix
        {                               // mins_msb
            CS = 0;                     // mins_lsb
            if(i < 4)
            {
            send_no_op_spi_byte();
            send_spi_byte(i + 1, *tens_mins_digit);
            send_no_op_spi_byte();
            tens_mins_digit = tens_mins_digit + 1;
            }

            if (i >= 4)
            {
            send_no_op_spi_byte();
            send_spi_byte(i + 1, *mins_digit);
            send_no_op_spi_byte();
            mins_digit = mins_digit + 1;
            }
            CS = 1;
        }

        for (i = 0; i < 8; i++)         // write most right matrix
        {                               // secs_msb
            CS = 0;                     // secs_lsb
            if(i < 4)
            {
            send_spi_byte(i + 1, *tens_secs_digit);
            send_no_op_spi_byte();
            send_no_op_spi_byte();
            tens_secs_digit = tens_secs_digit + 1;
            }
            if (i >= 4)
            {
            send_spi_byte(i + 1, *secs_digit);
            send_no_op_spi_byte();
            send_no_op_spi_byte();
            secs_digit = secs_digit + 1;
            }
            CS = 1;
        }
    }
}
