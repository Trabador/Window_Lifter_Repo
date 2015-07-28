/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %ButtonManager.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia%
* %date_created:    21/07/15 %
*=============================================================================*/
/* DESCRIPTION : Header for the button driver                                         */
/*============================================================================*/
/* FUNCTION COMMENT : contains definition and externs variables for the button driver  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 21/07/2015  |                | Alexis Garcia   					*/
/* Creation of the header                                             			*/
/*============================================================================*/


/* Includes */
#include "ButtonDebounce.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
#define 	up    64
#define 	down  65
#define 	pinch 66

#define 	PIN_BTN	  64
#define 	BtnNumber 3

#define 	BM_Timer_Cfg  25

#define 	UP_SIGNAL 	     	3
#define 	DOWN_SIGNAL			5
#define 	AP_SIGNAL			6
#define 	AP_SIGNAL_MANUAL 	2
#define 	NO_PRESS			7

#define 	UP_PRESS 	 	(SIU.GPDI[up].R == 0)
#define		UP_RELEASE 	 	(SIU.GPDI[up].R == 1)
#define 	DOWN_PRESS 	 	(SIU.GPDI[down].R == 0)
#define		DOWN_RELEASE 	(SIU.GPDI[down].R == 1)
#define 	PINCH_PRESS 	(SIU.GPDI[pinch].R == 0)
#define		PINCH_RELEASE 	(SIU.GPDI[pinch].R == 1)

/* Functions prototypes */
extern void BM_InitButtons(void);
extern void BM_GetCommandButton	(void);


