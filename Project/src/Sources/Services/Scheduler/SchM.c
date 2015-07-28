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

/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  2.0      | 17/07/2015  | Correction of naming convention |Alexis Garcia    */
/* 								                                              */
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
 S_SchControlType rs_SchControl;
 const S_SchConfigType * cps_SchConfigurationPtr;
 S_SchTaskControlBlock * rps_SchTaskControl;

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
 void SchM_Init(const S_SchConfigType *cs_SchM_Config)
 {
 	T_UBYTE lub_i;
 	S_SchTaskTableType * lps_TablePtr;
 	
 	
 	PIT_device_init();
    PIT_channel_configure(PIT_CHANNEL_0 , SchM_OsTick);	
 	cps_SchConfigurationPtr = cs_SchM_Config;
 	lps_TablePtr = (S_SchTaskTableType *)cs_SchM_Config->SchTaskTable;
 	
 	rps_SchTaskControl = (S_SchTaskControlBlock *)MemAlloc(sizeof(S_SchTaskControlBlock)*cs_SchM_Config->SchNumberOfTasks);
 	
 	for(lub_i=0;lub_i<cs_SchM_Config->SchNumberOfTasks;lub_i++)
 	{
 		rps_SchTaskControl[lub_i].SchTaskState = TASK_STATE_SUSPENDED;
 		rps_SchTaskControl[lub_i].TaskFunctionControlPtr = lps_TablePtr[lub_i].TaskFunctionPtr;
 	}
 	rs_SchControl.SchStatus = SCH_INIT;
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
 	rs_SchControl.SchStatus = SCH_HALTED;
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
 	rs_SchControl.SchCounter = 0;
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
 	S_SchTaskTableType * lps_TablePtr;
 	
 	rs_SchControl.SchCounter++;
 	lps_TablePtr  = (S_SchTaskTableType *)cps_SchConfigurationPtr->SchTaskTable;
 	for(lub_i=0;lub_i<cps_SchConfigurationPtr->SchNumberOfTasks;lub_i++)
 	{
 		if(((lps_TablePtr[lub_i].SchTaskMask) & (rs_SchControl.SchCounter)) == lps_TablePtr[lub_i].SchTaskOffset)
 		{
 			rps_SchTaskControl[lub_i].SchTaskState = TASK_STATE_READY;
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
 		for(lub_i=0;lub_i<cps_SchConfigurationPtr->SchNumberOfTasks;lub_i++)
 		{
 			if(rps_SchTaskControl[lub_i].SchTaskState == TASK_STATE_READY)
 			{
 				rs_SchControl.SchStatus = SCH_RUNNING;
 				rps_SchTaskControl[lub_i].SchTaskState = TASK_STATE_RUNNING;
 				rps_SchTaskControl[lub_i].TaskFunctionControlPtr();
 				rps_SchTaskControl[lub_i].SchTaskState = TASK_STATE_SUSPENDED;
 			}
 		}
 	}
 }