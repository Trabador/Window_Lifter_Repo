/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %SchM_Tasks.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    13/07/2015%
*=============================================================================*/
/* DESCRIPTION : 					                                          */
/*============================================================================*/
/* FUNCTION COMMENT : 														  */
/* 									                                          */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  |                               |Alexis Garcia     */
/* 									                                          */
/*============================================================================*/
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  2.0      | 17/07/2015  | Correction of naming convention |Alexis Garcia     */
/* 								                                              */
/*============================================================================*/
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  2.1      | 27/07/2015  | Minor function name changes |Alexis Garcia     */
/* 								                                              */
/*============================================================================*/
/* Includes */
/* -------- */
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



/* Private functions */
/* ----------------- */



/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	task_3P125MS
 *  Description          :	call of the function every 3.125 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [No]
 **************************************************************/
 void Sch_Task1P25MS(void)
 {
 	if(rub_AntiPinch == 0)
 	{
 		DEB_DebounceDetection();
 	}		
 }
 
 
 /**************************************************************
 *  Name                 :	task_6P25MS
 *  Description          :	call of the function every 6.25 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [No]
 **************************************************************/
 void Sch_Task2P5MS(void)
 {
 	
 }
 
 
 /**************************************************************
 *  Name                 :	task_12P5MS
 *  Description          :	call of the function every 12.5 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [No]
 **************************************************************/
 void Sch_Task5MS(void)
 {
 	
 }
 
 
 /**************************************************************
 *  Name                 :	task_25MS
 *  Description          :	call of the function every 25 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [No]
 **************************************************************/
 void Sch_Task10MS(void)
 {
 	BM_GetCommandButton();
 }
 
 
 /**************************************************************
 *  Name                 :	task_50MS
 *  Description          :	call of the function every 50 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [No]
 **************************************************************/
 void Sch_Task20MS(void)
 {
 			
 }
 
 
 /**************************************************************
 *  Name                 :	task_100MS
 *  Description          :	call of the function every 100 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation : 	[No]
 **************************************************************/
 void Sch_Task40MS(void)
 {
 	WL_StateMachine();		
 }
 
 