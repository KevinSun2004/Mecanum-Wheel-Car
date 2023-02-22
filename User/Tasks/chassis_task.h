/**
 * @file chassis_task.h
 * @author drinkcat (szt@drinkcat.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/***Includes***/
#include "pid_util.h"
#include "motor_dev.h"

/***Typedef***/
typedef struct
{
    PID_Typedef pid_info[4];
    float speed[4];
}Chassis_Typedef;

/***Functions***/
void chassis_init(void);
void chassis_tim_callback(void);
