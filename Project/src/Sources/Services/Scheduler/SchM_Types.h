/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %SchM_Types.h%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia%
* %date_created:    13/07/2015 %
*=============================================================================*/
/* DESCRIPTION : 					                                          */
/*============================================================================*/
/* FUNCTION COMMENT : 													      */
/* 																			  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  | 				               |Alexis Garcia     */
/* 								                                              */
/*============================================================================*/
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  2.0      | 17/07/2015  | Correction of naming convention |Alexis Garcia     */
/* 								                                              */
/*============================================================================*/
#ifndef _SCHEDULER_TYPE_H
#define _SCHEDULER_TYPE_H

/* Includes */
/* -------- */
#include "typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */
typedef void (*TaskFunctionPtrType) (void);
typedef T_UBYTE rub_SchTaskOffsetType;


typedef enum
{
	MASK_3P125MS = 3,
	MASK_6P25MS =  7,
	MASK_12P5MS =  15,
	MASK_25MS =    31,
	MASK_50MS =    63,
	MASK_100MS =   127
	
}E_SchTaskMaskType;

typedef enum
{
	TASK_BKG,
	TASK_3P125MS,
	TASK_6P25MS,
	TASK_12P5MS,
	TASK_25MS,
	TASK_50MS,
	TASK_100MS
	
}E_SchTaskIdType;

typedef enum
{
	TASK_STATE_SUSPENDED,
	TASK_STATE_READY,
	TASK_STATE_RUNNING
	
}E_SchTaskStateType;

typedef struct
{
	E_SchTaskStateType SchTaskState;
	TaskFunctionPtrType	TaskFunctionControlPtr;
	
}S_SchTaskControlBlock;

typedef struct
{
	rub_SchTaskOffsetType SchTaskOffset;
	E_SchTaskMaskType SchTaskMask;
	E_SchTaskIdType SchTaskId;
	TaskFunctionPtrType TaskFunctionPtr;
	
}S_SchTaskTableType;

typedef struct
{
	T_UBYTE SchNumberOfTasks;
	const S_SchTaskTableType *SchTaskTable;
}S_SchConfigType;

typedef enum
{
	SCH_UNINIT,
	SCH_INIT,
	SCH_RUNNING,
	SCH_OVERLOAD,
	SCH_HALTED
	
}E_SchStateType;

typedef struct
{
	T_UBYTE SchCounter;
	E_SchTaskIdType SchTaskRunning;
	E_SchStateType SchStatus;
	
}S_SchControlType;

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


/* Functions macros */


/* Exported defines */
#endif