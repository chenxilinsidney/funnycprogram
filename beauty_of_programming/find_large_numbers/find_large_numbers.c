/**
 * @file find_large_numbers.c
 * @brief find largest k numbers in a given array.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-02-04
 */

#include <stdlib.h>
#include <stdio.h>
// #define NDEBUG
#include <assert.h>

// #define NDBG_PRINT
#include "debug_print.h"

typedef int TYPE;

#define MAX_COUNT      10000000
TYPE array[MAX_COUNT] = {0};

/**
 * @brief select the last element as a pivoit.
 * Reorder the array so that all elements with values less than the pivot
 * come before the pivot, while all elements with values less than the pivot
 * come after it (equal values can go either way). After this partitioning, the
 * pivot is in its final position. 
 *
 * @param[in,out]  array          input and output array
 * @param[in]      index_begin    the begin index of the array(included)
 * @param[in]      index_end      the end index of the array(included)
 *
 * @return the position of the pivot(index from the array)
 */
TYPE partition(TYPE* array, TYPE index_begin, TYPE index_end)
{
    /// pick last element of the array as the pivot
    TYPE pivot = array[index_end];
    /// index of the elments that not greater than pivot
    TYPE i = index_begin - 1;
    TYPE j, temp;
    /// check array's elment one by one
    for (j = index_begin; j < index_end; j++) {
        if (array[j] >= pivot) {
            /// save the elements not less than pivot to left index of i.
            i++;
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    /// set the pivot to the right position
    array[index_end] = array[++i];
    array[i] = pivot;
    /// return the position of the pivot
    return i;
}

/**
 * @brief find the last index of the input array for largets N numbers.
 * the numbers that index is before the last index is the largest N numbers.
 *
 * @param[in,out]  array          input and output array
 * @param[in]      index_begin    the begin index of the array(included)
 * @param[in]      index_end      the end index of the array(included)
 * @param[in]      count          the count of the largest numbers.
 */
TYPE find_quick_sort(TYPE* array, TYPE index_begin, TYPE index_end, TYPE count)
{
    assert(count > 0);
    if (index_begin < index_end) {
        /// get pivot by partition
        TYPE index_pivot = partition(array, index_begin, index_end);
        TYPE first_array_count = index_pivot - index_begin + 1;
        DEBUG_PRINT_VALUE("%d", count);
        DEBUG_PRINT_VALUE("%d", index_begin);
        DEBUG_PRINT_VALUE("%d", index_end);
        DEBUG_PRINT_VALUE("%d", index_pivot);
        if (first_array_count < count)
            /// find the other numbers in second part of the array
            return find_quick_sort(array, index_pivot + 1, index_end,
                    count - first_array_count);
        else if (first_array_count > count)
            /// still find N numbers in first part of the array
            return find_quick_sort(array, index_begin, index_pivot - 1,
                    count);
        else
            /// just find N numbers
            return index_pivot;
    } else {
        return index_begin;
    }
}

int main(void) {
    /// read data to array
    TYPE count = 0;
    while(count < MAX_COUNT && scanf("%u\n", array + count) == 1) {
        ++count;
    }
    /// find largest N numbers
    TYPE N = 15;
    TYPE i, last_index;
    if ((last_index = find_quick_sort(array, 0, count - 1, N)) >= 0) {
        printf("get the largest %d numbers:\n", N);
        DEBUG_PRINT_VALUE("%d", last_index);
        for (i = 0; i <= last_index; i++) {
            printf("%d ", array[i]);
        }
    } else {
        printf("can not get the largest N numbers.\n");
    }
    return EXIT_SUCCESS;
}
