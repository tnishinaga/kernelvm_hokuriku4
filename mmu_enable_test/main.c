#include <stdint.h>
#include "drivers/memmap.h"
#include "mmu.h"
#include "interrupt.h"

int main(void)
{
    set_vector_table(0);

    pl011_init(STDIO, UART_CLOCK);

    my_puts(STDIO, "HelloWorld!\n");

    init_mmu();

    my_puts(STDIO, "Hello MMU World!\n");

    return 0;
}