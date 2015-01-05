/**
 * @file get_fibonacci_polynomial_by_bottom_up.c
 * @brief get the nth member of the fibonacci sequence by dynamic programming.
 * with bottom-up method.
 * the fibonacci sequence index begin from 0th:
 * 1, 1, 2, 3, 5, 8, 13, 21, 34....
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-31
 */

#include <stdlib.h>
#include <stdio.h>
// #define NDEBUG
#include <assert.h>
// #define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

#define NUM  9

TYPE fib(TYPE index)
{
    assert(index >= 0);
    TYPE cachs_prevous[2] = {1, 1};
    TYPE i;
    if(index == 0 || index == 1)
        return 1;
    for(i = 2; i <= index; i++) {
        cachs_prevous[i & 1] = cachs_prevous[0] + cachs_prevous[1];
    }
    return cachs_prevous[(--i) & 1];
}

int main(void)
{
    printf("index = %d\n", NUM);
    printf("fib = %d\n", fib(NUM));
    return EXIT_SUCCESS;
}
