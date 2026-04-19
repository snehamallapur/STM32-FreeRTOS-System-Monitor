#ifndef INC_DAQ_TASK_H_
#define INC_DAQ_TASK_H_

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os2.h"

/* Task function prototype */
void DAQ_Task(void *argument);

#endif /* INC_DAQ_TASK_H_ */
