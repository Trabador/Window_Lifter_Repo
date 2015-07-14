#include "MPC5606B.h"
#include "typedefs.h"
#include "PIT.h"
#include "SchM.h"
static void InitHW(void);
static void InitSysclk(void);
static void InitModesAndClocks(void);
static void InitPeriClkGen(void);
void initTimer(void);
void delay(vuint32_t tiempo);
static void DisableWatchdog(void);
void Test(void);
void BackgroundSubsystemTasks(void);
T_UBYTE Function1(T_UBYTE *rpub_U8Ptr);

T_UBYTE (*rpfu_PtrToFctn)(T_UBYTE *);
T_UBYTE rub_Var1 = 0xFA; 
T_UBYTE rub_Var2; 
T_UBYTE * rpub_PtrToU8;
 
 

int main(void) {
	InitHW();
	INTC_InitINTCInterrupts();
	EXCEP_InitExceptionHandlers();
	PIT_device_init();
	PIT_channel_configure(PIT_CHANNEL_0 , SchM_OsTick);
    PIT_channel_start(PIT_CHANNEL_0);
	enableIrq();
	
	for(;;){
		BackgroundSubsystemTasks();
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
void delay(vuint32_t tiempo){
	STM.CNT.R=0;
	while(STM.CNT.R<tiempo*1000){
	}
}
static void DisableWatchdog(void){
	SWT.SR.R = 0x0000c520;     /* Write keys to clear soft lock bit */
	SWT.SR.R = 0x0000d928;
	SWT.CR.R = 0x8000010A;     /* Clear watchdog enable (WEN) */
}
T_UBYTE Function1(T_UBYTE *rpub_U8Ptr){
	return (*rpub_U8Ptr);
}
void BackgroundSubsystemTasks(void) {
	rpub_PtrToU8 = &rub_Var1; /* We need to initialize the pointer to be used by our function invocation */
	rpfu_PtrToFctn = &Function1; /* Let's perform our deferencing procedure (initialization) */
	/* Let's first call our function through direct invocation */
	rub_Var2 = Function1(rpub_PtrToU8);
	/* Clear var2 in preparation to next invocation */
	rub_Var2 = 0;
	/* Now, perform invocation through our pointer */
	rub_Var2 = rpfu_PtrToFctn(rpub_PtrToU8);
	/* See, I told you, pointers to functions are FUN !! */;
}
void Test(void){
    static T_UWORD rub_U16Counter = 0;
	rub_U16Counter++;
	if (rub_U16Counter == 1000){
		rub_U16Counter = 0;	
	}
}

