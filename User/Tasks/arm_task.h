/**
 * @file arm_task.h
 * @author drinkcat (szt@drinkcat.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/***Includes***/
#ifndef _ARM_DEVICE_H_
#define _ARM_DEVICE_H_

#include "main.h"
#include "remote_dev.h"
#include "tim.h"
#include "stdbool.h"
#include "steering_engine_dev.h"
#include "init_config.h"

/***Define***/
#define PI 3.1415926

//arm length
#define L1 10 //long arm
#define L2 10 //short arm

//init for steering engine ccr
#define init_1 false
#define init_ver 90
#define init_x 10
#define init_y 0

//limit
#define alpha_low 0
#define alpha_high PI
#define beta_low 0
#define beta_high PI
#define gamma_low 0
#define gamma_high PI

//speed
#define arm_speed 0.1

#endif

/***Functions***/
void arm_init(void);
void move_arm(double x, double y, double degree);
void arm_control(void);
void arm_tim_callback(void);

int degree2ccr(int degree);
int radian2ccr(double radian);
double degree2radian(double degree);
