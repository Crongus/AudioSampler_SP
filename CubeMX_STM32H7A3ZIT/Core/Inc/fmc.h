/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : FMC.h
  * Description        : This file provides code for the configuration
  *                      of the FMC peripheral.
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
#ifndef __FMC_H
#define __FMC_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern NAND_HandleTypeDef hnand1;
extern SDRAM_HandleTypeDef hsdram1;

/* USER CODE BEGIN Private defines */
#define SDRAM_BANK_ADDR 				0xC0000000
#define FLASH_COMMON_BANK_ADDR			0x80000000
#define FLASH_ATTRIBUTE_BANK_ADDR		0x88000000
#define FLASH_DATA_OFFSET				0x00000000
#define FLASH_COMMAND_OFFSET			0x01000000
#define FLASH_ADDRESS_OFFSET			0x02000000



/* USER CODE END Private defines */

void MX_FMC_Init(void);
void HAL_NAND_MspInit(NAND_HandleTypeDef* hnand);
void HAL_NAND_MspDeInit(NAND_HandleTypeDef* hnand);
void HAL_SDRAM_MspInit(SDRAM_HandleTypeDef* hsdram);
void HAL_SDRAM_MspDeInit(SDRAM_HandleTypeDef* hsdram);

/* USER CODE BEGIN Prototypes */
void flashBoot(void);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__FMC_H */

/**
  * @}
  */

/**
  * @}
  */
