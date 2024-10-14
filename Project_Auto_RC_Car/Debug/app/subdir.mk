################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/Control_RC_Car.c \
../app/HC_SR04.c \
../app/ap.c \
../app/delay_us.c \
../app/motor.c 

OBJS += \
./app/Control_RC_Car.o \
./app/HC_SR04.o \
./app/ap.o \
./app/delay_us.o \
./app/motor.o 

C_DEPS += \
./app/Control_RC_Car.d \
./app/HC_SR04.d \
./app/ap.d \
./app/delay_us.d \
./app/motor.d 


# Each subdirectory must supply rules for building sources it contributes
app/%.o app/%.su app/%.cyclo: ../app/%.c app/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/DATA/SOC_workspace/stm32/Project_Auto_RC_Car/app" -I"C:/DATA/SOC_workspace/stm32/Project_Auto_RC_Car/app/common" -I"C:/DATA/SOC_workspace/stm32/Project_Auto_RC_Car/app/hw" -I"C:/DATA/SOC_workspace/stm32/Project_Auto_RC_Car/app/hw/driver" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-app

clean-app:
	-$(RM) ./app/Control_RC_Car.cyclo ./app/Control_RC_Car.d ./app/Control_RC_Car.o ./app/Control_RC_Car.su ./app/HC_SR04.cyclo ./app/HC_SR04.d ./app/HC_SR04.o ./app/HC_SR04.su ./app/ap.cyclo ./app/ap.d ./app/ap.o ./app/ap.su ./app/delay_us.cyclo ./app/delay_us.d ./app/delay_us.o ./app/delay_us.su ./app/motor.cyclo ./app/motor.d ./app/motor.o ./app/motor.su

.PHONY: clean-app

