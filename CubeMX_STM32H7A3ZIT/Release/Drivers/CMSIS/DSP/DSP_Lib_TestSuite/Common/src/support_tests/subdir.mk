################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/copy_tests.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/fill_tests.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_common_data.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_group.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/x_to_y_tests.c 

OBJS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/copy_tests.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/fill_tests.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_common_data.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_group.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/x_to_y_tests.o 

C_DEPS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/copy_tests.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/fill_tests.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_common_data.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_group.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/x_to_y_tests.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/%.o Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/%.su Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/%.cyclo: ../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/%.c Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7A3xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../../Include -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32MX_DevBoard/Drivers/CMSIS/RTOS2/Include" -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32MX_DevBoard/Drivers/CMSIS/NN/NN_Lib_Tests/nn_test/RTE/_ARMCM7_SP" -I"C:/Users/l42li/Documents/AudioSampler_SP/CubeMX_STM32MX_DevBoard/Drivers/CMSIS/Core_A/Include" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-Common-2f-src-2f-support_tests

clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-Common-2f-src-2f-support_tests:
	-$(RM) ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/copy_tests.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/copy_tests.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/copy_tests.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/copy_tests.su ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/fill_tests.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/fill_tests.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/fill_tests.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/fill_tests.su ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_common_data.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_common_data.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_common_data.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_common_data.su ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_group.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_group.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_group.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_group.su ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/x_to_y_tests.cyclo ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/x_to_y_tests.d ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/x_to_y_tests.o ./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/x_to_y_tests.su

.PHONY: clean-Drivers-2f-CMSIS-2f-DSP-2f-DSP_Lib_TestSuite-2f-Common-2f-src-2f-support_tests
