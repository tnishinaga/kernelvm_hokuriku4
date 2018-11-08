	.global ret1
	.align 4
ret1:
	mov r0, #1
	bx lr
	.global ret1_fin
ret1_fin:
	nop
