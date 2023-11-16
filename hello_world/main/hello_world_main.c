/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>

#include <inttypes.h>
#include "sdkconfig.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/portmacro.h"
#include "freertos/projdefs.h"

#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_log.h"
/**UI*/
#include "lvgl.h"
// #include "ui.h"
#include "board.h"
/**other*/
#include "mysleep.h"
#include "ctrl.h"

TaskControl task_ctl_stru;
TaskHandle_t sleep_mode_handle;
TaskHandle_t lvgl_handle;

void app_main(void)
{
    printf("Hello world!\n");
    xTaskCreate(sleep_mode_task, "sleep_mode_task", 4096 * 4, NULL, 3,&sleep_mode_handle);  //kxcj91008_test
    xTaskCreate(lvgl_task,"lvgl_task",8 * 2048, NULL,3,&lvgl_handle);
    SleepModeTaskTrigger(0);
}
