/**
 * @file init_config.c
 * @author drinkcat (szt@drinkcat.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/***Includes***/
#include "init_config.h"
#include "remote_dev.h"
#include "arm_task.h"
#include "chassis_task.h"

/***Functions***/

/**
 * @brief Frame Init
 * 
 */
void frame_init(void)
{
    remote_init();
    chassis_init();
    arm_init();
}
