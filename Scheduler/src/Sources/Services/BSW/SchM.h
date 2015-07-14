#ifndef SCHM_H
#define SCHM_H
	#include "SchM_Types.h"
	void SchM_Init(const SchedulerConfigType *SchmConfig);
	void SchM_Start(void);
	void SchM_Stop(void);
	void SchM_OsTick(void);
	void SchM_Background(void);
#endif

