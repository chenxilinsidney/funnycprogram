/**
 * @file knapsack_problem_dp_bottom_up.c
 * @brief solve 0-1 knapsack problem by dynamic programming
 * with bottom-up method.
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
#define MAX_COUNT      100  ///< count of the items
#define MAX_WEIGHT     300  ///< max weight of the items for memory
ElementType v[MAX_COUNT + 1] = {0};
ElementType w[MAX_COUNT + 1] = {0};
CommonType x[MAX_COUNT + 1] = {0};
CommonType V[MAX_COUNT + 1] = {0};
CommonType keep[MAX_COUNT + 1][MAX_WEIGHT + 1] = {{0}};

ElementType knapsack_problem(ElementType* v, ElementType* w,
        ElementType* x,
        CommonType count,
        ElementType maximum_weight,
        ElementType V[MAX_COUNT + 1],
        ElementType keep[MAX_COUNT + 1][MAX_WEIGHT + 1])
{
    assert(v != NULL && w != NULL && count >= -1 && maximum_weight >= 0 &&
            V != NULL);
    CommonType i, j;
    /// initialize first row
    for (i = 0; i <= maximum_weight; i++) {
        keep[0][i] = 0;
    }
    for (i = 1; i <= count; i++) {
        /// initialize first column
        V[0] = 0;
        keep[i][0] = 0;
        /// get matrix solution
        for (j = maximum_weight; j >= 1; j--) {
            if(w[i - 1] <= j) {
                ElementType b = V[j - w[i - 1]] + v[i - 1];
                if (V[j] < b) V[j] = b;
                if (V[j] > b)
                    keep[i][j] = 0;
                else
                    keep[i][j] = 1;
            } else {
                keep[i][j] = 0;
            }
        }
    }
    /// display the matrix
    printf("-V--");
    for (j = 0; j <= maximum_weight; j++)
        printf("%3d ", j);
    printf("\n");
    for (i = 0; i <= count; i++) {
        printf("%3d ", i);
        for (j = 0; j <= maximum_weight; j++)
            printf("%3d ", V[j]);
        printf("\n");
    }
    printf("keep");
    for (j = 0; j <= maximum_weight; j++)
        printf("%3d ", j);
    printf("\n");
    for (i = 0; i <= count; i++) {
        printf("%3d ", i);
        for (j = 0; j <= maximum_weight; j++)
            printf("%3d ", keep[i][j]);
        printf("\n");
    }
    /// get and display the item list by keep matrix
    printf("remain weight = ");
    ElementType remain_weight = maximum_weight;
    for (i = count; i >= 1; i--) {
        if (keep[i][remain_weight] == 1) {
            printf("%3d ", i);
            remain_weight -= w[i - 1];
            x[i - 1] = 1;
        } else {
            x[i - 1] = 0;
        }
    }
    printf("\n");
    printf("actual weight = %3d\n", maximum_weight - remain_weight);
    return V[maximum_weight];
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
    ElementType best_value = knapsack_problem(v, w, x, count,
            maximum_weight, V, keep);
    /// output result
    printf("best value = %d\n", best_value);
    CommonType i;
    for (i = 0; i < count; i++) {
        printf("item index = %3d, value = %3d, weight = %3d, get_flag = %3d\n",
                i + 1, v[i], w[i], x[i]);
    }
    return EXIT_SUCCESS;
}
