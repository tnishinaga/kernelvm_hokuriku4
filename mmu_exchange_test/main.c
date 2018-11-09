#include <stdint.h>
#include "drivers/memmap.h"
#include "mmu.h"
#include "interrupt.h"

void show_5_6(void)
{
    uint32_t *addr_0x00500000 = (uint32_t *)0x00500000;
	uint32_t *addr_0x00600000 = (uint32_t *)0x00600000;
	
    my_puts(STDIO, "0x00500000 = ");
	hexdump32(STDIO, *addr_0x00500000);
	my_puts(STDIO, "0x00600000 = ");
	hexdump32(STDIO, *addr_0x00600000);
}

int main(void)
{
    set_vector_table(0);

    pl011_init(STDIO, UART_CLOCK);


    extern uint32_t *ttbr0_lv1_section;
    uint32_t *addr_0x00500000 = (uint32_t *)0x00500000;
	uint32_t *addr_0x00600000 = (uint32_t *)0x00600000;
	*addr_0x00500000 = 0x00500000;
	*addr_0x00600000 = 0x00600000;

	my_puts(STDIO, "MMU disabled:\n");
    show_5_6();

    my_puts(STDIO, "\n");
	my_puts(STDIO, "Create straight section\n");
	create_straight_section();

    my_puts(STDIO, "\n");
	my_puts(STDIO, "Exchange entry 5 with 6\n");
	uint32_t tmp = ttbr0_lv1_section[5];
	ttbr0_lv1_section[5] = ttbr0_lv1_section[6];
	ttbr0_lv1_section[6] = tmp;

    init_mmu();

    my_puts(STDIO, "\n");
    my_puts(STDIO, "MMU enabled:\n");
    show_5_6();

    return 0;
}