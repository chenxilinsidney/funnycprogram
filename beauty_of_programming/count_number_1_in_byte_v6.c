/**
 * @file count_number_1_in_byte_v1.c
 * @brief count the number 1 in binary form of a byte(8 bits).
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-28
 */

#include <stdlib.h>
#include <stdio.h>

typedef unsigned int TYPE;
TYPE N = 234;

TYPE count_number_1_in_byte(TYPE n)
{
    TYPE m1 = 010101010101;
    n = (n & m1) +
        ((n >> 1) & m1) +
        ((n >> 2) & m1) +
        ((n >> 3) & m1) +
        ((n >> 4) & m1) +
        ((n >> 5) & m1);
    return n % 63;
}

int main(void)
{
    TYPE sum = 0;
    sum = count_number_1_in_byte(N);
    printf("sum of number 1 in %d is %d.\n", N, sum);
    return EXIT_SUCCESS;
}
