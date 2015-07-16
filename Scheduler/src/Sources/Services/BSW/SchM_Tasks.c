#include "SchM_Tasks.h"
#include "GPIO.h"
//#include "WindowLifter.h" Agregar Aqui Las Funciones De Window Lifter en cada una de las funciones dependiendo donde vallan.
/*Timed Task executed with a predefined period*/
/*Task functions shall be referred as per the task period, e.g. for 3.125ms task:
SchM_<TaskPrefix>_Task -> SchM_3p125ms_Task
The number  of task  functions  shall  exist  according  to  the  number  of  tasks as  per Scheduler configuration from the task descriptor.*/

void SchM_3p125ms_Task(void){
		
}
void SchM_6p25ms_Task(void){
	
}
void SchM_12p5ms_Task(void){
	LED_TOGGLE(LED1);
}
void SchM_25ms_Task(void){
	LED_TOGGLE(LED2);
}
void SchM_50ms_Task(void){
	LED_TOGGLE(LED3);
}
void SchM_100ms_Task(void){
	LED_TOGGLE(LED4);	
}
