#include "ButtonManager.h"
#include "window_lifter.h"

T_UWORD rub_timer = 0;

void BM_GetCommandButton (void)
{
	if(BtnValidation == 1)
	{
		rub_timer ++;
		if( (BtnCktDbn == AP_SIGNAL) && (re_Direction == GOING_UP) && re_Mode == AUTO)
		{
			rub_AntiPinch = 1;
		}
		else if(BtnCktDbn == AP_SIGNAL_MANUAL && re_Direction == GOING_UP && re_Mode == MANUAL)
		{
			rub_AntiPinch = 1;
		}
		else if(BtnCktDbn == UP_SIGNAL)
		{
			if(rub_timer <= BM_Timer_Cfg)
			{
				re_Mode = AUTO;
			}
			else
			{
				re_Mode = MANUAL;	
			}
			re_Direction = GOING_UP;
		}
		else if(BtnCktDbn == DOWN_SIGNAL)
		{
			if(rub_timer <= BM_Timer_Cfg)
			{
				re_Mode = AUTO;
			}
			else
			{
				re_Mode = MANUAL;	
			}
			re_Direction = GOING_DOWN;
		}
		else if(BtnCktDbn == 7)
		{
			re_Direction = INMOVIL;
			BtnValidation = 0;
		}	
	}
	else
	{
		rub_timer = 0;
	}
}


void BM_InitButtons(void)
{
	T_UBYTE lub_iterator;
	for(lub_iterator = 0; lub_iterator < BtnNumber ; lub_iterator++)
	{
		SIU.GPDI[lub_iterator + PIN_BTN].R = 1;
		SIU.PCR[lub_iterator + PIN_BTN].R = 0x0103;
	}
}
