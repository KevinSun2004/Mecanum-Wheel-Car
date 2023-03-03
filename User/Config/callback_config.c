/**
 * @file callback_config.c
 * @author drinkcat (szt@drinkcat.com)
 * @brief
 * @version 0.1
 * @date 2023-02-22
 *
 * @copyright Copyright (c) 2023
 *
 */

/***Includes***/
#include "callback_config.h"

/***Functions***/

/**
 * @brief Timer Callback
 * 
 * @param htim 
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim == &Program_TIM)
    {
        PS2_Read_Data();
        chassis_tim_callback();
    }
}

/**
 * @brief Uart Callback
 * 
 * @param huart 
 * @param Size 
 */
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    //if(huart == &Bluetooth_UART)
    //{
    //    remote_uart_callback();
    //}
}
