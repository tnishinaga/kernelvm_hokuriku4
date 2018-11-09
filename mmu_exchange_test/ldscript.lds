OUTPUT_ARCH(arm)
ENTRY(_start)
SECTIONS
{
	. = 0x00010000;
	
	.start : { start.o(.text) }

	.text : { *(.text*) }
	. = ALIGN(4);

	__rodata_start = .;
	.rodata : { *(.rodata*) }
	. = ALIGN(4);
	__rodata_end = .;

	__data_start = . ;
	.data : { *(.data*) }
	. = ALIGN(4);
	__data_end = . ;

	__bss_start = . ;
	.bss : { *(.bss*) }
	. = ALIGN(4);
	__bss_end = . ;

	. = ALIGN(4096);
	__free_start = .;

	. = . + 0x00400000; /* 8MiB of stack space */
	__interrupt_sp = .;

	. = . + 0x00400000; /* 8MiB of stack space */
	__svc_stack_top = .;
}
