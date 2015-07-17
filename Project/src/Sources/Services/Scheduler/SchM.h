/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %SchM.h%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis %
* %date_created:    13/07/2015%
*=============================================================================*/
/* DESCRIPTION : 					                                          */
/*============================================================================*/
/* FUNCTION COMMENT : 														  */
/*																			  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  | 			                   |Alexis Garcia     */
/* 								                                              */
/*============================================================================*/

/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  2.0      | 17/07/2015  | Correction of naming convention |Alexis Garcia     */
/* 								                                              */
/*============================================================================*/
#ifndef _SCHEDULER_H
#define _SCHEDULER_H


/* Includes */
/* -------- */
#include "SchM_Types.h"
#include "SchM_Cfg.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
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
/*Scheduler Initialization*/
extern void SchM_Init(const S_SchConfigType *cs_SchM_Config);
/*Scheduler De-initialization*/
extern void SchM_Stop(void);
/*Scheduler Start*/
extern void SchM_Start(void);
/*OS tick callback function*/
extern void SchM_OsTick(void);
/*Backgroud Task*/
extern void SchM_Background(void);


/* Functions macros */


/* Exported defines */

#endif