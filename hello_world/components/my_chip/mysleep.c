#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "esp_sleep.h"
#include "esp_pm.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "esp_log.h"
#include "driver/rtc_io.h"
#include "esp32s3/pm.h"
#include "mysleep.h"
#include "ctrl.h"

#define TAG "sleep"
extern TaskHandle_t sleep_mode_handle;
void accGoToSleepMode();
void SleepModeInit();

/**
=======================================================================================
*/

/**
 * EXT0 、 TIMER、 
*/
void SleepModeInit(){
    gpio_config_t io_conf = {
        .intr_type = GPIO_INTR_ANYEDGE,
        .pin_bit_mask = GPIO_INPUT_PIN_SEL,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = 1
    }; 
    gpio_config(&io_conf);

    // *EXT0
    printf("Enabling EXT0 wakeup on pin GPIO%d\n", EXT_WAKEUP_PIN);
    ESP_ERROR_CHECK(esp_sleep_enable_ext0_wakeup(EXT_WAKEUP_PIN, INPUT_LEVEL_LOW));
    ESP_ERROR_CHECK(rtc_gpio_pullup_dis(EXT_WAKEUP_PIN));
    ESP_ERROR_CHECK(rtc_gpio_pulldown_en(EXT_WAKEUP_PIN));
    // *timer
    printf("Enabling timer wakeup on 60S\n");
    ESP_ERROR_CHECK(esp_sleep_enable_timer_wakeup(2*1000*1000));

}


void sleep_mode_task(void* arg){

    SleepModeInit();
    task_ctl_stru.sleep_mode_state = 0;
    vTaskSuspend(sleep_mode_handle);
    task_ctl_stru.sleep_mode_state = 1;
    while (1)
    {
        if(task_ctl_stru.lvgl_state){
            ESP_LOGE(TAG,"lvgl_state didn't suspend");
        }

        ESP_LOGW(TAG, "go to sleep mode");
        vTaskDelay(100 / portTICK_PERIOD_MS); 
        ESP_ERROR_CHECK( esp_light_sleep_start());   
                
        switch (esp_sleep_get_wakeup_cause())
        {
            case ESP_SLEEP_WAKEUP_EXT0: {
                ESP_LOGW(TAG,"Wake up from ext0");
                    break;
                }
            case ESP_SLEEP_WAKEUP_UART:{ 
                ESP_LOGW(TAG,"Wake up from uart");
                break;
            }
            case ESP_SLEEP_WAKEUP_TIMER: {
                ESP_LOGW(TAG,"Wake up from timer");
                break;
            }
            default:
                ESP_LOGE(TAG,"Wake up no value");
                break;
        }
    }
    
}

void SleepModeTaskTrigger(uint8_t option){
        ESP_LOGW(TAG,"option %d",option);
        if(option ==0){
            task_ctl_stru.SLEEP_MODE_TRIGGER = 1;
            vTaskDelay(1000 / portTICK_PERIOD_MS);  
            vTaskResume(sleep_mode_handle);
        }
}
