#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "lcd.h"      // Include LCD driver
#include "led.h"      // Include LED driver
#include "switch.h"   // Include Switch driver

typedef struct {
    int switch1;
    int switch2;
} SwitchStatus;

SwitchStatus sharedSwitchStatus = {0, 0};

SemaphoreHandle_t switchSemaphore;
SemaphoreHandle_t lcdMutex;