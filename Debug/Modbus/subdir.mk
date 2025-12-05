################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus/portrw.c 

OBJS += \
./Modbus/portrw.o 

C_DEPS += \
./Modbus/portrw.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus/%.o Modbus/%.su Modbus/%.cyclo: ../Modbus/%.c Modbus/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/16197/Downloads/MyProject/LED_pd/LED_PD/Modbus" -I"C:/Users/16197/Downloads/MyProject/LED_pd/LED_PD/Modbus/modbus" -I"C:/Users/16197/Downloads/MyProject/LED_pd/LED_PD/Modbus/modbus/functions" -I"C:/Users/16197/Downloads/MyProject/LED_pd/LED_PD/Modbus/modbus/include" -I"C:/Users/16197/Downloads/MyProject/LED_pd/LED_PD/Modbus/modbus/rtu" -I"C:/Users/16197/Downloads/MyProject/LED_pd/LED_PD/Modbus/port" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Modbus

clean-Modbus:
	-$(RM) ./Modbus/portrw.cyclo ./Modbus/portrw.d ./Modbus/portrw.o ./Modbus/portrw.su

.PHONY: clean-Modbus

