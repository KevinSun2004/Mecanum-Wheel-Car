/**
 * @file motor_dev.c
 * @author drinkcat (szt@drinkcat.com)
 * @brief
 * @version 0.1
 * @date 2023-02-21
 *
 * @copyright Copyright (c) 2023
 *
 */

/***Includes***/
#include "motor_dev.h"
#include "init_config.h"
#include "tim.h"
#include "math.h"

/***Variables***/

/***Functions***/

/**
 * @brief Init Motor
 *
 */
void motor_init(void)
{
		HAL_TIM_Encoder_Start(&Motor1_Encoder, TIM_CHANNEL_ALL);
		__HAL_TIM_ENABLE_IT(&Motor1_Encoder, TIM_IT_UPDATE);
		HAL_TIM_Encoder_Start(&Motor2_Encoder, TIM_CHANNEL_ALL);
		__HAL_TIM_ENABLE_IT(&Motor1_Encoder, TIM_IT_UPDATE);
		HAL_TIM_Encoder_Start(&Motor3_Encoder, TIM_CHANNEL_ALL);
		__HAL_TIM_ENABLE_IT(&Motor1_Encoder, TIM_IT_UPDATE);
		HAL_TIM_Encoder_Start(&Motor4_Encoder, TIM_CHANNEL_ALL);
		__HAL_TIM_ENABLE_IT(&Motor1_Encoder, TIM_IT_UPDATE);
	
    //Start PWM Output
    HAL_TIM_PWM_Start(&Motor1_PWM_TIM, Motor1_PWM_CH);
    HAL_TIM_PWM_Start(&Motor2_PWM_TIM, Motor2_PWM_CH);
    HAL_TIM_PWM_Start(&Motor3_PWM_TIM, Motor3_PWM_CH);
    HAL_TIM_PWM_Start(&Motor4_PWM_TIM, Motor4_PWM_CH);
 
    //Start Read Encoder IT
    HAL_TIM_Base_Start_IT(&Program_TIM);
}

/**
 * @brief Get the motor speed
 * 
 * @param htim 
 * @param speed 
 * @return int32_t 
 */
int32_t encoder_count = 0;
void get_motor_speed(TIM_HandleTypeDef *htim, float *speed)
{
    encoder_count = (short)(__HAL_TIM_GET_COUNTER(htim));
	__HAL_TIM_SET_COUNTER(htim,0);
    *speed = encoder_count / 13.2f;
}

/**
 * @brief Motor Output Control
 * 
 * @param speed 
 */
void motor_ctrl(float v1, float v2, float v3, float v4)
{
    if(v1 >= 0) {HAL_GPIO_WritePin(Motor1_m1_Port, Motor1_m1_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(Motor1_m2_Port, Motor1_m2_Pin, GPIO_PIN_SET);}
    else {HAL_GPIO_WritePin(Motor1_m1_Port, Motor1_m1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(Motor1_m2_Port, Motor1_m2_Pin, GPIO_PIN_RESET);}
    __HAL_TIM_SetCompare(&Motor1_PWM_TIM, Motor1_PWM_CH, 200 * fabs(v1));

    if(v2 >= 0) {HAL_GPIO_WritePin(Motor2_m1_Port, Motor2_m1_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(Motor2_m2_Port, Motor2_m2_Pin, GPIO_PIN_SET);}
    else {HAL_GPIO_WritePin(Motor2_m1_Port, Motor2_m1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(Motor2_m2_Port, Motor2_m2_Pin, GPIO_PIN_RESET);}
    __HAL_TIM_SetCompare(&Motor2_PWM_TIM, Motor2_PWM_CH, 200 * fabs(v2));

    if(v3 >= 0) {HAL_GPIO_WritePin(Motor3_m1_Port, Motor3_m1_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(Motor3_m2_Port, Motor3_m2_Pin, GPIO_PIN_SET);}
    else {HAL_GPIO_WritePin(Motor3_m1_Port, Motor3_m1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(Motor3_m2_Port, Motor3_m2_Pin, GPIO_PIN_RESET);}
    __HAL_TIM_SetCompare(&Motor3_PWM_TIM, Motor3_PWM_CH, 200 * fabs(v3));

    if(v4 >= 0) {HAL_GPIO_WritePin(Motor4_m1_Port, Motor4_m1_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(Motor4_m2_Port, Motor4_m2_Pin, GPIO_PIN_SET);}
    else {HAL_GPIO_WritePin(Motor4_m1_Port, Motor4_m1_Pin, GPIO_PIN_SET); HAL_GPIO_WritePin(Motor4_m2_Port, Motor4_m2_Pin, GPIO_PIN_RESET);}
    __HAL_TIM_SetCompare(&Motor4_PWM_TIM, Motor4_PWM_CH, 200 * fabs(v4));
}
