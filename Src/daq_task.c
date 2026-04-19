#include "daq_task.h"
#include "app_queues.h"

extern ADC_HandleTypeDef hadc1;

#define TEMP_ALERT_THRESHOLD_C   45.0f
#define DAQ_PERIOD_MS            500

extern RNG_HandleTypeDef hrng;
/* Read internal temperature sensor */
static float DAQ_ReadTemperature(void)
{
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    uint32_t raw = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    /* H563 factory calibration values */
    uint16_t ts_cal1 = *((uint16_t*)0x08FFF814UL); /* 30°C  */
    uint16_t ts_cal2 = *((uint16_t*)0x08FFF818UL); /* 130°C */

    float temperature = (110.0f * ((float)raw - (float)ts_cal1)) /
                        ((float)ts_cal2 - (float)ts_cal1) + 30.0f;
    return temperature;
}

/* Read hardware RNG */
static uint32_t DAQ_ReadRNG(void)
{
    uint32_t rng_val = 0;
    HAL_RNG_GenerateRandomNumber(&hrng, &rng_val);
    return rng_val;
}

void DAQ_Task(void *argument)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    DAQ_Data_t data;

    for(;;)
    {
        data.temperature_c = DAQ_ReadTemperature();
        data.rng_value     = DAQ_ReadRNG();
        data.timestamp_ms  = xTaskGetTickCount() * portTICK_PERIOD_MS;

        /* Send to processing task, don't wait if queue is full */
        xQueueSend(xQueueDAQToProc, &data, 0);

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(DAQ_PERIOD_MS));
    }
}
