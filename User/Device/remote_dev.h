/**
 * @file remote_dev.h
 * @author drinkcat (szt@drinkcat.com)
 * @brief
 * @version 0.1
 * @date 2023-02-21
 *
 * @copyright Copyright (c) 2023
 *
 */

/***Includes***/
#include "main.h"
#include "stdbool.h"

/***Define***/
#define data_length 8
#define MAX_BUF     20

/***Typedef***/
typedef struct
{
    bool rotate_l;
    bool rotate_r;
    int control_x;
    int control_y;
    uint8_t arm_position;
    uint8_t count;
    uint8_t rx_buff[MAX_BUF];
}Remote_Typedef;

void remote_init(void);
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);
void rc_handler(uint8_t data[]);
