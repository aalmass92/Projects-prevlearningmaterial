#CC=arm-none-eabi-gcc
# LD=arm-none-eabi-ld

CC=${HOME}/ti/ccsv7/tools/compiler/gcc-arm-none-eabi-4_9-2015q3/bin/arm-none-eabi-gcc

%.o: %.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Compiler'
	$(CC) -c -mcpu=cortex-a8 -mtune=cortex-a8 -march=armv7-a -marm -Dam3359 -I"${HOME}/ti/ccsv7/tools/compiler/gcc-arm-none-eabi-4_9-2015q3/arm-none-eabi/include" -I"${HOME}/AM335X_StarterWare_02_00_01_01/include/hw" -I"${HOME}/AM335X_StarterWare_02_00_01_01/include" -I"${HOME}/AM335X_StarterWare_02_00_01_01/include/armv7a/am335x" -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o"$@" "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' 'p




all: blinky

startup_ARMCA8.o: startup_ARMCA8.S

blinky:        gpio.o gpioLEDBlink.o gpio_v2.o startup_ARMCA8.o
	$(CC)  -mtune=cortex-a8 -marm -Dam3359 -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -mcpu=cortex-a8 -Wl,-Map,"blinky.map" -Wl,--defsym,STACKSIZE=0x400 -Wl,--defsym,HEAPSIZE=0x400 -Wl,-T"AM335x.lds" -o blinky gpio.o gpioLEDBlink.o gpio_v2.o startup_ARMCA8.o
	arm-none-eabi-objcopy -O binary blinky blinky.bin

clean:
	rm *.o *~ *.d *.map *.bin
