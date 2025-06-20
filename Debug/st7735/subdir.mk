################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../st7735/fonts.c \
../st7735/st7735.c 

OBJS += \
./st7735/fonts.o \
./st7735/st7735.o 

C_DEPS += \
./st7735/fonts.d \
./st7735/st7735.d 


# Each subdirectory must supply rules for building sources it contributes
st7735/%.o st7735/%.su st7735/%.cyclo: ../st7735/%.c st7735/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -IC:/Users/alexn/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/alexn/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/alexn/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/alexn/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.2/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-st7735

clean-st7735:
	-$(RM) ./st7735/fonts.cyclo ./st7735/fonts.d ./st7735/fonts.o ./st7735/fonts.su ./st7735/st7735.cyclo ./st7735/st7735.d ./st7735/st7735.o ./st7735/st7735.su

.PHONY: clean-st7735

