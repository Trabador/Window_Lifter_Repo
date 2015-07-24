/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %SchM.c%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      uid10734106 %
* %date_created:    Mon Jul  13 17:36 2015 %
*=============================================================================*/
/* DESCRIPTION :The Schm.c File Is The Main File For The Ejecution Of The
				Task, Decide Wich Task Must Enter And When.					  */
/*============================================================================*/
/* FUNCTION COMMENT :	Initialize The Scheduler, Set All Task To Idle And	  */
/*                      Start The PIT Function For The Scheduler.			  */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 17/07/2015  |                               | Roberto Palos    */
/* 	Version 1 No Error In The Scheduler, Execute The Task At The Defined
				Times.														  */
/*============================================================================*/

/* Includes */
/* -------- */

#include "SchM.h"
#include "SchM_Types.h"
#include "PIT.h"
#include "MemAlloc_Cfg.h"

/*Public Function Definitions*/
/*Public functions shall be exported in SchM.h file and defined in SchM.c file.*/

/*Function initialization of Scheduler module*/
/*The SchM_Init function shall allocate and initialize the resources
to be used by the Scheduler Module,
including the timer module initialization used for the tick reference
and resources requested by the SchMConfig parameter, this means:
	Initialize the callback funtion passed as reference to the timer module used for the tick reference.
	Initialize all the tasks according to the task descriptor to suspended state.
	Initialize the scheduler state to initialized. */
	
/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* LONG and STRUCTURE RAM variables */
SchedulerControlType SchedulerControl;
const SchedulerConfigType  * rps_SchedulerConfigPtr;
SchedulerTaskControlType *SchedulerTaskControl;


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void SchM_Init(const SchedulerConfigType *SchmConfig){
	T_UBYTE lub_Init;
	vfnGPIO_LED_Init();
	INTC_InitINTCInterrupts();
	EXCEP_InitExceptionHandlers();
	enableIrq();
	PIT_device_init();
	PIT_channel_configure(PIT_CHANNEL_0 , SchM_OsTick);
	rps_SchedulerConfigPtr = SchmConfig;
	SchedulerTaskControl = (SchedulerTaskControlType *)MemAlloc(sizeof(SchedulerTaskControlType)*SchmConfig -> SchedulerNumberOfTask);
	for(lub_Init = 0; lub_Init < SchmConfig -> SchedulerNumberOfTask; lub_Init++){
		SchedulerTaskControl[lub_Init].SchedulerTaskState = TASK_STATE_SUSPEND;
		SchedulerTaskControl[lub_Init].TaskFunctionControlPtr = SchmConfig->SchedulerTaskTable[lub_Init].TaskFunctionPtr;
	}
	SchedulerControl.SchedulerStatus = SCHEDULER_INIT;
}

/*Function starts the execution of Scheduler module*/
/*The SchM_Start function shall start the timer channel used for the tick reference, set the scheduler  state to Idle state and call the SchM_Background function*/
void SchM_Start(void){
	PIT_channel_start(PIT_CHANNEL_0);
	SchedulerControl.SchedulerCounter = 0;
 	SchM_Background();
}
/*Function stops the execution of Scheduler module*/
/*The SchM_Stop function shall stop the timer channel used for the tick reference and set the scheduler state to halted*/
void SchM_Stop(void){
	PIT_channel_stop(PIT_CHANNEL_0);
	SchedulerControl.SchedulerStatus = SCHEDULER_HALTED;
}

/*Private Function Definitions*/
/*Private functions shall be defined in SchM.c file.*/

/*Callback function periodically called from the timer module providing the tick reference*/
/*The SchM_OsTick function shall be indirectly called by the timer module used for the
tick reference, when the timer expires. This function shall increment by one the
internal counter and set the correspondig task state to ready as per the define rate monotonic
scheduler algorithm based on the following task descriptor fileds:
	Mask
	Offset*/
void SchM_OsTick(void){
	T_UBYTE lub_Control;
	SchedulerTaskTableType * aux;
	SchedulerControl.SchedulerCounter++;
	aux = (SchedulerTaskTableType *)rps_SchedulerConfigPtr->SchedulerTaskTable;
 	for(lub_Control=0;lub_Control<rps_SchedulerConfigPtr->SchedulerNumberOfTask;lub_Control++){
 		if(((aux[lub_Control].SchedulerTaskMask) & (SchedulerControl.SchedulerCounter)) == aux[lub_Control].SchedulerTaskOffset){
 			SchedulerTaskControl[lub_Control].SchedulerTaskState = TASK_STATE_READY;
 		}
 	}
 }

/*Background function executed when scheduler state is idle*/
/*The SchM_Background function shall execute in an infinite loop. This function searchs for all the tasks to be in the ready state to be executed and:
Before the task execution:
	Set the scheduler state to running.
	Set the task state to be executed to running.
After the task execution
	Set the scheduler state to idle.
	Set the task state	to suspended.*/
void SchM_Background(void){
 	T_UBYTE lub_Check;
 	for(;;){
 		for(lub_Check = 0;lub_Check < rps_SchedulerConfigPtr->SchedulerNumberOfTask;lub_Check++){
 			if(SchedulerTaskControl[lub_Check].SchedulerTaskState == TASK_STATE_READY){
 				SchedulerControl.SchedulerStatus = SCHEDULER_RUNNING;
 				SchedulerTaskControl[lub_Check].SchedulerTaskState = TASK_STATE_RUNNING;
 				SchedulerTaskControl[lub_Check].TaskFunctionControlPtr();
 				SchedulerTaskControl[lub_Check].SchedulerTaskState = TASK_STATE_SUSPEND;
 			}
 		}
 	}
}