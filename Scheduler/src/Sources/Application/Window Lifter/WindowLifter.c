#include "typedefs.h"
#include "MCU_derivative.h"
#include "WindowLifter.h"
#include "GPIO.h"
#define ValidButton	5
#define READPIN(channel)	(SIU.GPDI[channel].R)
T_UBYTE Bttn_Active[4] = {0, 0, 0, 0};


T_UBYTE ButtonDetector(T_UBYTE lub_Port,T_UBYTE lub_StartPin, T_UBYTE lub_EndPin){
	volatile counter;
	T_UBYTE *lpub_PinSelector;
	T_UBYTE lub_TempMask = 0, lub_ReturnPort;
	lpub_PinSelector = &READPIN(lub_Port + lub_StartPin);
	lub_ReturnPort = 0;
	for(counter = 0; counter < lub_EndPin + 1 ; counter++){
		lub_TempMask = (*lpub_PinSelector & 0x01);
		lub_ReturnPort = lub_ReturnPort + lub_TempMask;
		if(counter + 1 == 4){
		}
		else{
			lub_ReturnPort = lub_ReturnPort << 1;
			lpub_PinSelector++;
		}
	}
	return lub_ReturnPort;
}

void DebouncePort(T_UWORD lub_Port){
	static T_UBYTE Bttn_Prev[4] = {0, 0, 0, 0}, x, Prev;
	static T_UWORD Bttn_Counter[4] = {0, 0, 0, 0};
	for(x = 0; x < 4; x++){
	Prev = (lub_Port & (0x01 << x)) >> x;
		if(Bttn_Prev[x] == Prev){
			Bttn_Counter[x]++;
			if(Bttn_Counter[x] >= ValidButton){
				Bttn_Active[x] = Prev;
			}
			else{

			}
		}
		else{
			Bttn_Counter[x] = 0;
			Bttn_Prev[x] = Prev;
		}
	}
}

void test(void){
	if(Bttn_Active[0] == 1){
		LED_ON(LED1);
	}
	else{
		LED_OFF(LED1);
	}
	if(Bttn_Active[1] == 1){
		LED_ON(LED2);
	}
	else{
		LED_OFF(LED2);
	}
	if(Bttn_Active[2] == 1){
		LED_ON(LED3);
	}
	else{
		LED_OFF(LED3);
	}
	if(Bttn_Active[3] == 1){
		LED_ON(LED4);
	}
	else{
		LED_OFF(LED4);
	}
	
}