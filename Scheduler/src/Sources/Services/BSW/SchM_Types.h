#ifndef __SCHEDULER_TYPES_H
#define __SCHEDULER_TYPES_H
	#include "typedefs.h"
	typedef void (*TaskFuntionPtrType)(void);
	typedef u8 SchedulerTaskOffsetType;
	
	typedef enum{
		MASK_3P125MS =	3,
		MASK_6P25MS =	7,
		MASK_12P5MS =	15,
		MASK_25MS =		31,
		MASK_50MS =		63,
		MASK_100MS =	127
	}SchedulerTaskMaskType;
	
	typedef enum{
		TASK_BKG,
		TASK_3P125MS,
		TASK_6P25MS,
		TASK_12P5MS,
		TASK_25MS,
		TASK_50MS,
		TASK_100MS
	}SchedulerTaskIDType;
	
	typedef enum{
		TASK_STATE_SUSPEND,
		TASK_STATE_READY,
		TASK_STATE_RUNNING
	}SchedulerTaskStateType;
	
	typedef struct{
		SchedulerTaskStateType SchedulerTaskState;
		TaskFuntionPtrType TaskFunctionControlPtr;
		
	}