/**
 * @file knapsack_problem_dp_top_down.c
 * @brief solve 0-1 knapsack problem by dynamic programming
 * with top-down with memoization method.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-04
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>
// #define NDEBUG
#include <assert.h>

// #define NDBG_PRINT
#include "debug_print.h"

typedef int ElementType;    ///< element data type
typedef int CommonType;     ///< common data type

/// data
#define MAX_COUNT      100
ElementType v[MAX_COUNT] = {0};
ElementType w[MAX_COUNT] = {0};
CommonType x[MAX_COUNT] = {0};
CommonType V[MAX_COUNT + 1][MAX_COUNT + 1] = {{0}};

ElementType knapsack_problem(ElementType* v, ElementType* w,
        CommonType count,
        ElementType maximum_weight,
        ElementType V[MAX_COUNT + 1][MAX_COUNT + 1])
{
    assert(v != NULL && w != NULL && count >= -1 && maximum_weight >= 0 &&
            V != NULL);
    /// no items or no weight
    if (count == -1 || maximum_weight == 0)
        return 0;
    /// the i-th item's weight exceed the range
    if (w[count - 1] > maximum_weight)
        return knapsack_problem(v, w, count - 1, maximum_weight, V);
    /// get best solution
    ElementType a = knapsack_problem(v, w, count - 1, maximum_weight, V);
    ElementType b = knapsack_problem(v, w, count - 1,
            maximum_weight - w[count - 1], V) + v[count - 1];
    return a > b ? a : b;
}

int main(void) {
    /// read data to array
    /// read maximum weight
    ElementType maximum_weight = 0;
    if (scanf("%d\n", &maximum_weight) != 1 || maximum_weight <= 0) {
        DEBUG_PRINT_STATE;
        DEBUG_PRINT_STRING("can not get right maximum_weight");
    }
    CommonType count = 0;
    while(count < MAX_COUNT && scanf("(%u,%u)\n", v + count, w + count) == 2) {
        ++count;
    }
    /// get result
    ElementType best_value = knapsack_problem(v, w, count,
            maximum_weight, V);
    /// output result
    printf("best value = %d\n", best_value);
    return EXIT_SUCCESS;
}
