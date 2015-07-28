/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %ButtonManager.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia%
* %date_created:    21/07/2015%
*=============================================================================*/
/* DESCRIPTION : C source that contains the driver control for buttons           */
/*============================================================================*/
/* FUNCTION COMMENT : This file inlcudes the driver for the buttons in the window lifter
						appplication 										  */
/*                                                							  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 21/07/2015  |                               | Alexis Garcia     */
/* Creation of the module                                             */
/*============================================================================*/
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.1      | 28/07/2015  |                               | Alexis Garcia    */
/* Correction of some magic number                                            */
/*============================================================================*/


/* Includes */
/* -------- */
#include "ButtonManager.h"
#include "window_lifter.h"

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

T_UWORD rub_timer = 0;
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
 *  Name                 :	BM_GetCommandButton
 *  Description          :	Provides a function that filters the signal coming from the debounce
 							and determines the command functionality for the wl app, also determines the mode of function (auto/manual)
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    [yes]
 **************************************************************/
void BM_GetCommandButton (void)
{
	if(BtnValidation == 1)
	{
		rub_timer ++;
		if( (BtnCktDbn == AP_SIGNAL) && (re_Direction == GOING_UP) && re_Mode == AUTO)
		{
			if(re_State == UP)
				rub_AntiPinch = 1;
		}
		else if(BtnCktDbn == AP_SIGNAL_MANUAL && re_Direction == GOING_UP && re_Mode == MANUAL)
		{
			if(re_State == UP)
				rub_AntiPinch = 1;
		}
		else if(BtnCktDbn == UP_SIGNAL && !DOWN_PRESS)
		{
			if(rub_timer <= BM_Timer_Cfg)
			{
				re_Mode = AUTO;
			}
			else
			{
				re_Mode = MANUAL;	
			}
			re_Direction = GOING_UP;
		}
		else if( BtnCktDbn == DOWN_SIGNAL && !UP_PRESS) 
		{
			if(rub_timer <= BM_Timer_Cfg)
			{
				re_Mode = AUTO;
			}
			else 
			{
				re_Mode = MANUAL;	
			}
			re_Direction = GOING_DOWN;
		}
		else if(BtnCktDbn == NO_PRESS)
		{
			re_Direction = INMOVIL;
			BtnValidation = 0;
		}
		else
		{
			BtnValidation = 0;	
		}
	}
	else
	{
		rub_timer = 0;
	}
}

/**************************************************************
 *  Name                 :	BM_InitButtons
 *  Description          :	Provides the function of initialice certain number of buttons in input mode 
 *  Parameters           :  void
 *  Return               :  void
 *  Critical/explanation :    [no]
 **************************************************************/
void BM_InitButtons(void)
{
	T_UBYTE lub_iterator;
	for(lub_iterator = 0; lub_iterator < BtnNumber ; lub_iterator++)
	{
		SIU.GPDI[lub_iterator + PIN_BTN].R = 1;
		SIU.PCR[lub_iterator + PIN_BTN].R = 0x0103;
	}
}
