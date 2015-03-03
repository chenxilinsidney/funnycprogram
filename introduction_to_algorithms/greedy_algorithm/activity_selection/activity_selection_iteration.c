/**
 * @file activity_selection_iteration.c
 * @brief activity selection by greedy algorirhm with iteration.
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
#define ACTIVITY_COUNT 12
ElementType s[ACTIVITY_COUNT] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
ElementType f[ACTIVITY_COUNT] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
ElementType result_index[ACTIVITY_COUNT] = {0};

void activity_selector(ElementType* s, ElementType* f,
        CommonType count,
        CommonType* result)
{
    *result++ = 1;
    CommonType m, k = 1;
    for (m = 2; m < count; m++) {
        if (s[m] >= f[k]) {
            *result++ = m;
            k = m;
        }
    }
}

int main(void) {
    activity_selector(s, f, ACTIVITY_COUNT, result_index);
    // output result
    printf("result = ");
    ElementType* result = result_index;
    while(*(result) != 0) {
        printf("%3d ", *result++);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
