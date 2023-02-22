/**
 * @file chassis_task.c
 * @author drinkcat (szt@drinkcat.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/***Includes***/
#include "chassis_task.h"

/***Variables***/
Chassis_Typedef chassis_info;

/***Functions***/

/**
 * @brief Chassis Init
 * 
 */
void chassis_init()
{
    //Init PID
    pid_data_reset(&chassis_info.pid_info[0]);
    pid_data_reset(&chassis_info.pid_info[1]);
    pid_data_reset(&chassis_info.pid_info[2]);
    pid_data_reset(&chassis_info.pid_info[3]);

    pid_set_value();

    motor_init();
}

/**
 * @brief Chassis Timer Callback
 * 
 */
void chassis_tim_callback()
{

}
