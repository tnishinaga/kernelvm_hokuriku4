#include <stdint.h>

#include "misc.h"
#include "memmap.h"

#define BUF_MAX 128

void my_puts(PL011_Type *serial, char *s)
{
    for (int i = 0; i < BUF_MAX; i++) {
        pl011_putc(*s, serial);
        s++;
        if (*s == '\0') {
            break;
        }
    }
}


void hexdump32(PL011_Type *stdio, uint32_t hex)
{
    char hexascii[] = "0123456789abcdef";
    for (uint32_t i = 1; i <= sizeof(hex) * 2; i++) {
        uint32_t idx = (hex >> (8 * sizeof(hex) - 4 * i)) & 0xf;
        pl011_putc(hexascii[idx], stdio);
    }
    pl011_putc('\n', stdio);
}
