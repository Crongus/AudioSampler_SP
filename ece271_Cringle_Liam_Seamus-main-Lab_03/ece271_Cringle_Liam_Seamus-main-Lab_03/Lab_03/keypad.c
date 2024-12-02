#include "stm32l476xx.h"
#include "SysClock.h"
#include "keypad.h"

void Keypad_Pin_Init() {
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN; // enable c port clock
	
	// set pins 12, 11, 10, and 4 to input, and 3-0 to output
	GPIOC->MODER &= ~(0x03F003FF);
	GPIOC->MODER |= 0x00000055;
	
	// make all output types open drain to prevent chip frying
	GPIOC->OTYPER |= (1UL<<3);
	GPIOC->OTYPER |= (1UL<<2);
	GPIOC->OTYPER |= (1UL<<1);
	GPIOC->OTYPER |= (1UL<<0);

	// set all pins to no pull up - no pull down
	GPIOC->PUPDR  &= ~(0x03F003FF);
}