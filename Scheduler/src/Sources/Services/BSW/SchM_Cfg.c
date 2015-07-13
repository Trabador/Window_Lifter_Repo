#include "Scheduler_Cfg.h"
#include "Scheduler_Tasks.h"

const SchedulerTaskTableType SchedulerTaskTableConfig[]={
	{0,	MASK_3P125MS,	TASK_3P125MS,	(void*)0},
	{0,	MASK_6P25MS,	TASK_6P25MS,	(void*)0},
	{0,	MASK_12P5MS,	TASK_12P5MS,	(void*)0},
	{0,	MASK_25MS,		TASK_25MS,		(void*)0},
	{0,	MASK_50MS,		TASK_50MS,		(void*)0},
	{0,	MASK_100MS,		TASK_100MS,		(void*)0},
};

const SchedulerConfigType SchedulerConfig[]={
	(sizeof(SchedulerTaskTableConfig)/sizeof(SchedulerTaskTableConfig[0}])),
	SchedulerTaskTableConfig
};
