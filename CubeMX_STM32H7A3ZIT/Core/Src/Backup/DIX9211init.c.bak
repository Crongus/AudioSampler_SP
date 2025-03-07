/*
 * DIX9211init.c
 *
 *  Created on: Dec 18, 2024
 *      Author: l42li
 */
#include "DIX9211init.h"
int DIX9211init(void) {

	extern I2C_HandleTypeDef hi2c1;
	int configData = 0x45;
	int y = 0;
	uint8_t* regData = &y;
	int ret = 57;
	if(HAL_I2C_IsDeviceReady(&hi2c1, (0x40 << 1), 20, 1000) == HAL_OK) {
		ret = HAL_I2C_Mem_Write(&hi2c1, (0x40 << 1), FUNCTION_ASN_REG_ADDR, I2C_MEMADD_SIZE_8BIT, (uint8_t*) &configData, 1, 1000);
	} else {
		*(int*)(0x20CDCDCD) = 12; // hardfault
	}
	if(HAL_I2C_IsDeviceReady(&hi2c1, (0x40 << 1), 20, 1000) == HAL_OK) {
		ret = HAL_I2C_Mem_Read(&hi2c1, (0x40 << 1), FUNCTION_ASN_REG_ADDR, I2C_MEMADD_SIZE_8BIT, (uint8_t*) regData, 1, 1000);
	} else {
		*(int*)(0x20CDCDCD) = 12; // hardfault
	}
	return *regData;


}
