/**
 * @file knapsack_problem_recursion.c
 * @brief solve 0-1 knapsack problem by recursion
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-04
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
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

ElementType knapsack_problem_recursion(ElementType* v, ElementType* w,
        CommonType count, ElementType maximum_weight, ElementType actual_weight)
{
    for 
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
    knapsack_problem_recursion();
    /// output result
    printf("maximum weight = %d, actual weight = %d, maximum value = %d",
            maximum_weight, actual_weight, maximum_value);
    CommonType i;
    for (i = 0; i < count; i++) {
        printf("item index = %3d, value = %3d, weight = %3d, get_flag = %3d\n",
                i, v[i], w[i], x[i]);
    }
}
