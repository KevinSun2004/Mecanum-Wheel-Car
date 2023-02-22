/**
 * @file init_config.h
 * @author drinkcat (szt@drinkcat.com)
 * @brief
 * @version 0.1
 * @date 2023-02-21
 *
 * @copyright Copyright (c) 2023
 *
 */

/***Includes***/

/**
 * @brief Define Motor Port && Pin && CLK
 *
 */
#define Motor1_m1_Port GPIOB
#define Motor1_m1_Pin  GPIO_PIN_0
#define Motor1_m2_Port GPIOB
#define Motor1_m2_Pin  GPIO_PIN_1
#define Motor1_PWM_TIM htim1
#define Motor1_PWM_CH  TIM_CHANNEL_1
#define Motor1_Encoder htim3
// Encoder: PA6 && PA7

#define Motor2_m1_Port GPIOB
#define Motor2_m1_Pin  GPIO_PIN_2
#define Motor2_m2_Port GPIOB
#define Motor2_m2_Pin  GPIO_PIN_3
#define Motor2_PWM_TIM htim1
#define Motor2_PWM_CH  TIM_CHANNEL_2
#define Motor2_Encoder htim4
// Encoder: PD12 && PD13

#define Motor3_m1_Port GPIOB
#define Motor3_m1_Pin  GPIO_PIN_4
#define Motor3_m2_Port GPIOB
#define Motor3_m2_Pin  GPIO_PIN_5
#define Motor3_PWM_TIM htim1
#define Motor3_PWM_CH  TIM_CHANNEL_3
#define Motor3_Encoder htim5
// Encoder: PA0 && PA1

#define Motor4_m1_Port GPIOB
#define Motor4_m1_Pin  GPIO_PIN_6
#define Motor4_m2_Port GPIOB
#define Motor4_m2_Pin  GPIO_PIN_7
#define Motor4_PWM_TIM htim1
#define Motor4_PWM_CH  TIM_CHANNEL_4
#define Motor4_Encoder htim8
// Encoder: PC6 && PC7

/**
 * @brief Define Steering Engine Port && Pin && CLK && CH
 *
 */
#define SteeringEngine1_Port GPIOA
#define SteeringEngine1_Pin  GPIO_PIN_15
#define SteeringEngine1_TIM  htim2
#define SteeringEngine1_CH   TIM_CHANNEL_1

#define SteeringEngine2_Port GPIOB
#define SteeringEngine2_Pin  GPIO_PIN_3
#define SteeringEngine2_TIM  htim2
#define SteeringEngine2_CH   TIM_CHANNEL_2

#define SteeringEngine3_Port GPIOA
#define SteeringEngine3_Pin  GPIO_PIN_2
#define SteeringEngine3_TIM  htim2
#define SteeringEngine3_CH   TIM_CHANNEL_3

#define SteeringEngine4_Port GPIOA
#define SteeringEngine4_Pin  GPIO_PIN_3
#define SteeringEngine4_TIM  htim2
#define SteeringEngine4_CH   TIM_CHANNEL_4

/**
 * @brief Define Read Encoder IT CLK
 *
 */
#define ReadEncoder_TIM htim6

/**
 * @brief Define Bluetooth Tx && Rx Port && Pin
 *
 */
#define Bluetooth_Tx_Port GPIOA
#define Bluetooth_Tx_Pin  GPIO_PIN_9

#define Bluetooth_Rx_Port GPIOA
#define Bluetooth_Rx_Pin  GPIO_PIN_10

#define Bluetooth_UART    huart1

/***Functions***/
void frame_init(void);
