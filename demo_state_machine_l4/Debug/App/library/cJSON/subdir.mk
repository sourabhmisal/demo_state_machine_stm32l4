################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/library/cJSON/cJSON.c \
../App/library/cJSON/cJSON_Utils.c 

OBJS += \
./App/library/cJSON/cJSON.o \
./App/library/cJSON/cJSON_Utils.o 

C_DEPS += \
./App/library/cJSON/cJSON.d \
./App/library/cJSON/cJSON_Utils.d 


# Each subdirectory must supply rules for building sources it contributes
App/library/cJSON/%.o App/library/cJSON/%.su: ../App/library/cJSON/%.c App/library/cJSON/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"/home/sourabh-misal/STM32CubeIDE/workspace_1.11.0_/demo_state_machine_l4/App" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-library-2f-cJSON

clean-App-2f-library-2f-cJSON:
	-$(RM) ./App/library/cJSON/cJSON.d ./App/library/cJSON/cJSON.o ./App/library/cJSON/cJSON.su ./App/library/cJSON/cJSON_Utils.d ./App/library/cJSON/cJSON_Utils.o ./App/library/cJSON/cJSON_Utils.su

.PHONY: clean-App-2f-library-2f-cJSON

