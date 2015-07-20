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
#include "buttons.h"

/*-- Variables ---------------------------------------------------------------*/

extern T_UBYTE rub_goUp;
/*-- Types Definitions -------------------------------------------------------*/

/*-- Defines -----------------------------------------------------------------*/


#define		min_valid_value 9
#define 	five_hundred_ms 500
#define 	exit_condition 	510


/*-- Function Prototypes -----------------------------------------------------*/

extern void initGPIO(void);
extern void initTimer(void);
void delay_ms(T_UWORD luw_time);

extern void downPressed(void);
void autoDown(void);
void manualDown(T_UBYTE *lpub_ptr);
extern void upPressed(void);
void autoUp(void);
void manualUp(T_UBYTE *lpub_ptr);
void pinchInterruption(void);

#endif /* _Window_H */

/*******************************************************************************/
