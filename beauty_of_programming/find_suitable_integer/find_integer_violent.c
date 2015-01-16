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

typedef unsigned int TYPE;

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
    TYPE M = 2;
    TYPE multiple;
    TYPE flag_get = 0;
    while (!flag_get) {
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
        /// increase M
        M++;
    }
    assert(M > 1);
    return --M;
}

int main(void) {
    /// get value N
    TYPE value;
    printf("input the positive integer: ");
    if(scanf("%u", &value) != 1 || value <= 0) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("can not get the right value.\n");
        DEBUG_PRINT_VALUE("%u", value);
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// get value M
    TYPE result = find_suitable_value(value);
    /// output result
    printf("the least positive integer: %d\n", result);
    return EXIT_SUCCESS;
}
