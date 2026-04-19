################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/app_freertos.c \
../Src/app_queues.c \
../Src/comms_task.c \
../Src/daq_task.c \
../Src/health_task.c \
../Src/main.c \
../Src/processing_task.c \
../Src/stm32h5xx_hal_msp.c \
../Src/stm32h5xx_hal_timebase_tim.c \
../Src/stm32h5xx_it.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32h5xx.c 

OBJS += \
./Src/app_freertos.o \
./Src/app_queues.o \
./Src/comms_task.o \
./Src/daq_task.o \
./Src/health_task.o \
./Src/main.o \
./Src/processing_task.o \
./Src/stm32h5xx_hal_msp.o \
./Src/stm32h5xx_hal_timebase_tim.o \
./Src/stm32h5xx_it.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32h5xx.o 

C_DEPS += \
./Src/app_freertos.d \
./Src/app_queues.d \
./Src/comms_task.d \
./Src/daq_task.d \
./Src/health_task.d \
./Src/main.d \
./Src/processing_task.d \
./Src/stm32h5xx_hal_msp.d \
./Src/stm32h5xx_hal_timebase_tim.d \
./Src/stm32h5xx_it.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32h5xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_144 -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32H5xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/app_freertos.cyclo ./Src/app_freertos.d ./Src/app_freertos.o ./Src/app_freertos.su ./Src/app_queues.cyclo ./Src/app_queues.d ./Src/app_queues.o ./Src/app_queues.su ./Src/comms_task.cyclo ./Src/comms_task.d ./Src/comms_task.o ./Src/comms_task.su ./Src/daq_task.cyclo ./Src/daq_task.d ./Src/daq_task.o ./Src/daq_task.su ./Src/health_task.cyclo ./Src/health_task.d ./Src/health_task.o ./Src/health_task.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/processing_task.cyclo ./Src/processing_task.d ./Src/processing_task.o ./Src/processing_task.su ./Src/stm32h5xx_hal_msp.cyclo ./Src/stm32h5xx_hal_msp.d ./Src/stm32h5xx_hal_msp.o ./Src/stm32h5xx_hal_msp.su ./Src/stm32h5xx_hal_timebase_tim.cyclo ./Src/stm32h5xx_hal_timebase_tim.d ./Src/stm32h5xx_hal_timebase_tim.o ./Src/stm32h5xx_hal_timebase_tim.su ./Src/stm32h5xx_it.cyclo ./Src/stm32h5xx_it.d ./Src/stm32h5xx_it.o ./Src/stm32h5xx_it.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/system_stm32h5xx.cyclo ./Src/system_stm32h5xx.d ./Src/system_stm32h5xx.o ./Src/system_stm32h5xx.su

.PHONY: clean-Src

