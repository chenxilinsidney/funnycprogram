/**
 * @file gcd_binary_recursion.c
 * @brief get greatest common divisor(gcd) for two input values.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-14
 */

#include <stdlib.h>
#include <stdio.h>
// #define NDEBUG
#include <assert.h>

// #define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

/**
 * @brief get greatest common divisor(gcd) for value m and n.
 *
 * @param[in]      m  first value
 * @param[in]      n  second value
 *
 * @return gcd value
 */
TYPE gcd(TYPE m, TYPE n)
{
    /// m and n range limits
    assert(m >= 0 && n >= 0);
    if (m < n)
        return gcd(n, m);
    else if (n == 0)
        return m;
    if (m & 1) {
        if (n & 1)
            return gcd(n, (m - n) >> 1);
        else
            return gcd(m, n >> 1);
    } else {
        if (n & 1)
            return gcd(m >> 1, n);
        else
            return gcd(m >> 1, n >> 1) << 1;
    }
}

int main(void) {
    /// get two value
    TYPE value_a, value_b;
    printf("input the first number: ");
    if(scanf("%d", &value_a) != 1) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("can not get the right value.\n");
        DEBUG_PRINT_VALUE("%u", value_a);
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    printf("input the second number: ");
    if(scanf("%d", &value_b) != 1) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("can not get the right value.\n");
        DEBUG_PRINT_VALUE("%u", value_b);
        fflush(stdout);
        assert(0);
        exit(EXIT_FAILURE);
    }
    /// get gcd
    TYPE result = gcd(value_a, value_b);
    /// output result
    printf("get the gcd number: %d\n", result);
    return EXIT_SUCCESS;
}
