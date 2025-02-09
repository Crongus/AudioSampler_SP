/*
 * keypad.h
 *
 *  Created on: Dec 4, 2024
 *      Author: Isaac Terrell
 */

#ifndef _KEYPAD_H_
#define _KEYPAD_H_

//GPIOPIN and GPIOBANK defines need to be adjusted to correspond w the GPIO pins being used.
//The keypad.c program assumes that the necessary GPIOs have already been properly initialized.
//For keypad use set ROW pins mode OUTPUT and speed VERY HIGH.
//Set COLUMN pins mode INPUT and rest state PULL-UP.
#define R1GPIOBANK GPIOB
#define R2GPIOBANK GPIOG
#define R3GPIOBANK GPIOE
#define R4GPIOBANK GPIOE

#define C1GPIOBANK GPIOC
#define C2GPIOBANK GPIOC
#define C3GPIOBANK GPIOB
#define C4GPIOBANK GPIOC
#define C5GPIOBANK GPIOF

#define R1GPIOPIN GPIO_PIN_6
#define R2GPIOPIN GPIO_PIN_14
#define R3GPIOPIN GPIO_PIN_13
#define R4GPIOPIN GPIO_PIN_14

#define C1GPIOPIN GPIO_PIN_0
#define C2GPIOPIN GPIO_PIN_3
#define C3GPIOPIN GPIO_PIN_1
#define C4GPIOPIN GPIO_PIN_2
#define C5GPIOPIN GPIO_PIN_11

int GetKey(void);
//This function is intended to be passed into after a keypad press was detected.
//Returns an int 1-20 identifying keypad button pressed (top left = 1, read left to right)
//Returns -1 on error, failure, or inconclusive

//Functions used internally to the keypad program.
int ReadOneColPin(int);
//Pass the col# you want (zero indexed), returns current logic state.
void DriveOneRowPin(int, int);
//Pass the row# you want to drive (zero indexed) and the logic state you want in that order.
void DriveAllRowPins(int);
//Pass the logic state you want.


#endif /* _KEYPAD_H_ */
