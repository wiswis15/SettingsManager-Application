################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CommandFactory.cpp \
../src/CommandIface.cpp \
../src/DataBaseManagerIface.cpp \
../src/DeleteCommand.cpp \
../src/FileDataBaseManager.cpp \
../src/GetCommand.cpp \
../src/SetCommand.cpp \
../src/SettingsManager.cpp \
../src/SettingsManagerIface.cpp \
../src/main.cpp 

OBJS += \
./src/CommandFactory.o \
./src/CommandIface.o \
./src/DataBaseManagerIface.o \
./src/DeleteCommand.o \
./src/FileDataBaseManager.o \
./src/GetCommand.o \
./src/SetCommand.o \
./src/SettingsManager.o \
./src/SettingsManagerIface.o \
./src/main.o 

CPP_DEPS += \
./src/CommandFactory.d \
./src/CommandIface.d \
./src/DataBaseManagerIface.d \
./src/DeleteCommand.d \
./src/FileDataBaseManager.d \
./src/GetCommand.d \
./src/SetCommand.d \
./src/SettingsManager.d \
./src/SettingsManagerIface.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/wissem/eclipse-workspace/KVPStorage/headerFiles" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


