#include "MPC5606B.h"
#include "typedefs.h"
#include "MemAlloc_Cfg.h"
#include "SchM_Cfg.h"
#include "pll.h"

int main(void) {
	InitHW();
	MemAllocInit(&MemAllocConfig);
	SchM_Init(&SchedulerConfig);
	SchM_Start();
	for(;;){
		
  }
}