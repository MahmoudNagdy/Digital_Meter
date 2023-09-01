################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/WDT/subdir.mk
-include MCAL/UART/subdir.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/Switch_Driver/subdir.mk
-include MCAL/LCD_DIO/subdir.mk
-include MCAL/ICU/subdir.mk
-include MCAL/Global_Interrupt/Debug/subdir.mk
-include MCAL/Global_Interrupt/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/Stepper/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include HAL/DC_MOTOR/subdir.mk
-include HAL/7Segment/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
digitMeter.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: digitMeter.elf secondary-outputs

# Tool invocations
digitMeter.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,digitMeter.map -mmcu=atmega32 -o "digitMeter.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

digitMeter.lss: digitMeter.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S digitMeter.elf  >"digitMeter.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: digitMeter.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 digitMeter.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) digitMeter.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
