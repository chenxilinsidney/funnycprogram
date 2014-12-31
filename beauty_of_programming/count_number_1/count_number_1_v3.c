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
TYPE N = 100000000000;

TYPE count_number_1(TYPE n)
{
    TYPE sum = 0;
    TYPE bits = 0;
    TYPE pow_bits = 1;
    TYPE n_cpy = n;
    while(n_cpy) {
        bits++;
        pow_bits *= 10;
        n_cpy /= 10;
    }
    pow_bits /= 10;
    if(bits > 1) {
        TYPE top_bit_value = n / pow_bits;
        TYPE low_bit_value = n % pow_bits;
        // recursive
        if(top_bit_value == 1) {
            sum = count_number_1(low_bit_value) +
                count_number_1(pow_bits - 1) +
                low_bit_value + 1;
        } else {
            sum = count_number_1(low_bit_value) +
                top_bit_value * count_number_1(pow_bits - 1) +
                pow_bits;
        }
    } else {
        // lowest bits
        if (n < 1)
            sum = 0;
        else
            sum = 1;
    }
    return sum;
}

int main(void)
{
    TYPE i;
    TYPE sum = 0;
    sum += count_number_1(N);
    printf("sum of number 1 in %lld is %lld.\n", N, sum);
    return EXIT_SUCCESS;
}
