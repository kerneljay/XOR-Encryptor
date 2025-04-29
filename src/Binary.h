#pragma once
#include "Main.h"

void print_binary(unsigned int value, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%c", (value & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}
