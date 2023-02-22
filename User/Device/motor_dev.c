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
