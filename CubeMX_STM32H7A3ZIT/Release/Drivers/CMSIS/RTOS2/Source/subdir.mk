################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/RTOS2/Source/os_systick.c \
../Drivers/CMSIS/RTOS2/Source/os_tick_gtim.c \
../Drivers/CMSIS/RTOS2/Source/os_tick_ptim.c 

OBJS += \
./Drivers/CMSIS/RTOS2/Source/os_systick.o \
./Drivers/CMSIS/RTOS2/Source/os_tick_gtim.o \
./Drivers/CMSIS/RTOS2/Source/os_tick_ptim.o 

C_DEPS += \
./Drivers/CMSIS/RTOS2/Source/os_systick.d \
./Drivers/CMSIS/RTOS2/Source/os_tick_gtim.d \
./Drivers/CMSIS/RTOS2/Source/os_tick_ptim.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/RTOS2/Source/%.o Drivers/CMSIS/RTOS2/Source/%.su Drivers/CMSIS/RTOS2/Source/%.cyclo: ../Drivers/CMSIS/RTOS2/Source/%.c Drivers/CMSIS/RTOS2/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7A3xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../../Include -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32MX_DevBoard/Drivers/CMSIS/RTOS2/Include" -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32MX_DevBoard/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM7_SP" -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32MX_DevBoard/Drivers/CMSIS/Core_A/Include" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-RTOS2-2f-Source

clean-Drivers-2f-CMSIS-2f-RTOS2-2f-Source:
	-$(RM) ./Drivers/CMSIS/RTOS2/Source/os_systick.cyclo ./Drivers/CMSIS/RTOS2/Source/os_systick.d ./Drivers/CMSIS/RTOS2/Source/os_systick.o ./Drivers/CMSIS/RTOS2/Source/os_systick.su ./Drivers/CMSIS/RTOS2/Source/os_tick_gtim.cyclo ./Drivers/CMSIS/RTOS2/Source/os_tick_gtim.d ./Drivers/CMSIS/RTOS2/Source/os_tick_gtim.o ./Drivers/CMSIS/RTOS2/Source/os_tick_gtim.su ./Drivers/CMSIS/RTOS2/Source/os_tick_ptim.cyclo ./Drivers/CMSIS/RTOS2/Source/os_tick_ptim.d ./Drivers/CMSIS/RTOS2/Source/os_tick_ptim.o ./Drivers/CMSIS/RTOS2/Source/os_tick_ptim.su

.PHONY: clean-Drivers-2f-CMSIS-2f-RTOS2-2f-Source
