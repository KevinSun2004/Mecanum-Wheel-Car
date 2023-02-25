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

/***Includes***/
#include "tim.h"
#include "usart.h"

/***Functions***/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);