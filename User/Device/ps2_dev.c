/**
 * @file ps2_dev.c
 * @author drinkcat (szt@drinkcat.com)
 * @brief
 * @version 0.1
 * @date 2023-02-28
 *
 * @copyright Copyright (c) 2023
 *
 */

/***Includes***/
#include "ps2_dev.h"

/***Variables***/
PS2_TypeDef PS2_Data   = {0};
uint8_t PS2_RawData[9] = {0};

/***Functions***/

/**
 * @brief PS2 Delay
 *
 */
void PS2_Delay()
{
    for (int i = 0; i < 0xBf; i++)
        __nop();
}

/**
 * @brief PS2 Read & Write Data
 *
 * @param TxData
 * @return uint8_t
 */
uint8_t PS2_Rx_and_Tx(uint8_t TxData)
{
    uint8_t TX = TxData, RX = 0;
    for (int i = 0; i < 8; i++)
    {
        if (TX & 0x01)
            HAL_GPIO_WritePin(CMD_Port, CMD_Pin, GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(CMD_Port, CMD_Pin, GPIO_PIN_RESET);
        TX >>= 1;
        HAL_GPIO_WritePin(CLK_Port, CLK_Pin, GPIO_PIN_SET);
        PS2_Delay();
        HAL_GPIO_WritePin(CLK_Port, CLK_Pin, GPIO_PIN_RESET);
        RX >>= 1;
        RX |= (HAL_GPIO_ReadPin(DAT_Port, DAT_Pin) << 7);
        PS2_Delay();
        HAL_GPIO_WritePin(CLK_Port, CLK_Pin, GPIO_PIN_SET);
        PS2_Delay();
    }
    return RX;
}

/**
 * @brief PS2 Data Decode
 *
 */
void PS2_Decode()
{
    if (PS2_RawData[2] == 0x5A)
    {
        PS2_Data.Key_Select = (~PS2_RawData[3] >> 0) & 0x01; // 选择键
        PS2_Data.Key_Start  = (~PS2_RawData[3] >> 3) & 0x01; // 开始键

        // 左侧按键
        PS2_Data.Key_L_Up    = (~PS2_RawData[3] >> 4) & 0x01;
        PS2_Data.Key_L_Right = (~PS2_RawData[3] >> 5) & 0x01;
        PS2_Data.Key_L_Down  = (~PS2_RawData[3] >> 6) & 0x01;
        PS2_Data.Key_L_Left  = (~PS2_RawData[3] >> 7) & 0x01;

        // 后侧按键
        PS2_Data.Key_L2 = (~PS2_RawData[4] >> 0) & 0x01;
        PS2_Data.Key_R2 = (~PS2_RawData[4] >> 1) & 0x01;
        PS2_Data.Key_L1 = (~PS2_RawData[4] >> 2) & 0x01;
        PS2_Data.Key_R1 = (~PS2_RawData[4] >> 3) & 0x01;

        // 右侧按键
        PS2_Data.Key_R_Up    = (~PS2_RawData[4] >> 4) & 0x01;
        PS2_Data.Key_R_Right = (~PS2_RawData[4] >> 5) & 0x01;
        PS2_Data.Key_R_Down  = (~PS2_RawData[4] >> 6) & 0x01;
        PS2_Data.Key_R_Left  = (~PS2_RawData[4] >> 7) & 0x01;

        if (PS2_RawData[1] == 0x41) // 无灯模式(摇杆值八向)
        {
            PS2_Data.Rocker_LX = 127 * (PS2_Data.Key_L_Right - PS2_Data.Key_L_Left);
            PS2_Data.Rocker_LY = 127 * (PS2_Data.Key_L_Up - PS2_Data.Key_L_Down);

            PS2_Data.Rocker_RX = 127 * (PS2_Data.Key_R_Right - PS2_Data.Key_R_Left);
            PS2_Data.Rocker_RY = 127 * (PS2_Data.Key_R_Up - PS2_Data.Key_R_Down);
        }
        else if (PS2_RawData[1] == 0x73) // 红灯模式(摇杆值模拟)
        {

            // 摇杆按键
            PS2_Data.Key_Rocker_Left  = (~PS2_RawData[3] >> 1) & 0x01;
            PS2_Data.Key_Rocker_Right = (~PS2_RawData[3] >> 2) & 0x01;

            // 摇杆值
            PS2_Data.Rocker_LX = PS2_RawData[7] - 0x80;
            PS2_Data.Rocker_LY = -1 - (PS2_RawData[8] - 0x80);
            PS2_Data.Rocker_RX = PS2_RawData[5] - 0x80;
            PS2_Data.Rocker_RY = -1 - (PS2_RawData[6] - 0x80);
        }

        //零漂
        if(abs(PS2_Data.Rocker_LX)<5) PS2_Data.Rocker_LX = 0;
        if(abs(PS2_Data.Rocker_LY)<5) PS2_Data.Rocker_LY = 0;
        if(abs(PS2_Data.Rocker_RX)<5) PS2_Data.Rocker_RX = 0;
        if(abs(PS2_Data.Rocker_RY)<5) PS2_Data.Rocker_RY = 0;
    }
}

/**
 * @brief PS2 Read Data
 *
 */
void PS2_Read_Data()
{
    HAL_GPIO_WritePin(ATT_Port, ATT_Pin, GPIO_PIN_RESET);
    PS2_RawData[0] = PS2_Rx_and_Tx(0x01); // 0
    PS2_RawData[1] = PS2_Rx_and_Tx(0x42); // 1
    for (int i = 2; i < 9; i++)
        PS2_RawData[i] = PS2_Rx_and_Tx(0xff);
    HAL_GPIO_WritePin(ATT_Port, ATT_Pin, GPIO_PIN_SET);
    PS2_Decode();
}
