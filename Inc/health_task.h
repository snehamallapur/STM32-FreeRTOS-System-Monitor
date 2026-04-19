#ifndef INC_HEALTH_TASK_H_
#define INC_HEALTH_TASK_H_

#include "FreeRTOS.h"
#include "task.h"

/* Task handles - needed to check stack watermarks */
extern TaskHandle_t xDAQTaskHandle;
extern TaskHandle_t xProcessingTaskHandle;
extern TaskHandle_t xCommsTaskHandle;
extern TaskHandle_t xHealthTaskHandle;

/* Task function prototype */
void Health_Task(void *argument);

#endif /* INC_HEALTH_TASK_H_ */
