################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/Fonts.c \
../Application/User/SSD1331.c \
../Application/User/STM_MY_LCD16X2.c \
D:/Eclipse/Projects/PCinfo/Src/main.c \
D:/Eclipse/Projects/PCinfo/Src/stm32f4xx_hal_msp.c \
D:/Eclipse/Projects/PCinfo/Src/stm32f4xx_it.c 

OBJS += \
./Application/User/Fonts.o \
./Application/User/SSD1331.o \
./Application/User/STM_MY_LCD16X2.o \
./Application/User/main.o \
./Application/User/stm32f4xx_hal_msp.o \
./Application/User/stm32f4xx_it.o 

C_DEPS += \
./Application/User/Fonts.d \
./Application/User/SSD1331.d \
./Application/User/STM_MY_LCD16X2.d \
./Application/User/main.d \
./Application/User/stm32f4xx_hal_msp.d \
./Application/User/stm32f4xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/%.o: ../Application/User/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"D:/Eclipse/Projects/PCinfo/Inc" -I"D:/Eclipse/Projects/PCinfo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/Eclipse/Projects/PCinfo/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"D:/Eclipse/Projects/PCinfo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/Eclipse/Projects/PCinfo/Drivers/CMSIS/Include" -I"D:/Eclipse/Projects/PCinfo/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/main.o: D:/Eclipse/Projects/PCinfo/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"D:/Eclipse/Projects/PCinfo/Inc" -I"D:/Eclipse/Projects/PCinfo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/Eclipse/Projects/PCinfo/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"D:/Eclipse/Projects/PCinfo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/Eclipse/Projects/PCinfo/Drivers/CMSIS/Include" -I"D:/Eclipse/Projects/PCinfo/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f4xx_hal_msp.o: D:/Eclipse/Projects/PCinfo/Src/stm32f4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"D:/Eclipse/Projects/PCinfo/Inc" -I"D:/Eclipse/Projects/PCinfo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/Eclipse/Projects/PCinfo/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"D:/Eclipse/Projects/PCinfo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/Eclipse/Projects/PCinfo/Drivers/CMSIS/Include" -I"D:/Eclipse/Projects/PCinfo/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f4xx_it.o: D:/Eclipse/Projects/PCinfo/Src/stm32f4xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"D:/Eclipse/Projects/PCinfo/Inc" -I"D:/Eclipse/Projects/PCinfo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/Eclipse/Projects/PCinfo/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"D:/Eclipse/Projects/PCinfo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/Eclipse/Projects/PCinfo/Drivers/CMSIS/Include" -I"D:/Eclipse/Projects/PCinfo/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


