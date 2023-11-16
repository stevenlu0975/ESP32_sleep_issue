typedef struct{

    bool SLEEP_MODE_TRIGGER;                //為1代表要把自己掛起
    bool sleep_mode_state;                  //為0代表已把自己掛起 sleep_mode_task
    bool lvgl_state;                        //為0代表已把自己掛起 lvgl_task
}TaskControl;
extern TaskControl task_ctl_stru;