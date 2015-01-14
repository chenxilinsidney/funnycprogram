/**
 * @file gcd_euclidean_algorithm.c
 * @brief get greatest commont divisor(gcd) for two input values.
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
 * @brief get greatest commont divisor(gcd) for value m and n.
 *
 * @param[in]      m  first value
 * @param[in]      n  second value
 *
 * @return gcd value
 */
TYPE gcd(TYPE m, TYPE n)
{
    if (m == 0)
        return n;
    else if (n == 0)
        return m;
    TYPE temp;
    if (m < n) {
        temp = m;
        m = n;
        n = temp;
    }
    while (n != 0) {
        temp = m % n;
        m = n;
        n = temp;
    }
    return m;
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
