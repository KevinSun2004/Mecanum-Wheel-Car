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
    // Init PID
    pid_data_reset(&chassis_info.pid_info[0]);
    pid_data_reset(&chassis_info.pid_info[1]);
    pid_data_reset(&chassis_info.pid_info[2]);
    pid_data_reset(&chassis_info.pid_info[3]);

    // Set PID Value
    pid_set_value(&chassis_info.pid_info[0], 1.0, 0, 0, 100, 100);
    pid_set_value(&chassis_info.pid_info[1], 1.0, 0, 0, 100, 100);
    pid_set_value(&chassis_info.pid_info[2], 1.0, 0, 0, 100, 100);
    pid_set_value(&chassis_info.pid_info[3], 1.0, 0, 0, 100, 100);

    motor_init();
}

/**
 * @brief Update Motor Speed
 *
 */
void update_speed()
{
    get_motor_speed(&Motor1_Encoder, &chassis_info.speed[0]);
    get_motor_speed(&Motor2_Encoder, &chassis_info.speed[1]);
    get_motor_speed(&Motor3_Encoder, &chassis_info.speed[2]);
    get_motor_speed(&Motor4_Encoder, &chassis_info.speed[3]);
}

/**
 * @brief PID Calculation
 *
 */
void pid_control()
{
    chassis_calc(PS2_Data.Rocker_LX, PS2_Data.Rocker_LY, PS2_Data.Rocker_RX);

    pid_set_fdb(&chassis_info.pid_info[0], chassis_info.speed[0]);
    pid_set_fdb(&chassis_info.pid_info[1], chassis_info.speed[1]);
    pid_set_fdb(&chassis_info.pid_info[2], chassis_info.speed[2]);
    pid_set_fdb(&chassis_info.pid_info[3], chassis_info.speed[3]);

    pid_calc(&chassis_info.pid_info[0]);
    pid_calc(&chassis_info.pid_info[1]);
    pid_calc(&chassis_info.pid_info[2]);
    pid_calc(&chassis_info.pid_info[3]);

    motor_ctrl(chassis_info.pid_info[0].output, chassis_info.pid_info[1].output,
               chassis_info.pid_info[2].output, chassis_info.pid_info[3].output);
}

/**
 * @brief Chassis Movement Calculation
 *
 * @param x
 * @param y
 * @param yaw
 */
void chassis_calc(int32_t x, int32_t y, int32_t yaw)
{
    pid_set_ref(&chassis_info.pid_info[0], 0.25f * (+x + y + yaw));
    pid_set_ref(&chassis_info.pid_info[1], 0.25f * (-x + y + yaw));
    pid_set_ref(&chassis_info.pid_info[2], 0.25f * (-x - y + yaw));
    pid_set_ref(&chassis_info.pid_info[3], 0.25f * (+x - y + yaw));
}

/**
 * @brief Chassis Timer Callback
 *
 */
void chassis_tim_callback()
{
    update_speed();
    pid_control();
}
