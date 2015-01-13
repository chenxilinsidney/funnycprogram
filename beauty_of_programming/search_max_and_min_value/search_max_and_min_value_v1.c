/**
 * @file search_max_and_min_value_v1.c
 * @brief search the maximum and minimum value in the sequence.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-12
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
// #define NDEBUG
#include <assert.h>

// #define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

#define MAX_COUNT      10000000
TYPE array[MAX_COUNT] = {0};

/**
 * @brief search the maximum and minimum value in the array
 *
 * @param[in]      array  sequence for search
 * @param[in]      count  sequence length
 * @param[out]     max    maximum value from the sequence
 * @param[out]     min    minimum value from the sequence
 */
void search_max_and_min_value(TYPE* array, TYPE count, TYPE* max, TYPE* min)
{
    assert(array != NULL && max != NULL && min != NULL && count >= 1);
    /// initialize max and min value
    *max = array[0];
    *min = array[0];
    TYPE i;
    for (i = 1; i < count; i++) {
        /// compare with max value for N - 1 times(N = count).
        if (array[i] > *max)
            *max = array[i];
        /// compare with min value for N - 1 times(N = count).
        if (array[i] < *min)
            *min = array[i];
    }
    return;
}

int main(void) {
    /// read data to array
    TYPE count = 0;
    while(count < MAX_COUNT && scanf("%u\n", array + count) == 1) {
        ++count;
    }
    /// search maximum and minimum value
    TYPE max = 0;
    TYPE min = 0;
    search_max_and_min_value(array, count, &max, &min);
    /// output result
    printf("max element is %d\n", max);
    printf("min element is %d\n", min);
    return EXIT_SUCCESS;
}
