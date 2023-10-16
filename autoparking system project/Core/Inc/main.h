/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define IR_Left_Pin GPIO_PIN_0
#define IR_Left_GPIO_Port GPIOB
#define LCD_RS_Pin GPIO_PIN_1
#define LCD_RS_GPIO_Port GPIOB
#define LCD_EN_Pin GPIO_PIN_2
#define LCD_EN_GPIO_Port GPIOB
#define LCD_DATA_0_Pin GPIO_PIN_10
#define LCD_DATA_0_GPIO_Port GPIOB
#define LCD_DATA_1_Pin GPIO_PIN_11
#define LCD_DATA_1_GPIO_Port GPIOB
#define LCD_DATA_2_Pin GPIO_PIN_12
#define LCD_DATA_2_GPIO_Port GPIOB
#define LCD_DATA_3_Pin GPIO_PIN_13
#define LCD_DATA_3_GPIO_Port GPIOB
#define STEERING_MOTOR_NEGITVE_Pin GPIO_PIN_8
#define STEERING_MOTOR_NEGITVE_GPIO_Port GPIOC
#define STEERING_MOTOR_POSITIVE_Pin GPIO_PIN_9
#define STEERING_MOTOR_POSITIVE_GPIO_Port GPIOC
#define STEERING_MOTOR_EN_Pin GPIO_PIN_8
#define STEERING_MOTOR_EN_GPIO_Port GPIOA
#define MOVING_MOTOR_NEGITVE_Pin GPIO_PIN_9
#define MOVING_MOTOR_NEGITVE_GPIO_Port GPIOA
#define MOVING_MOTOR_POSITIVE_Pin GPIO_PIN_10
#define MOVING_MOTOR_POSITIVE_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define IR_RIGHT_Pin GPIO_PIN_12
#define IR_RIGHT_GPIO_Port GPIOC
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
