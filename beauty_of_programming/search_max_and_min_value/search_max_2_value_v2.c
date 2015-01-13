/**
 * @file search_max_2_value_v2.c
 * @brief search the second maximum value in the sequence.
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
 * @param[in]      index_begin index begin of array(included)
 * @param[in]      index_end   index end of array(included)
 * @param[out]     max_first    maximum value from the sequence
 * @param[out]     max_second   second maximum value from the sequence
 */
void search_max_2_value(TYPE* array,
        TYPE index_begin, TYPE index_end,
        TYPE* max_first, TYPE* max_second)
{
    assert(array != NULL && max_first != NULL && max_second != NULL);
    assert(index_begin <= index_end);
    /// the minimum array comparison
    if (index_end - index_begin == 1) {
        if (array[index_end] < array[index_begin]) {
            *max_first = array[index_begin];
            *max_second = array[index_end];
        } else {
            *max_second = array[index_begin];
            *max_first = array[index_end];
        }
        return;
    } else if (index_end == index_begin) {
        *max_first = array[index_begin];
        *max_second = INT_MIN;
        return;
    }
    /// divide array to small problem
    TYPE middle = index_begin + ((unsigned)(index_end - index_begin) >> 1);
    TYPE max_f_left, max_f_right, max_s_left, max_s_right;
    search_max_2_value(array, index_begin, middle,
            &max_f_left, &max_s_left);
    search_max_2_value(array, middle + 1, index_end,
            &max_f_right, &max_s_right);
    /// conquer the small problem
    if (max_f_left > max_f_right) {
        if (max_s_left > max_f_right)
            *max_second = max_s_left;
        else
            *max_second = max_f_right;
        *max_first = max_f_left;
    } else {
        if (max_s_right > max_f_left)
            *max_second = max_s_right;
        else
            *max_second = max_f_left;
        *max_first = max_f_right;
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
    TYPE max_first = 0;
    TYPE max_second = 0;
    search_max_2_value(array, 0, count - 1, &max_first, &max_second);
    /// output result
    printf("max_first element is %d\n", max_first);
    printf("max_second element is %d\n", max_second);
    return EXIT_SUCCESS;
}
