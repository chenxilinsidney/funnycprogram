/**
 * @file find_integer_violent.c
 * @brief for an input positive integer N, find the least positive
 * interger to make M*N combined only with value 1 and 0 in decimal form.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-16
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
// #define NDEBUG
#include <assert.h>

// #define NDBG_PRINT
#include "debug_print.h"

typedef unsigned long TYPE;

/**
 * @brief input positive integer N, get the least positive integer
 * to make M*N combined only with value 1 and 0 in decimal form.
 *
 * @param[in]      N positive integer N
 *
 * @return suitable positive integer M
 */
TYPE find_suitable_value(TYPE N)
{
    /// input should be positive integer
    assert(N > 0);
    /// get positive integer M
    TYPE multiple, M = 1, flag_get = 0;
    while (!flag_get) {
        /// increase M
        M++;
        /// set flag
        flag_get = 1;
        /// get multiple of M and N
        multiple = N * M;
        /// detect if M is the suitable integer
        while (multiple) {
            if ((multiple % 10) != 1 && (multiple % 10) != 0) {
                flag_get = 0;
                break;
            }
            multiple /= 10;
        }
    }
    /// M exceed the range of data type
    if (M == 0) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("can not find value M because out of range\n");
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    return M;
}

int main(void) {
    /// print max M
    printf("max ouput value: %lu\n", ULONG_MAX);
    /// get value N
    TYPE value;
    printf("input the positive integer: ");
    if(scanf("%lu", &value) != 1 || value <= 0) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("can not get the right value.\n");
        DEBUG_PRINT_VALUE("%lu", value);
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// get value M
    TYPE result = find_suitable_value(value);
    /// output result
    printf("the least positive integer: %lu\n", result);
    return EXIT_SUCCESS;
}
