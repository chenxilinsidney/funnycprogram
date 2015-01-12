/**
 * @file find_id_by_sort_search.c
 * @brief find the id which repeats most in the sequence.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-01-07
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
 * come before the pivot, while all elements with values greater than the pivot
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
        if (array[j] <= pivot) {
            /// save the elements not greater than pivot to left index of i.
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
 * @brief sort the array by Quicksort method.
 *
 * @param[in,out]  array       sequence for sort
 * @param[in]      index_begin begin index of sequence for sort(included)
 * @param[in]      index_end   end index of sequence for sort(included)
 */
void quick_sort(TYPE* array, TYPE index_begin, TYPE index_end)
{
    /// sort only under the index_begin < index_end condition
    if ( index_begin < index_end) {
        /// exchange elements to the pivot position by partition function
        TYPE index_pivot = partition(array, index_begin, index_end);
        /// sort the array before the pivot position
        quick_sort(array, index_begin, index_pivot - 1);
        /// sort the array after the pivot position
        quick_sort(array, index_pivot + 1, index_end);
    }
}

/**
 * @brief find the max repeated element from a sorted sequence
 *
 * @param[in]      array  sorted sequence
 * @param[in]      count  sequence length
 *
 * @return the element that repeats max time
 */
TYPE search_max_repeated_element(TYPE* array, TYPE count)
{
    TYPE i, count_temp, value_temp;
    TYPE max_value = array[0];
    TYPE max_count = 0;
    for (i = 0; i < count; i++) {
        value_temp = array[i];
        count_temp = 0;
        while (array[++i] == value_temp)
            count_temp++;
        if (count_temp > max_count) {
            max_count = count_temp;
            max_value = value_temp;
        }
    }
    return max_value;
}

/**
 * @brief find the element that repeats max time in the unsorted array
 *
 * @param[in,out]  array  unsorted array
 * @param[in]      count  array length
 *
 * @return the element value that repeats max time
 */
TYPE find_id(TYPE* array, TYPE count)
{
    /// sort array first
    quick_sort(array, 0, count - 1);
    /// search the wanted element
    return search_max_repeated_element(array, count);
}

int main(void) {
    /// read data to array
    TYPE count = 0;
    while(count < MAX_COUNT && scanf("%u\n", array + count) == 1) {
        ++count;
    }
    /// find id
    TYPE id = find_id(array, count);
    /// output result
    printf("max repeat count element is %d.\n", id);
    return EXIT_SUCCESS;
}
