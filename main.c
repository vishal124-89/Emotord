/*
 * File:   main.c
 * Author: Vishal
 *
 * Created on 15 September, 2024, 12:45 PM
 */

#include "shread.h"
int main(void) {

    InitSwitches();
    InitLEDs();
    InitLCD();

    // Create semaphores and mutex
    switchSemaphore = SemaphoreCreateMutex();
    lcdMutex = SemaphoreCreateMutex();

    TaskCreate(SwitchTask, "SwitchTask", 100, NULL, 2, NULL);
    TaskCreate(LEDControlTask, "LEDControlTask", 100, NULL, 2, NULL);
    TaskCreate(LCDDisplayTask, "LCDDisplayTask", 100, NULL, 1, NULL);

    // Start the FreeRTOS scheduler
    TaskStartScheduler();

    while(1);
}

