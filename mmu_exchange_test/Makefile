CROSS=arm-none-eabi-
TARGET=TARGET_QEMU

CC=$(CROSS)gcc
LD=$(CROSS)ld
OBJCOPY=$(CROSS)objcopy

CFLAGS= -mfloat-abi=soft -mlittle-endian
CFLAGS+= -nostartfiles
CFLAGS+= -ffreestanding
CFLAGS+= -O2 -g3
CFLAGS+= -marm -march=armv6kz

LIBGCC = $(shell $(CC) -print-libgcc-file-name)

STARTUP=start.o
OBJS=main.o mmu.o misc.o vector.o interrupt.o drivers/arm_pl011.o

INC=-I./drivers/ -I.
CFLAGS+=$(INC)

# set target
CFLAGS+=-D$(TARGET)

all: kernel.img

.SUFFIXES: .elf .img

kernel.elf:	$(STARTUP) $(OBJS)
	$(LD) -static -nostartfiles -T ldscript.lds $^ $(LIBGCC) -o $@

.elf.img:
	$(OBJCOPY) -O binary $< $@
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
.S.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean::
	$(RM) -f *.o *.img *.elf */*.o */*/*.o 
	$(RM) -f tags *~

tags::
	ctags *.[chS]
