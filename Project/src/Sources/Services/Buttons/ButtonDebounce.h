/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %ButtonDebounce.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia%
* %date_created:    21/07/15 %
*=============================================================================*/
/* DESCRIPTION : Header for the debounce driver                                         */
/*============================================================================*/
/* FUNCTION COMMENT : contains definition and externs variables for the debounce driver  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 21/07/2015  |                | Alexis Garcia   					*/
/* Creation of the header                                             			*/
/*============================================================================*/

#ifndef DEB_H
#define DEB_H

/* Includes */
/* -------- */
#include "typedefs.h"
#include "ButtonDebounce.h"
#include "GPIO.h"

/* Exported types and constants */
/* ---------------------------- */
extern T_UBYTE BtnCktDbn;
extern T_UBYTE BtnValidation;
/* Types definition */
#define BttnDbncCount_Cfg 8

#define PIN_DIRECTION (&SIU.GPDI[64].R)
/* typedef */


/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */
extern void DEB_DebounceDetection (void);

/* Functions macros */


/* Exported defines */

#endif