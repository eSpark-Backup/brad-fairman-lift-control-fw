################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/STHS34PF80_presenceSensor/Driver/sths34pf80_reg.c 

C_DEPS += \
./Libraries/STHS34PF80_presenceSensor/Driver/sths34pf80_reg.d 

OBJS += \
./Libraries/STHS34PF80_presenceSensor/Driver/sths34pf80_reg.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/STHS34PF80_presenceSensor/Driver/%.o Libraries/STHS34PF80_presenceSensor/Driver/%.su Libraries/STHS34PF80_presenceSensor/Driver/%.cyclo: ../Libraries/STHS34PF80_presenceSensor/Driver/%.c Libraries/STHS34PF80_presenceSensor/Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/mainApp/includes" -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/Libraries/DRV8873_motorDriver/App" -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/Libraries/STHS34PF80_presenceSensor/App" -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/Libraries/STHS34PF80_presenceSensor/Driver" -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/Libraries/VL53L4CD_tofSensor/App" -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/Libraries/VL53L4CD_tofSensor/Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libraries-2f-STHS34PF80_presenceSensor-2f-Driver

clean-Libraries-2f-STHS34PF80_presenceSensor-2f-Driver:
	-$(RM) ./Libraries/STHS34PF80_presenceSensor/Driver/sths34pf80_reg.cyclo ./Libraries/STHS34PF80_presenceSensor/Driver/sths34pf80_reg.d ./Libraries/STHS34PF80_presenceSensor/Driver/sths34pf80_reg.o ./Libraries/STHS34PF80_presenceSensor/Driver/sths34pf80_reg.su

.PHONY: clean-Libraries-2f-STHS34PF80_presenceSensor-2f-Driver

