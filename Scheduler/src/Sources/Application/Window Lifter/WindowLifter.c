#include "typedefs.h"
#include "MCU_derivative.h"

void WindowLifterIdle(void);
void WindowLifterUp(void);
void WindowLifterDown(void);
void WindowLifterProtection(void);

#define READPIN(channel)	(SIU.GPDI[channel].R)

T_UWORD ButtonDetector(T_UBYTE lub_Port,T_UBYTE lub_StartPin, T_UBYTE lub_EndPin){
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
}
