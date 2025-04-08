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
#define SDRAM_CX_BASE(clip)				SDRAM_BANK_ADDR + clip*1000000
#define SDRAM_C1_BASE					SDRAM_BANK_ADDR + 1000000 // 1 MByte
#define SDRAM_C2_BASE					SDRAM_BANK_ADDR + 2000000 // 2 MByte
#define SDRAM_C3_BASE					SDRAM_BANK_ADDR + 3000000 // 3 MByte
#define SDRAM_C4_BASE					SDRAM_BANK_ADDR + 4000000 // 4 MByte
#define SDRAM_C5_BASE					SDRAM_BANK_ADDR + 5000000 // 5 MByte
#define SDRAM_C6_BASE					SDRAM_BANK_ADDR + 6000000 // 6 MByte
#define SDRAM_C7_BASE					SDRAM_BANK_ADDR + 7000000 // 7 MByte
#define SDRAM_C8_BASE					SDRAM_BANK_ADDR + 8000000 // 8 MByte
#define SDRAM_C9_BASE					SDRAM_BANK_ADDR + 9000000 // 9 MByte
#define SDRAM_C10_BASE					SDRAM_BANK_ADDR + 10000000 // 10 MByte
#define SDRAM_C11_BASE					SDRAM_BANK_ADDR + 11000000 // 11 MByte

#define FLASH_COMMON_BANK_ADDR			0x80000000
#define FLASH_ATTRIBUTE_BANK_ADDR		0x88000000
#define FLASH_DATA_OFFSET				  0x000000
#define FLASH_COMMAND_OFFSET			  0x010000
#define FLASH_ADDRESS_OFFSET			  0x020000
#define NAND_CMD_READ1					0x00
#define NAND_CMD_READ2					0x30


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
