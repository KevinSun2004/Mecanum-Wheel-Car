/**
 * @file arm_task.c
 * @author drinkcat (szt@drinkcat.com)
 * @brief
 * @version 0.1
 * @date 2023-02-22
 *
 * @copyright Copyright (c) 2023
 *
 */

/***Includes***/
#include "arm_task.h"

/***Variables***/
double current_x      = 0;
double current_y      = 0;
double current_degree = 0;

/***Funtions***/

/**
 * @brief Arm Init
 *
 */
void arm_init(void)
{
    move_arm(init_x, init_y, init_ver);
    steering_engine_init();
}

/**
 * @brief Move Arm
 *
 * @param x Target x
 * @param y Target y
 * @param degree Target degree
 */
void move_arm(double x, double y, double degree) // degree: degree between horizon and clip
{
    // cal_radian
    double alpha, beta, gamma;
    alpha = atan(y / x) + acos((L1 * L1 + x * x + y * y - L2 * L2) / (2 * L1 * sqrt(x * x + y * y)));
    beta  = acos((L1 * L1 + L2 * L2 - x * x - y * y) / (2 * L1 * L2));
    gamma = alpha + beta - PI + degree2radian(degree);

    // limit
    if (alpha < alpha_low || alpha > alpha_high) return;
    if (beta < beta_low || beta > beta_high) return;
    if (gamma < gamma_low || gamma > gamma_high) return;

    // within limit -> refresh variables
    current_x      = x;
    current_y      = y;
    current_degree = degree;

    set_ccr(SteeringEngine1_TIM, SteeringEngine1_CH, radian2ccr(alpha));
    set_ccr(SteeringEngine2_TIM, SteeringEngine2_CH, radian2ccr(beta));
    set_ccr(SteeringEngine3_TIM, SteeringEngine3_CH, radian2ccr(gamma));
}

/**
 * @brief Calc Arm Movement
 *
 * @param arm_position
 */
void arm_control()
{
    /*if (arm_position != 0x00) {
        switch (arm_position) {
            case 0xFF: // up
                move_arm(current_x, current_y + arm_speed, current_degree);
                break;

            case 0xFE: // down
                move_arm(current_x, current_y - arm_speed, current_degree);
                break;

            case 0xFD: // forward
                move_arm(current_x + arm_speed, current_y, current_degree);
                break;

            case 0xFC: // backward
                move_arm(current_x - arm_speed, current_y, current_degree);
                break;

            case 0x01: // p1
                move_arm(10, 0, 90);
                break;

            case 0x02: // p2
                move_arm(14, 0, 90);
                break;

            default:
                break;
        }
    }*/
}

/**
 * @brief Data Transfer Funtions
 *
 */
int radian2ccr(double radian)
{
    return (int)((180 * radian / PI) * 100 / 9 + 500);
}
int degree2ccr(int degree)
{
    return (int)((float)degree * 100 / 9 + 500);
}
double degree2radian(double degree)
{
    return degree * PI / 180;
}

/**
 * @brief Arm Timer Callback
 * 
 */
void arm_tim_callback()
{
    arm_control();
}