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
#include "callback_config.h"
#include "init_config.h"

/***Functions***/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim == &Program_TIM)
    {

    }
}
