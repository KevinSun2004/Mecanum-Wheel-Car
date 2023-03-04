/**
 * @file steering_engine_dev.h
 * @author drinkcat (szt@drinkcat.com)
 * @brief
 * @version 0.1
 * @date 2023-02-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _STEERING_ENGINE_DEV_H_
#define _STEERING_ENGINE_DEV_H_

/***Includes***/
#include "tim.h"
#include "connect_config.h"

#endif
/***Functions***/
void steering_engine_init(TIM_HandleTypeDef htim, uint32_t channel);
void set_ccr(TIM_HandleTypeDef htim, uint32_t channel, int value);
