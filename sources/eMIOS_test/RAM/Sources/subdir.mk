################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/ADCsetup.c" \
"../Sources/Exceptions.c" \
"../Sources/InitModesClocks.c" \
"../Sources/IntcInterrupts.c" \
"../Sources/PortInit.c" \
"../Sources/eMIOSetup.c" \
"../Sources/ivor_branch_table.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/ADCsetup.c \
../Sources/Exceptions.c \
../Sources/InitModesClocks.c \
../Sources/IntcInterrupts.c \
../Sources/PortInit.c \
../Sources/eMIOSetup.c \
../Sources/ivor_branch_table.c \
../Sources/main.c \

OBJS += \
./Sources/ADCsetup_c.obj \
./Sources/Exceptions_c.obj \
./Sources/InitModesClocks_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/PortInit_c.obj \
./Sources/eMIOSetup_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/ADCsetup_c.obj" \
"./Sources/Exceptions_c.obj" \
"./Sources/InitModesClocks_c.obj" \
"./Sources/IntcInterrupts_c.obj" \
"./Sources/PortInit_c.obj" \
"./Sources/eMIOSetup_c.obj" \
"./Sources/ivor_branch_table_c.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/ADCsetup_c.d \
./Sources/Exceptions_c.d \
./Sources/InitModesClocks_c.d \
./Sources/IntcInterrupts_c.d \
./Sources/PortInit_c.d \
./Sources/eMIOSetup_c.d \
./Sources/ivor_branch_table_c.d \
./Sources/main_c.d \

OBJS_OS_FORMAT += \
./Sources/ADCsetup_c.obj \
./Sources/Exceptions_c.obj \
./Sources/InitModesClocks_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/PortInit_c.obj \
./Sources/eMIOSetup_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/main_c.obj \

C_DEPS_QUOTED += \
"./Sources/ADCsetup_c.d" \
"./Sources/Exceptions_c.d" \
"./Sources/InitModesClocks_c.d" \
"./Sources/IntcInterrupts_c.d" \
"./Sources/PortInit_c.d" \
"./Sources/eMIOSetup_c.d" \
"./Sources/ivor_branch_table_c.d" \
"./Sources/main_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/ADCsetup_c.obj: ../Sources/ADCsetup.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/ADCsetup.args" -o "Sources/ADCsetup_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Exceptions_c.obj: ../Sources/Exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Exceptions.args" -o "Sources/Exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/InitModesClocks_c.obj: ../Sources/InitModesClocks.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/InitModesClocks.args" -o "Sources/InitModesClocks_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/IntcInterrupts_c.obj: ../Sources/IntcInterrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/IntcInterrupts.args" -o "Sources/IntcInterrupts_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/PortInit_c.obj: ../Sources/PortInit.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/PortInit.args" -o "Sources/PortInit_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/eMIOSetup_c.obj: ../Sources/eMIOSetup.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/eMIOSetup.args" -o "Sources/eMIOSetup_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/ivor_branch_table_c.obj: ../Sources/ivor_branch_table.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/ivor_branch_table.args" -o "Sources/ivor_branch_table_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


