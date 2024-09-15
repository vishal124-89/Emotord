#include "shared.h"
void LCDDisplayTask(void *pvParameters) {
    while(1) {
    
        SemaphoreTake(lcdMutex, portMAX_DELAY);

        LcdSetCursor(0, 0);
        LcdPrint("Switch 1: ");
        LcdPrint(sharedSwitchStatus.switch1 ? "Pressed" : "Not Pressed");

        LcdSetCursor(1, 0);
        LcdPrint("Switch 2: ");
        LcdPrint(sharedSwitchStatus.switch2 ? "Pressed" : "Not Pressed");

        LcdSetCursor(0, 1);
        LcdPrint("Red LED: ");
        LcdPrint(GetRedLEDStatus() ? "ON" : "OFF");

        LcdSetCursor(1, 1);
        LcdPrint("Green LED: ");
        LcdPrint(GetGreenLEDStatus() ? "ON" : "OFF");

        SemaphoreGive(lcdMutex);

        TaskDelay(pdMS_TO_TICKS(500));
    }
}