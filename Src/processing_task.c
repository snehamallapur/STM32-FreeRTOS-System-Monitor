#include "processing_task.h"
#include "app_queues.h"

#define ROLLING_WINDOW_SIZE     10
#define TEMP_ALERT_THRESHOLD_C  45.0f

static float temp_buffer[ROLLING_WINDOW_SIZE] = {0};
static uint8_t buffer_index = 0;
static uint8_t buffer_count = 0;

static float PROC_ComputeAverage(void)
{
    float sum = 0.0f;
    uint8_t count = (buffer_count < ROLLING_WINDOW_SIZE) ? buffer_count : ROLLING_WINDOW_SIZE;
    for(uint8_t i = 0; i < count; i++)
        sum += temp_buffer[i];
    return sum / count;
}

static float PROC_ComputeMin(void)
{
    float min = temp_buffer[0];
    uint8_t count = (buffer_count < ROLLING_WINDOW_SIZE) ? buffer_count : ROLLING_WINDOW_SIZE;
    for(uint8_t i = 1; i < count; i++)
        if(temp_buffer[i] < min) min = temp_buffer[i];
    return min;
}

static float PROC_ComputeMax(void)
{
    float max = temp_buffer[0];
    uint8_t count = (buffer_count < ROLLING_WINDOW_SIZE) ? buffer_count : ROLLING_WINDOW_SIZE;
    for(uint8_t i = 1; i < count; i++)
        if(temp_buffer[i] > max) max = temp_buffer[i];
    return max;
}

void Processing_Task(void *argument)
{
    DAQ_Data_t       rx_data;
    Processed_Data_t tx_data;

    for(;;)
    {
        /* Block indefinitely until data arrives from DAQ */
        if(xQueueReceive(xQueueDAQToProc, &rx_data, portMAX_DELAY) == pdTRUE)
        {
            /* Update rolling buffer */
            temp_buffer[buffer_index] = rx_data.temperature_c;
            buffer_index = (buffer_index + 1) % ROLLING_WINDOW_SIZE;
            buffer_count++;

            /* Compute stats */
            tx_data.temp_avg  = PROC_ComputeAverage();
            tx_data.temp_min  = PROC_ComputeMin();
            tx_data.temp_max  = PROC_ComputeMax();
            tx_data.rng_value = rx_data.rng_value;
            tx_data.alert     = (rx_data.temperature_c > TEMP_ALERT_THRESHOLD_C);

            /* Forward to comms task */
            xQueueSend(xQueueProcToComms, &tx_data, 0);
        }
    }
}
