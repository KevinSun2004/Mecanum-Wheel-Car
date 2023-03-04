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
#include "ps2_dev.h"
#include "tim.h"
#include "stdbool.h"
#include "steering_engine_dev.h"
#include "connect_config.h"

/***Define***/
#define PI 3.1415926

// arm length (mm)
#define L1 100 // long arm
#define L2 100 // short arm
#define H  100 // chassis height

// init position (mm)
#define init_x      100
#define init_y      0
#define init_degree 90
#define init_hand   0

// limit (radian)
#define alpha_low  0
#define alpha_high PI
#define beta_low   0
#define beta_high  PI
#define gamma_low  0
#define gamma_high PI
#define hand_low   0
#define hand_high  (PI / 2)

// speed
#define arm_speed 0.1

#endif

/***Functions***/
void arm_init(void);
void move_arm(double x, double y, double degree, double hand);
void arm_control(void);
void arm_tim_callback(void);
void update_ccr(int alpha, int beta, int gamma, int hand);
void update_current_value(int x, int y, int degree, int hand, double alpha, double beta, double gamma);
bool arm_limit(double alpha, double beta, double gamma, double hand);

int degree2ccr(int degree);
int radian2ccr(double radian);
double degree2radian(double degree);
