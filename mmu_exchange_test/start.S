    .align 4
    .global _start
_start:
    @ disable all interrupt
    cpsid aif, #0x1f
    @ set initial stack
    ldr sp, =__svc_stack_top
    
    @ clear BSS
    @ r1: BSS start address
    @ r2: BSS end address
    @ r3: 0
    ldr r1, =__bss_start
    ldr r2, =__bss_end
    movs r3, #0
.loop:
    @ finish if r1 == r2
    cmp r1, r2
    bpl .loopend
    @ write 0 to memory
    str r3, [r1], #4
    @ jump to clear_bss
    b .loop
.loopend:
    bl main
fin:
    wfi
    b fin

