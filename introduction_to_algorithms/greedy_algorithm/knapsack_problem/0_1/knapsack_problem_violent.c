/**
 * @file knapsack_problem_violent.c
 * @brief solve 0-1 knapsack problem by violence
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

void knapsack_problem_violent(ElementType* v, ElementType* w,
        CommonType count,
        ElementType maximum_weight,
        ElementType* best_weight,
        ElementType* best_value,
        ElementType* x)
{
    assert(v != NULL && w != NULL && count >= 1 && maximum_weight > 0 &&
            x != NULL && best_value != NULL && best_weight != NULL);
    /// initialize
    CommonType i, j, k;
    ElementType temp_weight, temp_value;
    CommonType x_temp[MAX_COUNT] = {0};
    *best_weight = 0; *best_value = 0;
    memset(x, 0, count * sizeof(ElementType));
    /// detect all combination
    CommonType type_count = pow(2, count);
    for (i = 0; i < type_count; i++) {
        /// get current total weight and totoal value and combination
        memset(x_temp, 0, count * sizeof(ElementType));
        k = 0;
        temp_value = 0;
        temp_weight = 0;
        j = i;
        do {
            if (j & 0x1) {
                temp_value += v[k];
                temp_weight += w[k];
                x_temp[k] = 1;
            }
            k++;
        } while (j >>= 1);
        /// save best state
        if (temp_weight < maximum_weight && temp_value > *best_value) {
            *best_weight = temp_weight;
            *best_value = temp_value;
            memcpy(x, x_temp, count * sizeof(ElementType));
        }
    }
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
    ElementType best_value, best_weight;
    knapsack_problem_violent(v, w, count,
            maximum_weight, &best_weight, &best_value, x);
    /// output result
    printf("maximum weight = %d, best weight = %d, best value = %d\n",
            maximum_weight, best_weight, best_value);
    CommonType i;
    for (i = 0; i < count; i++) {
        printf("item index = %3d, value = %3d, weight = %3d, get_flag = %3d\n",
                i, v[i], w[i], x[i]);
    }
    return EXIT_SUCCESS;
}
