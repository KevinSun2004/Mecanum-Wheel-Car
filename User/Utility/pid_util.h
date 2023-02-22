/**
 * @file pid_util.h
 * @author drinkcat (szt@drinkcat.com)
 * @brief
 * @version 0.1
 * @date 2023-02-22
 *
 * @copyright Copyright (c) 2023
 *
 */

/***Typedef***/
typedef struct
{
    float kp;
    float ki;
    float kd;
    float sum_max;
    float output_max;

    float ref;
    float fdb;
    float err;
    float err_last;
    float sum;
    float output;
} PID_Typedef;

/***Functions***/
void pid_data_reset(PID_Typedef *pid_info);
void pid_set_value(PID_Typedef *pid_info, float kp, float ki, float kd, float output_max, float sum_max);
void pid_set_ref(PID_Typedef *pid_info, float ref);
void pid_set_fdb(PID_Typedef *pid_info, float fdb);
