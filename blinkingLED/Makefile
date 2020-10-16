
MCU=msp430f5529
INCLUDES=-I . -I /lib/

CC=msp430-gcc
SRC= main.c TIMERA0_program.c
CFLAGS= -mmcu=$(MCU) -g -Wall $(INCLUDE)

%.i :%.c
	$(CC) $< $(CFLAGS) -E -o $@

%.asm : %.i
	$(CC) $< $(CFLAGS) -S -o $@

%.o : %.c
	$(CC) $< $(CFLAGS) -o $@


.PHONY : build
build:
	$(CC) $(SRC) $(CFLAGS) -o main.o
