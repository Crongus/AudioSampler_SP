/*
 * keypad.c
 *
 *  Created on: Dec 4, 2024
 *      Author: Isaac Terrell using logic by Liam Cringle
 */

#include <keypad.h>
#include "main.h"
#include "stm32h7xx_hal.h"
#include <stdio.h>
#include "usbd_cdc_if.h"

/*
 * Returns an int 0-19. Read left to right with top left=0.
 * Returns -1 if no key was found (this will happen if called without any press detected,
 * or more commonly due to weak pull-up causing a phantom press detection upon key release).
 * This function has NO KEY ROLLOVER. Simultaneous presses should be considered undefined
 * behavior.
 * Note also that this function currently leaves row pins as it was using them when it
 * returns control. A desirable change might be to have it re-drive them LO so that the
 * press detection algorithm does not have to handle it.
 */
int GetKey() {
	uint16_t ColNum, RowNum, RowFudge;
	//Note that we expect row pins already LO when this function is passed into.
	for (ColNum = 0; ColNum < 5; ColNum++) {
		if (!ReadOneColPin(ColNum))
			break;
	} //Find the column that's currently LO and stop
	if (ColNum > 4)
		return -1; //If the col finding loop doesn't break out there was a problem
	for (RowNum = 0; RowNum < 4; RowNum++) {
		DriveAllRowPins(1);
		DriveOneRowPin(RowNum, 0);
		//Get the rows HI then go through driving LO to see which one hits.
		HAL_Delay(3);
		//for (int i = 0; i < 500000; i++); // Dummy loop for delay in interupt
		//Our STM32H7 is running at 280 MHz. 3 ms delay seems to be adequate.
		//This should be adjusted up if performance isn't satisfactory, though
		if (!ReadOneColPin(ColNum))
			break;
		//Find the row that gets the identified column LO when driven and stop
	}
	DriveAllRowPins(0);
	if (RowNum > 3)
		return -1; //Row finding loop didn't find anything
	RowFudge = RowNum * 5;

	return ColNum + RowFudge;
	//How this logic works:
	//ColNum = 0, RowNum = 1 is key#6. 0 + 1 + (1 * 5) = 6
	//ColNum = 3, RowNum = 2 is key#14. 3 + 1 + (2 * 5) = 14
}

int ReadOneColPin(int col) {
	//Mind that the col variable is zero-indexed
	//GPIOBANK and GPIOPIN constants are one-indexed
	switch (col) {
	case 0:
		return (HAL_GPIO_ReadPin(C1GPIOBANK, C1GPIOPIN));
		// need this for interrupt reasons
		//return (__HAL_GPIO_EXTI_GET_IT(C1GPIOPIN) != 0x00U);
		break;
	case 1:
		return (HAL_GPIO_ReadPin(C2GPIOBANK, C2GPIOPIN));
		//return (__HAL_GPIO_EXTI_GET_IT(C2GPIOPIN) != 0x00U);
		break;
	case 2:
		return (HAL_GPIO_ReadPin(C3GPIOBANK, C3GPIOPIN));
		//return (__HAL_GPIO_EXTI_GET_IT(C3GPIOPIN) != 0x00U);
		break;
	case 3:
		return (HAL_GPIO_ReadPin(C4GPIOBANK, C4GPIOPIN));
		//return (__HAL_GPIO_EXTI_GET_IT(C4GPIOPIN) != 0x00U);
		break;
	case 4:
		return (HAL_GPIO_ReadPin(C5GPIOBANK, C5GPIOPIN));
		//return (__HAL_GPIO_EXTI_GET_IT(C5GPIOPIN) != 0x00U);
		break;
	default:
		break;
	}
	return -1; //This will only happen if the passed col was out of bounds
}

void DriveOneRowPin(int row, int state) {
	//Be aware that "row" as passed is zero-indexed
	//GPIOBANK and GPIOPIN constants are one-indexed
	switch (row) {
	case 0:
		if (state) {
			HAL_GPIO_WritePin(R1GPIOBANK, R1GPIOPIN, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(R1GPIOBANK, R1GPIOPIN, GPIO_PIN_RESET);
		}
		break;
	case 1:
		if (state) {
			HAL_GPIO_WritePin(R2GPIOBANK, R2GPIOPIN, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(R2GPIOBANK, R2GPIOPIN, GPIO_PIN_RESET);
		}
		break;
	case 2:
		if (state) {
			HAL_GPIO_WritePin(R3GPIOBANK, R3GPIOPIN, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(R3GPIOBANK, R3GPIOPIN, GPIO_PIN_RESET);
		}
		break;
	case 3:
		if (state) {
			HAL_GPIO_WritePin(R4GPIOBANK, R4GPIOPIN, GPIO_PIN_SET);
		} else {
			HAL_GPIO_WritePin(R4GPIOBANK, R4GPIOPIN, GPIO_PIN_RESET);
		}
		break;
	default:
		break; //Row out of bounds -> function returns without doing anything
	}
	return;
}

void DriveAllRowPins(int state) {
	if (state) {
		HAL_GPIO_WritePin(R1GPIOBANK, R1GPIOPIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R2GPIOBANK, R2GPIOPIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R3GPIOBANK, R3GPIOPIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R4GPIOBANK, R4GPIOPIN, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(R1GPIOBANK, R1GPIOPIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(R2GPIOBANK, R2GPIOPIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(R3GPIOBANK, R3GPIOPIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(R4GPIOBANK, R4GPIOPIN, GPIO_PIN_RESET);
	}
	return;
}

void interruptTest(void) {
	uint8_t string[50];
	int x = GetKey();
	int size = sprintf((char* restrict) string, "Key = %d\r\n", x);
	CDC_Transmit_HS(string, size);
}
