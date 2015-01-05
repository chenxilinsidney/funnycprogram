/**
 * @file get_fibonacci_polynomial_by_matrix.c
 * @brief get the nth member of the fibonacci sequence by dynamic programming.
 * with bottom-up method.
 * the fibonacci sequence index begin from 0th:
 * 0, 1, 1, 2, 3, 5, 8, 13, 21, 34....
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

#define NUM  9

struct matrix_2by2 {
    TYPE m11;
    TYPE m12;
    TYPE m21;
    TYPE m22;
};

struct matrix_2by2 matrix_multiply_2by2(
        struct matrix_2by2 matrix_a,
        struct matrix_2by2 matrix_b)
{
    struct matrix_2by2 matrix_c;
    matrix_c.m11 = matrix_a.m11 * matrix_b.m11 + matrix_a.m12 * matrix_b.m21;
    matrix_c.m12 = matrix_a.m11 * matrix_b.m12 + matrix_a.m12 * matrix_b.m22;
    matrix_c.m21 = matrix_a.m21 * matrix_b.m11 + matrix_a.m22 * matrix_b.m21;
    matrix_c.m22 = matrix_a.m21 * matrix_b.m12 + matrix_a.m22 * matrix_b.m22;
    return matrix_c;
}

struct matrix_2by2 matrix_power_2by2(TYPE n)
{
    assert(n > 0);
    struct matrix_2by2 matrix_source = {1, 1, 1, 0};
    if (n == 1) {
        return matrix_source;
    } else {
        if ((n & 0x1) == 0) {
            struct matrix_2by2 matrix_temp =
                matrix_power_2by2((unsigned)n >> 1);
            struct matrix_2by2 matrix_return =
                matrix_multiply_2by2(matrix_temp, matrix_temp);
            return matrix_return;
        } else {
            struct matrix_2by2 matrix_temp =
                matrix_power_2by2((unsigned)(n - 1) >> 1);
            struct matrix_2by2 matrix_return =
                matrix_multiply_2by2(matrix_temp, matrix_temp);
            matrix_return = matrix_multiply_2by2(matrix_return, matrix_source);
            return matrix_return;
        }
    }
}

TYPE fib(TYPE index)
{
    assert(index >= 0);
    if (index == 0)
        return 0;
    else if (index == 1)
        return 1;
    struct matrix_2by2 matrix_return = matrix_power_2by2(index - 1);
    return matrix_return.m11;
}

int main(void)
{
    printf("index = %d\n", NUM);
    printf("fib = %d\n", fib(NUM));
    return EXIT_SUCCESS;
}
