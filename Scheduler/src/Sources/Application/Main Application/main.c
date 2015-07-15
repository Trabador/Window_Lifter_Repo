#include "MPC5606B.h"
#include "typedefs.h"
#include "MemAlloc_Cfg.h"
#include "SchM_Cfg.h"


static void InitHW(void);
static void InitSysclk(void);
static void InitModesAndClocks(void);
static void InitPeriClkGen(void);
void initTimer(void);
static void DisableWatchdog(void);
 

int main(void) {
	InitHW();
	MemAllocInit(&MemAllocConfig);
	SchM_Init(&SchedulerConfig);
	SchM_Start();
	for(;;){
		
  }
}
static void InitHW(void){
	DisableWatchdog();
	InitModesAndClocks();
	initTimer();
	InitSysclk();
}
static void InitSysclk(void){
	InitModesAndClocks();
	InitPeriClkGen();
}
static void InitModesAndClocks(void) {
	ME.MER.R = 0x0000001D;          	/* Enable DRUN, RUN0, SAFE, RESET modes */
	                              		/* Initialize PLL before turning it on: */
	CGM.FMPLL_CR.R = 0x02400100;    	/* 8 MHz xtal: Set PLL0 to 64 MHz */   

	ME.RUN[0].R = 0x001F0074;       	/* RUN0 cfg: 16MHzIRCON,OSC0ON,PLL0ON,syclk=PLL */
	ME.RUNPC[1].R = 0x00000010; 		/* Peri. Cfg. 1 settings: only run in RUN0 mode */	

	ME.PCTL[92].R = 0x01;           	/* PIT, RTI: select ME_RUN_PC[1] */
	ME.PCTL[68].R = 0x01;				/* SIUL */
	
		    		
	                              		/* Mode Transition to enter RUN0 mode: */
	ME.MCTL.R = 0x40005AF0;         	/* Enter RUN0 Mode & Key */
	ME.MCTL.R = 0x4000A50F;         	/* Enter RUN0 Mode & Inverted Key */  
	while (ME.GS.B.S_MTRANS) {}     	/* Wait for mode transition to complete */    
	                              		/* Note: could wait here using timer and/or I_TC IRQ */
	while(ME.GS.B.S_CURRENTMODE != 4) 	/* Verify RUN0 is the current mode */
	{;} 								
}
static void InitPeriClkGen(void) {
	CGM.SC_DC[2].R = 0x80;          	/* MPC56xxB: Enable peri set 3 sysclk divided by 1 */
}
void initTimer(void){
	STM.CR.R=0x00003F01;
	STM.CH[0].CCR.R=1;
	STM.CNT.R=0;
}
static void DisableWatchdog(void){
	SWT.SR.R = 0x0000c520;     /* Write keys to clear soft lock bit */
	SWT.SR.R = 0x0000d928;
	SWT.CR.R = 0x8000010A;     /* Clear watchdog enable (WEN) */
}
