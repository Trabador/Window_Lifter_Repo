#ifndef _LEDS_H
#define _LEDS_H

#include "typedefs.h"
#include "GPIO.h"

#define 	LED_G_OFF (SIU.GPDO[led_g].R = 1)
#define 	LED_G_ON (SIU.GPDO[led_g].R = 0) 
#define 	LED1_OFF (SIU.GPDO[led1].R = 1 )
#define 	LED1_ON	(SIU.GPDO[led1].R = 0)
#define 	LED2_OFF (SIU.GPDO[led2].R = 1 )
#define 	LED2_ON	(SIU.GPDO[led2].R = 0 )
#define 	LED3_OFF (SIU.GPDO[led3].R = 1 )
#define 	LED3_ON	(SIU.GPDO[led3].R = 0 )
#define 	LED4_OFF (SIU.GPDO[led4].R = 1 )
#define 	LED4_ON	(SIU.GPDO[led4].R = 0 )
#define 	LED5_OFF (SIU.GPDO[led5].R = 1 )
#define 	LED5_ON	(SIU.GPDO[led5].R = 0 )
#define 	LED6_OFF (SIU.GPDO[led6].R = 1 )
#define 	LED6_ON	(SIU.GPDO[led6].R = 0 )
#define 	LED7_OFF (SIU.GPDO[led7].R = 1 )
#define 	LED7_ON	(SIU.GPDO[led7].R = 0 )
#define 	LED8_OFF (SIU.GPDO[led8].R = 1 )
#define 	LED8_ON	(SIU.GPDO[led8].R = 0 )
#define 	LED9_OFF (SIU.GPDO[led9].R = 1 )
#define 	LED9_ON	(SIU.GPDO[led9].R = 0 )
#define 	LED10_OFF (SIU.GPDO[led10].R = 1 )
#define 	LED10_ON	(SIU.GPDO[led10].R = 0 )
#define 	LED_B_OFF (SIU.GPDO[led_b].R = 1 )
#define 	LED_B_ON (SIU.GPDO[led_b].R = 0 )

#define 	max_Led_Number		10
#define 	index_Handler				11
#define 	min_Led_Number 		0
#define 	one_Led		1


typedef enum 
{
	led_b,
	led1,
	led2,
	led3,
	led4,
	led5,
	led6,
	led7,
	led8,
	led9,
	led10,
	led_g
	
}E_LedType;

extern void initLeds(void);
extern E_LedType led_list;

#endif