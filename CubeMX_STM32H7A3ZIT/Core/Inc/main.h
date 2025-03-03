/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32h7xx_hal.h"
#include <stdlib.h>
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern volatile int mode;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Keypad_C5_Pin GPIO_PIN_2
#define Keypad_C5_GPIO_Port GPIOE
#define Keypad_C5_EXTI_IRQn EXTI2_IRQn
#define Keypad_C4_Pin GPIO_PIN_3
#define Keypad_C4_GPIO_Port GPIOE
#define Keypad_C4_EXTI_IRQn EXTI3_IRQn
#define Keypad_R1_Pin GPIO_PIN_4
#define Keypad_R1_GPIO_Port GPIOE
#define Keypad_C3_Pin GPIO_PIN_5
#define Keypad_C3_GPIO_Port GPIOE
#define Keypad_C3_EXTI_IRQn EXTI9_5_IRQn
#define Keypad_R2_Pin GPIO_PIN_6
#define Keypad_R2_GPIO_Port GPIOE
#define Keypad_R3_Pin GPIO_PIN_13
#define Keypad_R3_GPIO_Port GPIOC
#define Keypad_C2_Pin GPIO_PIN_14
#define Keypad_C2_GPIO_Port GPIOC
#define Keypad_C2_EXTI_IRQn EXTI15_10_IRQn
#define Keypad_C1_Pin GPIO_PIN_15
#define Keypad_C1_GPIO_Port GPIOC
#define Keypad_C1_EXTI_IRQn EXTI15_10_IRQn
#define Keypad_R4_Pin GPIO_PIN_7
#define Keypad_R4_GPIO_Port GPIOF

/* USER CODE BEGIN Private defines */
#define STOPMODE		0
#define TXMODE			1
#define RXMODE			2
#define ERRMODE			-1
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
