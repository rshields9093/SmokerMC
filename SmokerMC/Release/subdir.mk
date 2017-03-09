################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
INO_SRCS += \
../ArduinoWebClient.ino \
../BBQ.ino \
../SmokerMC.ino \
../Steinhart-Hart_Temp.ino \
../TempProbe_BetaOnlyMethod.ino \
../WiFi_Test_Code_1.ino \
../WiFi_Test_Code_2.ino 

CPP_SRCS += \
../.ino.cpp \
../GenericThermistor.cpp 

LINK_OBJ += \
./.ino.cpp.o \
./GenericThermistor.cpp.o 

INO_DEPS += \
.\ArduinoWebClient.ino.d \
.\BBQ.ino.d \
.\SmokerMC.ino.d \
.\Steinhart-Hart_Temp.ino.d \
.\TempProbe_BetaOnlyMethod.ino.d \
.\WiFi_Test_Code_1.ino.d \
.\WiFi_Test_Code_2.ino.d 

CPP_DEPS += \
.\.ino.cpp.d \
.\GenericThermistor.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
.ino.cpp.o: ../.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\variants\standard" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial\src" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

ArduinoWebClient.o: ../ArduinoWebClient.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\variants\standard" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial\src" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

BBQ.o: ../BBQ.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\variants\standard" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial\src" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

GenericThermistor.cpp.o: ../GenericThermistor.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\variants\standard" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial\src" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

SmokerMC.o: ../SmokerMC.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\variants\standard" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial\src" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Steinhart-Hart_Temp.o: ../Steinhart-Hart_Temp.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\variants\standard" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial\src" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

TempProbe_BetaOnlyMethod.o: ../TempProbe_BetaOnlyMethod.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\variants\standard" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial\src" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

WiFi_Test_Code_1.o: ../WiFi_Test_Code_1.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\variants\standard" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial\src" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

WiFi_Test_Code_2.o: ../WiFi_Test_Code_2.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\variants\standard" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial\src" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


