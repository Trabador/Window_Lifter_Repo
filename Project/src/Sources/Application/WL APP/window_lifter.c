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
/* Integration under Continuus CM                                             */
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
T_UBYTE rub_led = 1;

T_UBYTE rub_LimitUp = 1;
T_UBYTE rub_LimitDown = 0;
T_UBYTE rub_AntiPinch;

T_UBYTE lub_timer = 0;

E_DirectionList re_Direction = INMOVIL;
E_StateList 	re_State;
E_ModeList 		re_Mode;


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


void WL_IdleState(void)
{
	LED_G_OFF;	
	LED_B_OFF;
	if(re_Direction == GOING_UP)
	{
		re_State = UP;
	}
	else if(re_Direction == GOING_DOWN)
	{
		re_State = DOWN;
	}
	else
	{
		re_Direction = INMOVIL;
		re_State = IDLE;
	}
}

void WL_UpState(void)
{
	lub_timer ++;
	LED_G_OFF;
	if( (UP_RELEASE == 1 && re_Mode == MANUAL) || (rub_LimitUp == 1))
	{
		re_Direction = INMOVIL;
		re_State = IDLE;
	}
	
	else if( (re_Mode==AUTO) || (UP_PRESS) )
	{
		if(lub_timer >= WL_timer_cfg)
		{
			lub_timer = 0;
			LED_B_ON;
			if(rub_AntiPinch == 0)
			{
				re_Direction = GOING_UP;
				LEDS_ON(rub_led);
				rub_led--;
				rub_LimitDown = 0;
				if(rub_led < 1)
				{
					rub_led = 1;
					rub_LimitUp = 1;
				}
			}
			else
			{
				re_State = DOWN;
				re_Mode = AUTO;
			}	
		}
	}
}

void WL_DownState(void)
{
	lub_timer ++;
	LED_B_OFF;
	if( (DOWN_RELEASE == 1 && re_Mode == MANUAL) || (rub_LimitDown == 1) )
	{
		if(rub_AntiPinch == 1)
		{
			re_State = PROTECT;
			lub_timer = 0;
		}
		else
		{
			re_Direction = INMOVIL;
			re_State = IDLE;
		}
	}
	
	else if( (re_Mode==AUTO) || (DOWN_PRESS) )
	{	
		if(lub_timer >= WL_timer_cfg)
		{
			lub_timer = 0;
			LED_G_ON;
			re_Direction = GOING_DOWN;
			LEDS_OFF(rub_led);
			rub_led++;
			rub_LimitUp = 0;
			if(rub_led > 10)
			{	
				rub_led = 10;
				rub_LimitDown = 1;
			}
		}
	}
}

void WL_ProtectState(void)
{
		lub_timer++;
		LED_G_ON;
		re_Direction  = INMOVIL;
		
		if(lub_timer >= BLOCK_5S)
		{
			LED_G_OFF;
			lub_timer = 0;
			rub_AntiPinch = 0;
			re_State = IDLE;	
		}
}


void WL_StateMachine(void)
{
	switch(re_State)
	{
		case IDLE:
			WL_IdleState();
		break;
		case UP:
			WL_UpState();
		break;
		case DOWN:
			WL_DownState();
		break;
		case PROTECT:
			WL_ProtectState();
		break;
		default:
			re_State = IDLE;
		break;
	}
}