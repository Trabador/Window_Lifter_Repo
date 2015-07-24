#include "typedefs.h"

void WindowLifterIdle(void);
void WindowLifterUp(void);
void WindowLifterDown(void);
void WindowLifterProtection(void);


T_UBYTE Up_Indicator, Down_Indicator;
T_UBYTE Limit_Up, Limit_Down;
T_UBYTE Up_Flag, Down_Flag;
T_UBYTE Position, LED[10];
T_UBYTE OFF = 0, ON = 1, MAX = , MIN;
T_UBYTE DelayBetweenStates;

T_UBYTE state;
enum{
	IDLE,
	UP,
	DOWN,
	PROTECTION
};

T_UWORD ButtonDetector(T_UBYTE lub_Port,T_UBYTE lub_StartPin, T_UBYTE lub_EndPin){
	volatile counter;
	T_UBYTE *lpub_PinSelector;
	T_UBYTE lub_TempMask = 0, lub_ReturnPort;
	lpub_PinSelector = &lub_Port;
	lub_ReturnPort = 0;
	for(counter = 0; counter < 4 ; counter++){
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

T_UWORD Debounce(T_UWORD lub_Buttons){
	for(;;){
		if(lub_Buttons << for_variable == lub_Buttons_Before[for_variable]){
			Deb_Counter[for_variable]++;
			if(Deb_Counter[for_variable] == Valid_Button){
				Bttn_Valid[for_variable] == lub_Buttons << for_variable;
			}
			else{
			}
		}
		else{
			Deb_Counter[for_variable] = 0;
			lub_Buttons_Before[for_variable] = lub_Buttons << for_variable;
		}
	}
}

void WindowLifter(void){
	switch(state){
		case IDLE:
			WindowLifterIdle();
			break;
		case UP:
			WindowLifterUp();
			break;
		case DOWN:
			WindowLifterDown();
			break;
		case PROTECTION:
			WindowLifterProtection();
			break;
		default:
			//
			break;
	}
}

void WindowLifterIdle(void){
	Up_Indicator = OFF;
	Down_Indicator = OFF;
//	ButtonDetector();
}

void WindowLifterUp(void){
	if(Up_Flag && Limit_Up == OFF){
		Up_Indicator = ON;
		if(Position == MAX){
			Limit_Up = ON;
		}
		else{
			Position = Position + 1;
			LED[Position] = ON;
			DelayBetweenStates = 0;
		}
		Limit_Down = OFF;
	}	
}

void WindowLifterDown(void){
	if(Down_Flag && Limit_Down == OFF){
		Down_Indicator = ON;
		if(Position == MIN){
			Limit_Down = ON;
		}
		else{
			Position = Position - 1;
			LED[Position] = OFF;
			DelayBetweenStates = 0;
		}
		Limit_Up = OFF;
	}	
}

void WindowLifterProtection(void){

}