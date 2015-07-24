/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %pll.c%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      uid10734106 %
* %date_created:    Mon Jul  13 17:36 2015 %
*=============================================================================*/
/* DESCRIPTION :The pll.c Include All The Configuration To Initialize The    
				Microcontroller HardWare.									  */
/*============================================================================*/
/* FUNCTION COMMENT :	Disabble WatchDog, Initialize The Microcontroller To
						In 8 MHz Crystal, Initialize The Timer For Delay
						Function.											  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 17/07/2015  |                               | Roberto Palos    */
/* 	Version 1 Removed The Doble Call To Function "InitModesAndClocks.		  */
/*============================================================================*/

/* Includes */
/* -------- */
#include "pll.h"
/* MCU-specific derivative */
#include "MCU_derivative.h" 
/* Data types */
#include "typedefs.h"


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 : InitHW
 *  Description          :
 *  Parameters           :  [/]
 *  Return               :
 *  Critical/explanation :    [No]
 **************************************************************/
void InitHW(void){
	DisableWatchdog();
	InitSysclk();
	InitTimer();
}


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : InitSysclk
 *  Description          :
 *  Parameters           :  [/]
 *  Return               :
 *  Critical/explanation :    [No]
 **************************************************************/
void InitSysclk(void){
	InitModesAndClocks();
	InitPeriClkGen();
}

/**************************************************************
 *  Name                 : InitModesAndClocks
 *  Description          :
 *  Parameters           :  [/]
 *  Return               :
 *  Critical/explanation :    [No]
 **************************************************************/
void InitModesAndClocks(void){
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

/**************************************************************
 *  Name                 : InitPeriClkGen
 *  Description          :
 *  Parameters           :  [/]
 *  Return               :
 *  Critical/explanation :    [No]
 **************************************************************/
void InitPeriClkGen(void){
	CGM.SC_DC[2].R = 0x80;          	/* MPC56xxB: Enable peri set 3 sysclk divided by 1 */
}

/**************************************************************
 *  Name                 : InitTimer
 *  Description          :
 *  Parameters           :  [/]
 *  Return               :
 *  Critical/explanation :    [No]
 **************************************************************/
void InitTimer(void){
	STM.CR.R=0x00003F01;
	STM.CH[0].CCR.R=1;
	STM.CNT.R=0;
}

/**************************************************************
 *  Name                 : DisableWatchdog
 *  Description          :
 *  Parameters           :  [/]
 *  Return               :
 *  Critical/explanation :    [No]
 **************************************************************/
void DisableWatchdog(void){
	SWT.SR.R = 0x0000c520;     /* Write keys to clear soft lock bit */
	SWT.SR.R = 0x0000d928;
	SWT.CR.R = 0x8000010A;     /* Clear watchdog enable (WEN) */
}
