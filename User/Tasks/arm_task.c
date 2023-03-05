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
double current_hand   = 0;
double current_alpha  = 0;
double current_beta   = 0;
double current_gamma  = 0;

/***Funtions***/

/**
 * @brief Arm Init
 *
 */
void arm_init(void)
{
    move_arm(init_x, init_y, init_degree, init_hand);
    steering_engine_init(SteeringEngine1_TIM, SteeringEngine1_CH);
    steering_engine_init(SteeringEngine2_TIM, SteeringEngine2_CH);
    steering_engine_init(SteeringEngine3_TIM, SteeringEngine3_CH);
    steering_engine_init(SteeringEngine4_TIM, SteeringEngine4_CH);
}

/**
 * @brief Update ccr
 *
 * @param alpha
 * @param beta
 * @param gamma
 * @param hand
 */
void update_ccr(int alpha, int beta, int gamma, int hand)
{
    set_ccr(SteeringEngine1_TIM, SteeringEngine1_CH, alpha);
    set_ccr(SteeringEngine2_TIM, SteeringEngine2_CH, beta);
    set_ccr(SteeringEngine3_TIM, SteeringEngine3_CH, gamma);
    set_ccr(SteeringEngine4_TIM, SteeringEngine4_CH, hand);
}

/**
 * @brief Update Current Value
 *
 * @param alpha
 * @param beta
 * @param gamma
 * @param hand
 */
void update_current_value(int x, int y, int degree, int hand, double alpha, double beta, double gamma)
{
    current_x      = x;
    current_y      = y;
    current_degree = degree;
    current_hand   = hand;
    current_alpha  = alpha;
    current_beta   = beta;
    current_gamma  = gamma;
}

/**
 * @brief Test If Data is Within Limit
 *
 * @param alpha
 * @param beta
 * @param gamma
 * @param hand
 * @return true: Within Limit
 * @return false: Without Limit
 */
bool arm_limit(double alpha, double beta, double gamma, double hand)
{
    if (alpha < alpha_low || alpha > alpha_high) return false;
    if (beta < beta_low || beta > beta_high) return false;
    if (gamma < gamma_low || gamma > gamma_high) return false;
    if (hand < hand_low || hand > hand_high) return false;
    return true;
}

/**
 * @brief Move Arm
 *
 * @param x Target x
 * @param y Target y
 * @param degree Target degree
 * @param hand Hand
 */
void move_arm(double x, double y, double degree, double hand) // degree: degree between horizon and clip
{
    // cal_radian
    double alpha, beta, gamma;
    alpha = atan(y / x) + acos((L1 * L1 + x * x + y * y - L2 * L2) / (2 * L1 * sqrt(x * x + y * y)));
    beta  = acos((L1 * L1 + L2 * L2 - x * x - y * y) / (2 * L1 * L2));
    gamma = alpha + beta - PI + degree2radian(degree);

    // limit
    if (!arm_limit(alpha, beta, gamma, hand)) return;

    // within limit -> refresh variables
    update_current_value(x, y, degree, hand, alpha, beta, gamma);
}

/**
 * @brief Arm Control
 *
 * @param arm_position
 */
void arm_control()
{
    /**
     * 遥控器控制方式
     * 左侧四个方向 & 两个独立按键控制固定位置
     * 右侧四个按键控制机械臂位姿
     * 四个扳机分别控制夹爪收夹、俯仰角度
     *
     * 需要的高度：
     *
     * 0mm (1)
     * 150mm (2)
     * 200mm
     * 225mm (3)
     * 250mm
     * 300mm (4)
     * 400mm (5)
     * 放置到储存盘 (6)
     *
     */

    // 位置1
    if (PS2_Data.Key_L_Up == 1)
        move_arm(100, 0 - H, 90, current_hand);
    // 位置2
    if (PS2_Data.Key_L_Down == 1)
        move_arm(100, 150 - H, 90, current_hand);
    // 位置3
    if (PS2_Data.Key_L_Right == 1)
        move_arm(100, 225 - H, 90, current_hand);
    // 位置4
    if (PS2_Data.Key_L_Left == 1)
        move_arm(100, 300 - H, 90, current_hand);
    // 位置5
    if (PS2_Data.Key_Select == 1)
        move_arm(100, 0 - H, 90, current_hand);
    // 位置6
    if (PS2_Data.Key_Start == 1)
        move_arm(100, 0 - H, 90, current_hand);
    // 上移
    if (PS2_Data.Key_R_Up == 1)
        move_arm(current_x, current_y + arm_speed, current_degree, current_hand);
    // 下移
    if (PS2_Data.Key_R_Down == 1)
        move_arm(current_x, current_y - arm_speed, current_degree, current_hand);
    // 前移
    if (PS2_Data.Key_R_Right == 1)
        move_arm(current_x + arm_speed, current_y, current_degree, current_hand);
    // 后移
    if (PS2_Data.Key_R_Left == 1)
        move_arm(current_x - arm_speed, current_y, current_degree, current_hand);
    // 下旋
    if (PS2_Data.Key_L1 == 1)
        move_arm(current_x, current_y, current_degree + arm_speed, current_hand);
    // 上旋
    if (PS2_Data.Key_R1 == 1)
        move_arm(current_x, current_y, current_degree - arm_speed, current_hand);
    // 夹爪张开
    if (PS2_Data.Key_R2 == 1)
        move_arm(current_x, current_y, current_degree, current_hand + arm_speed);
    // 夹爪收起
    if (PS2_Data.Key_L2 == 1)
        move_arm(current_x, current_y, current_degree, current_hand - arm_speed);

    // Update Output 
    update_ccr(radian2ccr(current_alpha), radian2ccr(current_beta), radian2ccr(current_gamma), degree2ccr(current_hand));
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