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

/***Variables***/
Remote_Typedef remote_info;

/***Functions***/

/**
 * @brief Remote Init
 *
 */
void remote_init(void)
{
    remote_info.arm_position = 0;
    remote_info.control_x    = 0;
    remote_info.control_y    = 0;
    remote_info.count        = 0;
    remote_info.rotate_l     = 0;
    remote_info.rotate_r     = 0;

    // Init UART_DMA
    HAL_UARTEx_ReceiveToIdle_DMA(&Bluetooth_UART, (uint8_t *)remote_info.rx_buff, MAX_BUF);
}

/**
 * @brief Rx Callback
 *
 * @param huart
 * @param Size
 */
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if (remote_info.rx_buff[0] == 0xA5 && remote_info.rx_buff[data_length - 1] == 0x5A) {
        rc_handler(remote_info.rx_buff);
    }
    HAL_UARTEx_ReceiveToIdle_DMA(&Bluetooth_UART, (uint8_t *)remote_info.rx_buff, MAX_BUF);
}

/**
 * @brief Data Handler
 *
 * @param data
 */
void rc_handler(uint8_t data[])
{
    remote_info.control_x = data[1];
    remote_info.control_y = data[2];
    if (remote_info.control_x > 127) remote_info.control_x -= 256;
    if (remote_info.control_y > 127) remote_info.control_y -= 256;
    remote_info.arm_position = data[3];
    remote_info.rotate_l     = data[4];
    remote_info.rotate_r     = data[5];
}
