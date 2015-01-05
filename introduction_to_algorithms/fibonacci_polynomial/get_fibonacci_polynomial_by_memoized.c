/**
 * @file get_fibonacci_polynomial_by_memoized.c
 * @brief get the nth member of the fibonacci sequence by dynamic programming.
 * with top-down with memoization method.
 * the fibonacci sequence index begin from 0th:
 * 1, 1, 2, 3, 5, 8, 13, 21, 34....
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-31
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define NDEBUG
#include <assert.h>

#include "memory.h"
#define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

#define NUM  9

/**
 * @brief get nth number of the fibonacci sequence.
 *
 * @param index index of the number. begin from 0.
 *
 * @return the nth number
 */
TYPE fib_aux(TYPE index, TYPE* cache);

TYPE fib(TYPE index)
{
    /// initialize cache first
    TYPE* cache = SMALLOC(NUM + 1, TYPE);
    TYPE i;
    for (i = 0; i <= NUM; i++)
        cache[i] = INT_MIN;
    /// get result with cache
    TYPE result = fib_aux(index, cache);
    SFREE(&cache);
    return result;
}

TYPE fib_aux(TYPE index, TYPE* cache)
{
    assert(index >= 0);
    if (cache[index] > INT_MIN) {
        return cache[index];
    }
    if (index == 0 || index == 1) {
        cache[index] = 1;
    } else {
        cache[index] = fib(index - 1) + fib(index - 2);
    }
    return cache[index];
}

int main(void)
{
    printf("index = %d\n", NUM);
    printf("fib = %d\n", fib(NUM));
    return EXIT_SUCCESS;
}
