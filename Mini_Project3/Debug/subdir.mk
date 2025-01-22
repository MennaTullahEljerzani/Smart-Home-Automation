################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../buzzer.c \
../dc_motor.c \
../flame_sensor.c \
../gpio.c \
../lcd.c \
../ldr.c \
../led.c \
../pwm.c \
../smart_home.c \
../temperature_sensor.c 

OBJS += \
./adc.o \
./buzzer.o \
./dc_motor.o \
./flame_sensor.o \
./gpio.o \
./lcd.o \
./ldr.o \
./led.o \
./pwm.o \
./smart_home.o \
./temperature_sensor.o 

C_DEPS += \
./adc.d \
./buzzer.d \
./dc_motor.d \
./flame_sensor.d \
./gpio.d \
./lcd.d \
./ldr.d \
./led.d \
./pwm.d \
./smart_home.d \
./temperature_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


