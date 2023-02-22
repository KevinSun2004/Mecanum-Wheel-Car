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

/***Includes***/
#include "tim.h"

/***Functions***/
void motor_init(void);
int32_t get_motor_speed(TIM_HandleTypeDef *htim, float *speed);
