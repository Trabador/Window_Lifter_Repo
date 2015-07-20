/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %leds.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia%
* %date_created:    20/07/2015
*=============================================================================*/
/* DESCRIPTION : Leds driver			                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This includes the basic functionality of the leds module
						and configuration of the leds module				  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 20/07/2015  |creation of the component      | Alexis Garcia 	  */
/*                                             */
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

/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	2
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Exported functions */
/* ------------------ */

/**************************************************************
 *  Name                 :	initLeds
 *  Description          :	sets the led bar on default (closed) 
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    no
 ***************************************************************/



void initLeds(void)
{
	LED1_ON;
	LED2_ON;
	LED3_ON;
	LED4_ON;
	LED5_ON;
	LED6_ON;
	LED7_ON;
	LED8_ON;
	LED9_ON;
	LED10_ON;
	LED_B_OFF;
	LED_G_OFF;
}