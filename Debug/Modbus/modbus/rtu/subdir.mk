################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus/modbus/rtu/mbcrc.c \
../Modbus/modbus/rtu/mbrtu.c 

OBJS += \
./Modbus/modbus/rtu/mbcrc.o \
./Modbus/modbus/rtu/mbrtu.o 

C_DEPS += \
./Modbus/modbus/rtu/mbcrc.d \
./Modbus/modbus/rtu/mbrtu.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus/modbus/rtu/%.o Modbus/modbus/rtu/%.su Modbus/modbus/rtu/%.cyclo: ../Modbus/modbus/rtu/%.c Modbus/modbus/rtu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"D:/UC-80_offical/Modbus" -I"D:/UC-80_offical/Modbus/modbus/ascii" -I"D:/UC-80_offical/Modbus/modbus/functions" -I"D:/UC-80_offical/Modbus/modbus/include" -I"D:/UC-80_offical/Modbus/modbus/rtu" -I"D:/UC-80_offical/Modbus/port" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Modbus-2f-modbus-2f-rtu

clean-Modbus-2f-modbus-2f-rtu:
	-$(RM) ./Modbus/modbus/rtu/mbcrc.cyclo ./Modbus/modbus/rtu/mbcrc.d ./Modbus/modbus/rtu/mbcrc.o ./Modbus/modbus/rtu/mbcrc.su ./Modbus/modbus/rtu/mbrtu.cyclo ./Modbus/modbus/rtu/mbrtu.d ./Modbus/modbus/rtu/mbrtu.o ./Modbus/modbus/rtu/mbrtu.su

.PHONY: clean-Modbus-2f-modbus-2f-rtu

