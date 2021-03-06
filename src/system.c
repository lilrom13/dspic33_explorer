/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC33E__)
    	#include <p33Exxxx.h>
    #elif defined(__dsPIC33F__)
    	#include <p33Fxxxx.h>
    #endif
#endif


#include <stdint.h>          /* For uint16_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */

#include "system.h"          /* variables/params used by system.c             */

/******************************************************************************/
/* System Level Functions                                                     */
/*                                                                            */
/* Custom oscillator configuration funtions, reset source evaluation          */
/* functions, and other non-peripheral microcontroller initialization         */
/* functions get placed in system.c.                                          */
/*                                                                            */
/******************************************************************************/

/* Refer to the device Family Reference Manual Oscillator section for
information about available oscillator configurations.  Typically
this would involve configuring the oscillator tuning register or clock
switching useing the compiler's __builtin_write_OSCCON functions.
Refer to the C Compiler for PIC24 MCUs and dsPIC DSCs User Guide in the
compiler installation directory /doc folder for documentation on the
__builtin functions.*/

/* TODO Add clock switching code if appropriate.  An example stub is below.   */
/*The following process is used to set up the PLL to operate the device at 60 MIPS with a 8 MHz
external crystal:
1. To execute instructions at 60 MHz, ensure that the required system clock frequency is:
FOSC = 2 x FCY = 120 MHz
2. To set up the PLL and meet the requirements of the PLL, follow these steps:
a) Select the PLL postscaler to meet the VCO output frequency requirement
(120 MHz < FSYS < 340 MHz).
? Select a PLL postscaler ratio of N2 = 2
? Ensure that FSYS = (FOSC x N2) = 240 MHz
b) Select the PLL prescaler to meet the PFD input frequency requirement
(0.8 MHz < FPLLI < 8.0 MHz).
? Select a PLL prescaler ratio of N1 = 2
? Ensure that FPLLI = (FIN ÷ N1) = 5 MHz
c) Select the PLL feedback divisor to generate the required VCO output frequency
based on the PFD input frequency.
? FSYS = FPLLI x M
? M = FSYS ÷ FPLLI = 48
d) Configure the FNOSC<2:0> bits (FOSCSEL<2:0>) to select a clock source without
the PLL (for example, Internal FRC) at Power-on Reset.
e) In the main program, change the PLL prescaler, PLL postscaler and PLL feedback
divisor values to those just dec*/
void ConfigureOscillator(void)
{
    /* Disable Watch Dog Timer */
    RCONbits.SWDTEN = 0;

    // Configure PLL prescaler, PLL postscaler, PLL divisor
    PLLFBD = 63; // M=65
    CLKDIVbits.PLLPOST = 0; // N2=2
    CLKDIVbits.PLLPRE = 1; // N1=3
    
    // Initiate Clock Switch to Primary Oscillator with PLL (NOSC=0b011)
    __builtin_write_OSCCONH(0x03);
    __builtin_write_OSCCONL(OSCCON | 0x01);
    // Wait for Clock switch to occur
    while (OSCCONbits.COSC != 0b011);
    // Wait for PLL to lock
    while (OSCCONbits.LOCK != 1);
}

