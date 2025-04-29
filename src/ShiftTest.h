#pragma once
#include "Main.h"
#include "Binary.h"

unsigned int value = 0x12345678;  // Some 32-bit value

void ShiftTestUndefinedBehavior()
{

    // Test shift with a negative operand (undefined behavior)
    printf("Shifting with a negative operand (undefined behavior):\n");
    printf("value << -1: %u\n", value << -1);

    // Test shift with an operand equal to the number of bits (32 for unsigned int on most systems)
    printf("\nShifting with operand equal to number of bits (32 bits):\n");
    printf("value << 32: %u\n", value << 32);

    // Test shift with an operand greater than the number of bits
    printf("\nShifting with operand greater than the number of bits (33):\n");
    printf("value << 33: %u\n", value << 33);
}

void ShiftTestRandom()
{
    // printf("Size of unsigned int: %zu bytes\n", sizeof(unsigned int)); // This is 4 bytes
    // printf("Bits in unsigned int: %zu\n", sizeof(unsigned int) * CHAR_BIT); // This is 32 bits

    printf("Random test: %u\n", value << 31); // left shift
}


void ShiftTestRandom2()
{
    unsigned char ch = 0b11100101;  // 229 in decimal
    signed char sch = (signed char)ch;

    printf("Original unsigned char (ch):\n");
    print_binary(ch, 8); // why is this 8?

    printf("\nRight shifting unsigned char ch by 1:\n");
    print_binary(ch >> 1, 8);  // Expected: 01110010

    printf("\nRight shifting unsigned char ch by 2:\n");
    print_binary(ch >> 2, 8);  // Expected: 00111001

    printf("\nOriginal signed char (sch):\n");
    print_binary((unsigned char)sch, 8);  // print as unsigned to see bit pattern

    printf("\nRight shifting signed char sch by 1:\n");
    print_binary((unsigned char)(sch >> 1), 8);  // Result may be arithmetic shift (11110010)

    printf("\nRight shifting signed char sch by 2:\n");
    print_binary((unsigned char)(sch >> 2), 8);  // Result may be arithmetic shift (11111001)

    // Note: Shift amounts >= 8 for char are undefined behavior — not included in this test
}

void DivideBitPatternBy2()
{
    int i = 14; // Bit pattern 00001110
    unsigned int j = i >> 1;
    printf("%u\n", j);
}

void ShiftRandomAssTestFromGeeksForGeeks()
{
    // 00000101 -- a bit pattern
    // 00001001 -- b bit pattern
    
    // a = 5 (00000101 in 8-bit binary), 
    // b = 9 (00001001 in 8-bit binary)
    unsigned int a = 5, b = 9;
    printf("a = %u, b = %u\n", a, b);

    // Bitwise AND operator &
    // The result is 00000001
    printf("a&b = %u\n", a & b);

    // Bitwise OR operator |
    // The result is 00001101
    printf("a|b = %u\n", a | b);

    // The result is 00001100
    printf("a^b = %u\n", a ^ b);

    // The result is 11111111111111111111111111111010
    // (assuming 32-bit unsigned int)
    // printf("~a = %u\n", a = ~a); // Learn truth tables first and other stuff before testing this

    // The result is 00010010
    printf("b<<1 = %u\n", b << 1);

    // The result is 00000100
    printf("b>>1 = %u\n", b >> 1);

}
