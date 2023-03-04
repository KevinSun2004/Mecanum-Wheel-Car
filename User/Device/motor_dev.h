/**
 * @file motor_dev.h
 * @author drinkcat (szt@drinkcat.com)
 * @brief
 * @version 0.1
 * @date 2023-02-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _MOTOR_DEV_H_
#define _MOTOR_DEV_H_

/***Includes***/
#include "tim.h"
#include "connect_config.h"
#include "tim.h"
#include "math.h"

#endif
/***Functions***/
void motor_init(void);
void get_motor_speed(TIM_HandleTypeDef *htim, float *speed);
void motor_ctrl(float v1, float v2, float v3, float v4);
