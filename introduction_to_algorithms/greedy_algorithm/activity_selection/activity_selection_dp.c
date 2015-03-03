/**
 * @file activity_selection_dp.c
 * @brief activity selection by dynamic programming method.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-03
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NDEBUG
#include <assert.h>

#define NDBG_PRINT
#include "debug_print.h"

typedef int ElementType;    ///< element data type
typedef int CommonType;     ///< common data type

/// activity data
#define ACTIVITY_COUNT 13
ElementType s[ACTIVITY_COUNT] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12, INT_MAX};
ElementType f[ACTIVITY_COUNT] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16, INT_MAX};
ElementType c[ACTIVITY_COUNT][ACTIVITY_COUNT] = {{0}};
ElementType t[ACTIVITY_COUNT][ACTIVITY_COUNT] = {{0}};
ElementType result_index[ACTIVITY_COUNT] = {0};

void activity_selector(ElementType* s, ElementType* f, CommonType count,
        CommonType c[ACTIVITY_COUNT][ACTIVITY_COUNT],
        CommonType t[ACTIVITY_COUNT][ACTIVITY_COUNT])
{
    CommonType i, j, k, temp;
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            /// initialize Sij as empty set first
            c[i][j] = 0;
            /// get better set if exist
            for (k = i + 1; k < j; k++) {
                if (s[k] >= f[i] && f[k] <= s[j]) {
                    temp = c[i][k] + c[k][j] + 1;
                    if (c[i][j] < temp) {
                        c[i][j] = temp;
                        t[i][j] = k;
                    }
                }
            }
        }
    }
    /// display c
    printf("c = \n");
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++)
            printf("%3d ", c[i][j]);
        printf("\n");
    }
    /// display t
    printf("t = \n");
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++)
            printf("%3d ", t[i][j]);
        printf("\n");
    }
}

void trace_route(CommonType t[ACTIVITY_COUNT][ACTIVITY_COUNT],
        CommonType i,
        CommonType j,
        ElementType* result)
{
    if (i < j) {
        if (t[i][j] != 0)
            *result++ = t[i][j];
        trace_route(t, i, t[i][j], result);
    }
}

int main(void) {
    activity_selector(s, f, ACTIVITY_COUNT, c, t);
    // output result
    trace_route(t, 0, ACTIVITY_COUNT - 1, result_index);
    printf("result = ");
    ElementType* result = result_index;
    while(*(result) != 0) {
        printf("%3d ", *result++);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
