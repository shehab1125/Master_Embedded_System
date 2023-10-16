################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/ECU/Motor/ecu_motor.c 

OBJS += \
./Drivers/ECU/Motor/ecu_motor.o 

C_DEPS += \
./Drivers/ECU/Motor/ecu_motor.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ECU/Motor/%.o Drivers/ECU/Motor/%.su Drivers/ECU/Motor/%.cyclo: ../Drivers/ECU/Motor/%.c Drivers/ECU/Motor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-ECU-2f-Motor

clean-Drivers-2f-ECU-2f-Motor:
	-$(RM) ./Drivers/ECU/Motor/ecu_motor.cyclo ./Drivers/ECU/Motor/ecu_motor.d ./Drivers/ECU/Motor/ecu_motor.o ./Drivers/ECU/Motor/ecu_motor.su

.PHONY: clean-Drivers-2f-ECU-2f-Motor

