#ifndef  INC_APP_QUEUES_H_
#define  INC_APP_QUEUES_H_

#include "FreeRTOS.h"
#include "queue.h"
#include <stdbool.h>

//Data Structures

typedef struct {
	float temperature_c;
	uint32_t rng_value;
	uint32_t timestamp_ms;
}DAQ_Data_t;

typedef struct {
	float temp_avg;
	float temp_min;
	float temp_max;
	uint32_t rng_value;
	bool alert;
	
}Processed_Data_t;

//Queue Handles

extern QueueHandle_t xQueueDAQToProc;
extern QueueHandle_t xQueueProToComms;

#endif
