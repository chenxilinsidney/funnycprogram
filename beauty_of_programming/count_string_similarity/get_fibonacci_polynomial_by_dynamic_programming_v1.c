/**
 * @file get_fibonacci_polynomial_by_dynamic_programming.c
 * @brief get the nth member of the fibonacci sequence by dynamic programming.
 * using the top-down approach.
 * the fibonacci sequence index begin from 0th:
 * 1, 1, 2, 3, 5, 8, 13, 21, 35....
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

#define NUM  40
TYPE cache[NUM] = {1, 1};

TYPE fib(TYPE index)
{
    assert(index >= 0);
    DEBUG_PRINT_STRING("In recursion now.\n");
    DEBUG_PRINT_VALUE("%d", index);
    static TYPE cache_count = 2;
    if(index < cache_count) {
        DEBUG_PRINT_STRING("get value from cache.\n");
        DEBUG_PRINT_VALUE("%d", cache[index]);
        DEBUG_PRINT_VALUE("%d", index);
        DEBUG_PRINT_STRING("Out recursion now.\n");
        return cache[index];
    } else {
        cache[index] = fib(index - 1) + fib(index - 2);
        DEBUG_PRINT_VALUE("%d", cache_count);
        cache_count++;
        DEBUG_PRINT_STRING("set value to cache.\n");
        DEBUG_PRINT_VALUE("%d", cache[index]);
        DEBUG_PRINT_VALUE("%d", index);
        DEBUG_PRINT_STRING("Out recursion now.\n");
        return cache[index];
    }
}

int main(void)
{
    printf("index = %d\n", NUM);
    printf("fib = %d\n", fib(NUM));
    return EXIT_SUCCESS;
}
