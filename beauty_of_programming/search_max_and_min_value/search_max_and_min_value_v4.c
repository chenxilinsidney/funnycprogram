/**
 * @file search_max_and_min_value_v3.c
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
 * @param[in]      index_begin index begin of array(included)
 * @param[in]      index_end   index end of array(included)
 * @param[out]     max    maximum value from the sequence
 * @param[out]     min    minimum value from the sequence
 */
void search_max_and_min_value(TYPE* array,
        TYPE index_begin, TYPE index_end,
        TYPE* max, TYPE* min)
{
    assert(max != NULL && min != NULL);
    /// the minimum array comparison
    if (index_end - index_begin <= 1) {
        if (array[index_end] < array[index_begin]) {
            *max = array[index_begin];
            *min = array[index_end];
        } else {
            *min = array[index_begin];
            *max = array[index_end];
        }
        return;
    }
    /// divide array to small problem
    TYPE middle = index_begin + ((unsigned)(index_end - index_begin) >> 1);
    TYPE max_left = INT_MIN;
    TYPE max_right = INT_MIN;
    TYPE min_left = INT_MAX;
    TYPE min_right = INT_MAX;
    search_max_and_min_value(array, index_begin, middle,
            &max_left, &min_left);
    search_max_and_min_value(array, middle + 1, index_end,
            &max_right, &min_right);
    /// conquer the small problem
    if (max_left > max_right)
        *max = max_left;
    else
        *max = max_right;
    if (min_left < min_right)
        *min = min_left;
    else
        *min = min_right;
    return;
}

int main(void) {
    /// read data to array
    TYPE count = 0;
    while(count < MAX_COUNT && scanf("%u\n", array + count) == 1) {
        ++count;
    }
    /// search maximum and minimum value
    TYPE max = INT_MIN;
    TYPE min = INT_MAX;
    search_max_and_min_value(array, 0, count - 1, &max, &min);
    /// output result
    printf("max element is %d\n", max);
    printf("min element is %d\n", min);
    return EXIT_SUCCESS;
}
