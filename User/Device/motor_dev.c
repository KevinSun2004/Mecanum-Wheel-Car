/**
 * @file motor_dev.c
 * @author drinkcat (szt@drinkcat.com)
 * @brief
 * @version 0.1
 * @date 2023-02-21
 *
 * @copyright Copyright (c) 2023
 *
 */

/***Includes***/
#include "motor_dev.h"
#include "init_config.h"
#include "tim.h"

/***Variables***/

/***Functions***/

/**
 * @brief Init Motor
 *
 */
void motor_init(void)
{
    //Start PWM Output
    HAL_TIM_PWM_Start(&Motor1_PWM_TIM, Motor1_PWM_CH);
    HAL_TIM_PWM_Start(&Motor2_PWM_TIM, Motor2_PWM_CH);
    HAL_TIM_PWM_Start(&Motor3_PWM_TIM, Motor3_PWM_CH);
    HAL_TIM_PWM_Start(&Motor4_PWM_TIM, Motor4_PWM_CH);
 
    //Start Read Encoder IT
    HAL_TIM_Base_Start_IT(&Program_TIM);
}

/**
 * @brief Get the motor speed
 * 
 * @param htim 
 * @param speed 
 * @return int32_t 
 */
int32_t encoder_count = 0;
int32_t get_motor_speed(TIM_HandleTypeDef *htim, float *speed)
{
    encoder_count = (short)(__HAL_TIM_GET_COUNTER(htim));
	__HAL_TIM_SET_COUNTER(htim,0);
	return encoder_count / 132;
}