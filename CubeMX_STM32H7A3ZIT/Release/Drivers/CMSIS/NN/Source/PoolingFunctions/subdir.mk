################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/NN/Source/PoolingFunctions/arm_pool_q7_HWC.c 

OBJS += \
./Drivers/CMSIS/NN/Source/PoolingFunctions/arm_pool_q7_HWC.o 

C_DEPS += \
./Drivers/CMSIS/NN/Source/PoolingFunctions/arm_pool_q7_HWC.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/NN/Source/PoolingFunctions/%.o Drivers/CMSIS/NN/Source/PoolingFunctions/%.su Drivers/CMSIS/NN/Source/PoolingFunctions/%.cyclo: ../Drivers/CMSIS/NN/Source/PoolingFunctions/%.c Drivers/CMSIS/NN/Source/PoolingFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7A3xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../../Include -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32MX_DevBoard/Drivers/CMSIS/RTOS2/Include" -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32MX_DevBoard/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM7_SP" -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32MX_DevBoard/Drivers/CMSIS/Core_A/Include" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-NN-2f-Source-2f-PoolingFunctions

clean-Drivers-2f-CMSIS-2f-NN-2f-Source-2f-PoolingFunctions:
	-$(RM) ./Drivers/CMSIS/NN/Source/PoolingFunctions/arm_pool_q7_HWC.cyclo ./Drivers/CMSIS/NN/Source/PoolingFunctions/arm_pool_q7_HWC.d ./Drivers/CMSIS/NN/Source/PoolingFunctions/arm_pool_q7_HWC.o ./Drivers/CMSIS/NN/Source/PoolingFunctions/arm_pool_q7_HWC.su

.PHONY: clean-Drivers-2f-CMSIS-2f-NN-2f-Source-2f-PoolingFunctions

