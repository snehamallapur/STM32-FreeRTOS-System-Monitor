#include "comms_task.h"
#include "app_queues.h"
#include "main.h"
#include <stdio.h>
#include <string.h>

#define COMMS_TX_BUFFER_SIZE  128

extern UART_HandleTypeDef huart3;
void Comms_Task(void *argument)
{
    Processed_Data_t rx_data;
    char tx_buffer[COMMS_TX_BUFFER_SIZE];
    uint16_t len;

    for(;;)
    {
        /* Block until processing task sends data */
        if(xQueueReceive(xQueueProcToComms, &rx_data, portMAX_DELAY) == pdTRUE)
        {
            /* Format the output string */
            len = snprintf(tx_buffer, sizeof(tx_buffer),
                "[%08lu] TEMP: %.1fC | AVG: %.1fC | MIN: %.1fC | MAX: %.1fC | RNG: 0x%08lX | ALERT: %s\r\n",
                xTaskGetTickCount() * portTICK_PERIOD_MS,
                rx_data.temp_avg,
                rx_data.temp_min,
                rx_data.temp_max,
                rx_data.rng_value,
                rx_data.alert ? "YES" : "NO");

            /* Transmit over USB CDC */
            HAL_UART_Transmit(&huart3, (uint8_t*)tx_buffer, len, HAL_MAX_DELAY);

            /* Toggle LD1 as visual feedback */
            BSP_LED_On(LED_RED);
        }
    }
}
