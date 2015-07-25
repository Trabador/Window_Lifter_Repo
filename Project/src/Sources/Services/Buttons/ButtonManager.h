#ifndef BTN_MNG_H
#define	BTN_MNG_H

#include "ButtonDebounce.h"


#define 	up 64
#define 	down 65
#define 	pinch 66

#define 	PIN_BTN	64
#define 	BtnNumber 3

#define 	BM_Timer_Cfg 40

#define 	UP_PRESS 	 	(SIU.GPDI[up].R == 0)
#define		UP_RELEASE 	 	(SIU.GPDI[up].R == 1)
#define 	DOWN_PRESS 	 	(SIU.GPDI[down].R == 0)
#define		DOWN_RELEASE 	(SIU.GPDI[down].R == 1)
#define 	PINCH_PRESS 	(SIU.GPDI[pinch].R == 0)
#define		PINCH_RELEASE 	(SIU.GPDI[pinch].R == 1)


#define 	UP_SIGNAL 	3
#define 	DOWN_SIGNAL	5
#define 	AP_SIGNAL	6
#define 	AP_SIGNAL_MANUAL 	2

extern void BM_InitButtons(void);
extern void BM_GetCommandButton	(void);


#endif