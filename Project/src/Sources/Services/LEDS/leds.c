/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %leds.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia%
* %date_created:    21/07/2015%
*=============================================================================*/
/* DESCRIPTION : C source that contains the driver control for leds           */
/*============================================================================*/
/* FUNCTION COMMENT : This file inlcudes the driver for the leds in the window lifter
						appplication 										  */
/*                                                							  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 21/07/2015  |                               | Alexis Garcia     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */
#include "leds.h"
/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */

/* Exported functions */
/* ------------------ */

/**************************************************************
 *  Name                 :	LED_LedsStartup
 *  Description          :	sets the led bar on default (closed) and the direction leds in off
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    no
 **************************************************************/
void LED_LedsStartup(void)
{
	T_UBYTE led;
	for(led = 1;led <= 10; led++)
	{
		LEDS_ON(led);
			
	}
	LED_B_OFF;
	LED_G_OFF;
}

/**************************************************************
 *  Name                 :	LED_InitLeds
 *  Description          :	sets the ports for the leds in input mode and in off for default
 *  Parameters           :  void
 *  Return               : void
 *  Critical/explanation :    no
 **************************************************************/
void LED_InitLeds(void)
{
	SIU.GPDO[led_g].R = 1;
	SIU.PCR[led_g].R = 0x0200;
	SIU.GPDO[led1].R = 1;
	SIU.PCR[led1].R = 0x0200;
	SIU.GPDO[led2].R = 1;
	SIU.PCR[led2].R = 0x0200;
	SIU.GPDO[led3].R = 1;
	SIU.PCR[led3].R = 0x0200;
	SIU.GPDO[led4].R = 1;
	SIU.PCR[led4].R = 0x0200;
	SIU.GPDO[led5].R = 1;
	SIU.PCR[led5].R = 0x0200;
	SIU.GPDO[led6].R = 1;
	SIU.PCR[led6].R = 0x0200;
	SIU.GPDO[led7].R = 1;
	SIU.PCR[led7].R = 0x0200;
	SIU.GPDO[led8].R = 1;
	SIU.PCR[led8].R = 0x0200;
	SIU.GPDO[led9].R = 1;
	SIU.PCR[led9].R = 0x0200;
	SIU.GPDO[led10].R = 1;
	SIU.PCR[led10].R = 0x0200;
	SIU.GPDO[led_b].R = 1;
	SIU.PCR[led_b].R = 0x0200;
}