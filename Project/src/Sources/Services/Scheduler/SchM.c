/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %SchM.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    13/07/2015%
*=============================================================================*/
/* DESCRIPTION : 					                                          */
/*============================================================================*/
/* FUNCTION COMMENT : 														  */
/* 							                                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  |                               | Alexis Garcia    */
/* 									                                          */
/*============================================================================*/

/* Includes */
/* -------- */

#include "SchM.h"
#include  "PIT.h"
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
 SchControlType SchControl;
 const SchConfigType * rps_SchConfigurationPtr;
 SchTaskControlBlock *SchTaskControl;

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
 *  Name                 :	SchM_Init
 *  Description          :	Initialice and allocate the necessesary resources to be used by the scheduler.
 							Initialice the PIT , sets all the tasks in the task control block in suspended state
 							and sets the shcheduler state in init 	
 *  Parameters           :  In SchConfigType *SchM_Config
 *  Return               :	void
 *  Critical/explanation :  [yes]
 **************************************************************/
 void SchM_Init(const SchConfigType *SchM_Config)
 {
 	T_UBYTE lub_i;
 	SchTaskTableType * aux;
 	
 	
 	PIT_device_init();
    PIT_channel_configure(PIT_CHANNEL_0 , SchM_OsTick);	
 	rps_SchConfigurationPtr = SchM_Config;
 	aux = (SchTaskTableType *)SchM_Config->SchTaskTable;
 	
 	SchTaskControl = (SchTaskControlBlock *)MemAlloc(sizeof(SchTaskControlBlock)*SchM_Config->SchNumberOfTasks);
 	
 	for(lub_i=0;lub_i<SchM_Config->SchNumberOfTasks;lub_i++)
 	{
 		SchTaskControl[lub_i].SchTaskState = TASK_STATE_SUSPENDED;
 		SchTaskControl[lub_i].TaskFunctionControlPtr = aux[lub_i].TaskFunctionPtr;
 	}
 	SchControl.SchStatus = SCH_INIT;
 }
 
 
 /**************************************************************
 *  Name                 :	SchM_Stop
 *  Description          :	Stops the pit channel, and puts the scheduler state in Halted
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [no]
 **************************************************************/
 void SchM_Stop(void)
 {
 	PIT_channel_stop(PIT_CHANNEL_0);
 	SchControl.SchStatus = SCH_HALTED;
 }
 
 
 /**************************************************************
 *  Name                 :	SchM_Start
 *  Description          :	Starts the pit channel, the scheduler counter and calls the background function
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [no]
 **************************************************************/
 void SchM_Start(void)
 {
 	PIT_channel_start(PIT_CHANNEL_0);
 	SchControl.SchCounter = 0;
 	SchM_Background();		
 }
 
 
 /**************************************************************
 *  Name                 :	SchM_OsTick
 *  Description          :	This is called in the periodic interruption tick of the scheduler,checks every task
 							for a valid activation based on the formula (mask & counter) = offset, and if its valid
 							sets the respective task in ready
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [yes ]
 **************************************************************/
 void SchM_OsTick(void)
 {
 
 	T_UBYTE lub_i;
 	SchTaskTableType * aux;
 	
 	SchControl.SchCounter++;
 	aux = (SchTaskTableType *)rps_SchConfigurationPtr->SchTaskTable;
 	for(lub_i=0;lub_i<rps_SchConfigurationPtr->SchNumberOfTasks;lub_i++)
 	{
 		if(((aux[lub_i].SchTaskMask) & (SchControl.SchCounter)) == aux[lub_i].SchTaskOffset)
 		{
 			SchTaskControl[lub_i].SchTaskState = TASK_STATE_READY;
 		}
 	}
 	
 }
 
 
 /**************************************************************
 *  Name                 :	SchM_Background
 *  Description          :	Checks for the tasks that are ready state and makes them run, 
 							after that , sets his state in suspended
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [yes]
 **************************************************************/
 void SchM_Background(void)
 {
 	T_UBYTE lub_i;
 	for(;;)	/*infinite loop*/
 	{
 		for(lub_i=0;lub_i<rps_SchConfigurationPtr->SchNumberOfTasks;lub_i++)
 		{
 			if(SchTaskControl[lub_i].SchTaskState == TASK_STATE_READY)
 			{
 				SchControl.SchStatus = SCH_RUNNING;
 				SchTaskControl[lub_i].SchTaskState = TASK_STATE_RUNNING;
 				SchTaskControl[lub_i].TaskFunctionControlPtr();
 				SchTaskControl[lub_i].SchTaskState = TASK_STATE_SUSPENDED;
 			}
 		}
 	}
 }