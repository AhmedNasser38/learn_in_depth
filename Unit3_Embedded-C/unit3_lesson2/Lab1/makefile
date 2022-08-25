#@Copyright  : Ahmed_Nasser
#cross tool chain
CC=arm-none-eabi-
#contain debug and targetName cortex-m4
CFLAGS=-g -mcpu=arm926ej-s
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
proj_name=learn-in-depth


all: $(proj_name).bin
	@echo "******************Build is done**********************"

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS)  $(INCS) $< -o $@

$(proj_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(ASOBJ) $(OBJ) -o $@ -Map=Map_file.map

$(proj_name).bin: $(proj_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.o