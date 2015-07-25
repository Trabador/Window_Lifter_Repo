#ifndef DEB_H
#define DEB_H

#include "typedefs.h"
#include "ButtonDebounce.h"
#include "GPIO.h"

#define BttnDbncCount_Cfg 3

#define PIN_DIRECTION (&SIU.GPDI[64].R)

extern T_UBYTE BtnCktDbn;
extern T_UBYTE BtnValidation;

extern void DEB_DebounceDetection (void);


#endif