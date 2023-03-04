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

#ifndef _CHASSIS_TASK_H_
#define _CHASSIS_TASK_H_

/***Includes***/
#include "pid_util.h"
#include "motor_dev.h"
#include "connect_config.h"
#include "remote_dev.h"
#include "ps2_dev.h"

/***Typedef***/
typedef struct
{
    PID_Typedef pid_info[4];
    float speed[4];
} Chassis_Typedef;

#endif
/***Functions***/
void chassis_init(void);
void chassis_tim_callback(void);
void pid_control(void);
void chassis_calc(int32_t x, int32_t y, int32_t yaw);
