################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/startup_ARMCM7.s 

C_SRCS += \
../Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/startup_ARMCM7.c \
../Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/system_ARMCM7.c 

OBJS += \
./Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/startup_ARMCM7.o \
./Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/system_ARMCM7.o 

S_DEPS += \
./Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/startup_ARMCM7.d 

C_DEPS += \
./Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/startup_ARMCM7.d \
./Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/system_ARMCM7.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/%.o Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/%.su Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/%.cyclo: ../Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/%.c Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7A3xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../../Include -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32MX_DevBoard/Drivers/CMSIS/RTOS2/Include" -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32MX_DevBoard/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM7_SP" -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32MX_DevBoard/Drivers/CMSIS/Core_A/Include" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/%.o: ../Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/%.s Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Drivers-2f-CMSIS-2f-NN-2f-Examples-2f-ARM-2f-arm_nn_examples-2f-cifar10-2f-RTE-2f-Device-2f-ARMCM7_SP

clean-Drivers-2f-CMSIS-2f-NN-2f-Examples-2f-ARM-2f-arm_nn_examples-2f-cifar10-2f-RTE-2f-Device-2f-ARMCM7_SP:
	-$(RM) ./Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/startup_ARMCM7.cyclo ./Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/startup_ARMCM7.d ./Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/startup_ARMCM7.o ./Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/startup_ARMCM7.su ./Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/system_ARMCM7.cyclo ./Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/system_ARMCM7.d ./Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/system_ARMCM7.o ./Drivers/CMSIS/NN/Examples/ARM/arm_nn_examples/cifar10/RTE/Device/ARMCM7_SP/system_ARMCM7.su

.PHONY: clean-Drivers-2f-CMSIS-2f-NN-2f-Examples-2f-ARM-2f-arm_nn_examples-2f-cifar10-2f-RTE-2f-Device-2f-ARMCM7_SP
