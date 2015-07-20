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
/* DESCRIPTION : C source containing the functions for the window lifter module*/
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
/* creation of module                                         */
/*============================================================================*/

/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  2.0      | 20/07/2015  |                               | Alexis Garcia    */
/* Modification of the SW architecture , creation of leds and button modules  */
/*============================================================================*/


/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */
/** Variable types and common definitions */
/** Own headers */
#include "window_lifter.h"


/* GPIO routines prototypes */ 
/** Used modules */

/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/

/*enum for the led ports*/

/*global variable for the count of tej actual leds on*/
T_UBYTE rub_led = 10;
/*flag fot the autopinc detection*/
T_UBYTE rub_autopinchUp = 0;
/*flag that activates when the window goes up*/
T_UBYTE rub_goUp = 0;

/*****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/


/**************************************************************
 *  Name                 :	initGPIO
 *  Description          :	sets the input/output ports 
 *  Parameters           :  void
 *  Return               : void
 *  Critical/explanation :    no
 **************************************************************/
void initGPIO(void)
{
	SIU.GPDO[led_g].R = 1;
	SIU.PCR[led_g].R = 0x0200;
	SIU.GPDO[led1].R = 1;
	SIU.PCR[led1].R = 0x0200;
	SIU.GPDO[led2].R = 1;
	SIU.PCR[led2].R = 0x0200;
	SIU.GPDO[led3].R = 1;
	SIU.PCR[led3].R = 0x0200;
	SIU.GPDO[led4].R = 1;
	SIU.PCR[led4].R = 0x0200;
	SIU.GPDO[led5].R = 1;
	SIU.PCR[led5].R = 0x0200;
	SIU.GPDO[led6].R = 1;
	SIU.PCR[led6].R = 0x0200;
	SIU.GPDO[led7].R = 1;
	SIU.PCR[led7].R = 0x0200;
	SIU.GPDO[led8].R = 1;
	SIU.PCR[led8].R = 0x0200;
	SIU.GPDO[led9].R = 1;
	SIU.PCR[led9].R = 0x0200;
	SIU.GPDO[led10].R = 1;
	SIU.PCR[led10].R = 0x0200;
	SIU.GPDO[led_b].R = 1;
	SIU.PCR[led_b].R = 0x0200;
		
 	SIU.GPDI[up].R = 1;
 	SIU.PCR[up].R = 0x0103;
 	
 	SIU.GPDI[down].R = 1;
 	SIU.PCR[down].R = 0x0103; 
 		
 	SIU.GPDI[pinch].R = 1;
 	SIU.PCR[pinch].R = 0x0103;
	
}


/**************************************************************
 *  Name                 :	initTimer
 *  Description          :	initialize and sets the timer 
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    no
 **************************************************************/
void initTimer(void)
{
	STM.CR.R=0x00003F01;
	STM.CH[0].CCR.R=1;
	STM.CNT.R=0;
	
}


/**************************************************************
 *  Name                 :	delay
 *  Description          :	provoques a dely in ms equals to the parameter value
 *  Parameters           :  input
 *  Return               :	void
 *  Critical/explanation :    no
 **************************************************************/
void delay_ms(T_UWORD luw_time)
{
	STM.CNT.R=0;
	while(STM.CNT.R<(luw_time*1000))
	{
		
	}
	
}
/**************************************************************
 *  Name                 :	autoDown
 *  Description          :	provides the functionality for the automatic down mode
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    no
 **************************************************************/
void autoDown(void)
{
	T_UBYTE lub_i;
	lub_i = index_Handler-rub_led;	
	while(rub_led>=one_Led)
	{
		delay_ms(400);
		SIU.GPDO[lub_i].R = 1;
		lub_i++;
		rub_led--;
	}
	rub_led = min_Led_Number;
}

/**************************************************************
 *  Name                 :	manualDown
 *  Description          :	provides the functionality for the manual down mode
 *  Parameters           :  input
 *  Return               :	void
 *  Critical/explanation :    no
 **************************************************************/
void manualDown(T_UBYTE *lpub_ptr)
{
	T_UBYTE lub_i;
	lub_i = index_Handler;
	while(DOWN_PRESS && !(*lpub_ptr) && (rub_led>=one_Led))
	{
		delay_ms(400);
		if(DOWN_PRESS)
		{
			SIU.GPDO[lub_i-rub_led].R = 1;
			rub_led--;
			*lpub_ptr = 0;	
		}
	}
	if(rub_led<=min_Led_Number)
		rub_led = min_Led_Number;
}

/**************************************************************
 *  Name                 :	autoUp
 *  Description          :	provides the functionality for the automatic up mode
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    no
 **************************************************************/
void autoUp(void)
{
	T_UBYTE lub_i;
	lub_i = max_Led_Number-rub_led;	
	while((rub_led<=max_Led_Number) && !rub_autopinchUp)
	{
		delay_ms(400);
		rub_goUp = 0; 
		if(!rub_autopinchUp)
		{
			rub_goUp = 1;
			SIU.GPDO[lub_i].R = 0;
			lub_i--;
			rub_led++;	
			
		}
		else
		{
			//do nothing
		}
	}
	if(!rub_autopinchUp)
	{
		rub_led = max_Led_Number;
	}	
	else
		rub_autopinchUp  = 0;
}

/**************************************************************
 *  Name                 :	manualUp
 *  Description          :	provides the functionality for the manual up mode
 *  Parameters           :  input
 *  Return               :	void
 *  Critical/explanation :    no
 **************************************************************/
void manualUp(T_UBYTE *lpub_ptr)
{
	T_UBYTE lub_i;
	lub_i = max_Led_Number;
	while(UP_PRESS && !(*lpub_ptr) && (rub_led<=max_Led_Number))
	{	
		delay_ms(400);
		rub_goUp = 0;
		if(!rub_autopinchUp)
		{
			rub_goUp = 1;
			if(UP_PRESS)
			{
				SIU.GPDO[lub_i-rub_led].R = 0;
				rub_led++;
				*lpub_ptr = 0;		
			}
		}	
	}
	if(!rub_autopinchUp)
	{
		if(rub_led>=max_Led_Number)
			rub_led = max_Led_Number;	
	}
	else 
		rub_autopinchUp = 0;
}

/**************************************************************
 *  Name                 :	downPressed
 *  Description          :	checks if the button down press time is valid and depending on the time
 							calls a specific mode 
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  no
 **************************************************************/
void downPressed(void)
{	
	T_UBYTE lub_valid,lub_automode;
	T_UWORD luw_counter;
	lub_automode = 1;
	lub_valid = 0;
	luw_counter = 0;
	rub_goUp = 0;
	if(rub_led != min_Led_Number)
	{
		LED_G_ON;	
	}
	while(DOWN_PRESS && (luw_counter<=exit_condition))
	{
		delay_ms(1);
		luw_counter++;
		if(luw_counter > min_valid_value)
		{
			lub_valid = 1; 
		}
		if(luw_counter > five_hundred_ms)
		{
			lub_automode = 0;
			luw_counter = 1000;
		}
	}
	
	if(lub_valid)
	{
		if(!DOWN_PRESS || lub_automode)
		{
			autoDown();
		}
		else
		{
			manualDown(&lub_automode);
		}
		
	}
	else
	{
		//do nothing
	}
	LED_G_OFF;
}

/**************************************************************
 *  Name                 :	upPressed
 *  Description          :	checks if the button up press time is valid and depending on the time
 							calls a specific mode 
 *  Parameters           :  void	
 *  Return               :	void
 *  Critical/explanation :  no
 **************************************************************/
void upPressed(void)
{	
	T_UBYTE lub_valid,lub_automode;
	T_UWORD luw_counter;
	lub_automode = 1;
	lub_valid = 0;
	luw_counter = 0;
	if(rub_led != max_Led_Number)
	{
		LED_B_ON;	
	}
	while(UP_PRESS && (luw_counter<=exit_condition))
	{
		luw_counter++;
		delay_ms(1);
		if(luw_counter > min_valid_value)
		{
			lub_valid = 1; 
		}
		if(luw_counter > five_hundred_ms)
		{
			lub_automode = 0;
			luw_counter = 1000;
		}
	}
	
	if(lub_valid)
	{
		if(!UP_PRESS || lub_automode)
		{
			autoUp();
		}
		else
		{
			manualUp(&lub_automode);
		}
	}
	else
	{
		//do nothing
	}
	LED_B_OFF;
}

/**************************************************************
 *  Name                 :	pinchInterruption
 *  Description          :	provides a handling for the interruption detection every 500us, it cn only  
 							be called on the up movement and after calls the auto down mode it blocks all inputs
 							for 5 seconds	
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
void pinchInterruption(void)
{
	T_UBYTE lub_valid;
	T_UWORD luw_counter;
	lub_valid = 0;
	luw_counter = 0;
	if(rub_goUp)
	{
		while(PINCH_PRESS && (luw_counter<=exit_condition))
		{	
			luw_counter++;
			delay_ms(1);
			if(luw_counter > min_valid_value)
			{
				lub_valid = 1; 
			}
		}	
		if(lub_valid && rub_goUp)
		{
			LED_B_OFF;
			rub_goUp=0;
			rub_autopinchUp = 1;
			LED_G_ON;
			autoDown();
			delay_ms(5000);
			LED_G_OFF;
		}
		
	}
	else
	{
		//do nothing
	}    
}
