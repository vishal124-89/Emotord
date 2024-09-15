#include "shared.h"
void SwitchTask(void *pvParameters) {
    while(1) {
        // Read switch 1 and switch 2 status
        int switch1_status = ReadSwitch1();
        int switch2_status = ReadSwitch2();

        // Update shared switch status with semaphore protection
        SemaphoreTake(switchSemaphore, portMAX_DELAY);
        sharedSwitchStatus.switch1 = switch1_status;
        sharedSwitchStatus.switch2 = switch2_status;
        SemaphoreGive(switchSemaphore);

        // Delay the task for 100ms
        TaskDelay(pdMS_TO_TICKS(100));
    }
}
