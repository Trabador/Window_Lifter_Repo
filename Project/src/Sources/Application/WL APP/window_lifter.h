/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %window_lifter.h%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:     %
*=============================================================================*/
/* DESCRIPTION : Header file for the window lifter                            */
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  | SAR/SIF/SCN_xxx               | Alexis Garcia    */
/* Integration under Continuus CM                                             */
/*============================================================================*/


#ifndef _Window_H        /*prevent duplicated includes*/
#define _Window_H

/*-- Includes ----------------------------------------------------------------*/

/** Core modules */
/** Variable types and common definitions */

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


#define		min_valid_value 9
#define 	five_hundred_ms 500
#define 	exit_condition 	510
#define 	WL_timer_cfg	4
#define		BLOCK_5S	50


/*-- Function Prototypes -----------------------------------------------------*/

extern void initGPIO(void);
extern void initTimer(void);
void delay_ms(T_UWORD luw_time);

extern void WL_StateMachine(void);

#endif /* _Window_H */

/*******************************************************************************/
