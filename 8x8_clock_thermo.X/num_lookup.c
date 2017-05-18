#include <pic.h>
#include"config.h"
#include"updateDisplay.h"
#include"send_spi_byte.h"
#include"send_no_op_spi_byte.h"
char j;
void num_lookup(void)
{
   // char null[] = {0x00, 0x00, 0x00, 0x00};
   char num[40] = {0xfc, 0x84, 0xfc, 0x00, 0x10, 0x08, 0xfc, 0x00,
    0xF4, 0x94, 0x9C, 0x00,0x84, 0x94, 0xFC, 0x00, 0x3c, 0x20, 0xF8, 0x00,
    0x9c, 0x94, 0xF4, 0x00,0xFc, 0x94, 0xF4, 0x00,0x04, 0xe4, 0x1C, 0x00,
    0xfc, 0xa4, 0xFc, 0x00, 0xbc, 0xa4, 0xFc, 0x00 };// 4 byte numbers defined with
                                                 // values from 0 to 9
// 0 = [0]->[3]
// 1 = [4]->[7]
// 2 = [8]->[11]
// 3 = [12]->[15]
// 4 = [16]->[19]
// 5 = [20]->[23]
// 6 = [24]->[27]
// 7 = [28]->[31]
// 8 = [32]->[35]
// 9 = [36]->[39]
   

  updateDisplay(&num[hours_msb * 4], &num[hours_lsb * 4], &num[mins_msb * 4],&num[mins_lsb * 4], &num[secs_msb * 4], &num[secs_lsb * 4]);
        
}