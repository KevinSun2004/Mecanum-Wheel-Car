/**
 * @file remote_dev.c
 * @author drinkcat (szt@drinkcat.com)
 * @brief
 * @version 0.1
 * @date 2023-02-21
 *
 * @copyright Copyright (c) 2023
 *
 */

/***Includes***/
#include "remote_dev.h"
#include "init_config.h"
#include "usart.h"
#include "dma.h"
#include "stdbool.h"

/***Variables***/

/**
 * @brief Buffer
 *
 */
uint8_t rx_buff[MAX_BUF];

/**
 * @brief Rc_info
 *
 */
bool rotate_l        = 0;
bool rotate_r        = 0;
int control_x        = 0;
int control_y        = 0;
uint8_t arm_position = 0x00;
uint8_t count        = 0;

/***Functions***/

/**
 * @brief Remote Init
 *
 */
void remote_init(void)
{
    // Init UART_DMA
    HAL_UARTEx_ReceiveToIdle_DMA(&Bluetooth_UART, (uint8_t *)rx_buff, MAX_BUF);
}

/**
 * @brief Rx Callback
 *
 * @param huart
 * @param Size
 */
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if (rx_buff[0] == 0xA5 && rx_buff[data_length - 1] == 0x5A)
    {
        rc_handler(rx_buff);
    }
    HAL_UARTEx_ReceiveToIdle_DMA(&Bluetooth_UART, (uint8_t *)rx_buff, MAX_BUF);
}

/**
 * @brief Data Handler
 *
 * @param data
 */
void rc_handler(uint8_t data[])
{
    control_x = data[1];
    control_y = data[2];
    if (control_x > 127) control_x -= 256;
    if (control_y > 127) control_y -= 256;
    arm_position = data[3];
    rotate_l     = data[4];
    rotate_r     = data[5];
}
