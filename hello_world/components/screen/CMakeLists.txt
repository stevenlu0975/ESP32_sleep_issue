idf_component_register(SRCS "screen.c" "ledc_pwm.c"
                    INCLUDE_DIRS "include" ""
                    REQUIRES lvgl esp_lcd driver freertos gt911 my_chip )
