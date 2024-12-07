################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/Device/ST/STM32H7xx/Source/Templates/system_stm32h7xx.c 

OBJS += \
./Drivers/CMSIS/Device/ST/STM32H7xx/Source/Templates/system_stm32h7xx.o 

C_DEPS += \
./Drivers/CMSIS/Device/ST/STM32H7xx/Source/Templates/system_stm32h7xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/Device/ST/STM32H7xx/Source/Templates/%.o Drivers/CMSIS/Device/ST/STM32H7xx/Source/Templates/%.su Drivers/CMSIS/Device/ST/STM32H7xx/Source/Templates/%.cyclo: ../Drivers/CMSIS/Device/ST/STM32H7xx/Source/Templates/%.c Drivers/CMSIS/Device/ST/STM32H7xx/Source/Templates/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_SDRAM -DSKIP_SYSCLK_INIT -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7A3xx -DUSE_PWR_LDO_SUPPLY -c -I../Core/Inc -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32MX_DevBoard/Drivers/CMSIS/RTOS2/Include" -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32MX_DevBoard/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM7_SP" -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32MX_DevBoard/Drivers/CMSIS/Core_A/Include" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32H7A3ZIT/USB_DEVICE/App" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-Device-2f-ST-2f-STM32H7xx-2f-Source-2f-Templates

clean-Drivers-2f-CMSIS-2f-Device-2f-ST-2f-STM32H7xx-2f-Source-2f-Templates:
	-$(RM) ./Drivers/CMSIS/Device/ST/STM32H7xx/Source/Templates/system_stm32h7xx.cyclo ./Drivers/CMSIS/Device/ST/STM32H7xx/Source/Templates/system_stm32h7xx.d ./Drivers/CMSIS/Device/ST/STM32H7xx/Source/Templates/system_stm32h7xx.o ./Drivers/CMSIS/Device/ST/STM32H7xx/Source/Templates/system_stm32h7xx.su

.PHONY: clean-Drivers-2f-CMSIS-2f-Device-2f-ST-2f-STM32H7xx-2f-Source-2f-Templates

