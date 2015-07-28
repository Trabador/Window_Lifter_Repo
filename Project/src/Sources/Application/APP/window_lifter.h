/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %window_lifter.h%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:     28/07/2015%
*=============================================================================*/
/* DESCRIPTION : Header file for the window lifter                            */
/*============================================================================*/
/* FUNCTION COMMENT : contains defines , enumerations and extern varibles
					  for the module of window lifter app		              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 21/07/2015  | 								| Alexis Garcia    */
/* Integration under Continuus CM                                             */
/*============================================================================*/


#ifndef _Window_H        /*prevent duplicated includes*/
#define _Window_H

/*-- Includes ----------------------------------------------------------------*/
#include "typedefs.h"
#include "leds.h"
#include "ButtonManager.h"

/*-- Variables ---------------------------------------------------------------*/
extern T_UBYTE rub_AntiPinch;
/*-- Types Definitions -------------------------------------------------------*/
typedef	enum
{
	IDLE = 0,
	UP,
	DOWN,
	PROTECT
}E_StateList;

typedef enum
{
	AUTO = 0,
	MANUAL
}E_ModeList;

typedef enum
{
	INMOVIL = 0,
	GOING_UP,
	GOING_DOWN
}E_DirectionList;

extern E_StateList 		re_State;
extern E_ModeList 		re_Mode;
extern E_DirectionList 	re_Direction;
/*-- Defines -----------------------------------------------------------------*/
#define 	WL_timer_cfg		10
#define		BLOCK_5S			125
#define 	MAX_LED				1
#define 	MIN_LED				10
#define 	Enabled				1


/*-- Function Prototypes -----------------------------------------------------*/
extern void initTimer(void);
void delay_ms(T_UWORD luw_time);

extern void WL_StateMachine(void);

#endif /* _Window_H */

/*******************************************************************************/
