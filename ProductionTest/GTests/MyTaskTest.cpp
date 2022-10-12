#include "gtest/gtest.h"
#include "Mock/FreeRTOS_MOCK_FFF.h"

extern "C"{
#include <stdio.h>

}

class MyTaskTest:public::testing::Test
{
protected:
    void SetUp() override
    {
        RESET_FAKE(xSemaphoreCreateBinary);
        RESET_FAKE(vTaskDelay);
        RESET_FAKE(xSemaphoreGive);
        RESET_FAKE(xQueueCreate);
        FFF_RESET_HISTORY();
    };
    void TearDown() override{};
};