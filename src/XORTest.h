#pragma once

#include "Main.h"

int testXORValue = 1;

void XORTest()
{
    while (1) {
        testXORValue = testXORValue ^ 1;
        printf("%d\n", testXORValue);
    }
}

