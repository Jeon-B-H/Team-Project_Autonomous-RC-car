################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/hw/driver/led.c 

OBJS += \
./app/hw/driver/led.o 

C_DEPS += \
./app/hw/driver/led.d 


# Each subdirectory must supply rules for building sources it contributes
app/hw/driver/%.o app/hw/driver/%.su app/hw/driver/%.cyclo: ../app/hw/driver/%.c app/hw/driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/DATA/SOC_workspace/stm32/Project_Auto_RC_Car/app" -I"C:/DATA/SOC_workspace/stm32/Project_Auto_RC_Car/app/common" -I"C:/DATA/SOC_workspace/stm32/Project_Auto_RC_Car/app/hw" -I"C:/DATA/SOC_workspace/stm32/Project_Auto_RC_Car/app/hw/driver" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-app-2f-hw-2f-driver

clean-app-2f-hw-2f-driver:
	-$(RM) ./app/hw/driver/led.cyclo ./app/hw/driver/led.d ./app/hw/driver/led.o ./app/hw/driver/led.su

.PHONY: clean-app-2f-hw-2f-driver

