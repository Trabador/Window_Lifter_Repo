#include "SchM_Cfg.h"
#include "SchM_Tasks.h"
#include "SchM_Types.h"
const SchedulerTaskTableType SchedulerTaskTableConfig [] = {
	{0,	MASK_3P125MS,	TASK_3P125MS,	(void*)0},
	{1,	MASK_6P25MS,	TASK_6P25MS,	(void*)0},
	{2,	MASK_12P5MS,	TASK_12P5MS,	(void*)0},
	{3,	MASK_25MS,		TASK_25MS,		(void*)0},
	{5,	MASK_50MS,		TASK_50MS,		(void*)0},
	{6,	MASK_100MS,		TASK_100MS,		(void*)0},
};

const SchedulerConfigType SchedulerConfigSize[]={
	(sizeof(SchedulerTaskTableConfig)/sizeof(SchedulerTaskTableConfig[0])),
	SchedulerTaskTableConfig
};
