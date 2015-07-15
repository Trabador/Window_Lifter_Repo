#include "SchM_Cfg.h"
#include "SchM_Tasks.h"
const SchedulerTaskTableType SchedulerTaskTableConfig [] = {
	{0,	MASK_3P125MS,	TASK_3P125MS,	&SchM_3p125ms_Task},
	{1,	MASK_6P25MS,	TASK_6P25MS,	&SchM_6p25ms_Task},
	{2,	MASK_12P5MS,	TASK_12P5MS,	&SchM_12p5ms_Task},
	{3,	MASK_25MS,		TASK_25MS,		&SchM_25ms_Task},
	{5,	MASK_50MS,		TASK_50MS,		&SchM_50ms_Task},
	{6,	MASK_100MS,		TASK_100MS,		&SchM_100ms_Task},
};

const SchedulerConfigType SchedulerConfig = {
	(sizeof(SchedulerTaskTableConfig)/sizeof(SchedulerTaskTableConfig[0])),
	SchedulerTaskTableConfig
};
