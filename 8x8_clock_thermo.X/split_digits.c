#include <pic.h>
#include "config.h"

void split_digits(void)
{
    secs_lsb = seconds%10;
    secs_msb = seconds/10;
    mins_lsb = minutes%10;
    mins_msb = minutes/10;
    hours_lsb = hours%10;
    hours_msb = hours/10;
}
