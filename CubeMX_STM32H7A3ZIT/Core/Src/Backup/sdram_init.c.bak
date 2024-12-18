/*
 * sdram_init.c
 * Most code yanked from STM examples from cubeMX
 *  Created on: Dec 5, 2024
 *      Author: l42li
 */

/*
 * 1 Power On while CKE = L and DQM = H and input signals are "nop"
 * 2 start clock and be stable for 200 us
 * 3 bring CKE = H and DQM = H
 * 4 Precharge all banks
 * 5 Mode Register Set
 * 6 Min of 2 auto-refresh cycles
 *
 */
#include "sdram_init.h"

void SDRAM_Initialization_Sequence(SDRAM_HandleTypeDef *hsdram,
		FMC_SDRAM_CommandTypeDef *Command) {
	__IO uint32_t tmpmrd = 0;
	/* Step 2:  Configure a clock configuration enable command */
	Command->CommandMode = FMC_SDRAM_CMD_CLK_ENABLE;
	Command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
	Command->AutoRefreshNumber = 1;
	Command->ModeRegisterDefinition = 0;

	/* Send the command */
	HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);

	/* Step 3: Insert 200 us minimum delay */
	/* Inserted delay is equal to 1 ms due to systick time base unit (ms) */
	HAL_Delay(1);

	/* Step 4: Configure a PALL (precharge all) command */
	Command->CommandMode = FMC_SDRAM_CMD_PALL;
	Command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
	Command->AutoRefreshNumber = 1;
	Command->ModeRegisterDefinition = 0;

	/* Send the command */
	HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);

	/* Step 4: Configure a PALL (precharge all) command */
	Command->CommandMode = FMC_SDRAM_CMD_PALL;
	Command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
	Command->AutoRefreshNumber = 1;
	Command->ModeRegisterDefinition = 0;

	/* Send the command */
	HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);

	/* Step 5: Program the external memory mode register */
	tmpmrd = (uint32_t) SDRAM_MODEREG_BURST_LENGTH_1 |
	SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL |
	SDRAM_MODEREG_CAS_LATENCY_3 |
	SDRAM_MODEREG_OPERATING_MODE_STANDARD |
	SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;

	Command->CommandMode = FMC_SDRAM_CMD_LOAD_MODE;
	Command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
	Command->AutoRefreshNumber = 1;
	Command->ModeRegisterDefinition = tmpmrd;

	/* Send the command */
	HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);

	/* Step 6 : Configure a Auto-Refresh command */
	Command->CommandMode = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
	Command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
	Command->AutoRefreshNumber = 2;
	Command->ModeRegisterDefinition = 0;

	/* Send the command twice*/
	HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);
	//HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);

}

