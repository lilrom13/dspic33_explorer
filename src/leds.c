/********************************************************************
 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the "Company") for its PIC(R) Microcontroller is intended and
 supplied to you, the Company's customer, for use solely and
 exclusively on Microchip PIC Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *******************************************************************/

#include <xc.h>
#include <leds.h>
#include <stdbool.h>

#include "pim_dspic33ep512mu810.h"

/*********************************************************************
 * Function: void LED_On(LED led);
 *
 * Overview: Turns requested LED on
 *
 * PreCondition: LED configured via LED_Configure()
 *
 * Input: LED led - enumeration of the LEDs available in this
 *        demo.  They should be meaningful names and not the names of
 *        the LEDs on the silkscreen on the board (as the demo code may
 *        be ported to other boards).
 *         i.e. - LED_On(LED_CONNECTION_DETECTED);
 *
 * Output: none
 *
 ********************************************************************/
void LED_On ( LED led )
{
    uint16_t volatile * p_led_lat = (uint16_t *) &LATAbits;

    switch (led)
    {
        case LED_D3:
            *p_led_lat |= LED_ON << _LATA_LATA0_POSITION;
            break ;

        case LED_D4:
            *p_led_lat |= LED_ON << _LATA_LATA1_POSITION;
            break ;

        case LED_D5:
            *p_led_lat |= LED_ON << _LATA_LATA2_POSITION;
            break ;

        case LED_D6:
            *p_led_lat |= LED_ON << _LATA_LATA3_POSITION;
            break ;

        case LED_D7:
            *p_led_lat |= LED_ON << _LATA_LATA4_POSITION;
            break ;

        case LED_D8:
            *p_led_lat |= LED_ON << _LATA_LATA5_POSITION;
            break ;

        case LED_D9:
            *p_led_lat |= LED_ON << _LATA_LATA6_POSITION;
            break ;

        case LED_D10:
            *p_led_lat |= LED_ON << _LATA_LATA7_POSITION;
            break ;

        case LED_NONE:
            break ;
    }
}
/*********************************************************************
 * Function: void LED_Off(LED led);
 *
 * Overview: Turns requested LED off
 *
 * PreCondition: LED configured via LEDConfigure()
 *
 * Input: LED led - enumeration of the LEDs available in this
 *        demo.  They should be meaningful names and not the names of
 *        the LEDs on the silkscreen on the board (as the demo code may
 *        be ported to other boards).
 *         i.e. - LED_Off(LED_CONNECTION_DETECTED);
 *
 * Output: none
 *
 ********************************************************************/
void LED_Off ( LED led )
{
    uint16_t volatile * p_led_lat = (uint16_t *) &LATAbits;

    switch (led)
    {
        case LED_D3:
            *p_led_lat &= ~(1 << _LATA_LATA0_POSITION);
            break ;

        case LED_D4:
            *p_led_lat &= ~(1 << _LATA_LATA1_POSITION);
            break ;

        case LED_D5:
            *p_led_lat &= ~(1 << _LATA_LATA2_POSITION);
            break ;

        case LED_D6:
            *p_led_lat &= ~(1 << _LATA_LATA3_POSITION);
            break ;

        case LED_D7:
            *p_led_lat &= ~(1 << _LATA_LATA4_POSITION);
            break ;

        case LED_D8:
            *p_led_lat &= ~(1 << _LATA_LATA5_POSITION);
            break ;

        case LED_D9:
            *p_led_lat &= ~(1 << _LATA_LATA6_POSITION);
            break ;

        case LED_D10:
            *p_led_lat &= ~(1 << _LATA_LATA7_POSITION);
            break ;

        case LED_NONE:
            break ;
    }
}
/*********************************************************************
 * Function: void LED_Toggle(LED led);
 *
 * Overview: Toggles the state of the requested LED
 *
 * PreCondition: LED configured via LEDConfigure()
 *
 * Input: LED led - enumeration of the LEDs available in this
 *        demo.  They should be meaningful names and not the names of
 *        the LEDs on the silkscreen on the board (as the demo code may
 *        be ported to other boards).
 *         i.e. - LED_Toggle(LED_CONNECTION_DETECTED);
 *
 * Output: none
 *
 ********************************************************************/
void LED_Toggle ( LED led )
{
    uint16_t volatile * p_led_lat = (uint16_t *) &LATAbits;

    switch (led)
    {
        case LED_D3:
            *p_led_lat ^= 1 << _LATA_LATA0_POSITION;
            break ;

        case LED_D4:
            *p_led_lat ^= 1 << _LATA_LATA1_POSITION;
            break ;

        case LED_D5:
            *p_led_lat ^= 1 << _LATA_LATA2_POSITION;
            break ;

        case LED_D6:
            *p_led_lat ^= 1 << _LATA_LATA3_POSITION;
            break ;

        case LED_D7:
            *p_led_lat ^= 1 << _LATA_LATA4_POSITION;
            break ;

        case LED_D8:
            *p_led_lat ^= 1 << _LATA_LATA5_POSITION;
            break ;

        case LED_D9:
            *p_led_lat ^= 1 << _LATA_LATA6_POSITION;
            break ;

        case LED_D10:
            *p_led_lat ^= 1 << _LATA_LATA7_POSITION;
            break ;

        case LED_NONE:
            break ;
    }
}
/*********************************************************************
 * Function: bool LED_Get(LED led);
 *
 * Overview: Returns the current state of the requested LED
 *
 * PreCondition: LED configured via LEDConfigure()
 *
 * Input: LED led - enumeration of the LEDs available in this
 *        demo.  They should be meaningful names and not the names of
 *        the LEDs on the silkscreen on the board (as the demo code may
 *        be ported to other boards).
 *         i.e. - LED_Get(LED_CONNECTION_DETECTED);
 *
 * Output: true if on, false if off
 *
 ********************************************************************/
bool LED_Get ( LED led )
{
    uint16_t volatile * p_led_lat = (uint16_t *) &LATAbits;

    switch (led)
    {
        case LED_D3:
            return ( (*p_led_lat >> _LATA_LATA0_POSITION) & LED_ON ? true : false );

        case LED_D4:
            return ( (*p_led_lat >> _LATA_LATA1_POSITION) & LED_ON ? true : false );

        case LED_D5:
            return ( (*p_led_lat >> _LATA_LATA2_POSITION) & LED_ON ? true : false );

        case LED_D6:
            return ( (*p_led_lat >> _LATA_LATA3_POSITION) & LED_ON ? true : false );

        case LED_D7:
            return ( (*p_led_lat >> _LATA_LATA4_POSITION) & LED_ON ? true : false );

        case LED_D8:
            return ( (*p_led_lat >> _LATA_LATA5_POSITION) & LED_ON ? true : false );

        case LED_D9:
            return ( (*p_led_lat >> _LATA_LATA6_POSITION) & LED_ON ? true : false );

        case LED_D10:
            return ( (*p_led_lat >> _LATA_LATA7_POSITION) & LED_ON ? true : false );

        case LED_NONE:
            return false ;

    }
    return false ;
}
/*********************************************************************
 * Function: void LED_Enable(LED led);
 *
 * Overview: Configures the LED for use by the other LED API
 *
 * PreCondition: none
 *
 * Input: LED led - enumeration of the LEDs available in this
 *        demo.  They should be meaningful names and not the names of
 *        the LEDs on the silkscreen on the board (as the demo code may
 *        be ported to other boards).
 *
 * Output: none
 *
 ********************************************************************/
void LED_Enable ( LED led )
{
    uint16_t volatile * p_led_tris = (uint16_t *) &TRISAbits;

    switch (led)
    {
        case LED_D3:
            *p_led_tris &= ~_TRISA_TRISA0_MASK;
            break ;

        case LED_D4:
            *p_led_tris &= ~_TRISA_TRISA1_MASK;
            break ;

        case LED_D5:
            *p_led_tris &= ~_TRISA_TRISA2_MASK;
            break ;

        case LED_D6:
            *p_led_tris &= ~_TRISA_TRISA3_MASK;
            break ;

        case LED_D7:
            *p_led_tris &= ~_TRISA_TRISA4_MASK;
            break ;

        case LED_D8:
            *p_led_tris &= ~_TRISA_TRISA5_MASK;
            break ;

        case LED_D9:
            *p_led_tris &= ~_TRISA_TRISA6_MASK;
            break ;

        case LED_D10:
            *p_led_tris &= ~_TRISA_TRISA7_MASK;
            break ;

        case LED_NONE:
            break ;
    }
}

