/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %window_lifter.c%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    %
*=============================================================================*/
/* DESCRIPTION : C source main function with the detection of the button press
					and the setting of the timer,IRQ, GPIO and leds			  */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source template according to  */
/* the new software platform                                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  |                               | Alexis Garcia    */
/* Creation of module                                        */
/*============================================================================*/
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  2.0      | 20/07/2015  |                               | Alexis Garcia    */
/* Modification of the SW architecture , creation of leds and button modules  */
/*============================================================================*/

/*****************************************************************************************************
* Includes
*****************************************************************************************************/
#include 	"MCU_derivative.h"
#include    "GPIO.h"
#include    "PIT.h"
#include 	"window_lifter.h"
/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/

/****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/

void disableWatchdog(void) 
{
  SWT.SR.R = 0x0000c520;     /* Write keys to clear soft lock bit */
  SWT.SR.R = 0x0000d928; 
  SWT.CR.R = 0x8000010A;     /* Clear watchdog enable (WEN) */
}


/*****************************************************************************************************
* Definition of global wide MACROs / #DEFINE-CONSTANTs
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/
   

/******************************************************************************************************
* Definition of module wide VARIABLEs 
******************************************************************************************************/

/******************************************************************************************************
* Code of module wide FUNCTIONS
******************************************************************************************************/

/*~~~~~~~ Main Code ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/**************************************************************
 *  Name                 :	main
 *  Description          :	main function used for button detection and main setting
 *  Parameters           :  void
 *  Return               :  int 
 *  Critical/explanation :  no
 **************************************************************/
int main(void) 
{
	initModesAndClock();
	/* Disable Watchdog */
	disableWatchdog();
	/*Initialize LEDs on TRK-MPC560xB board */
	vfnGPIO_LED_Init();	
	/*Initialize Interrupts */
	INTC_InitINTCInterrupts();
	/*Initialize Exception Handlers */
	EXCEP_InitExceptionHandlers();
	
	PIT_device_init();
    PIT_channel_configure(PIT_CHANNEL_0 , pinchInterruption);	
    PIT_channel_start(PIT_CHANNEL_0);
    
    /*enable the interruptions*/
    enableIrq();
    /*sets the input and output pins*/
    initGPIO();
    /*sets and initialize the timer*/
    initTimer();
    /*sets the window leds in on or totally closed*/
    initLeds();
    /*initialize the flag goUP in false*/
    rub_goUp = 0 ;
	
	while(1)//infinite loop
	{		
		rub_goUp = 0;//sets the up movement in false
		if(!(UP_PRESS && DOWN_PRESS))
		{
			if(UP_PRESS && !DOWN_PRESS)//button Up press detection
			{
				upPressed();
			}
			else if(DOWN_PRESS && !UP_PRESS)//button down press detection
			{
				downPressed();
			}	
			else
			{
				//do nothing
			}
		}
		else
		{
			//do nothing
		}	
	}//infinite loop end
}



