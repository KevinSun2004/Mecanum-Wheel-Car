/**
 * @file steering_engine_dev.c
 * @author drinkcat (szt@drinkcat.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/***Includes***/
#include "steering_engine_dev.h"
#include "init_config.h"

/***Functions***/

/**
 * @brief Init Steering Engine
 * 
 */
void steering_engine_init(void)
{
    //Start PWM Output
    HAL_TIM_PWM_Start(&SteeringEngine1_TIM, SteeringEngine1_CH);
    HAL_TIM_PWM_Start(&SteeringEngine2_TIM, SteeringEngine2_CH);
    HAL_TIM_PWM_Start(&SteeringEngine3_TIM, SteeringEngine3_CH);
    HAL_TIM_PWM_Start(&SteeringEngine4_TIM, SteeringEngine4_CH);
}

/**
 * @brief Set the CCR Value
 * 
 * @param htim 
 * @param channel 
 * @param value 
 */
void set_ccr(TIM_HandleTypeDef htim, uint32_t channel, uint32_t value)
{
    __HAL_TIM_SetCompare(&htim, channel, value);
}
