/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %ButtonDebounce.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia%
* %date_created:    28/07/2015%
*=============================================================================*/
/* DESCRIPTION : C source that contains the driver control for the button debounce         */
/*============================================================================*/
/* FUNCTION COMMENT : This file inlcudes the driver for the debounce in the window lifter
						appplication 										  */
/*                                                							  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 24/07/2015  |                               | Alexis Garcia    */
/* Creation Of The Module		                                              */
/*  1.1      | 26/07/2015  |							   | Roberto Palos    */
/* Creation of the function DEB_GetButtons				   					  */
/*  1.2		 | 27/07/2015  |                               | Alexis Garcia	  */
/* Adaptation of the functionDEB_GetButtons to work with function DEB_Debounce*/
/* Detection.                                                                 */
/*============================================================================*/

/* Includes */
/* -------- */
#include "ButtonDebounce.h"
#include "ButtonManager.h"

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
T_UBYTE BtnCktDbn = 0;
T_UBYTE BtnValidation = 0;


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */
T_UBYTE DEB_GetButtons(void);


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
 *  Name                 :	DEB_DebounceDetection
 *  Description          :	Provides the functionality for the detection of the debounce of a button, if is pressed 
 							for more than 10 millisencods it consider a valid press
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    [yes]
 **************************************************************/
void DEB_DebounceDetection (void)
{
	T_UBYTE BtnCktIn;
	static BtnCktIn_count = 0;
	static T_UBYTE BtnCktInPrev = 0;
	
	BtnCktIn = DEB_GetButtons();
	if(BtnCktInPrev == BtnCktIn)
	{
		BtnCktIn_count++;
		if(BtnCktIn_count >= BttnDbncCount_Cfg)
		{
			BtnCktIn_count = 0;
			BtnCktDbn = BtnCktIn;
			BtnValidation = 1;
		}
	}
	else
	{
		BtnValidation = 0;
		BtnCktIn_count = 0;
		BtnCktInPrev = BtnCktIn;
	}
}
/**************************************************************
 *  Name                 :	DEB_GetButtons
 *  Description          :  Gets the direction of the register and process the data to return a value that contains 
 							the bits that represents the buttons presed in that time
 *  Parameters           :  void
 *  Return               :	T_UBYTE lub_ButtonValue
 *  Critical/explanation :    [yes]
 **************************************************************/

T_UBYTE DEB_GetButtons(void)
{
	T_UBYTE lub_iterator;
	T_UBYTE *lpub_PinNumber;
	T_UBYTE lub_BitValue;
	T_UBYTE lub_ButtonValue;
	lpub_PinNumber = PIN_DIRECTION;
	lub_ButtonValue = 0;
	for(lub_iterator = 0; lub_iterator < BtnNumber ; lub_iterator++){
		lub_BitValue = (*lpub_PinNumber & 0x01);
		lub_ButtonValue = lub_ButtonValue + lub_BitValue;
		if(BtnNumber == lub_iterator + 1){
		}
		else
		{
			lub_ButtonValue = lub_ButtonValue << 1;
			lpub_PinNumber++;
		}
	}
	return lub_ButtonValue;
}


