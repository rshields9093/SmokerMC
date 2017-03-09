################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/eclipse/arduinoPlugin/libraries/Ethernet/1.1.2/src/Dhcp.cpp \
C:/eclipse/arduinoPlugin/libraries/Ethernet/1.1.2/src/Dns.cpp \
C:/eclipse/arduinoPlugin/libraries/Ethernet/1.1.2/src/Ethernet.cpp \
C:/eclipse/arduinoPlugin/libraries/Ethernet/1.1.2/src/EthernetClient.cpp \
C:/eclipse/arduinoPlugin/libraries/Ethernet/1.1.2/src/EthernetServer.cpp \
C:/eclipse/arduinoPlugin/libraries/Ethernet/1.1.2/src/EthernetUdp.cpp 

LINK_OBJ += \
./libraries/Ethernet/src/Dhcp.cpp.o \
./libraries/Ethernet/src/Dns.cpp.o \
./libraries/Ethernet/src/Ethernet.cpp.o \
./libraries/Ethernet/src/EthernetClient.cpp.o \
./libraries/Ethernet/src/EthernetServer.cpp.o \
./libraries/Ethernet/src/EthernetUdp.cpp.o 

CPP_DEPS += \
.\libraries\Ethernet\src\Dhcp.cpp.d \
.\libraries\Ethernet\src\Dns.cpp.d \
.\libraries\Ethernet\src\Ethernet.cpp.d \
.\libraries\Ethernet\src\EthernetClient.cpp.d \
.\libraries\Ethernet\src\EthernetServer.cpp.d \
.\libraries\Ethernet\src\EthernetUdp.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/Ethernet/src/Dhcp.cpp.o: C:/eclipse/arduinoPlugin/libraries/Ethernet/1.1.2/src/Dhcp.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\variants\standard" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial\src" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/Ethernet/src/Dns.cpp.o: C:/eclipse/arduinoPlugin/libraries/Ethernet/1.1.2/src/Dns.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\variants\standard" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial\src" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/Ethernet/src/Ethernet.cpp.o: C:/eclipse/arduinoPlugin/libraries/Ethernet/1.1.2/src/Ethernet.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\variants\standard" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial\src" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/Ethernet/src/EthernetClient.cpp.o: C:/eclipse/arduinoPlugin/libraries/Ethernet/1.1.2/src/EthernetClient.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\variants\standard" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial\src" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/Ethernet/src/EthernetServer.cpp.o: C:/eclipse/arduinoPlugin/libraries/Ethernet/1.1.2/src/EthernetServer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\variants\standard" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial\src" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries/Ethernet/src/EthernetUdp.cpp.o: C:/eclipse/arduinoPlugin/libraries/Ethernet/1.1.2/src/EthernetUdp.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.3-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\cores\arduino" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\variants\standard" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SoftwareSerial\src" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI" -I"C:\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.17\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


