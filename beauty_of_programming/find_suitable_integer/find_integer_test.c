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
    /// for an multiple
    TYPE temp, count, multiple = 1, binary = 1;
    /// detect if multiple is out of range by comparing with previous value
    TYPE multiple_previous = 0;
    /// get right multiple
    do {
        /// increase binary value
        binary++;
        /// initialize the value
        temp = binary;
        multiple = 0;
        count = 1;
        /// binary form '11'(3) to decimal form '11'(11)
        while (temp) {
            multiple += (temp & 1) * count;
            count *= 10;
            temp >>= 1;
        }
        /// detect if multiple is out of range
        if (multiple < multiple_previous) {
            multiple = 0;
            break;
        }
        multiple_previous = multiple;
    } while (multiple % N != 0);
    /// M exceed the range of data type
    if (multiple == 0) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("can not find value M because out of range\n");
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    return multiple / N;
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
