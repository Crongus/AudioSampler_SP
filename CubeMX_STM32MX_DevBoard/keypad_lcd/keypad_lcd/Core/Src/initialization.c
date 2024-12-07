/*
 * initialization.c
 *
 *  Created on: Dec 6, 2024
 *      Author: Isaac Terrell
 */

/*
 * The DIX9211 I2C slave address is 1000 000 (0x40)
 * (last two bits are user configurable but we tied them).
 * Write a register address then the bits you want in there.
 * We write the setting that turns on Standalone DIT mode
 * and then the defaults for that mode are all fine for
 * our purposes.
 * A way to read from registers is defined but we should not
 * need that except for debugging purposes.
 */
void DIX9211_Init(I2C_HandleTypeDef Dix9211Handle) {
	/*
	 * TI says that reg address and write data are expected as
	 * 8 bit MSB first. I have no idea whether the HAL driver
	 * does LSB or MSB. Reversing buffer bit order is something
	 * to try if function does not seem to work
	 *
	 * For standalone DIT set Reg 6F = DDDD D101 (D=don't care)
	 * We can preserve the default values in first 5 bits (0100 0)
	 */
	uint8_t buffer[2] = {0x6F, 0x45};
	//Eight bit words
	//Reg = 6F
	//Write data = 0100 0101 = 0x45
	HAL_I2C_Master_Transmit(&Dix9211Handle, 0x40, &buffer, 2, 1000);
}
