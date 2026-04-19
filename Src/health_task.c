#include "health_task.h"
#include "main.h"
#include <stdio.h>
#include <string.h>

#define HEALTH_REPORT_PERIOD_MS  5000
#define HEALTH_TX_BUFFER_SIZE    192

extern UART_HandleTypeDef huart3;

TaskHandle_t xDAQTaskHandle        = NULL;
TaskHandle_t xProcessingTaskHandle = NULL;
TaskHandle_t xCommsTaskHandle      = NULL;
TaskHandle_t xHealthTaskHandle     = NULL;

void Health_Task(void *argument)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    char tx_buffer[HEALTH_TX_BUFFER_SIZE];
    uint16_t len;

    for(;;)
    {
        /* Read stack high watermarks for all tasks */
        UBaseType_t daq_watermark   = uxTaskGetStackHighWaterMark(xDAQTaskHandle);
        UBaseType_t proc_watermark  = uxTaskGetStackHighWaterMark(xProcessingTaskHandle);
        UBaseType_t comms_watermark = uxTaskGetStackHighWaterMark(xCommsTaskHandle);
        UBaseType_t health_watermark = uxTaskGetStackHighWaterMark(xHealthTaskHandle);

        len = snprintf(tx_buffer, sizeof(tx_buffer),
            "[HEALTH] DAQ: %lu words free | PROC: %lu words free | COMMS: %lu words free | HEALTH: %lu words free\r\n",
            (uint32_t)daq_watermark,
            (uint32_t)proc_watermark,
            (uint32_t)comms_watermark,
            (uint32_t)health_watermark);

        HAL_UART_Transmit(&huart3, (uint8_t*)tx_buffer, len, HAL_MAX_DELAY);

        /* Toggle LD2 as heartbeat */
        BSP_LED_On(LED_YELLOW);

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(HEALTH_REPORT_PERIOD_MS));
    }
}
