#include "SchM_Tasks.h"

/*Timed Task executed with a predefined period*/
/*Task functions shall be referred as per the task period, e.g. for 3.125ms task:
SchM_<TaskPrefix>_Task -> SchM_3p125ms_Task
The number  of task  functions  shall  exist  according  to  the  number  of  tasks as  per Scheduler configuration from the task descriptor.*/
/*
void SchM_<TaskPrefix>_Task(void){
	
}
*/