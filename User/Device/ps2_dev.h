/**
 * @file ps2_dev.h
 * @author drinkcat (szt@drinkcat.com)
 * @brief
 * @version 0.1
 * @date 2023-02-28
 *
 * @copyright Copyright (c) 2023
 *
 */

/***Includes***/
#include "main.h"
#include "init_config.h"

/***Typedef***/
typedef struct
{
    uint8_t A_D;                                       // 模拟(红灯)为1 数字(无灯)为0
    int8_t Rocker_RX, Rocker_RY, Rocker_LX, Rocker_LY; // 摇杆值(模拟状态为实际值0-0xFF)(数字态为等效的值0,0x80,0xFF)
    // 按键值0为未触发,1为触发态
    uint8_t Key_L1, Key_L2, Key_R1, Key_R2;                // 后侧大按键
    uint8_t Key_L_Right, Key_L_Left, Key_L_Up, Key_L_Down; // 左侧按键
    uint8_t Key_R_Right, Key_R_Left, Key_R_Up, Key_R_Down; // 右侧按键
    uint8_t Key_Select;                                    // 选择键
    uint8_t Key_Start;                                     // 开始键
    uint8_t Key_Rocker_Left, Key_Rocker_Right;             // 摇杆按键

} PS2_TypeDef;

/***Funtions***/
void PS2_Delay(void);
uint8_t PS2_Rx_and_Tx(uint8_t TxData);
void PS2_Decode(void);
void PS2_Decode(void);
void PS2_Read_Data(void);
