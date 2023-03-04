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

/***Functions***/

/**
 * @brief Init Steering Engine
 *
 * @param htim
 * @param channel
 */
void steering_engine_init(TIM_HandleTypeDef htim, uint32_t channel)
{
    HAL_TIM_PWM_Start(&htim, channel);
}

/**
 * @brief Set the CCR Value
 *
 * @param htim
 * @param channel
 * @param value
 */
void set_ccr(TIM_HandleTypeDef htim, uint32_t channel, int value)
{
    __HAL_TIM_SetCompare(&htim, channel, value);
}
