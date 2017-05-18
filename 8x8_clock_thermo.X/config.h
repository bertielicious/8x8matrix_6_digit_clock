/* 
 * File:   config.h
 * Author: Phil
 *
 * Created on 17 February 2017, 11:09
 */


// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>
#include <pic.h>
#include <stdio.h>
#include <stdlib.h>


// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator 32.768kHz)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 32768        // 32.768kHz watch XTAL

//**********************SPI CONSTANTS***********************************************
#define normal_operation_addr 0x0C //normal operation mode hi byte
#define normal_operation_data 0x01 //normal operation mode lo byte
#define decode_off_addr 0x09 // no BCD decoding needed hi byte
#define decode_off_data 0x00 // no BCD decoding needed lo byte
#define scan_limit_addr 0x0B // display 8 columns of leds hi byte
#define scan_limit_data 0x07 // display 8 columns of leds lo byte
#define display_intensity_addr 0x0A // minimum display intensity hi byte
#define display_intensity_data 0x00 // minimum display intensity lo byte
#define no_op_addr 0x00 // No operation address
#define no_op_data 0x00 // No operation data

//**********************DEFINITIONS OF PORT IN/OUTPUTS************************
#define CS PORTAbits.RA5
#define DIAGNOSTIC_LED PORTCbits.RC6
#define SET_TIME PORTAbits.RD3
#define SET_DATE PORTAbits.RD2
#define MONTH_HOURS PORTAbits.RD1
#define DAY_MINS PORTAbits.RD0
#define TEMP_IN PORTAbits.RA0    // analogue input to microcontroller for LM35
/*******GLOBAL VARIABLES******************************************************/
int seconds = 0;
int minutes = 0;
int hours = 0;
int secs_lsb = 0;
int secs_msb = 0;
int mins_lsb = 0;
int mins_msb = 0;
int hours_lsb = 0;
int hours_msb = 0;

/*****************************************************************************/

