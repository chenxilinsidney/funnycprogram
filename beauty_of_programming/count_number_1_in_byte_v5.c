/**
 * @file count_number_1_in_byte_v1.c
 * @brief count the number 1 in binary form of a byte(8 bits).
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-28
 */

#include <stdlib.h>
#include <stdio.h>

typedef unsigned char TYPE;
TYPE N = 234;

TYPE count_number_1_in_byte(TYPE n)
{
    n = (n & 0x55) + ((n >> 1) & 0x55);
    n = (n & 0x33) + ((n >> 2) & 0x33);
    n = (n & 0x0f) + ((n >> 4) & 0x0f);
    return n;
}

int main(void)
{
    TYPE sum = 0;
    sum = count_number_1_in_byte(N);
    printf("sum of number 1 in %d is %d.\n", N, sum);
    return EXIT_SUCCESS;
}
