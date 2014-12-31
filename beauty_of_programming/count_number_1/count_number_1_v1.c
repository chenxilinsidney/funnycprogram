/**
 * @file count_number_1_v1.c
 * @brief count the number 1 for all number less than N.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-28
 */

#include <stdlib.h>
#include <stdio.h>

typedef int TYPE;
TYPE N = 1000000000;

TYPE count_number_1(TYPE n)
{
    TYPE sum = 0;
    while(n) {
        sum += n % 10 == 1 ? 1 : 0;
        n /= 10;
    }
    return sum;
}

int main(void)
{
    TYPE i;
    TYPE sum = 0;
    for(i = 1; i <= N; i++) {
        sum += count_number_1(i);
    }
    printf("sum of number 1 in %d is %d.\n", N, sum);
    return EXIT_SUCCESS;
}
