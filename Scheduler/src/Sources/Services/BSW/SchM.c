#include "SchM.h"
#include "SchM_Types.h"

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
	SchedulerControlType SchedulerControl;
	SchedulerConfigType * rps_SchedulerConfigPtr;
	static SchedulerTaskControlType  SchedulerTaskControlArray[6];
void SchM_Init(const SchedulerConfigType *SchmConfig){
	T_UBYTE lub_NumberTasks;
	rps_SchedulerConfigPtr = SchmConfig;	
	
	for(lub_NumberTasks = 0;lub_NumberTasks < 4;lub_NumberTasks++){
		SchedulerTaskControlArray[lub_NumberTasks].SchedulerTaskState = TASK_STATE_SUSPEND;
		SchedulerTaskControlArray[lub_NumberTasks].TaskFunctionControlPtr = SchmConfig->SchedulerTaskTable->TaskFunctionPtr;
		
	}
	
	
}
/*Function starts the execution of Scheduler module*/
/*The SchM_Start function shall start the timer channel used for the tick reference, set the scheduler  state to Idle state and call the SchM_Background function*/
void SchM_Start(void){
	
}
/*Function stops the execution of Scheduler module*/
/*The SchM_Stop function shall stop the timer channel used for the tick reference and set the scheduler state to halted*/
void SchM_Stop(void){
	
}

/*Private Function Definitions*/
/*Private functions shall be defined in SchM.c file.*/

/*Callback function periodically called from the timer module providing the tick reference*/
/*The SchM_OsTick function shall be indirectly called by the timer module used for the tick reference, when the timer expires. This function shall increment by one the internal counter and set the correspondig task state to ready as per the define rate monotonic scheduler algorithm based on the following task descriptor fileds:
	Mask
	Offset*/
void SchM_OsTick(void){
	
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
	
}