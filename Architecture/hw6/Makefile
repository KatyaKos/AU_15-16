LD ?= ld
CC ?= gcc

CFLAGS = -ffreestanding -m32
AFLAGS = -ffreestanding -m32

all: mbr

OBJS = hello.o

mbr: $(OBJS) linker.ld
	$(LD) -T linker.ld $(OBJS) -o mbr

%.o: %.S
	$(CC) $(AFLAGS) -c $< -o $@

clean:
	rm *.o mbr

.PHONY: clean
