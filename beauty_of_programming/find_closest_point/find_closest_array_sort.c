/**
 * @file find_closest_array_sort.c
 * @brief find the two values in a given array that make their distance be
 * the minimum value so the the values are the closest pairs.
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-02-15
 */

#include <stdlib.h>
#include <stdio.h>
// #define NDEBUG
#include <assert.h>

// #define NDBG_PRINT
#include "debug_print.h"

typedef int ElementType;    ///< element data type
typedef int CommonType;     ///< common data type

#define MAX_COUNT      10000000
ElementType array[MAX_COUNT] = {0};

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
CommonType partition(ElementType* array, CommonType index_begin,
        CommonType index_end)
{
    /// pick last element of the array as the pivot
    ElementType pivot = array[index_end];
    /// index of the elments that not greater than pivot
    CommonType i = index_begin - 1;
    CommonType j, temp;
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
 * @brief quick sort method for input array from index_begin to index_end.
 *
 * @param[in,out]  array          input and output array
 * @param[in]      index_begin    the begin index of the array(included)
 * @param[in]      index_end      the end index of the array(included)
 */
void quick_sort(ElementType* array, CommonType index_begin,
        CommonType index_end)
{
    /// sort only under the index_begin < index_end condition
    if ( index_begin < index_end) {
        /// exchange elements to the pivot position by partition function
        CommonType index_pivot = partition(array, index_begin, index_end);
        /// sort the array before the pivot position
        quick_sort(array, index_begin, index_pivot - 1);
        /// sort the array after the pivot position
        quick_sort(array, index_pivot + 1, index_end);
    }
}

/**
 * @brief find value_a and value_b that they have the minimum distance in
 * the array.
 *
 * @param[in]     array           element array
 * @param[in]     array_size      element array size
 * @param[out]    value_a         element a
 * @param[out]    value_b         element b
 *
 * @return return the minimum distance between value_a and value_b
 */
ElementType find_closest_array(ElementType* array, CommonType array_size,
        ElementType* value_a, ElementType* value_b)
{
    assert(array != NULL && value_a != NULL &&
            value_b != NULL && array_size >= 2);
    /// initialize values.
    ElementType distance_min = abs(array[0] - array[1]);
    *value_a = array[0];
    *value_b = array[1];
    /// find closest value_a and value_b by sort
    quick_sort(array, 0, array_size - 1);
    CommonType i;
    ElementType temp;
    for (i = 1; i < array_size - 1; i++) {
        if ((temp = abs(array[i] - array[i + 1])) < distance_min) {
            *value_a = array[i];
            *value_b = array[i + 1];
            distance_min = temp;
        }
    }
    /// return minimum distance
    return distance_min;
}

int main(void) {
    /// read data to array
    CommonType count = 0;
    while(count < MAX_COUNT && scanf("%u\n", array + count) == 1) {
        ++count;
    }
    /// find closest values
    ElementType value_a;
    ElementType value_b;
    ElementType distance = find_closest_array(array, count,
            &value_a, &value_b);
    /// output result
    printf("closest value_a and value_b is %d, %d.\n", value_a, value_b);
    printf("closest distance is %d.\n", distance);
    return EXIT_SUCCESS;
}
