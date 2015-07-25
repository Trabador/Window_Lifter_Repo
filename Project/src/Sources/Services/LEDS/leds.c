#include "leds.h"
/**************************************************************
 *  Name                 :	initLeds
 *  Description          :	sets the led bar on default (closed) 
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    no
 **************************************************************/



void LED_InitLeds(void)
{
	T_UBYTE led;
	for(led = 1;led <= 10; led++)
	{
		LEDS_ON(led);
			
	}
	LED_B_OFF;
	LED_G_OFF;
}