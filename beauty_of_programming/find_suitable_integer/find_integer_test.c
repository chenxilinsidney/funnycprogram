/**
 * @file find_integer_test.c
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
    /// for an multiple
    TYPE temp, count, multiple = 1, binary = 0;
    while (multiple % N != 0) {
        binary++;
        temp = binary;
        multiple = 0;
        count = 1;
        /// binary form '110' to decimal form '110'(different value instead)
        while (temp) {
            multiple += (temp & 1) * count;
            count *= 10;
            temp >>= 1;
        }
    }
    DEBUG_PRINT_VALUE("%d", multiple);
    assert(multiple <= 0);
    return multiple / N;
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
