#include "freertos/semphr.h"
#include "esp_sleep.h"

void gpio_irq_acc_handler_task(void* arg);
void sleep_mode_task(void* arg);
void resetFreeGpioInit();
void SleepModeTaskTrigger(uint8_t b);

//EXT0
#define ETX0_INPUT_PIN 2
#define GPIO_INTERRUPT_INPUT_PIN     ETX0_INPUT_PIN      //ACC
#define GPIO_INPUT_PIN_SEL  1ULL<<GPIO_INTERRUPT_INPUT_PIN
#define ESP_INTR_FLAG_DEFAULT 0
//SLEEP
#define EXT_WAKEUP_PIN ETX0_INPUT_PIN       //sleep
#define INPUT_LEVEL_HIGH 1// – input level which will trigger wakeup (0=low, 1=high)
#define INPUT_LEVEL_LOW !INPUT_LEVEL_HIGH// – input level which will trigger wakeup (0=low, 1=high) 
