#include "MyTask.h"
#include <stdio.h>
#include "include/FreeRTOS.h"
#include "include/task.h"
#include "Utils.h"
#include "include/semphr.h"

static SemaphoreHandle_t _resultReadySempahore = NULL;
// --------------------------------------------------------------------------------------
void myTask_init() {
    // Initialisation code can be placed here
    utils_initialise();
}

// --------------------------------------------------------------------------------------
void myTask_run(void) {
    vTaskDelay(pdMS_TO_TICKS(200));
    int8_t result = utils_add(20, 56);
    utils_storeValue(result);

    xSemaphoreGive(_resultReadySempahore);
}

// --------------------------------------------------------------------------------------
void taskMyTask(void* pvParameters)
{
    _resultReadySempahore = (SemaphoreHandle_t)pvParameters;

    myTask_init();

    for (;;)
    {
        myTask_run();
    }
}