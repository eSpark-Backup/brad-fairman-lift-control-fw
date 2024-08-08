################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/DRV8873/DRV8873.cpp 

OBJS += \
./Drivers/DRV8873/DRV8873.o 

CPP_DEPS += \
./Drivers/DRV8873/DRV8873.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/DRV8873/%.o Drivers/DRV8873/%.su Drivers/DRV8873/%.cyclo: ../Drivers/DRV8873/%.cpp Drivers/DRV8873/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0plus -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/mainApp/includes" -I"C:/Users/eSpark/Documents/GitHub/bradfairman-liftcontrol-fw/Firmware/STM32/BradFairman_LiftControl/Drivers/DRV8873" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-DRV8873

clean-Drivers-2f-DRV8873:
	-$(RM) ./Drivers/DRV8873/DRV8873.cyclo ./Drivers/DRV8873/DRV8873.d ./Drivers/DRV8873/DRV8873.o ./Drivers/DRV8873/DRV8873.su

.PHONY: clean-Drivers-2f-DRV8873

