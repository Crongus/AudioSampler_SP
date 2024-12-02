#include <string.h>
#include <stdio.h>
#include "stm32l476xx.h"
#include "SysClock.h"
#include "I2C.h"
#include "ssd1306.h"
#include "ssd1306_tests.h"
#include "keypad.c"

// Note: The code gets Warning L6989W
// Report: this is an known issue for STM32L4xx.
// https://www.keil.com/support/docs/3853.htm
// We can ignore this warning because we are not using
// external memory.

uint8_t Data_Receive[6];
uint8_t Data_Send[6];
void I2C_GPIO_init(void);
	
int main(void){
	
	// Variables
	int length = 12;
	volatile int i;
	int j;
	int count = 0;
	unsigned char key;
	unsigned char len = 0;
	unsigned char temp;
	char str[length];

	// Innitializing
	System_Clock_Init(); // Switch System Clock = 80 MHz
	I2C_GPIO_init();
	I2C_Initialization(I2C1);
  ssd1306_Init();
	Keypad_Pin_Init();
	
	// infinite while loop
	while(1) {
		for(i=0; i<100000; i++); // delay
		key = keypad_scan();
		// '*' input will backspace
			if (key == '*' && len > 0) {
			len --;
			str[len] = 0;
		} else if(key != 0xff) {
			if(len < length-1){
				// adds the key press to the buffer that is then displayed
				str[len] = key;
				str[len + 1] = 0;
				len++; 
			} else {
				for(i = length-1; i >=0 ; i--) {
					str[i] = str[i-1];
				}
				str[0] = key;
			}
		}
		
		// updade the screen
		ssd1306_Fill(White);
		ssd1306_SetCursor(2,0);
		ssd1306_WriteString(str, Font_11x18, Black);
		ssd1306_UpdateScreen();
		count++;		
	}

	while(1);	 // Deadloop
}

unsigned char keypad_scan() {
	
	// key_map maps the actual inputs to what the keys are on the keypad
	unsigned char key_map [4][4] = {
		{'1','2','3','A'},
		{'4','5','6','B'},
		{'7','8','9','C'},
		{'*','0','#','D'}
	};
	unsigned char row, col, ColumnPressed;
	ColumnPressed = 0;
	unsigned char key = 0xFF;
	int i;
	uint32_t inputMask, outputMask = 0;
	
	// the pins for the rows and cols are in these 2 arrays
	int rows[] = {0, 1, 2, 3};
	int cols[] = {4, 10, 11, 12};
	
	// innitialize the 2 masks
	for(col = 0; col < 4; col++)
		inputMask |= 1UL << cols[col];
	
	for(row = 0; row < 4; row++)
		outputMask |= 1UL << rows[row];
	
	
	// Check whether any key has been pressed
	// 1.) Output zeros on all row pins
	// 2.) Delay shortly, and read inputs of column pins
	// 3.) if inputs are 1 for all columns, then no key has been pressed
	
	GPIOC->ODR &= ~outputMask; // clear row bits
	for(i=0; i<100000; i++);
	
	// return FF when there is no button pressed
	if ((GPIOC->IDR & inputMask) == inputMask)
		return 0xFF;
	
	// identify the column of the key pressed
	for(col = 0; col < 4; col++) {
		if((GPIOC->IDR & (1<<cols[col])) == 0)
			ColumnPressed = col;
	}
	
	// identify the row of the column pressed
	for(row = 0; row < 4; row++) {
		// Set up the row outputs
		GPIOC->ODR |= outputMask;
		GPIOC->ODR &= ~(1<<rows[row]);           
		for(i=0; i<10000; i++); // delay
		if((GPIOC->IDR & (1<<cols[ColumnPressed])) == 0) {
			key = key_map[row][ColumnPressed];
		}
	}
	for(i=0; i<100000; i++); // delay to allow for keys held down to repeat
	return key;
}