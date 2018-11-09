#pragma once



#ifdef TARGET_QEMU
    // versatilepb
    #include "arm_pl011.h"

    // memmap
    #define UART ((PL011_Type *)0x101f1000)

    // config
    #define UART_CLOCK (24000000 * 3UL) // QEMU set apb-pclk to 24MHz(x3 PLL?)
    #define STDIO UART

#elif TARGET_RASPBERRYPI_ONE
#endif

