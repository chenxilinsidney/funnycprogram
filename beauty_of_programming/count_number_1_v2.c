/**
 * @file count_number_1_v2.c
 * @brief count the number 1 for all number less than N.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-28
 */

#include <stdlib.h>
#include <stdio.h>

typedef long long TYPE;
TYPE N = 1000000000;

TYPE main(void)
{
    TYPE i;
    TYPE sum = 0;
    TYPE bits = 1;
    TYPE high_bit_value = 0;
    TYPE current_bit_value = 0;
    TYPE low_bit_value = 0;
    while(bits < N) {
        high_bit_value = N / (10 * bits);
        // current_bit_value = (N % (10 * bits)) / bits;
        // low_bit_value = (N % (10 * bits)) % bits;
        current_bit_value = (N / bits) % 10;
        low_bit_value = N - (N / bits) * bits;
        if (0 == current_bit_value)
            sum += bits * high_bit_value;
        else if(1 == current_bit_value)
            sum += bits * high_bit_value + low_bit_value + 1;
        else
            sum += bits * (high_bit_value + 1);
        bits *= 10;
    }
    printf("sum of number 1 in %d is %d.\n", N, sum);
    return EXIT_SUCCESS;
}
