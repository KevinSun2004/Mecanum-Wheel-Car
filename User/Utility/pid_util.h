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
}PID_Typedef;
