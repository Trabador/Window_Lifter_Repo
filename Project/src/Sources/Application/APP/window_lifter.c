/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %window_lifter.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    28/07/2015%
*=============================================================================*/
/* DESCRIPTION : C source containing the functions for the window lifter module*/
/*============================================================================*/
/* FUNCTION COMMENT : Contains the functionality of the state machine that controls
					the events of the wl app                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 21/07/2015  |                               | Alexis Garcia    */
/* Creation of the module		                                            */
/*============================================================================*/
/*----------------------------------------------------------------------------*/
/*  2.0      | 27/07/2015  |                               | Alexis Garcia    */
/* Modification of the module, movement of some functions to the drivers and
	addition of comments according to the template		                       
	2.1 	|  28/07/15    |                                | Alexis Garcia 
	removed magic numbers in functions										  */
/*============================================================================*/



/*****************************************************************************************************
* Include files
*****************************************************************************************************/
#include "window_lifter.h"

/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/
/*global variable for the count of tej actual leds on*/
T_UBYTE rub_led = Enabled;

T_UBYTE rub_LimitUp = Enabled;
T_UBYTE rub_LimitDown = 0;
T_UBYTE rub_AntiPinch = 0;

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
 *  Name                 :	WL_IdleState
 *  Description          :	checks for the input commands and depending on that sets the next state
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
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

/**************************************************************
 *  Name                 :	WL_UpState
 *  Description          :	Controls the up movement and turns on the leds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
void WL_UpState(void)
{
	lub_timer ++;
	LED_G_OFF;
	if( (UP_RELEASE == Enabled && re_Mode == MANUAL) || (rub_LimitUp == Enabled))
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
				if(rub_led < MAX_LED)
				{
					rub_led = MAX_LED;
					rub_LimitUp = Enabled;
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

/**************************************************************
 *  Name                 :	WL_DownState
 *  Description          :	Controls the down movement and tuns off leds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
void WL_DownState(void)
{
	lub_timer ++;
	LED_B_OFF;
	if( (DOWN_RELEASE == Enabled && re_Mode == MANUAL) || (rub_LimitDown == Enabled) )
	{
		if(rub_AntiPinch == Enabled)
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
			if(rub_led > MIN_LED)
			{	
				rub_led = MIN_LED;
				rub_LimitDown = Enabled;
			}	
		}
	}
}

/**************************************************************
 *  Name                 :	WL_ProtectState
 *  Description          :	Prevents the state change and the lecture of the buttons for 5 seconds 
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
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

/*Extern Functions*/
/**************************************************************
 *  Name                 :	WL_StateMachine
 *  Description          :	Control the flow of the states for the window lifter 
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  yes
 **************************************************************/
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