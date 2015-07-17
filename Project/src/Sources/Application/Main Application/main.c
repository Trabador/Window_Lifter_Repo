/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %main.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    13/07/2015%
*=============================================================================*/
/* DESCRIPTION : 					                                          */
/*============================================================================*/
/* FUNCTION COMMENT : 														  */
/* 							                                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  |                               | Alexis Garcia    */
/* 									                                          */
/*============================================================================*/

/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  2.0      | 17/07/2015  | Correction of naming convention |Alexis Garcia     */
/* 								                                              */
/*============================================================================*/

/* Includes */
/* -------- */
#include    "MCU_derivative.h"
#include    "GPIO.h"
#include    "SchM.h"
#include 	"MemAlloc_Cfg.h"
/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */

/* Exported functions prototypes */
/* ----------------------------- */

/* Inline functions */
/* ---------------- */

 void disableWatchdog(void) 
 {
  	SWT.SR.R = 0x0000c520;     /* Write keys to clear soft lock bit */
  	SWT.SR.R = 0x0000d928; 
  	SWT.CR.R = 0x8000010A;     /* Clear watchdog enable (WEN) */
 }

/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : 	main
 *  Description          :	main function
 *  Parameters           :  void
 *  Return               :	int
 *  Critical/explanation :  [No]
 **************************************************************/
 /*~~~~~~~ Main Code ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
 int main(void) 
 {
	/*enbles and cofigures the memory allocation for the scheduler control block*/
	MemAllocInit(&MemAllocConfig);
	initModesAndClock();
	/* Disable Watchdog */
	disableWatchdog();
	/*Initialize LEDs on TRK-MPC560xB board */
	vfnGPIO_LED_Init();	
	/*Initialize Interrupts */
	INTC_InitINTCInterrupts();
	/*Initialize Exception Handlers */
	EXCEP_InitExceptionHandlers();
    /* Enable External Interrupts*/
    enableIrq();
	
	
	SchM_Init(&cs_SchConfig);
	SchM_Start();
	
	/* Infinite loop */
	for (;;) 
	{
		/*Dummy line*/
	}
 }

 /*~~~~~~~ End of Main Code ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/




/* Exported functions */
/* ------------------ */