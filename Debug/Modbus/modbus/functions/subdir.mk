################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Modbus/modbus/functions/mbfunccoils.c \
../Modbus/modbus/functions/mbfuncdiag.c \
../Modbus/modbus/functions/mbfuncdisc.c \
../Modbus/modbus/functions/mbfuncholding.c \
../Modbus/modbus/functions/mbfuncinput.c \
../Modbus/modbus/functions/mbfuncother.c \
../Modbus/modbus/functions/mbutils.c 

OBJS += \
./Modbus/modbus/functions/mbfunccoils.o \
./Modbus/modbus/functions/mbfuncdiag.o \
./Modbus/modbus/functions/mbfuncdisc.o \
./Modbus/modbus/functions/mbfuncholding.o \
./Modbus/modbus/functions/mbfuncinput.o \
./Modbus/modbus/functions/mbfuncother.o \
./Modbus/modbus/functions/mbutils.o 

C_DEPS += \
./Modbus/modbus/functions/mbfunccoils.d \
./Modbus/modbus/functions/mbfuncdiag.d \
./Modbus/modbus/functions/mbfuncdisc.d \
./Modbus/modbus/functions/mbfuncholding.d \
./Modbus/modbus/functions/mbfuncinput.d \
./Modbus/modbus/functions/mbfuncother.d \
./Modbus/modbus/functions/mbutils.d 


# Each subdirectory must supply rules for building sources it contributes
Modbus/modbus/functions/%.o Modbus/modbus/functions/%.su Modbus/modbus/functions/%.cyclo: ../Modbus/modbus/functions/%.c Modbus/modbus/functions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/16197/Downloads/MyProject/LED_pd/LED_PD/Modbus" -I"C:/Users/16197/Downloads/MyProject/LED_pd/LED_PD/Modbus/modbus" -I"C:/Users/16197/Downloads/MyProject/LED_pd/LED_PD/Modbus/modbus/functions" -I"C:/Users/16197/Downloads/MyProject/LED_pd/LED_PD/Modbus/modbus/include" -I"C:/Users/16197/Downloads/MyProject/LED_pd/LED_PD/Modbus/modbus/rtu" -I"C:/Users/16197/Downloads/MyProject/LED_pd/LED_PD/Modbus/port" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Modbus-2f-modbus-2f-functions

clean-Modbus-2f-modbus-2f-functions:
	-$(RM) ./Modbus/modbus/functions/mbfunccoils.cyclo ./Modbus/modbus/functions/mbfunccoils.d ./Modbus/modbus/functions/mbfunccoils.o ./Modbus/modbus/functions/mbfunccoils.su ./Modbus/modbus/functions/mbfuncdiag.cyclo ./Modbus/modbus/functions/mbfuncdiag.d ./Modbus/modbus/functions/mbfuncdiag.o ./Modbus/modbus/functions/mbfuncdiag.su ./Modbus/modbus/functions/mbfuncdisc.cyclo ./Modbus/modbus/functions/mbfuncdisc.d ./Modbus/modbus/functions/mbfuncdisc.o ./Modbus/modbus/functions/mbfuncdisc.su ./Modbus/modbus/functions/mbfuncholding.cyclo ./Modbus/modbus/functions/mbfuncholding.d ./Modbus/modbus/functions/mbfuncholding.o ./Modbus/modbus/functions/mbfuncholding.su ./Modbus/modbus/functions/mbfuncinput.cyclo ./Modbus/modbus/functions/mbfuncinput.d ./Modbus/modbus/functions/mbfuncinput.o ./Modbus/modbus/functions/mbfuncinput.su ./Modbus/modbus/functions/mbfuncother.cyclo ./Modbus/modbus/functions/mbfuncother.d ./Modbus/modbus/functions/mbfuncother.o ./Modbus/modbus/functions/mbfuncother.su ./Modbus/modbus/functions/mbutils.cyclo ./Modbus/modbus/functions/mbutils.d ./Modbus/modbus/functions/mbutils.o ./Modbus/modbus/functions/mbutils.su

.PHONY: clean-Modbus-2f-modbus-2f-functions

