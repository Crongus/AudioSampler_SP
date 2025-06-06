/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    i2s.c
 * @brief   This file provides code for the configuration
 *          of the I2S instances.
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
/* Includes ------------------------------------------------------------------*/
#include "i2s.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

I2S_HandleTypeDef hi2s1;
I2S_HandleTypeDef hi2s2;
DMA_HandleTypeDef hdma_spi1_rx;
DMA_HandleTypeDef hdma_spi2_tx;

/* I2S1 init function */
void MX_I2S1_Init(void)
{

  /* USER CODE BEGIN I2S1_Init 0 */

  /* USER CODE END I2S1_Init 0 */

  /* USER CODE BEGIN I2S1_Init 1 */

  /* USER CODE END I2S1_Init 1 */
  hi2s1.Instance = SPI1;
  hi2s1.Init.Mode = I2S_MODE_MASTER_RX;
  hi2s1.Init.Standard = I2S_STANDARD_PHILIPS;
  hi2s1.Init.DataFormat = I2S_DATAFORMAT_16B;
  hi2s1.Init.MCLKOutput = I2S_MCLKOUTPUT_ENABLE;
  hi2s1.Init.AudioFreq = I2S_AUDIOFREQ_8K;
  hi2s1.Init.CPOL = I2S_CPOL_LOW;
  hi2s1.Init.FirstBit = I2S_FIRSTBIT_MSB;
  hi2s1.Init.WSInversion = I2S_WS_INVERSION_DISABLE;
  hi2s1.Init.Data24BitAlignment = I2S_DATA_24BIT_ALIGNMENT_RIGHT;
  hi2s1.Init.MasterKeepIOState = I2S_MASTER_KEEP_IO_STATE_ENABLE;
  if (HAL_I2S_Init(&hi2s1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2S1_Init 2 */

  /* USER CODE END I2S1_Init 2 */

}
/* I2S2 init function */
void MX_I2S2_Init(void)
{

  /* USER CODE BEGIN I2S2_Init 0 */

  /* USER CODE END I2S2_Init 0 */

  /* USER CODE BEGIN I2S2_Init 1 */

  /* USER CODE END I2S2_Init 1 */
  hi2s2.Instance = SPI2;
  hi2s2.Init.Mode = I2S_MODE_MASTER_TX;
  hi2s2.Init.Standard = I2S_STANDARD_PHILIPS;
  hi2s2.Init.DataFormat = I2S_DATAFORMAT_16B;
  hi2s2.Init.MCLKOutput = I2S_MCLKOUTPUT_ENABLE;
  hi2s2.Init.AudioFreq = 8000UL;
  hi2s2.Init.CPOL = I2S_CPOL_LOW;
  hi2s2.Init.FirstBit = I2S_FIRSTBIT_MSB;
  hi2s2.Init.WSInversion = I2S_WS_INVERSION_DISABLE;
  hi2s2.Init.Data24BitAlignment = I2S_DATA_24BIT_ALIGNMENT_RIGHT;
  hi2s2.Init.MasterKeepIOState = I2S_MASTER_KEEP_IO_STATE_ENABLE;
  if (HAL_I2S_Init(&hi2s2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2S2_Init 2 */

  /* USER CODE END I2S2_Init 2 */

}

void HAL_I2S_MspInit(I2S_HandleTypeDef* i2sHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(i2sHandle->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspInit 0 */

  /* USER CODE END SPI1_MspInit 0 */
    /* I2S1 clock enable */
    __HAL_RCC_SPI1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    /**I2S1 GPIO Configuration
    PA5     ------> I2S1_CK
    PA6     ------> I2S1_SDI
    PC4     ------> I2S1_MCK
    PA15     ------> I2S1_WS
    */
    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* I2S1 DMA Init */
    /* SPI1_RX Init */
    hdma_spi1_rx.Instance = DMA1_Stream0;
    hdma_spi1_rx.Init.Request = DMA_REQUEST_SPI1_RX;
    hdma_spi1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_spi1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_spi1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_spi1_rx.Init.Mode = DMA_CIRCULAR;
    hdma_spi1_rx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_spi1_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_spi1_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(i2sHandle,hdmarx,hdma_spi1_rx);

    /* I2S1 interrupt Init */
    HAL_NVIC_SetPriority(SPI1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(SPI1_IRQn);
  /* USER CODE BEGIN SPI1_MspInit 1 */

  /* USER CODE END SPI1_MspInit 1 */
  }
  else if(i2sHandle->Instance==SPI2)
  {
  /* USER CODE BEGIN SPI2_MspInit 0 */

  /* USER CODE END SPI2_MspInit 0 */
    /* I2S2 clock enable */
    __HAL_RCC_SPI2_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**I2S2 GPIO Configuration
    PC1     ------> I2S2_SDO
    PB12     ------> I2S2_WS
    PB13     ------> I2S2_CK
    PC6     ------> I2S2_MCK
    */
    GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* I2S2 DMA Init */
    /* SPI2_TX Init */
    hdma_spi2_tx.Instance = DMA1_Stream1;
    hdma_spi2_tx.Init.Request = DMA_REQUEST_SPI2_TX;
    hdma_spi2_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_spi2_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi2_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi2_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_spi2_tx.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_spi2_tx.Init.Mode = DMA_CIRCULAR;
    hdma_spi2_tx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_spi2_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_spi2_tx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(i2sHandle,hdmatx,hdma_spi2_tx);

    /* I2S2 interrupt Init */
    HAL_NVIC_SetPriority(SPI2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(SPI2_IRQn);
  /* USER CODE BEGIN SPI2_MspInit 1 */

  /* USER CODE END SPI2_MspInit 1 */
  }
}

void HAL_I2S_MspDeInit(I2S_HandleTypeDef* i2sHandle)
{

  if(i2sHandle->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspDeInit 0 */

  /* USER CODE END SPI1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SPI1_CLK_DISABLE();

    /**I2S1 GPIO Configuration
    PA5     ------> I2S1_CK
    PA6     ------> I2S1_SDI
    PC4     ------> I2S1_MCK
    PA15     ------> I2S1_WS
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_15);

    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_4);

    /* I2S1 DMA DeInit */
    HAL_DMA_DeInit(i2sHandle->hdmarx);

    /* I2S1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(SPI1_IRQn);
  /* USER CODE BEGIN SPI1_MspDeInit 1 */

  /* USER CODE END SPI1_MspDeInit 1 */
  }
  else if(i2sHandle->Instance==SPI2)
  {
  /* USER CODE BEGIN SPI2_MspDeInit 0 */

  /* USER CODE END SPI2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SPI2_CLK_DISABLE();

    /**I2S2 GPIO Configuration
    PC1     ------> I2S2_SDO
    PB12     ------> I2S2_WS
    PB13     ------> I2S2_CK
    PC6     ------> I2S2_MCK
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_1|GPIO_PIN_6);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_12|GPIO_PIN_13);

    /* I2S2 DMA DeInit */
    HAL_DMA_DeInit(i2sHandle->hdmatx);

    /* I2S2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(SPI2_IRQn);
  /* USER CODE BEGIN SPI2_MspDeInit 1 */

  /* USER CODE END SPI2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
void changeFreq(I2S_HandleTypeDef *hi2s, unsigned long freq) {
	hi2s->Init.AudioFreq = freq;
	uint32_t i2sdiv;
	  uint32_t i2sodd;
	  uint32_t packetlength;
	  uint32_t tmp;
	  uint32_t i2sclk;
	  uint32_t ispcm;
	if (IS_I2S_MASTER(hi2s->Init.Mode))
	  {
		/*------------------------- I2SDIV and ODD Calculation ---------------------*/
		/* If the requested audio frequency is not the default, compute the prescaler */
		if (hi2s->Init.AudioFreq != I2S_AUDIOFREQ_DEFAULT)
		{
		  /* Check the frame length (For the Prescaler computing) ********************/
		  if (hi2s->Init.DataFormat != I2S_DATAFORMAT_16B)
		  {
			/* Channel length is 32 bits */
			packetlength = 2UL;
		  }
		  else
		  {
			/* Channel length is 16 bits */
			packetlength = 1UL;
		  }

		  /* Check if PCM standard is used */
		  if ((hi2s->Init.Standard == I2S_STANDARD_PCM_SHORT) ||
			  (hi2s->Init.Standard == I2S_STANDARD_PCM_LONG))
		  {
			ispcm = 1UL;
		  }
		  else
		  {
			ispcm = 0UL;
		  }

		  /* Get the source clock value: based on System Clock value */
	#if defined (SPI_SPI6I2S_SUPPORT)
		  if (hi2s->Instance == SPI6)
		  {
			/* SPI6 source clock */
			i2sclk = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_SPI6);
		  }
		  else
		  {
			/* SPI1,SPI2 and SPI3 share the same source clock */
			i2sclk = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_SPI123);
		  }
	#else
		  /* SPI1,SPI2 and SPI3 share the same source clock */
		  i2sclk = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_SPI123);
	#endif  /* SPI_SPI6I2S_SUPPORT */

		  /* Compute the Real divider depending on the MCLK output state, with a floating point */
		  if (hi2s->Init.MCLKOutput == I2S_MCLKOUTPUT_ENABLE)
		  {
			/* MCLK output is enabled */
			tmp = (uint32_t)((((i2sclk / (256UL >> ispcm)) * 10UL) / hi2s->Init.AudioFreq) + 5UL);
		  }
		  else
		  {
			/* MCLK output is disabled */
			tmp = (uint32_t)((((i2sclk / ((32UL >> ispcm) * packetlength)) * 10UL) / hi2s->Init.AudioFreq) + 5UL);
		  }

		  /* Remove the flatting point */
		  tmp = tmp / 10UL;

		  /* Check the parity of the divider */
		  i2sodd = (uint32_t)(tmp & (uint32_t)1UL);

		  /* Compute the i2sdiv prescaler */
		  i2sdiv = (uint32_t)((tmp - i2sodd) / 2UL);
		}
		else
		{
		  /* Set the default values */
		  i2sdiv = 2UL;
		  i2sodd = 0UL;
		}

		/* Test if the obtain values are forbidden or out of range */
		if (((i2sodd == 1UL) && (i2sdiv == 1UL)) || (i2sdiv > 0xFFUL))
		{
		  /* Set the error code */
		  SET_BIT(hi2s->ErrorCode, HAL_I2S_ERROR_PRESCALER);
		  return  HAL_ERROR;
		}

		/* Force i2smod to 1 just to be sure that (2xi2sdiv + i2sodd) is always higher than 0 */
		if (i2sdiv == 0UL)
		{
		  i2sodd = 1UL;
		}

		MODIFY_REG(hi2s->Instance->I2SCFGR, (SPI_I2SCFGR_I2SDIV                 | SPI_I2SCFGR_ODD),
				   ((i2sdiv << SPI_I2SCFGR_I2SDIV_Pos) | (i2sodd << SPI_I2SCFGR_ODD_Pos)));
	  }
}
/* USER CODE END 1 */
