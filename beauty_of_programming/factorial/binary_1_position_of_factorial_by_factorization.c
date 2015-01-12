/**
 * @file binary_1_position_of_factorial_by_factorization.c
 * @brief get the binary 1's position of the binary form number which is
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

TYPE binary_1_position(TYPE N)
{
    assert(N >= 1);
    TYPE count = 0;
    TYPE i, j;
    /// count all value
    for (i = 1; i <= N; i++) {
        j = i;
        /// count factorization for number 2
        while ((j & 0x1) == 0) {
            count++;
            j >>= 1;
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
    TYPE result = binary_1_position(N);
    printf("binary 1's position distance of binary form number %d! is: %d\n",
            N, result);
    return EXIT_SUCCESS;
}
