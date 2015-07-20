#ifndef _BTNS_H
#define _BTNS_H

#include "typedefs.h"

#define 	pinch 64
#define 	up 65
#define 	down 66

#define 	UP_PRESS (SIU.GPDI[up].R == 0)
#define 	DOWN_PRESS (SIU.GPDI[down].R == 0)
#define 	PINCH_PRESS (SIU.GPDI[pinch].R == 0)

#endif 