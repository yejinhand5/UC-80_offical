################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus/port/portevent.c \
../Modbus/port/portserial.c \
../Modbus/port/porttimer.c 

OBJS += \
./Modbus/port/portevent.o \
./Modbus/port/portserial.o \
./Modbus/port/porttimer.o 

C_DEPS += \
./Modbus/port/portevent.d \
./Modbus/port/portserial.d \
./Modbus/port/porttimer.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus/port/%.o Modbus/port/%.su Modbus/port/%.cyclo: ../Modbus/port/%.c Modbus/port/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"D:/UC-80_offical/Modbus" -I"D:/UC-80_offical/Modbus/modbus/ascii" -I"D:/UC-80_offical/Modbus/modbus/functions" -I"D:/UC-80_offical/Modbus/modbus/include" -I"D:/UC-80_offical/Modbus/modbus/rtu" -I"D:/UC-80_offical/Modbus/port" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Modbus-2f-port

clean-Modbus-2f-port:
	-$(RM) ./Modbus/port/portevent.cyclo ./Modbus/port/portevent.d ./Modbus/port/portevent.o ./Modbus/port/portevent.su ./Modbus/port/portserial.cyclo ./Modbus/port/portserial.d ./Modbus/port/portserial.o ./Modbus/port/portserial.su ./Modbus/port/porttimer.cyclo ./Modbus/port/porttimer.d ./Modbus/port/porttimer.o ./Modbus/port/porttimer.su

.PHONY: clean-Modbus-2f-port

