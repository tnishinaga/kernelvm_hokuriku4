#pragma once

#include <stdint.h>

#include "memmap.h"

void my_puts(PL011_Type *serial, char *s);
void hexdump32(PL011_Type *stdio, uint32_t hex);
