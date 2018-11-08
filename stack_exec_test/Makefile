CC=gcc
CFLAGS=-g3 -O0 -mcpu=arm1176jzf-s -march=armv6zk
NOEXEC_FLAG=-z noexecstack
EXEC_FLAG=-z execstack

all: stack_exec.elf hello_map.elf stack_noexec.elf hello_map_noexec.elf

stack_exec.elf: stack_exec.c ret1.S
	$(CC) $(CFLAGS) $(EXEC_FLAG) $^ -o $@

hello_map.elf: hello_map.c
	$(CC) $(CFLAGS) $^ -o $@

stack_noexec.elf: stack_exec.c ret1.S
	$(CC) $(CFLAGS) $(NOEXEC_FLAG) $^ -o $@

hello_map_noexec.elf: hello_map.c
	$(CC) $(CFLAGS) $(NOEXEC_FLAG) $^ -o $@

clean:
	rm -f *.elf
