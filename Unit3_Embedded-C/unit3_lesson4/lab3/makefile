#@Copyright  : Ahmed_Nasser
#cross tool chain
CC=arm-none-eabi-
#contain debug and targetName
CFLAGS=-gdwarf-2 -mcpu=cortex-m4 -g
#include files .>dirctor
INCS=-I .
#includes libaries (in linker stage)
LIBS=
#automated file.c to file.o
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
#automated file.s(assembly) to file.o
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
#project name
proj_name=lab4_cotrexM4


all: $(proj_name).bin
	@echo "******************Build is done**********************"

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	# first line when deal with cortexM3/M4
	#export PATH=/c/ST/STM32CubeIDE_1.4.0/STM32CubeIDE/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.7-2018-q2-update.win32_1.4.0.202007081208/tools/bin:$PATH
	$(CC)gcc.exe -c $(CFLAGS)  $(INCS) $< -o $@

$(proj_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ)  -o $@ -Map=Map_file.map
	cp $(proj_name).elf $(proj_name).axf

$(proj_name).bin: $(proj_name).elf
	$(CC)objcopy.exe -O binary $< $@

$(proj_name).hex: $(proj_name).elf
	$(CC)objcopy.exe -O binary $< $@	

clean_all:
	rm *.o *.elf *.bin *.map

clean:
	rm *.elf *.o
