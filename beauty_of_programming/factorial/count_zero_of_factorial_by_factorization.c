/**
 * @file count_zero_of_factorial_by_factorization.c
 * @brief count the zero numbers at the end of number which is
 * caculated by factorial of N by math factorization.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-11
 */

#include <stdlib.h>
#include <stdio.h>
// #define NDEBUG
#include <assert.h>

// #define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

TYPE count_zero_of_factorial(TYPE N)
{
    assert(N >= 1);
    TYPE count = 0;
    TYPE i, j;
    /// count all value
    for (i = 1; i <= N; i++) {
        j = i;
        /// count factorization for number 5
        while (j % 5 == 0) {
            count++;
            j /= 5;
        }
    }
    return count;
}

int main(void)
{
    /// get input number N
    TYPE N = 0;
    printf("Please input the factorial number:\n");
    if(scanf("%d", &N) != 1 || N < 1) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("can not get the right number(excluded).\n");
        DEBUG_PRINT_VALUE("%d", N);
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// get result
    TYPE result = count_zero_of_factorial(N);
    printf("zero number count at the end of number %d! is: %d\n",
            N, result);
    return EXIT_SUCCESS;
}