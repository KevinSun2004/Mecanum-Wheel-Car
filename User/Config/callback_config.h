/**
 * @file callback_config.h
 * @author drinkcat (szt@drinkcat.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _CALLBACK_CONFIG_H_
#define _CALLBACK_CONFIG_H_

/***Includes***/
#include "tim.h"
#include "usart.h"
#include "init_config.h"
#include "chassis_task.h"
#include "remote_dev.h"
#include "ps2_dev.h"

#endif
/***Functions***/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);
