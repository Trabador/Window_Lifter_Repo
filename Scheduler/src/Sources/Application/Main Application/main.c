/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %main.c%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      uid10734106 %
* %date_created:    Mon Jul  13 17:36 2015 %
*=============================================================================*/
/* DESCRIPTION :	Main Function, Initialize HardWare And Call For The
					Scheduler Function To Start							      */
/*============================================================================*/
/* FUNCTION COMMENT : 	Start The HardWare, Alloc Memory For The Structure,   */
/*						Initialize Task Scheduler And Start The Scheduler	  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 17/07/2015  |                               | Roberto Palos    */
/* 	Version 1 Include The Scheduler Fully Working, No Window Lifter Options
	Added Yet.																  */
/*============================================================================*/

/* Includes */
/* -------- */

#include "MPC5606B.h"
#include "typedefs.h"
#include "MemAlloc_Cfg.h"
#include "SchM_Cfg.h"
#include "pll.h"
#include "GPIO.h"


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
int main(void) {
	InitHW();
	MemAllocInit(&MemAllocConfig);
	SchM_Init(&SchedulerConfig);
	SchM_Start();
	for(;;){
		/* Error In Scheduler, SchM_Start() Will Never Leave*/
		LED_ON(LED1);
		LED_ON(LED2);
		LED_ON(LED3);
		LED_ON(LED4);
  }
}
