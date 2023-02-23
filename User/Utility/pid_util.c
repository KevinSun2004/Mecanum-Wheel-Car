/**
 * @file pid_util.c
 * @author drinkcat (szt@drinkcat.com)
 * @brief
 * @version 0.1
 * @date 2023-02-22
 *
 * @copyright Copyright (c) 2023
 *
 */

/***Includes***/
#include "pid_util.h"

/***Functions***/

/**
 * @brief Reset PID Data
 * 
 * @param pid_info Pointer to PID Structure
 */
void pid_data_reset(PID_Typedef *pid_info)
{
    pid_info->err        = 0;
    pid_info->err_last   = 0;
    pid_info->fdb        = 0;
    pid_info->kd         = 0;
    pid_info->ki         = 0;
    pid_info->kp         = 0;
    pid_info->output     = 0;
    pid_info->output_max = 0;
    pid_info->ref        = 0;
    pid_info->sum        = 0;
    pid_info->sum_max    = 0;
}

/**
 * @brief Set PID Value
 * 
 * @param pid_info Pointer to PID Structure
 * @param kp 
 * @param ki 
 * @param kd 
 * @param output_max 
 * @param sum_max 
 */
void pid_set_value(PID_Typedef *pid_info, float kp, float ki, float kd, float output_max, float sum_max)
{
    pid_info->kp         = kp;
    pid_info->ki         = ki;
    pid_info->kd         = kd;
    pid_info->output_max = output_max;
    pid_info->sum_max    = sum_max;
}

/**
 * @brief Set Reference
 * 
 * @param pid_info Pointer to PID Structure
 * @param ref 
 */
void pid_set_ref(PID_Typedef *pid_info, float ref)
{
    pid_info -> ref = ref;
}

/**
 * @brief Set Feedback
 * 
 * @param pid_info Pointer to PID Structure
 * @param fdb 
 */
void pid_set_fdb(PID_Typedef *pid_info, float fdb)
{
    pid_info -> fdb = fdb;
}

/**
 * @brief PID Calculation
 * 
 * @param pid_info 
 */
float err,derr;
void pid_calc(PID_Typedef *pid_info)
{
	err = pid_info->ref - pid_info->fdb;
	pid_info->sum += err;
	pid_info->err_last = pid_info->err;
	pid_info->err = err;
	derr = pid_info->err - pid_info->err_last;

    //Limit Sum
    if(pid_info->sum > pid_info->sum_max) pid_info->sum = pid_info->sum_max;
    if(pid_info->sum < -pid_info->sum_max) pid_info->sum = -pid_info->sum_max;

	pid_info->output = pid_info->kp * err + pid_info->ki * pid_info->sum + pid_info->kd * derr;            

    //Limit Output
    if(pid_info->output > pid_info->output_max) pid_info->output = pid_info->output_max;
    if(pid_info->output < -pid_info->output_max) pid_info->output = -pid_info->output_max;
}
