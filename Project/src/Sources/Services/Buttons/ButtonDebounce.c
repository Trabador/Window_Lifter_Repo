#include "ButtonDebounce.h"
#include "ButtonManager.h"


T_UBYTE BtnCktDbn = 0;
T_UBYTE BtnValidation = 0;

T_UBYTE DEB_GetButtons(void);
 
void DEB_DebounceDetection (void)
{
	T_UBYTE BtnCktIn = 7;
	static BtnCktIn_count = 0;
	static T_UBYTE BtnCktInPrev = 0;
	
	BtnCktIn = DEB_GetButtons();
	if(BtnCktInPrev == BtnCktIn)
	{
		BtnCktIn_count++;
		if(BtnCktIn_count >= BttnDbncCount_Cfg)
		{
			BtnCktIn_count = 0;
			BtnCktDbn = BtnCktIn;
			BtnValidation = 1;
		}
	}
	else
	{
		BtnValidation = 0;
		BtnCktIn_count = 0;
		BtnCktInPrev = BtnCktIn;
	}
}


T_UBYTE DEB_GetButtons(void)
{
	T_UBYTE lub_iterator;
	T_UBYTE *lpub_PinNumber;
	T_UBYTE lub_BitValue;
	T_UBYTE lub_ButtonValue;
	lpub_PinNumber = PIN_DIRECTION;
	lub_ButtonValue = 0;
	for(lub_iterator = 0; lub_iterator < BtnNumber ; lub_iterator++){
		lub_BitValue = (*lpub_PinNumber & 0x01);
		lub_ButtonValue = lub_ButtonValue + lub_BitValue;
		if(BtnNumber == lub_iterator + 1){
		}
		else
		{
			lub_ButtonValue = lub_ButtonValue << 1;
			lpub_PinNumber++;
		}
	}
	return lub_ButtonValue;
}


