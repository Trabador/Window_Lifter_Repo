/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %SchM_Cfg.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    13/07/2015%
*=============================================================================*/
/* DESCRIPTION : 					                                          */
/*============================================================================*/
/* FUNCTION COMMENT : 														  */
/* 								                                              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  |                               |Alexis Garcia     */
/* 								                                              */
/*============================================================================*/


/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  2.0      | 17/07/2015  | Correction of naming convention |Alexis Garcia     */
/* 								                                              */
/*============================================================================*/
/* Includes */
/* -------- */
#include "SchM_Cfg.h"
#include "SchM_Tasks.h"




/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */
const S_SchTaskTableType cas_SchTaskTableConfig [] =
{
	/*Offset, Mask, TaskID, Function Pointer*/
	{0, MASK_3P125MS, TASK_3P125MS, &Sch_Task3P125MS},
	{1, MASK_6P25MS,   TASK_6P25MS, &Sch_Task6P25MS},
	{2, MASK_12P5MS,   TASK_12P5MS, &Sch_Task12P5MS},
	{3, MASK_25MS,       TASK_25MS, &Sch_Task25MS},
	{5, MASK_50MS,       TASK_50MS, &Sch_Task50MS},
	{6, MASK_100MS,     TASK_100MS, &Sch_Task100MS}
};

const S_SchConfigType cs_SchConfig = 
{
	(sizeof(cas_SchTaskTableConfig)/sizeof(cas_SchTaskTableConfig[0])),
	cas_SchTaskTableConfig	
};


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
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/