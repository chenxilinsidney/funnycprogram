/**
 * @file get_fibonacci_polynomial_by_dynamic_programming.c
 * @brief get the nth member of the fibonacci sequence by dynamic programming.
 * the fibonacci sequence index begin from 0th:
 * 1, 1, 2, 3, 5, 8, 13, 21, 35....
 * @author chenxilinsidney
 * @version 1.0
 * @date 2014-12-31
 */

#include <stdlib.h>
#include <stdio.h>

// #define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

#define NUM  4
TYPE cache[NUM] = {0};

TYPE fib(TYPE index)
{
    DEBUG_PRINT_STRING("In recursion now.\n");
    DEBUG_PRINT_VALUE("%d", index);
    static TYPE cache_count = 0;
    if(index < cache_count) {
        DEBUG_PRINT_STRING("get value from cache.\n");
        DEBUG_PRINT_VALUE("%d", cache[index]);
        DEBUG_PRINT_STRING("Out recursion now.\n");
        return cache[index];
    } else if(index == 0 || index == 1) {
        DEBUG_PRINT_STRING("set first and second index 0/1.\n");
        cache[index] = 1;
        cache_count++;
        DEBUG_PRINT_STRING("Out recursion now.\n");
        return 1;
    } else {
        DEBUG_PRINT_STRING("Will go to new recursion.\n");
        cache[index] = fib(index - 2) + fib(index - 1);
        cache_count++;
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
