#include "MySecondTask.h"
#include "include/FreeRTOS.h"
#include "include/task.h"
#include "include/semphr.h"
#include "include/queue.h"


static SemaphoreHandle_t _resultReadySempahore = NULL;
static QueueHandle_t _myQueueHandle = NULL;
static  TickType_t xLastWakeTime;
const TickType_t xFrequency = 10;

// --------------------------------------------------------------------------------------
void mySecondTask_initialise() {
    _resultReadySempahore = xSemaphoreCreateBinary();
    _myQueueHandle = xQueueCreate(2, 10);
}

// --------------------------------------------------------------------------------------
void mySecondTask_init() {
    // Initialisation code can be placed here
    xLastWakeTime = xTaskGetTickCount();
}

// --------------------------------------------------------------------------------------
void mySecondTask_run(void) {
    uint8_t buf[10];

    vTaskDelay(pdMS_TO_TICKS(200));

    xSemaphoreGive(_resultReadySempahore);
    xQueueSend(_myQueueHandle, buf, portMAX_DELAY);
    if (xQueueReceive(_myQueueHandle, buf, portMAX_DELAY)) {
        // OK
    }
    else {
        // Timeout
    }

    vTaskDelayUntil(&xLastWakeTime, xFrequency);
}

// --------------------------------------------------------------------------------------
void taskMySecondTask(void* pvParameters)
{
    mySecondTask_init();

    for (;;)
    {
        mySecondTask_run();
    }
}