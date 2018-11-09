#include <stdint.h>
#include "memmap.h"
#include "misc.h"
#include "interrupt.h"

void set_vector_table(uint32_t *base)
{
    extern void *__vector_start;
    extern void *__vector_end;
    uint32_t *start = (uint32_t *)&__vector_start;
    uint32_t *end = (uint32_t *)&__vector_end;

    for (uint32_t *addr = start; addr < end; addr++) {
        // copy to VECTOR_BASE
        *base = *addr;
        base++;
    }
}

void C_Undef_interrupt()
{
    my_puts(STDIO, "_Undef_interrupt\n");
    while(1) {
        __asm volatile ("wfi");
    }
    
}
void C_SWI_interrupt()
{
    my_puts(STDIO, "_SWI_interrupt\n");
    while(1) {
        __asm volatile ("wfi");
    }
    
}
void C_PrefAbort_interrupt()
{
    my_puts(STDIO, "_PrefAbort_interrupt\n");
    while(1) {
        __asm volatile ("wfi");
    }
    
}
void C_DataAbort_interrupt()
{
    my_puts(STDIO, "_DataAbort_interrupt\n");
    while(1) {
        __asm volatile ("wfi");
    }
    
}
void C_Reserved_interrupt()
{
    my_puts(STDIO, "_Reserved_interrupt\n");
    while(1) {
        __asm volatile ("wfi");
    }
    
}
void C_IRQ_interrupt()
{
    my_puts(STDIO, "_IRQ_interrupt\n");
    while(1) {
        __asm volatile ("wfi");
    }
    
}
void C_FIQ_interrupt()
{
    my_puts(STDIO, "_FIQ_interrupt\n");
    while(1) {
        __asm volatile ("wfi");
    }
    
}