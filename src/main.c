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


#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */
#include "leds.h"
/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
int16_t main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();

    /* TODO <INSERT USER APPLICATION CODE HERE> */

    /* turn on a led*/
    
    LED_Enable(LED_D3);
    LED_Enable(LED_D4);
    LED_Enable(LED_D5);
    LED_Enable(LED_D6);
    LED_Enable(LED_D7);
    LED_Enable(LED_D8);
    LED_Enable(LED_D9);
    LED_Enable(LED_D10);
    
    LED_On(LED_D3);
    LED_On(LED_D4);
    LED_On(LED_D5);
    LED_On(LED_D6);
    LED_On(LED_D7);
    LED_On(LED_D8);
    LED_On(LED_D9);
    LED_On(LED_D10);
    
    if (LED_Get(LED_D3))
    {
        LED_Off(LED_D3);
    }
    
    LED_Toggle(LED_D3);
    LED_Toggle(LED_D3);
    
    while(1)
    {

    }
}
