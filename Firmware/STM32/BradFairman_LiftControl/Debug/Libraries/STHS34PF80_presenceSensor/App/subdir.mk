################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Libraries/STHS34PF80_presenceSensor/App/Presence_sensor.cpp 

OBJS += \
./Libraries/STHS34PF80_presenceSensor/App/Presence_sensor.o 

CPP_DEPS += \
./Libraries/STHS34PF80_presenceSensor/App/Presence_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/STHS34PF80_presenceSensor/App/%.o Libraries/STHS34PF80_presenceSensor/App/%.su Libraries/STHS34PF80_presenceSensor/App/%.cyclo: ../Libraries/STHS34PF80_presenceSensor/App/%.cpp Libraries/STHS34PF80_presenceSensor/App/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0plus -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/mainApp/includes" -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/Libraries" -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/Libraries/DRV8873_motorDriver" -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/Libraries/DRV8873_motorDriver/App" -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/Libraries/STHS34PF80_presenceSensor/App" -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/Libraries/STHS34PF80_presenceSensor/Driver" -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/Libraries/VL53L4CD_tofSensor/App" -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/Libraries/VL53L4CD_tofSensor/Driver" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libraries-2f-STHS34PF80_presenceSensor-2f-App

clean-Libraries-2f-STHS34PF80_presenceSensor-2f-App:
	-$(RM) ./Libraries/STHS34PF80_presenceSensor/App/Presence_sensor.cyclo ./Libraries/STHS34PF80_presenceSensor/App/Presence_sensor.d ./Libraries/STHS34PF80_presenceSensor/App/Presence_sensor.o ./Libraries/STHS34PF80_presenceSensor/App/Presence_sensor.su

.PHONY: clean-Libraries-2f-STHS34PF80_presenceSensor-2f-App

