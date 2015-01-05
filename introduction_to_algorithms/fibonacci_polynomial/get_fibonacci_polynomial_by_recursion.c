/**
 * @file get_fibonacci_polynomial_by_recursion.c
 * @brief get the nth member of the fibonacci sequence by recursion.
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

#define NUM  4

TYPE fib(TYPE index)
{
    assert(index >= 0);
    DEBUG_PRINT_STRING("In recursion now.\n");
    DEBUG_PRINT_VALUE("%d", index);
    if(index == 0 || index == 1) {
        DEBUG_PRINT_STRING("get first and second index 0/1.\n");
        DEBUG_PRINT_VALUE("%d", index);
        DEBUG_PRINT_STRING("Out recursion now.\n");
        return 1;
    } else {
        TYPE temp = fib(index - 1) + fib(index - 2);
        DEBUG_PRINT_VALUE("%d", temp);
        DEBUG_PRINT_VALUE("%d", index);
        DEBUG_PRINT_STRING("Out recursion now.\n");
        return temp;
    }
}

int main(void)
{
    printf("index = %d\n", NUM);
    printf("fib = %d\n", fib(NUM));
    return EXIT_SUCCESS;
}
