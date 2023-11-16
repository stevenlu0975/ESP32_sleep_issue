#include "driver/ledc.h"
#define LCD_PIN_BK_LIGHT       45
/**
 * 1~8191
 * 
*/
void ledc_pwm_init(int lightLevel){
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_TIMER_13_BIT, // 分辨率
        .freq_hz = 5000,                      // PWM频率（1 kHz）
        .speed_mode = LEDC_LOW_SPEED_MODE,   // 速度模式
        .timer_num = LEDC_TIMER_0,            // 使用的定时器
        .clk_cfg = LEDC_AUTO_CLK              // 自动时钟分频
    };
    ledc_timer_config(&ledc_timer);
    ledc_channel_config_t ledc_channel = {
        .channel = LEDC_CHANNEL_0,       // 使用的PWM通道
        .duty = 0,                       // 初始占空比
        .gpio_num = LCD_PIN_BK_LIGHT,          // 使用的GPIO引脚
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .hpoint = 0,
        .timer_sel = LEDC_TIMER_0
    };
    ledc_channel_config(&ledc_channel);// 启动PWM通道
    ledc_fade_func_install(0);// 设置占空比（范围从0到8191，0表示低电平，8191表示高电平）

    // 修改為之後，要觸發更新
    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, lightLevel);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
}
/**
 * 0~8191
*/
void ledc_pwm_update_duty(uint16_t  duty){
    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, duty);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
}
int ledc_pwm_get_duty(){
    return  ledc_get_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_0);
}