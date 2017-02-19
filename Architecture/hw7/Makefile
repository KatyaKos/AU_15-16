LD ?= ld
CC ?= gcc

CFLAGS = -ffreestanding -m32
AFLAGS = -ffreestanding -m32

all: info

OBJS = boot.o kernel.o

info: $(OBJS) linker.ld
	$(LD) -z max-page-size=0x1000 -T linker.ld $(OBJS) -o info

%.o: %.S
	$(CC) $(AFLAGS) -c $< -o $@

kernel.o : kernel.c
	$(CC) $(CFLAGS) -std=c99 -Wall -nostdlib -c kernel.c -o kernel.o

clean:
	rm -rf *.o info

.PHONY: clean
