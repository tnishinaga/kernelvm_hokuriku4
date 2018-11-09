	.global  __vector_start
__vector_start:
	ldr	pc, _vec_Reset
	ldr	pc, _vec_Undef
	ldr	pc, _vec_SWI
	ldr	pc, _vec_PrefAbort
	ldr	pc, _vec_DataAbort
	ldr	pc, _vec_Reserved
	ldr	pc, _vec_IRQ
	ldr	pc, _vec_FIQ
_vec_Reset:		.word	_start
_vec_Undef:		.word	_Undef_interrupt
_vec_SWI:		.word	_SWI_interrupt
_vec_PrefAbort:	.word	_PrefAbort_interrupt
_vec_DataAbort:	.word	_DataAbort_interrupt
_vec_Reserved:	.word	_Reserved_interrupt
_vec_IRQ:		.word	_IRQ_interrupt
_vec_FIQ:		.word	_FIQ_interrupt
	
	.global __vector_end
__vector_end:
	nop

@ handlers
_Undef_interrupt:
	ldr sp, =__interrupt_sp
	bl C_Undef_interrupt

_SWI_interrupt:
	ldr sp, =__interrupt_sp
	bl C_SWI_interrupt

_PrefAbort_interrupt:
	ldr sp, =__interrupt_sp
	bl C_PrefAbort_interrupt

_DataAbort_interrupt:
	ldr sp, =__interrupt_sp
	bl C_DataAbort_interrupt

_Reserved_interrupt:
	ldr sp, =__interrupt_sp
	bl C_Reserved_interrupt

_IRQ_interrupt:
	ldr sp, =__interrupt_sp
	bl C_IRQ_interrupt

_FIQ_interrupt:
	ldr sp, =__interrupt_sp
	bl C_FIQ_interrupt

