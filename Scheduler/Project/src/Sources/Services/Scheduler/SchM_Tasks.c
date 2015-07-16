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

/* Includes */
/* -------- */
#include "GPIO.h"	/*for test purposes*/

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
 void task_3P125MS(void)
 {
 	
 }
 
 
 /**************************************************************
 *  Name                 :	task_6P25MS
 *  Description          :	call of the function every 6.25 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [No]
 **************************************************************/
 void task_6P25MS(void)
 {
 	
 }
 
 
 /**************************************************************
 *  Name                 :	task_12P5MS
 *  Description          :	call of the function every 12.5 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [No]
 **************************************************************/
 void task_12P5MS(void)
 {
 	/*for test purposes*/
 }
 
 
 /**************************************************************
 *  Name                 :	task_25MS
 *  Description          :	call of the function every 25 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [No]
 **************************************************************/
 void task_25MS(void)
 {
 	LED_TOGGLE(LED3);
 }
 
 
 /**************************************************************
 *  Name                 :	task_50MS
 *  Description          :	call of the function every 50 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [No]
 **************************************************************/
 void task_50MS(void)
 {
 	LED_TOGGLE(LED1);/*for test purposes*/
 }
 
 
 /**************************************************************
 *  Name                 :	task_100MS
 *  Description          :	call of the function every 100 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation : 	[No]
 **************************************************************/
 void task_100MS(void)
 {
 	LED_TOGGLE(LED2);
 }
 
 